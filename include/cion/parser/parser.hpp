#ifndef CION_PARSER_HEADER
#define CION_PARSER_HEADER

#include "cion/lexer/lexer.hpp"
#include "cion/token/token_types.hpp"

#include <memory>
#include <queue>

#include <chrono>

namespace cion {
	namespace ast {
		class BinaryAssignExpr;
		class AssignExpr;
		class AddAssignExpr;
		class SubtractAssignExpr;
		class MultiplyAssignExpr;
		class DivideAssignExpr;
		class ModuloAssignExpr;
		class LogicalOrAssignExpr;
		class LogicalAndAssignExpr;
		class BitOrAssignExpr;
		class BitXorAssignExpr;
		class BitAndAssignExpr;
		class ShiftLeftAssignExpr;
		class ShiftRightAssignExpr;

		class BinaryExpr;
		class LogicalOrExpr;
		class LogicalAndExpr;
		class BitOrExpr;
		class BitXorExpr;
		class BitAndExpr;
		class AddExpr;
		class SubtractExpr;
		class MultiplyExpr;
		class DivideExpr;
		class ModuloExpr;
		class ShiftLeftExpr;
		class ShiftRightExpr;
		class EqualityExpr;
		class InequalityExpr;
		class LessThanExpr;
		class LessEqualsExpr;
		class GreaterThanExpr;
		class GreaterEqualsExpr;

		class BooleanExpr;
		class BreakStmnt;
		class CallExpr;
		class CharExpr;
		class CompilationUnitDecl;
		class CompoundStmnt;
		class ConditionalExpr;
		class ContinueStmnt;
		class Decl;
		class DeclStmnt;
		class EmptyStmnt;
		class Expr;
		class ExprStmnt;
		class FloatExpr;
		class FunctionDecl;
		class IfStmnt;
		class IndexExpr;
		class IntegerExpr;
		class ParamDecl;
		class NothingExpr;
		class NothingType;

		class BuiltinType;
		class BuiltinBoolType;
		class BuiltinCharType;
		class BuiltinFloatType;
		class BuiltinIntType;

		class ReturnStmnt;
		class Stmnt;
		class StringExpr;
		class Type;

		class UnaryExpr;
		class BitNegateExpr;
		class LogicalNegateExpr;
		class PlusExpr;
		class MinusExpr;
		class IncrementExpr;
		class DecrementExpr;
		class PostIncrementExpr;
		class PostDecrementExpr;

		class VarDecl;
		class VarExpr;
		class WhileStmnt;
	} // namespace ast

	class Parser final {
	private:
		Token const& previous_token() const;
		Token const& current_token() const;
		Token const& next_token();
		Token const& peek_token();
		Token const& expect(TokenType const& token_type);
		bool         optional(TokenType const& token_type);

		bool is_binary_op(TokenType const& tt);
		bool is_assign_op(TokenType const& tt);
		bool is_unary_op(TokenType const& tt);

		bool is_start_of_builtin_int_type(TokenType const& tt) const;
		bool is_start_of_builtin_float_type(TokenType const& tt) const;
		bool is_start_of_decl_stmnt(TokenType const& tt) const;

		std::vector<std::unique_ptr<ast::Expr>>      parse_argument_list();
		std::vector<std::unique_ptr<ast::ParamDecl>> parse_param_decl_list();

		std::unique_ptr<ast::Expr>                   parse_expr();
		std::unique_ptr<ast::Expr>                   parse_assignment_expr();
		std::unique_ptr<ast::Expr>                   parse_conditional_expr();
		std::unique_ptr<ast::Expr>                   parse_logical_or_expr();
		std::unique_ptr<ast::Expr>                   parse_logical_and_expr();
		std::unique_ptr<ast::Expr>                   parse_bit_or_expr();
		std::unique_ptr<ast::Expr>                   parse_bit_xor_expr();
		std::unique_ptr<ast::Expr>                   parse_bit_and_expr();
		std::unique_ptr<ast::Expr>                   parse_equality_expr();
		std::unique_ptr<ast::Expr>                   parse_relational_expr();
		std::unique_ptr<ast::Expr>                   parse_bitshift_expr();
		std::unique_ptr<ast::Expr>                   parse_additive_expr();
		std::unique_ptr<ast::Expr>                   parse_multiplicative_expr();
		std::unique_ptr<ast::Expr>                   parse_unary_expr();
		std::unique_ptr<ast::Expr>                   parse_postfix_expr();
		std::unique_ptr<ast::Expr>                   parse_primary_expr();

		std::unique_ptr<ast::BuiltinIntType>         parse_builtin_int_type();
		std::unique_ptr<ast::BuiltinFloatType>       parse_builtin_float_type();
		std::unique_ptr<ast::Type>                   parse_type();

		std::unique_ptr<ast::ParamDecl>              parse_param_decl();
		std::unique_ptr<ast::FunctionDecl>           parse_function_decl();
		std::unique_ptr<ast::VarDecl>                parse_var_decl();

		std::unique_ptr<ast::Stmnt>                  parse_stmnt();
		std::unique_ptr<ast::CompoundStmnt>          parse_compound_stmnt();
		std::unique_ptr<ast::WhileStmnt>             parse_while_stmnt();
		std::unique_ptr<ast::IfStmnt>                parse_if_stmnt();
		std::unique_ptr<ast::ReturnStmnt>            parse_return_stmnt();
		std::unique_ptr<ast::BreakStmnt>             parse_break_stmnt();
		std::unique_ptr<ast::ContinueStmnt>          parse_continue_stmnt();
		std::unique_ptr<ast::ExprStmnt>              parse_expr_stmnt();
		std::unique_ptr<ast::DeclStmnt>              parse_decl_stmnt();

		std::unique_ptr<ast::Decl>                   parse_top_level_decl();
		std::unique_ptr<ast::CompilationUnitDecl>    parse_compilation_unit_decl();

	public:
		explicit Parser(TokenStream & token_stream, ErrorHandler const& error_handler);

		std::unique_ptr<ast::CompilationUnitDecl> parse();

	private:
		TokenStream & m_token_stream;
		std::unique_ptr<Token> m_previous_token;
		std::unique_ptr<Token> m_current_token;
		std::queue<std::unique_ptr<Token>> m_peeked_tokens;

		TokenTypes const& ctts;
		ErrorHandler const& m_error_handler;
	};
}

#endif // CION_PARSER_HEADER
