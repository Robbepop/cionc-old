#ifndef CION_PARSER_HEADER
#define CION_PARSER_HEADER

#include "lexer/lexer.hpp"
#include "token/cion_token_types.hpp"

#include "ast/stmnt.hpp"
#include "ast/expr.hpp"
#include "ast/type.hpp"
#include "ast/builtin_type.hpp"
#include "ast/var_decl.hpp"
#include "ast/param_decl.hpp"
#include "ast/function_decl.hpp"
#include "ast/compilation_unit_decl.hpp"

#include "ast/compound_stmnt.hpp"
#include "ast/break_stmnt.hpp"
#include "ast/continue_stmnt.hpp"
#include "ast/return_stmnt.hpp"
#include "ast/if_stmnt.hpp"
#include "ast/while_stmnt.hpp"
#include "ast/expr_stmnt.hpp"
#include "ast/decl_stmnt.hpp"

#include <memory>
#include <queue>

#include <chrono>

namespace cion {
	class CionParser final {
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

/*
		Token const& prevToken() const;
		Token const& curToken() const;
		Token const& nextToken();
		Token const& peekToken();
		Token const& expect(TokenType const& token_type);
		bool         optional(TokenType const& token_type);

		bool isBinaryExpr();
		bool isAssignExpr();
		bool isUnaryExpr();

		std::unique_ptr<ast::ExprList>            parseExprList();
		std::unique_ptr<ast::Expr>                parseExpr();

		std::unique_ptr<ast::Expr>                parseAssignExpr();
		std::unique_ptr<ast::Expr>                parseConditionalExpr();
		std::unique_ptr<ast::Expr>                parseLogicalOrExpr();
		std::unique_ptr<ast::Expr>                parseLogicalAndExpr();
		std::unique_ptr<ast::Expr>                parseBitOrExpr();
		std::unique_ptr<ast::Expr>                parseBitXorExpr();
		std::unique_ptr<ast::Expr>                parseBitAndExpr();
		std::unique_ptr<ast::Expr>                parseEqualityExpr();
		std::unique_ptr<ast::Expr>                parseRelationalExpr();
		std::unique_ptr<ast::Expr>                parseBitShiftExpr();
		std::unique_ptr<ast::Expr>                parseAdditiveExpr();
		std::unique_ptr<ast::Expr>                parseMultiplicativeExpr();
		std::unique_ptr<ast::Expr>                parseUnaryExpr();
		std::unique_ptr<ast::Expr>                parsePostfixExpr();
		std::unique_ptr<ast::Expr>                parsePrimaryExpr();

		std::unique_ptr<ast::BuiltinIntType>      parseBuiltinIntType();
		std::unique_ptr<ast::BuiltinFloatType>    parseBuiltinFloatType();
		std::unique_ptr<ast::Type>                parseType();

		std::unique_ptr<ast::Stmnt>               parseStmnt();

		std::unique_ptr<ast::VarDecl>        parseVarDecl();

		std::unique_ptr<ast::ParamDecl>           parseParamDecl();
		std::vector<std::unique_ptr<ast::ParamDecl>> parseParamDeclList();

		std::unique_ptr<ast::FunctionDecl>        parseFunctionDecl();

		std::unique_ptr<ast::CompoundStmnt>       parseCompoundStmnt();
		std::unique_ptr<ast::WhileStmnt>          parseWhileStmnt();
		std::unique_ptr<ast::IfStmnt>             parseIfStmnt();
		std::unique_ptr<ast::ReturnStmnt>         parseReturnStmnt();
		std::unique_ptr<ast::BreakStmnt>          parseBreakStmnt();
		std::unique_ptr<ast::ContinueStmnt>       parseContinueStmnt();
		std::unique_ptr<ast::ExprStmnt>           parseExprStmnt();

		std::unique_ptr<ast::Decl>                parseTopLevelDecl();
		std::unique_ptr<ast::CompilationUnitDecl> parseCompilationUnitDecl();
*/

	public:
		explicit CionParser(TokenStream & token_stream, ErrorHandler const& error_handler);

		std::unique_ptr<ast::CompilationUnitDecl> parse();

	private:
		TokenStream & m_token_stream;
		std::unique_ptr<Token> m_previous_token;
		std::unique_ptr<Token> m_current_token;
		std::queue<std::unique_ptr<Token>> m_peeked_tokens;

		CionTokenTypes const& ctts;
		ErrorHandler const& m_error_handler;
	};
}

#endif // CION_PARSER_HEADER
