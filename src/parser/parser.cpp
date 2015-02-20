#include "cion/parser/parser.hpp"

#include "cion/token/token_types.hpp"
#include "cion/error/error_handler.hpp"
#include "cion/error/lexer_exception.hpp"
#include "cion/error/parser_exception.hpp"

#include "cion/ast/all.hpp"

#include <chrono>
#include <cassert>

//#define DEBUG
#ifdef DEBUG
#include <iostream>
#define DEBUG_STDOUT(x) (std::cout << x)
#define DEBUG_STDERR(x) (std::cerr << x)
#undef DEBUG
#else
#define DEBUG_STDOUT(x)
#define DEBUG_STDERR(x)
#endif

namespace cion {

//////////////////////////////////////////////////////////////////////////////////////////
//// Constructor
//////////////////////////////////////////////////////////////////////////////////////////

	Parser::Parser(
		TokenStream & token_stream,
		ErrorHandler const& error_handler
	) :
		m_token_stream{token_stream},
		ctts{TokenTypes::instance()},
		m_error_handler{error_handler}
	{}

//////////////////////////////////////////////////////////////////////////////////////////
//// Helper Functions
//////////////////////////////////////////////////////////////////////////////////////////

	Token const& Parser::previous_token() const {
		return *m_previous_token;
	}

	Token const& Parser::current_token() const {
		return *m_current_token;
	}

	Token const& Parser::next_token() {
		m_previous_token = std::move(m_current_token);
		if (m_peeked_tokens.empty()) {
			m_current_token = m_token_stream.next_token();
		} else {
			m_current_token = std::move(m_peeked_tokens.front());
			m_peeked_tokens.pop();
		}
		return *m_current_token;
	}

	Token const& Parser::peek_token() {
		m_peeked_tokens.push(m_token_stream.next_token());
		return *(m_peeked_tokens.back());
	}

	Token const& Parser::expect(TokenType const& token_type) {
		if (current_token().get_type() != token_type) {
			throw parser_exception(
				m_error_handler.file_name(),
				current_token().get_source_location(),
				"expected token type: " + token_type.name() + "\n");
		}
		next_token(); // consume token with the expected type
		return previous_token();
	}

	bool Parser::optional(TokenType const& token_type) {
		if (current_token().get_type() == token_type) {
			next_token(); // consume the optional token
			return true;
		}
		return false;
	}

//////////////////////////////////////////////////////////////////////////////////////////
//// Recursive Descendent Parsing Functions
//////////////////////////////////////////////////////////////////////////////////////////

	bool Parser::is_binary_op(TokenType const& tt) {
		return
			tt == ctts.op_pipe_pipe ||
			tt == ctts.op_and_and ||
			tt == ctts.op_pipe ||
			tt == ctts.op_caret ||
			tt == ctts.op_and ||
			tt == ctts.op_equals_equals ||
			tt == ctts.op_not_equals ||
			tt == ctts.op_less_than ||
			tt == ctts.op_greater_than ||
			tt == ctts.op_less_equals ||
			tt == ctts.op_greater_equals ||
			tt == ctts.op_plus ||
			tt == ctts.op_minus ||
			tt == ctts.op_star ||
			tt == ctts.op_slash ||
			tt == ctts.op_percent ||
			tt == ctts.op_left_left ||
			tt == ctts.op_right_right
			? true : false;
	}

	bool Parser::is_assign_op(TokenType const& tt) {
		return
			tt == ctts.op_equals ||
			tt == ctts.op_plus_equals ||
			tt == ctts.op_minus_equals ||
			tt == ctts.op_star_equals ||
			tt == ctts.op_slash_equals ||
			tt == ctts.op_percent_equals ||
			tt == ctts.op_pipe_equals ||
			tt == ctts.op_pipe_pipe_equals ||
			tt == ctts.op_caret_equals ||
			tt == ctts.op_and_equals ||
			tt == ctts.op_and_and_equals ||
			tt == ctts.op_left_left_equals ||
			tt == ctts.op_right_right_equals
			? true : false;
	}

	bool Parser::is_unary_op(TokenType const& tt) {
		return
			tt == ctts.op_tilde ||
			tt == ctts.op_exclam_mark ||
			tt == ctts.op_pipe ||
			tt == ctts.op_minus ||
			tt == ctts.op_plus_plus ||
			tt == ctts.op_minus_minus
			? true : false;
	}

//////////////////////////////////////////////////////////////////////////////////////////
//// Parsing functions for expressions and expression lists.
//////////////////////////////////////////////////////////////////////////////////////////

	std::vector<std::unique_ptr<ast::Expr>> Parser::parse_argument_list() {
		std::vector<std::unique_ptr<ast::Expr>> expressions;

		expressions.push_back(parse_expr());

		while (optional(ctts.op_comma)) {
			expressions.push_back(parse_expr());
		}

		return expressions;
	}

	std::unique_ptr<ast::Expr> Parser::parse_expr() {
		return parse_assignment_expr();
	}

	std::unique_ptr<ast::Expr> Parser::parse_assignment_expr() {
		auto lhs = parse_conditional_expr();

		if        (optional(ctts.op_equals)) {
			DEBUG_STDERR("parsed: AssignExpr\n");
			return {std::make_unique<ast::AssignExpr>(
				std::move(lhs), parse_assignment_expr())};

		} else if (optional(ctts.op_plus_equals)) {
			DEBUG_STDERR("parsed: AddAssignExpr\n");
			return {std::make_unique<ast::AddAssignExpr>(
				std::move(lhs), parse_assignment_expr())};

		} else if (optional(ctts.op_minus_equals)) {
			DEBUG_STDERR("parsed: SubtractAssignExpr\n");
			return {std::make_unique<ast::SubtractAssignExpr>(
				std::move(lhs), parse_assignment_expr())};

		} else if (optional(ctts.op_star_equals)) {
			DEBUG_STDERR("parsed: MultiplyAssignExpr\n");
			return {std::make_unique<ast::MultiplyAssignExpr>(
				std::move(lhs), parse_assignment_expr())};

		} else if (optional(ctts.op_slash_equals)) {
			DEBUG_STDERR("parsed: DivideAssignExpr\n");
			return {std::make_unique<ast::DivideAssignExpr>(
				std::move(lhs), parse_assignment_expr())};

		} else if (optional(ctts.op_percent_equals)) {
			DEBUG_STDERR("parsed: ModuloAssignExpr\n");
			return {std::make_unique<ast::ModuloAssignExpr>(
				std::move(lhs), parse_assignment_expr())};

		} else if (optional(ctts.op_pipe_equals)) {
			DEBUG_STDERR("parsed: BitOrAssignExpr\n");
			return {std::make_unique<ast::BitOrAssignExpr>(
				std::move(lhs), parse_assignment_expr())};

		} else if (optional(ctts.op_pipe_pipe_equals)) {
			DEBUG_STDERR("parsed: LogicalOrAssignExpr\n");
			return {std::make_unique<ast::LogicalOrAssignExpr>(
				std::move(lhs), parse_assignment_expr())};

		} else if (optional(ctts.op_caret_equals)) {
			DEBUG_STDERR("parsed: BitXorAssignExpr\n");
			return {std::make_unique<ast::BitXorAssignExpr>(
				std::move(lhs), parse_assignment_expr())};

		} else if (optional(ctts.op_and_equals)) {
			DEBUG_STDERR("parsed: BitAndAssignExpr\n");
			return {std::make_unique<ast::BitAndAssignExpr>(
				std::move(lhs), parse_assignment_expr())};

		} else if (optional(ctts.op_and_and_equals)) {
			DEBUG_STDERR("parsed: LogicalAndAssignExpr\n");
			return {std::make_unique<ast::LogicalAndAssignExpr>(
				std::move(lhs), parse_assignment_expr())};

		} else if (optional(ctts.op_left_left_equals)) {
			DEBUG_STDERR("parsed: ShiftLeftAssignExpr\n");
			return {std::make_unique<ast::ShiftLeftAssignExpr>(
				std::move(lhs), parse_assignment_expr())};

		} else if (optional(ctts.op_right_right_equals)) {
			DEBUG_STDERR("parsed: ShiftRightAssignExpr\n");
			return {std::make_unique<ast::ShiftRightAssignExpr>(
				std::move(lhs), parse_assignment_expr())};
		}

		return lhs;
	}

	std::unique_ptr<ast::Expr> Parser::parse_conditional_expr() {
		auto condition = parse_logical_or_expr();

		if (optional(ctts.op_question_mark)) {
			DEBUG_STDERR("parsed: ConditionalExpr\n");

			auto then_expr = parse_expr();

			expect(ctts.op_colon);

			auto else_expr = parse_expr();

			return {std::make_unique<ast::ConditionalExpr>(
				std::move(condition), std::move(then_expr), std::move(else_expr))};
		}

		return condition;
	}

	std::unique_ptr<ast::Expr> Parser::parse_logical_or_expr() {
		auto lhs = parse_logical_and_expr();

		while (optional(ctts.op_pipe_pipe)) {
			DEBUG_STDERR("parsed: LogicalOrExpr\n");
			auto rhs = parse_logical_and_expr();
			lhs = {std::make_unique<ast::LogicalOrExpr>(
				std::move(lhs), std::move(rhs))};
		}

		return lhs;
	}

	std::unique_ptr<ast::Expr> Parser::parse_logical_and_expr() {
		auto lhs = parse_bit_or_expr();

		while (optional(ctts.op_and_and)) {
			DEBUG_STDERR("parsed: LogicalAndExpr\n");
			auto rhs = parse_bit_or_expr();
			lhs = {std::make_unique<ast::LogicalAndExpr>(
				std::move(lhs), std::move(rhs))};
		}

		return lhs;
	}

	std::unique_ptr<ast::Expr> Parser::parse_bit_or_expr() {
		auto lhs = parse_bit_xor_expr();

		while (optional(ctts.op_pipe)) {
			DEBUG_STDERR("parsed: BitOrExpr\n");
			auto rhs = parse_bit_xor_expr();
			lhs = {std::make_unique<ast::BitOrExpr>(
				std::move(lhs), std::move(rhs))};
		}

		return lhs;
	}

	std::unique_ptr<ast::Expr> Parser::parse_bit_xor_expr() {
		auto lhs = parse_bit_and_expr();

		while (optional(ctts.op_caret)) {
			DEBUG_STDERR("parsed: BitXorExpr\n");
			auto rhs = parse_bit_and_expr();
			lhs = {std::make_unique<ast::BitXorExpr>(
				std::move(lhs), std::move(rhs))};
		}

		return lhs;
	}

	std::unique_ptr<ast::Expr> Parser::parse_bit_and_expr() {
		auto lhs = parse_equality_expr();

		while (optional(ctts.op_and)) {
			DEBUG_STDERR("parsed: BitAndExpr\n");
			auto rhs = parse_equality_expr();
			lhs = {std::make_unique<ast::BitAndExpr>(
				std::move(lhs), std::move(rhs))};
		}

		return lhs;
	}

	std::unique_ptr<ast::Expr> Parser::parse_equality_expr() {
		auto lhs = parse_relational_expr();

		while (true) {
			if        (optional(ctts.op_equals_equals)) {
				DEBUG_STDERR("parsed: EqualityExpr\n");
				auto rhs = parse_relational_expr();
				lhs = {std::make_unique<ast::EqualityExpr>(
					std::move(lhs), std::move(rhs))};

			} else if (optional(ctts.op_not_equals)) {
				DEBUG_STDERR("parsed: InequalityExpr\n");
				auto rhs = parse_relational_expr();
				lhs = {std::make_unique<ast::InequalityExpr>(
					std::move(lhs), std::move(rhs))};

			} else break;
		}

		return lhs;
	}

	std::unique_ptr<ast::Expr> Parser::parse_relational_expr() {
		auto lhs = parse_bitshift_expr();

		while (true) {
			if        (optional(ctts.op_less_than)) {
				DEBUG_STDERR("parsed: LessThanExpr\n");
				auto rhs = parse_bitshift_expr();
				lhs = {std::make_unique<ast::LessThanExpr>(
					std::move(lhs), std::move(rhs))};

			} else if (optional(ctts.op_less_equals)) {
				DEBUG_STDERR("parsed: LessEqualsExpr\n");
				auto rhs = parse_bitshift_expr();
				lhs = {std::make_unique<ast::LessEqualsExpr>(
					std::move(lhs), std::move(rhs))};

			} else if (optional(ctts.op_greater_than)) {
				DEBUG_STDERR("parsed: GreaterThanExpr\n");
				auto rhs = parse_bitshift_expr();
				lhs = {std::make_unique<ast::GreaterThanExpr>(
					std::move(lhs), std::move(rhs))};

			} else if (optional(ctts.op_greater_equals)) {
				DEBUG_STDERR("parsed: GreaterEqualsExpr\n");
				auto rhs = parse_bitshift_expr();
				lhs = {std::make_unique<ast::GreaterEqualsExpr>(
					std::move(lhs), std::move(rhs))};

			} else break;
		}

		return lhs;
	}

	std::unique_ptr<ast::Expr> Parser::parse_bitshift_expr() {
		auto lhs = parse_additive_expr();

		while (true) {
			if        (optional(ctts.op_left_left)) {
				DEBUG_STDERR("parsed: ShiftLeftExpr\n");
				auto rhs = parse_additive_expr();
				lhs = {std::make_unique<ast::ShiftLeftExpr>(
					std::move(lhs), std::move(rhs))};

			} else if (optional(ctts.op_right_right)) {
				DEBUG_STDERR("parsed: ShiftRightExpr\n");
				auto rhs = parse_additive_expr();
				lhs = {std::make_unique<ast::ShiftRightExpr>(
					std::move(lhs), std::move(rhs))};

			} else break;
		}

		return lhs;
	}

	std::unique_ptr<ast::Expr> Parser::parse_additive_expr() {
		auto lhs = parse_multiplicative_expr();

		while (true) {
			if        (optional(ctts.op_plus)) {
				DEBUG_STDERR("parsed: AddExpr\n");
				auto rhs = parse_multiplicative_expr();
				lhs = {std::make_unique<ast::AddExpr>(
					std::move(lhs), std::move(rhs))};

			} else if (optional(ctts.op_minus)) {
				DEBUG_STDERR("parsed: SubtractExpr\n");
				auto rhs = parse_multiplicative_expr();
				lhs = {std::make_unique<ast::SubtractExpr>(
					std::move(lhs), std::move(rhs))};

			} else break;
		}

		return lhs;
	}

	std::unique_ptr<ast::Expr> Parser::parse_multiplicative_expr() {
		auto lhs = parse_unary_expr();

		while (true) {
			if        (optional(ctts.op_star)) {
				DEBUG_STDERR("parsed: MultiplyExpr\n");
				auto rhs = parse_unary_expr();
				lhs = {std::make_unique<ast::MultiplyExpr>(
					std::move(lhs), std::move(rhs))};

			} else if (optional(ctts.op_slash)) {
				DEBUG_STDERR("parsed: DivideExpr\n");
				auto rhs = parse_unary_expr();
				lhs = {std::make_unique<ast::DivideExpr>(
					std::move(lhs), std::move(rhs))};

			} else if (optional(ctts.op_percent)) {
				DEBUG_STDERR("parsed: ModuloExpr\n");
				auto rhs = parse_unary_expr();
				lhs = {std::make_unique<ast::ModuloExpr>(
					std::move(lhs), std::move(rhs))};

			} else break;
		}

		return lhs;
	}

	std::unique_ptr<ast::Expr> Parser::parse_unary_expr() {
		if        (optional(ctts.op_tilde)) {
			DEBUG_STDERR("parsed: BitNegateExpr");
			return {std::make_unique<ast::BitNegateExpr>(parse_unary_expr())};

		} else if (optional(ctts.op_exclam_mark)) {
			DEBUG_STDERR("parsed: LogicalNegateExpr");
			return {std::make_unique<ast::LogicalNegateExpr>(parse_unary_expr())};

		} else if (optional(ctts.op_plus)) {
			DEBUG_STDERR("parsed: PlusExpr");
			return {std::make_unique<ast::PlusExpr>(parse_unary_expr())};

		} else if (optional(ctts.op_minus)) {
			DEBUG_STDERR("parsed: MinusExpr");
			return {std::make_unique<ast::MinusExpr>(parse_unary_expr())};

		} else if (optional(ctts.op_plus_plus)) {
			DEBUG_STDERR("parsed: IncrementExpr");
			return {std::make_unique<ast::IncrementExpr>(parse_unary_expr())};

		} else if (optional(ctts.op_minus_minus)) {
			DEBUG_STDERR("parsed: DecrementExpr");
			return {std::make_unique<ast::DecrementExpr>(parse_unary_expr())};
		}

		return parse_postfix_expr();
	}

	std::unique_ptr<ast::Expr> Parser::parse_postfix_expr() {
		auto lhs = parse_primary_expr();

		while (true) {
			if        (optional(ctts.opening_brack)) {
				DEBUG_STDERR("parsed: IndexExpr\n");
				auto indices = parse_argument_list();
				expect(ctts.closing_brack);
				lhs = {std::make_unique<ast::IndexExpr>(
					std::move(lhs), std::move(indices))};

			} else if (optional(ctts.opening_paren)) {
				DEBUG_STDERR("parsed: CallExpr\n");
				if (optional(ctts.closing_paren)) {
					lhs = {std::make_unique<ast::CallExpr>(std::move(lhs))};
				} else {
					auto args = parse_argument_list();
					expect(ctts.closing_paren);
					lhs = {std::make_unique<ast::CallExpr>(
						std::move(lhs), std::move(args))};
				}

			} else if (optional(ctts.op_plus_plus)) {
				DEBUG_STDERR("parsed: PostIncrementExpr\n");
				lhs = {std::make_unique<ast::PostIncrementExpr>(std::move(lhs))};

			} else if (optional(ctts.op_minus_minus)) {
				DEBUG_STDERR("parsed: PostDecrementExpr\n");
				lhs = {std::make_unique<ast::PostDecrementExpr>(std::move(lhs))};

			} else break;
		}

		return lhs;
	}

	std::unique_ptr<ast::Expr> Parser::parse_primary_expr() {
		const auto tt = current_token().get_type();

		// parse parenthesed expressions: '(' expr ')'
		if        (optional(ctts.opening_paren)) {
			DEBUG_STDERR("parsed: braced expression\n");
			auto expr = parse_expr();
			expect(ctts.closing_paren);
			return expr;

		// parse boolean literals: 'true' or 'false'
		} else if (optional(ctts.lit_bool)) {
			DEBUG_STDERR("parsed: boolean_literal\n");
			return std::make_unique<ast::BooleanExpr>(
				previous_token().get_bool());

		// parse character literals: 'x'
		} else if (optional(ctts.lit_char)) {
			DEBUG_STDERR("parsed: char_literal\n");
			return std::make_unique<ast::CharExpr>(
				previous_token().get_char());

		// parse string literals: "foo"
		} else if (optional(ctts.lit_string)) {
			DEBUG_STDERR("parsed: string_literal\n");
			return std::make_unique<ast::StringExpr>(
				previous_token().get_string());

		// parse integral literals: 42
		} else if (optional(ctts.lit_integral)) {
			DEBUG_STDERR("parsed: integer_literal\n");
			return std::make_unique<ast::IntegerExpr>(
				previous_token().get_integral());

		// parse number literals: 13.37
		} else if (optional(ctts.lit_number)) {
			DEBUG_STDERR("parsed: float_literal\n");
			return std::make_unique<ast::FloatExpr>(
				previous_token().get_number());

		// parse simple names: foo
		} else if (tt == ctts.identifier) {
			DEBUG_STDERR("parsed: variable_expr\n");
			auto name = current_token().get_string();
			next_token(); // consume identifier
			return std::make_unique<ast::VarExpr>(name);
		}

		throw parser_exception(
			m_error_handler.file_name(),
			current_token().get_source_location(),
			"no matching expression was found.\n");
	}

//////////////////////////////////////////////////////////////////////////////////////////
//// Parsing functions for custom and primitive types.
//////////////////////////////////////////////////////////////////////////////////////////

	bool Parser::is_start_of_builtin_int_type(TokenType const& tt) const {
		return
			tt == ctts.type_int ||
			tt == ctts.type_int8 ||
			tt == ctts.type_int16 ||
			tt == ctts.type_int32 ||
			tt == ctts.type_int64 ||
			tt == ctts.type_uint ||
			tt == ctts.type_uint8 ||
			tt == ctts.type_uint16 ||
			tt == ctts.type_uint32 ||
			tt == ctts.type_uint64
			? true : false;
	}

	std::unique_ptr<ast::BuiltinIntType> Parser::parse_builtin_int_type() {
		using ptiw = ast::BuiltinIntType::Width;
		const auto tt = current_token().get_type();
		assert(is_start_of_builtin_int_type(tt));
		const auto bit_width =
			  tt == ctts.type_int   || tt == ctts.type_uint   ? ptiw::unspecified
			: tt == ctts.type_int8  || tt == ctts.type_uint8  ? ptiw::one_byte
			: tt == ctts.type_int16 || tt == ctts.type_uint16 ? ptiw::two_bytes
			: tt == ctts.type_int32 || tt == ctts.type_uint32 ? ptiw::four_bytes
			: tt == ctts.type_int64 || tt == ctts.type_uint64 ? ptiw::eight_bytes
			: throw parser_exception(
				m_error_handler.file_name(),
				current_token().get_source_location(),
				"invalid bit width specifier of int type\n");
		const auto is_signed =
			   tt == ctts.type_int
			|| tt == ctts.type_int8
			|| tt == ctts.type_int16
			|| tt == ctts.type_int32
			|| tt == ctts.type_int64 ? true : false;
		next_token(); // consume this int type token
		return std::make_unique<ast::BuiltinIntType>(is_signed, bit_width);
	}

	bool Parser::is_start_of_builtin_float_type(TokenType const& tt) const {
		return
			tt == ctts.type_float ||
			tt == ctts.type_float16 ||
			tt == ctts.type_float32 ||
			tt == ctts.type_float64
			? true : false;
	}

	std::unique_ptr<ast::BuiltinFloatType> Parser::parse_builtin_float_type() {
		using ptiw = ast::BuiltinFloatType::Width;
		const auto tt = current_token().get_type();
		assert(is_start_of_builtin_float_type(tt));
		const auto bit_width =
			  tt == ctts.type_float   ? ptiw::unspecified
			: tt == ctts.type_float16 ? ptiw::two_bytes
			: tt == ctts.type_float32 ? ptiw::four_bytes
			: tt == ctts.type_float64 ? ptiw::eight_bytes
			: throw parser_exception(
				m_error_handler.file_name(),
				current_token().get_source_location(),
				"invalid bit width specifier of float type\n");
		next_token(); // consume this float type token
		return std::make_unique<ast::BuiltinFloatType>(bit_width);
	}

	std::unique_ptr<ast::Type> Parser::parse_type() {
		const auto tt = current_token().get_type();
		if        (tt == ctts.type_bool) {
			next_token();
			DEBUG_STDERR("parsed: BuiltinBoolType\n");
			return std::make_unique<ast::BuiltinBoolType>();

		} else if (tt == ctts.type_char) {
			next_token();
			DEBUG_STDERR("parsed: BuiltinCharType\n");
			return std::make_unique<ast::BuiltinCharType>();

		} else if (is_start_of_builtin_int_type(tt)) {
			DEBUG_STDERR("parsed: BuiltinIntType\n");
			return parse_builtin_int_type();

		} else if (is_start_of_builtin_float_type(tt)) {
			DEBUG_STDERR("parsed: BuiltinFloatType\n");
			return parse_builtin_float_type();
		}

		throw parser_exception(
			m_error_handler.file_name(),
			current_token().get_source_location(),
			"no matching type specifier was found.\n");
	}

//////////////////////////////////////////////////////////////////////////////////////////
//// Parse top level statements.
//////////////////////////////////////////////////////////////////////////////////////////

	std::unique_ptr<ast::VarDecl> Parser::parse_var_decl() {
		expect(ctts.cmd_var);

		auto var_name = expect(ctts.identifier).get_string();

		std::unique_ptr<ast::Type> type;
		std::unique_ptr<ast::Expr> expr;

		if (optional(ctts.op_colon)) {
			type = parse_type();

			expr = optional(ctts.op_equals)
				? parse_expr()
				: std::unique_ptr<ast::Expr>{std::make_unique<ast::NothingExpr>()};

		} else {
			type = std::unique_ptr<ast::Type>{
				std::make_unique<ast::NothingType>()};
			expect(ctts.op_equals);
			expr = parse_expr();
		}

		expect(ctts.op_semi_colon);

		DEBUG_STDERR("parsed: VarDecl\n");
		return std::make_unique<ast::VarDecl>(
			var_name, std::move(type), std::move(expr));
	}

	std::unique_ptr<ast::ParamDecl> Parser::parse_param_decl() {
		auto param_name = expect(ctts.identifier).get_string();

		expect(ctts.op_colon);

		auto param_type = parse_type();

		DEBUG_STDERR("parsed: ParamDecl\n");
		return std::make_unique<ast::ParamDecl>(param_name, std::move(param_type));
	}

	std::vector<std::unique_ptr<ast::ParamDecl>> Parser::parse_param_decl_list() {
		std::vector<std::unique_ptr<ast::ParamDecl>> params;

		if (current_token().get_type() == ctts.identifier
				&& peek_token().get_type() == ctts.op_colon) {
			params.push_back(parse_param_decl());

			while (optional(ctts.op_comma)) {
				params.push_back(parse_param_decl());
			}
		}

		DEBUG_STDERR("parsed: ParamDeclList\n");
		return params;
	}

	std::unique_ptr<ast::CompoundStmnt> Parser::parse_compound_stmnt() {
		expect(ctts.opening_brace);

		std::vector<std::unique_ptr<ast::Stmnt>> statements;
		while (current_token().get_type() != ctts.closing_brace) {
			statements.push_back(parse_stmnt());
		}

		expect(ctts.closing_brace);

		DEBUG_STDERR("parsed: CompoundStmnt\n");
		return std::make_unique<ast::CompoundStmnt>(std::move(statements));
	}

	std::unique_ptr<ast::FunctionDecl> Parser::parse_function_decl() {
		expect(ctts.cmd_function);

		auto function_name = expect(ctts.identifier).get_string();

		expect(ctts.opening_paren);

		auto params = parse_param_decl_list();

		expect(ctts.closing_paren);

		auto return_type_required = false;
		if (current_token().get_type() == ctts.op_arrow) {
			next_token(); // consume '->'
			return_type_required = true;
		}

		auto return_type = (return_type_required)
			? parse_type()
			: std::unique_ptr<ast::Type>{std::make_unique<ast::NothingType>()};

		auto function_body = parse_compound_stmnt();

		DEBUG_STDERR("parsed: FunctionDecl\n");
		return std::make_unique<ast::FunctionDecl>(
			function_name,
			std::move(params),
			std::move(return_type),
			std::move(function_body));
	}

	std::unique_ptr<ast::Decl> Parser::parse_top_level_decl() {
		DEBUG_STDERR("parsed: TopLevelDecl\n");

		const auto tt = current_token().get_type();

		// Global Variable Declaration
		if        (tt == ctts.cmd_var) {
			return parse_var_decl();

		// Free Function Declaration
		} else if (tt == ctts.cmd_function) {
			return parse_function_decl();
		}

		throw parser_exception(
			m_error_handler.file_name(),
			current_token().get_source_location(),
			"expected top-level statement\n");
	}

	std::unique_ptr<ast::CompilationUnitDecl> Parser::parse_compilation_unit_decl() {
		std::vector<std::unique_ptr<ast::Decl>> top_level_decls;
		while (current_token().get_type() != TokenType::eof) {
			top_level_decls.push_back(parse_top_level_decl());
			DEBUG_STDERR("\n");
		}
		DEBUG_STDERR("parsed: CompilationUnitDecl\n");
		return std::make_unique<ast::CompilationUnitDecl>(std::move(top_level_decls));
	}

//////////////////////////////////////////////////////////////////////////////////////////
//// Parse normal statements.
//////////////////////////////////////////////////////////////////////////////////////////

	std::unique_ptr<ast::WhileStmnt> Parser::parse_while_stmnt() {
		expect(ctts.cmd_while);

		auto condition = parse_expr();

		auto body = parse_compound_stmnt();

		return std::make_unique<ast::WhileStmnt>(
			std::move(condition), std::move(body));
	}

	std::unique_ptr<ast::IfStmnt> Parser::parse_if_stmnt() {
		expect(ctts.cmd_if);

		auto condition = parse_expr();

		auto then_stmnt = parse_compound_stmnt();

		if (optional(ctts.cmd_else)) {
			using stmnt = std::unique_ptr<ast::Stmnt>;
			auto else_stmnt = (current_token().get_type() == ctts.cmd_if)
				? stmnt{parse_if_stmnt()}
				: stmnt{parse_compound_stmnt()};
			return std::make_unique<ast::IfStmnt>(
				std::move(condition), std::move(then_stmnt), std::move(else_stmnt));
		}

		return std::make_unique<ast::IfStmnt>(
			std::move(condition), std::move(then_stmnt));
	}

	std::unique_ptr<ast::ReturnStmnt> Parser::parse_return_stmnt() {
		expect(ctts.cmd_return);
		auto return_expr = current_token().get_type() != ctts.op_semi_colon
			? parse_expr()
			: std::unique_ptr<ast::Expr>{std::make_unique<ast::NothingExpr>()};
		expect(ctts.op_semi_colon);
		return std::make_unique<ast::ReturnStmnt>(std::move(return_expr));
	}

	std::unique_ptr<ast::BreakStmnt> Parser::parse_break_stmnt() {
		expect(ctts.cmd_break);
		return std::make_unique<ast::BreakStmnt>();
	}

	std::unique_ptr<ast::ContinueStmnt> Parser::parse_continue_stmnt() {
		expect(ctts.cmd_continue);
		return std::make_unique<ast::ContinueStmnt>();
	}

	std::unique_ptr<ast::ExprStmnt> Parser::parse_expr_stmnt() {
		auto expr = parse_expr();
		expect(ctts.op_semi_colon);
		return std::make_unique<ast::ExprStmnt>(std::move(expr));
	}

	bool Parser::is_start_of_decl_stmnt(TokenType const& tt) const {
		return
			tt == ctts.cmd_var ||
			tt == ctts.cmd_function
			? true : false;
	}

	std::unique_ptr<ast::DeclStmnt> Parser::parse_decl_stmnt() {
		const auto tt = current_token().get_type();
		assert(is_start_of_decl_stmnt(tt));
		using decl = std::unique_ptr<ast::Decl>;
		return std::make_unique<ast::DeclStmnt>(
			tt == ctts.cmd_var ? decl{parse_var_decl()} : decl{parse_function_decl()}
		);
	}

	std::unique_ptr<ast::Stmnt> Parser::parse_stmnt() {
		using stmnt = std::unique_ptr<ast::Stmnt>;
		const auto tt = current_token().get_type();
		return
			tt == ctts.cmd_while       ? stmnt{parse_while_stmnt()}:
			tt == ctts.cmd_if          ? stmnt{parse_if_stmnt()}:
			tt == ctts.cmd_return      ? stmnt{parse_return_stmnt()}:
			tt == ctts.cmd_break       ? stmnt{parse_break_stmnt()}:
			tt == ctts.cmd_continue    ? stmnt{parse_continue_stmnt()}:
			tt == ctts.opening_brace   ? stmnt{parse_compound_stmnt()}:
			is_start_of_decl_stmnt(tt) ? stmnt{parse_decl_stmnt()}:
			                             stmnt{parse_expr_stmnt()};
	}

//////////////////////////////////////////////////////////////////////////////////////////
//// Public Parsing Interface Function
//////////////////////////////////////////////////////////////////////////////////////////

	std::unique_ptr<ast::CompilationUnitDecl> Parser::parse() {
		DEBUG_STDERR("parser init\n");
		try {
			next_token();
			return parse_compilation_unit_decl();
		} catch (lexer_exception const& e) {
			//std::cerr << "lexer exception thrown: " << e.message() << "\n";
			DEBUG_STDERR("lexer exception thrown: " << e.message() << "\n");
		} catch (parser_exception const& e) {
			DEBUG_STDERR("parser exception thrown in " << e.message() << "\n");
			//std::cerr << "parser exception thrown in " << e.message() << "\n";
		}
		std::exit(EXIT_FAILURE);
	}
}
