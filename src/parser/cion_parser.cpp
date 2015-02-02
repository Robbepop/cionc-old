#include "parser/cion_parser.hpp"

#include "token/cion_token_types.hpp"
#include "error/error_handler.hpp"
#include "error/lexer_exception.hpp"
#include "error/parser_exception.hpp"

#include "ast/statement.hpp"
#include "ast/primitive_type_bool.hpp"
#include "ast/primitive_type_char.hpp"
#include "ast/primitive_type_int.hpp"
#include "ast/primitive_type_float.hpp"
#include "ast/variable_declaration_statement.hpp"
#include "ast/boolean_expr.hpp"
#include "ast/char_literal.hpp"
#include "ast/string_literal.hpp"
#include "ast/integer_literal.hpp"
#include "ast/float_literal.hpp"
#include "ast/variable_expression.hpp"
#include "ast/assignment_expression.hpp"
#include "ast/conditional_expression.hpp"
#include "ast/binary_expression.hpp"
#include "ast/unary_expression.hpp"
#include "ast/postfix_expression.hpp"
#include "ast/index_expression.hpp"
#include "ast/call_expression.hpp"
#include "ast/nothing_expression.hpp"
#include "ast/nothing_type.hpp"


#include <chrono>

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

	CionParser::CionParser(
		TokenStream & token_stream,
		ErrorHandler const& error_handler
	) :
		m_token_stream{token_stream},
		ctts{CionTokenTypes::get_instance()},
		m_error_handler{error_handler}
	{}

//////////////////////////////////////////////////////////////////////////////////////////
//// Helper Functions
//////////////////////////////////////////////////////////////////////////////////////////

	Token const& CionParser::previous_token() const {
		return *m_previous_token;
	}

	Token const& CionParser::current_token() const {
		return *m_current_token;
	}

	Token const& CionParser::next_token() {
		m_previous_token = std::move(m_current_token);
		if (m_peeked_tokens.empty()) {
			m_current_token = m_token_stream.next_token();
		} else {
			m_current_token = std::move(m_peeked_tokens.front());
			m_peeked_tokens.pop();
		}
		return *m_current_token;
	}

	Token const& CionParser::peek_token() {
		m_peeked_tokens.push(m_token_stream.next_token());
		return *(m_peeked_tokens.back());
	}

	Token const& CionParser::expect(TokenType const& token_type) {
		if (current_token().get_type() != token_type) {
			throw parser_exception(
				m_error_handler.file_name(),
				current_token().get_source_location(),
				"expected token type: " + token_type.get_name() + "\n");
		}
		next_token(); // consume token with the expected type
		return previous_token();
	}

	bool CionParser::optional(TokenType const& token_type) {
		if (current_token().get_type() == token_type) {
			next_token(); // consume the optional token
			return true;
		}
		return false;
	}

//////////////////////////////////////////////////////////////////////////////////////////
//// Recursive Descendent Parsing Functions
//////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////
//// Parsing functions for expressions and expression lists.
//////////////////////////////////////////////////////////////////////////////////////////

	std::unique_ptr<ast::ExpressionList> CionParser::parse_expression_list() {
		std::vector<std::unique_ptr<ast::Expr>> expressions;

		expressions.push_back(parse_expression());

		while (optional(ctts.op_comma)) {
			expressions.push_back(parse_expression());
		}

		return std::make_unique<ast::ExpressionList>(std::move(expressions));
	}

	std::unique_ptr<ast::Expr> CionParser::parse_expression() {
		return parse_assignment_expression();
	}

	std::unique_ptr<ast::Expr> CionParser::parse_assignment_expression() {
		auto lhs = parse_conditional_expression();

		using assignment = ast::AssignmentExpression;

		auto tt = current_token().get_type();
		if (assignment::is_operator(tt)) {
			auto op = assignment::get_operator(tt);
			next_token(); // consume assignment operator
			return {std::make_unique<assignment>(
				op, std::move(lhs), parse_expression())};
		}

		DEBUG_STDERR("parsed: assignment_expression\n");
		return lhs;
	}

	std::unique_ptr<ast::Expr> CionParser::parse_conditional_expression() {
		auto condition = parse_logical_or_expression();

		if (optional(ctts.op_question_mark)) {
			auto then_expr = parse_expression();

			expect(ctts.op_colon);

			auto else_expr = parse_expression();

			return {std::make_unique<ast::ConditionalExpression>(
				std::move(condition), std::move(then_expr), std::move(else_expr))};
		}

		DEBUG_STDERR("parsed: conditional_expression\n");
		return condition;
	}

	std::unique_ptr<ast::Expr> CionParser::parse_logical_or_expression() {
		auto lhs = parse_logical_and_expression();

		using op = ast::BinaryExpression::Operator;

		while (optional(ctts.op_pipe_pipe)) {
			auto rhs = parse_logical_and_expression();
			lhs = {std::make_unique<ast::BinaryExpression>(
				op::logical_or, std::move(lhs), std::move(rhs))};
		}

		DEBUG_STDERR("parsed: logical_or_expression\n");
		return lhs;
	}

	std::unique_ptr<ast::Expr> CionParser::parse_logical_and_expression() {
		auto lhs = parse_inclusive_or_expression();

		using op = ast::BinaryExpression::Operator;

		while (optional(ctts.op_ampersand_ampersand)) {
			auto rhs = parse_inclusive_or_expression();
			lhs = {std::make_unique<ast::BinaryExpression>(
				op::logical_and, std::move(lhs), std::move(rhs))};
		}

		DEBUG_STDERR("parsed: logical_and_expression\n");
		return lhs;
	}

	std::unique_ptr<ast::Expr> CionParser::parse_inclusive_or_expression() {
		auto lhs = parse_exclusive_or_expression();

		using op = ast::BinaryExpression::Operator;

		while (optional(ctts.op_pipe)) {
			auto rhs = parse_exclusive_or_expression();
			lhs = {std::make_unique<ast::BinaryExpression>(
				op::inclusive_or, std::move(lhs), std::move(rhs))};
		}

		DEBUG_STDERR("parsed: inclusive_or_expression\n");
		return lhs;
	}

	std::unique_ptr<ast::Expr> CionParser::parse_exclusive_or_expression() {
		auto lhs = parse_bitwise_and_expression();

		using op = ast::BinaryExpression::Operator;

		while (optional(ctts.op_caret)) {
			auto rhs = parse_bitwise_and_expression();
			lhs = {std::make_unique<ast::BinaryExpression>(
				op::exclusive_or, std::move(lhs), std::move(rhs))};
		}

		DEBUG_STDERR("parsed: exclusive_or_expression\n");
		return lhs;
	}

	std::unique_ptr<ast::Expr> CionParser::parse_bitwise_and_expression() {
		auto lhs = parse_equality_expression();

		using op = ast::BinaryExpression::Operator;

		while (optional(ctts.op_ampersand)) {
			auto rhs = parse_equality_expression();
			lhs = {std::make_unique<ast::BinaryExpression>(
				op::bitwise_and, std::move(lhs), std::move(rhs))};
		}

		DEBUG_STDERR("parsed: bitwise_and_expression\n");
		return lhs;
	}

	std::unique_ptr<ast::Expr> CionParser::parse_equality_expression() {
		auto lhs = parse_relational_expression();

		using op = ast::BinaryExpression::Operator;

		while (true) {
			if        (optional(ctts.op_equals_equals)) {
				auto rhs = parse_relational_expression();
				lhs = {std::make_unique<ast::BinaryExpression>(
					op::equality, std::move(lhs), std::move(rhs))};

			} else if (optional(ctts.op_not_equals)) {
				auto rhs = parse_relational_expression();
				lhs = {std::make_unique<ast::BinaryExpression>(
					op::inequality, std::move(lhs), std::move(rhs))};

			} else break;
		}

		DEBUG_STDERR("parsed: equality_expression\n");
		return lhs;
	}

	std::unique_ptr<ast::Expr> CionParser::parse_relational_expression() {
		auto lhs = parse_bitshift_expression();

		using op = ast::BinaryExpression::Operator;

		while (true) {
			if        (optional(ctts.op_less_than)) {
				auto rhs = parse_bitshift_expression();
				lhs = {std::make_unique<ast::BinaryExpression>(
					op::less_than, std::move(lhs), std::move(rhs))};

			} else if (optional(ctts.op_less_equals)) {
				auto rhs = parse_bitshift_expression();
				lhs = {std::make_unique<ast::BinaryExpression>(
					op::less_equals, std::move(lhs), std::move(rhs))};

			} else if (optional(ctts.op_greater_than)) {
				auto rhs = parse_bitshift_expression();
				lhs = {std::make_unique<ast::BinaryExpression>(
					op::greater_than, std::move(lhs), std::move(rhs))};

			} else if (optional(ctts.op_greater_equals)) {
				auto rhs = parse_bitshift_expression();
				lhs = {std::make_unique<ast::BinaryExpression>(
					op::greater_equals, std::move(lhs), std::move(rhs))};

			} else break;
		}

		DEBUG_STDERR("parsed: relational_expression\n");
		return lhs;
	}

	std::unique_ptr<ast::Expr> CionParser::parse_bitshift_expression() {
		auto lhs = parse_additive_expression();

		using op = ast::BinaryExpression::Operator;

		while (true) {
			if        (optional(ctts.op_left_left)) {
				auto rhs = parse_additive_expression();
				lhs = {std::make_unique<ast::BinaryExpression>(
					op::shift_left, std::move(lhs), std::move(rhs))};

			} else if (optional(ctts.op_right_right)) {
				auto rhs = parse_additive_expression();
				lhs = {std::make_unique<ast::BinaryExpression>(
					op::shift_right, std::move(lhs), std::move(rhs))};

			} else break;
		}

		DEBUG_STDERR("parsed: bitshift_expression\n");
		return lhs;
	}

	std::unique_ptr<ast::Expr> CionParser::parse_additive_expression() {
		auto lhs = parse_multiplicative_expression();

		using op = ast::BinaryExpression::Operator;

		while (true) {
			if        (optional(ctts.op_plus)) {
				auto rhs = parse_multiplicative_expression();
				lhs = {std::make_unique<ast::BinaryExpression>(
					op::plus, std::move(lhs), std::move(rhs))};

			} else if (optional(ctts.op_minus)) {
				auto rhs = parse_multiplicative_expression();
				lhs = {std::make_unique<ast::BinaryExpression>(
					op::minus, std::move(lhs), std::move(rhs))};

			} else break;
		}

		DEBUG_STDERR("parsed: additive_expression\n");
		return lhs;
	}

	std::unique_ptr<ast::Expr> CionParser::parse_multiplicative_expression() {
		auto lhs = parse_unary_expression();

		using op = ast::BinaryExpression::Operator;

		while (true) {
			if        (optional(ctts.op_star)) {
				auto rhs = parse_unary_expression();
				lhs = {std::make_unique<ast::BinaryExpression>(
					op::multiplication, std::move(lhs), std::move(rhs))};

			} else if (optional(ctts.op_slash)) {
				auto rhs = parse_unary_expression();
				lhs = {std::make_unique<ast::BinaryExpression>(
					op::division, std::move(lhs), std::move(rhs))};

			} else if (optional(ctts.op_percent)) {
				auto rhs = parse_unary_expression();
				lhs = {std::make_unique<ast::BinaryExpression>(
					op::modulo, std::move(lhs), std::move(rhs))};

			} else break;
		}

		DEBUG_STDERR("parsed: multiplicative_expression\n");
		return lhs;
	}

	std::unique_ptr<ast::Expr> CionParser::parse_unary_expression() {
		using unary = ast::UnaryExpression;

		if (unary::is_operator(current_token().get_type())) {
			DEBUG_STDERR("parsed: unary_expression\n");
			auto op = unary::get_operator(current_token().get_type());
			next_token(); // consume unary operator
			return {std::make_unique<unary>(op, parse_unary_expression())};
		}

		return parse_postfix_expression();
	}

	std::unique_ptr<ast::Expr> CionParser::parse_postfix_expression() {
		auto lhs = parse_primary_expression();

		while (true) {
			if        (optional(ctts.opening_brack)) {
				DEBUG_STDERR("parsed: index_expression\n");
				auto index = parse_expression_list();
				expect(ctts.closing_brack);
				lhs = {std::make_unique<ast::IndexExpression>(
					std::move(lhs), std::move(index))};

			} else if (optional(ctts.opening_paren)) {
				DEBUG_STDERR("parsed: call_expression\n");
				if (optional(ctts.closing_paren)) {
					lhs = {std::make_unique<ast::CallExpression>(std::move(lhs))};
				} else {
					auto args = parse_expression_list();
					expect(ctts.closing_paren);
					lhs = {std::make_unique<ast::CallExpression>(
						std::move(lhs), std::move(args))};
				}

			} else if (optional(ctts.op_plus_plus)) {
				DEBUG_STDERR("parsed: post_increment_expression\n");
				using op = ast::PostfixExpression::Operator;
				lhs = {std::make_unique<ast::PostfixExpression>(
					op::increment, std::move(lhs))};

			} else if (optional(ctts.op_minus_minus)) {
				DEBUG_STDERR("parsed: post_decrement_expression\n");
				using op = ast::PostfixExpression::Operator;
				lhs = {std::make_unique<ast::PostfixExpression>(
					op::decrement, std::move(lhs))};

			} else break;
		}

		return lhs;
	}

	std::unique_ptr<ast::Expr> CionParser::parse_primary_expression() {
		const auto tt = current_token().get_type();

		// parse parenthesed expressions: '(' expr ')'
		if        (optional(ctts.opening_paren)) {
			DEBUG_STDERR("parsed: braced expression\n");
			auto expr = parse_expression();
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
			return std::make_unique<ast::CharLiteral>(
				previous_token().get_char());

		// parse string literals: "foo"
		} else if (optional(ctts.lit_string)) {
			DEBUG_STDERR("parsed: string_literal\n");
			return std::make_unique<ast::StringLiteral>(
				previous_token().get_string());

		// parse integral literals: 42
		} else if (optional(ctts.lit_integral)) {
			DEBUG_STDERR("parsed: integer_literal\n");
			return std::make_unique<ast::IntegerLiteral>(
				previous_token().get_integral());

		// parse number literals: 13.37
		} else if (optional(ctts.lit_number)) {
			DEBUG_STDERR("parsed: float_literal\n");
			return std::make_unique<ast::FloatLiteral>(
				previous_token().get_number());

		// parse simple names: foo
		} else if (tt == ctts.identifier) {
			DEBUG_STDERR("parsed: variable_expression\n");
			auto name = current_token().get_string();
			next_token(); // consume identifier
			return std::make_unique<ast::VariableExpression>(name);
		}

		throw parser_exception(
			m_error_handler.file_name(),
			current_token().get_source_location(),
			"no matching expression was found.\n");
	}

//////////////////////////////////////////////////////////////////////////////////////////
//// Parsing functions for custom and primitive types.
//////////////////////////////////////////////////////////////////////////////////////////

	std::unique_ptr<ast::PrimitiveTypeInt> CionParser::parse_primitive_type_int() {
		using ptiw = ast::PrimitiveTypeInt::Width;
		const auto tt = current_token().get_type();
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
		return std::make_unique<ast::PrimitiveTypeInt>(is_signed, bit_width);
	}

	std::unique_ptr<ast::PrimitiveTypeFloat> CionParser::parse_primitive_type_float() {
		using ptiw = ast::PrimitiveTypeFloat::Width;
		const auto tt = current_token().get_type();
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
		return std::make_unique<ast::PrimitiveTypeFloat>(bit_width);
	}

	std::unique_ptr<ast::TypeSpecifier> CionParser::parse_type_specifier() {
		const auto tt = current_token().get_type();
		if        (tt == ctts.type_bool) {
			next_token();
			DEBUG_STDERR("parsed: primitive_type_bool\n");
			return std::make_unique<ast::PrimitiveTypeBool>();
		} else if (tt == ctts.type_char) {
			next_token();
			DEBUG_STDERR("parsed: primitive_type_char\n");
			return std::make_unique<ast::PrimitiveTypeChar>();
		} else if (tt == ctts.type_int
		        || tt == ctts.type_int8
		        || tt == ctts.type_int16
		        || tt == ctts.type_int32
		        || tt == ctts.type_int64
		        || tt == ctts.type_uint
		        || tt == ctts.type_uint8
		        || tt == ctts.type_uint16
		        || tt == ctts.type_uint32
		        || tt == ctts.type_uint64) {
			DEBUG_STDERR("parsed: primitive_type_int\n");
			return parse_primitive_type_int();
		} else if (tt == ctts.type_float
				|| tt == ctts.type_float16
				|| tt == ctts.type_float32
				|| tt == ctts.type_float64) {
			DEBUG_STDERR("parsed: primitive_type_float\n");
			return parse_primitive_type_float();
		}

		throw parser_exception(
			m_error_handler.file_name(),
			current_token().get_source_location(),
			"no matching type specifier was found.\n");
	}

//////////////////////////////////////////////////////////////////////////////////////////
//// Parse top level statements.
//////////////////////////////////////////////////////////////////////////////////////////

	std::unique_ptr<ast::VariableDeclarationStatement> CionParser::parse_variable_declaration() {
		expect(ctts.cmd_var);

		auto var_name = expect(ctts.identifier).get_string();

		std::unique_ptr<ast::TypeSpecifier> type;
		std::unique_ptr<ast::Expr> expr;

		if (optional(ctts.op_colon)) {
			type = parse_type_specifier();

			expr = optional(ctts.op_equals)
				? parse_expression()
				: std::unique_ptr<ast::Expr>{std::make_unique<ast::NothingExpression>()};

		} else {
			type = std::unique_ptr<ast::TypeSpecifier>{
				std::make_unique<ast::NothingType>()};
			expect(ctts.op_equals);
			expr = parse_expression();
		}

		expect(ctts.op_semi_colon);

		DEBUG_STDERR("parsed: variable_declaration_statement\n");
		return std::make_unique<ast::VariableDeclarationStatement>(
			var_name, std::move(type), std::move(expr));
	}

	std::unique_ptr<ast::LogicalParameter> CionParser::parse_logical_parameter() {
		auto param_name = expect(ctts.identifier).get_string();

		expect(ctts.op_colon);

		auto param_type = parse_type_specifier();

		DEBUG_STDERR("parsed: logical_parameter\n");
		return std::make_unique<ast::LogicalParameter>(param_name, std::move(param_type));
	}

	std::unique_ptr<ast::LogicalParameterPack> CionParser::parse_logical_parameter_pack() {
		std::vector<std::unique_ptr<ast::LogicalParameter>> args;

		if (current_token().get_type() == ctts.identifier
				&& peek_token().get_type() == ctts.op_colon) {
			args.push_back(parse_logical_parameter());

			while (optional(ctts.op_comma)) {
				args.push_back(parse_logical_parameter());
			}
		}

		DEBUG_STDERR("parsed: logical_parameter_pack\n");
		return std::make_unique<ast::LogicalParameterPack>(std::move(args));
	}

	std::unique_ptr<ast::CompoundStatement> CionParser::parse_compound_statement() {
		expect(ctts.opening_brace);

		std::vector<std::unique_ptr<ast::Statement>> statements;
		while (current_token().get_type() != ctts.closing_brace) {
			statements.push_back(parse_statement());
		}

		expect(ctts.closing_brace);

		DEBUG_STDERR("parsed: compound_statement\n");
		return std::make_unique<ast::CompoundStatement>(std::move(statements));
	}

	std::unique_ptr<ast::FunctionDefinitionStatement> CionParser::parse_function_definition() {
		expect(ctts.cmd_function);

		auto function_name = expect(ctts.identifier).get_string();

		expect(ctts.opening_paren);

		auto logical_parameter_pack = parse_logical_parameter_pack();

		expect(ctts.closing_paren);

		auto return_type_required = false;
		if (current_token().get_type() == ctts.op_arrow) {
			next_token(); // consume '->'
			return_type_required = true;
		}

		auto return_type = (return_type_required)
			? parse_type_specifier()
			: std::unique_ptr<ast::TypeSpecifier>{std::make_unique<ast::NothingType>()};

		auto function_body = parse_compound_statement();

		DEBUG_STDERR("parsed: function_definition\n");
		return std::make_unique<ast::FunctionDefinitionStatement>(
			function_name,
			std::move(logical_parameter_pack),
			std::move(return_type),
			std::move(function_body));
	}

	std::unique_ptr<ast::Statement> CionParser::parse_top_level_statement() {
		DEBUG_STDERR("parsed: top_level_statement\n");

		const auto tt = current_token().get_type();

		// Global Variable Declaration
		if        (tt == ctts.cmd_var) {
			return parse_variable_declaration();

		// Free Function Declaration
		} else if (tt == ctts.cmd_function) {
			return parse_function_definition();
		}

		throw parser_exception(
			m_error_handler.file_name(),
			current_token().get_source_location(),
			"expected top-level statement\n");
	}

	std::unique_ptr<ast::CompilationUnit> CionParser::parse_compilation_unit() {
		std::vector<std::unique_ptr<ast::Statement>> top_level_statements;
		while (current_token().get_type() != TokenType::eof) {
			top_level_statements.push_back(parse_top_level_statement());
			DEBUG_STDERR("\n");
		}
		DEBUG_STDERR("parsed: compilation_unit\n");
		return std::make_unique<ast::CompilationUnit>(std::move(top_level_statements));
	}

//////////////////////////////////////////////////////////////////////////////////////////
//// Parse normal statements.
//////////////////////////////////////////////////////////////////////////////////////////

	std::unique_ptr<ast::WhileStatement> CionParser::parse_while_statement() {
		expect(ctts.cmd_while);

		auto condition = parse_expression();

		auto body = parse_compound_statement();

		return std::make_unique<ast::WhileStatement>(
			std::move(condition), std::move(body));
	}

	std::unique_ptr<ast::IfStatement> CionParser::parse_if_statement() {
		expect(ctts.cmd_if);

		auto condition = parse_expression();

		auto then_stmnt = parse_compound_statement();

		if (optional(ctts.cmd_else)) {
			using stmnt = std::unique_ptr<ast::Statement>;
			auto else_stmnt = (current_token().get_type() == ctts.cmd_if)
				? stmnt{parse_if_statement()}
				: stmnt{parse_compound_statement()};
			return std::make_unique<ast::IfStatement>(
				std::move(condition), std::move(then_stmnt), std::move(else_stmnt));
		}

		return std::make_unique<ast::IfStatement>(
			std::move(condition), std::move(then_stmnt));
	}

	std::unique_ptr<ast::ReturnStatement> CionParser::parse_return_statement() {
		expect(ctts.cmd_return);
		auto return_expr = current_token().get_type() != ctts.op_semi_colon
			? parse_expression()
			: std::unique_ptr<ast::Expr>{std::make_unique<ast::NothingExpression>()};
		expect(ctts.op_semi_colon);
		return std::make_unique<ast::ReturnStatement>(std::move(return_expr));
	}

	std::unique_ptr<ast::BreakStatement> CionParser::parse_break_statement() {
		expect(ctts.cmd_break);
		return std::make_unique<ast::BreakStatement>();
	}

	std::unique_ptr<ast::ContinueStatement> CionParser::parse_continue_statement() {
		expect(ctts.cmd_continue);
		return std::make_unique<ast::ContinueStatement>();
	}

	std::unique_ptr<ast::ExpressionStatement> CionParser::parse_expression_statement() {
		auto expr = parse_expression();
		expect(ctts.op_semi_colon);
		return std::make_unique<ast::ExpressionStatement>(std::move(expr));
	}

	std::unique_ptr<ast::Statement> CionParser::parse_statement() {
		using stmnt = std::unique_ptr<ast::Statement>;

		const auto tt = current_token().get_type();

		return
			tt == ctts.cmd_var       ? stmnt{parse_variable_declaration()}:
			tt == ctts.cmd_function  ? stmnt{parse_function_definition()}:
			tt == ctts.cmd_while     ? stmnt{parse_while_statement()}:
			tt == ctts.cmd_if        ? stmnt{parse_if_statement()}:
			tt == ctts.cmd_return    ? stmnt{parse_return_statement()}:
			tt == ctts.cmd_break     ? stmnt{parse_break_statement()}:
			tt == ctts.cmd_continue  ? stmnt{parse_continue_statement()}:
			tt == ctts.opening_brace ? stmnt{parse_compound_statement()}:
			                           stmnt{parse_expression_statement()};
	}

//////////////////////////////////////////////////////////////////////////////////////////
//// Public Parsing Interface Function
//////////////////////////////////////////////////////////////////////////////////////////

	std::unique_ptr<ast::CompilationUnit> CionParser::parse() {
		DEBUG_STDERR("parser init\n");
		try {
			next_token();
			return parse_compilation_unit();
		} catch (lexer_exception const& e) {
			std::cerr << "lexer exception thrown: " << e.message() << "\n";
		} catch (parser_exception const& e) {
			std::cerr << "parser exception thrown in " << e.message() << "\n";
		}
		std::exit(EXIT_FAILURE);
	}
}
