#ifndef CION_PARSER_HEADER
#define CION_PARSER_HEADER

#include "lexer/lexer.hpp"
#include "token/cion_token_types.hpp"

#include "ast/statement.hpp"
#include "ast/expression.hpp"
#include "ast/expression_list.hpp"
#include "ast/type_specifier.hpp"
#include "ast/primitive_type_int.hpp"
#include "ast/primitive_type_float.hpp"
#include "ast/variable_declaration_statement.hpp"
#include "ast/logical_parameter.hpp"
#include "ast/function_definition_statement.hpp"
#include "ast/compilation_unit.hpp"

#include "ast/compound_statement.hpp"
#include "ast/break_statement.hpp"
#include "ast/continue_statement.hpp"
#include "ast/return_statement.hpp"
#include "ast/if_statement.hpp"
#include "ast/while_statement.hpp"
#include "ast/expression_statement.hpp"

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

		std::unique_ptr<ast::ExpressionList>               parse_expression_list();
		std::unique_ptr<ast::Expression>                   parse_expression();

		std::unique_ptr<ast::Expression>                   parse_assignment_expression();
		std::unique_ptr<ast::Expression>                   parse_conditional_expression();
		std::unique_ptr<ast::Expression>                   parse_logical_or_expression();
		std::unique_ptr<ast::Expression>                   parse_logical_and_expression();
		std::unique_ptr<ast::Expression>                   parse_inclusive_or_expression();
		std::unique_ptr<ast::Expression>                   parse_exclusive_or_expression();
		std::unique_ptr<ast::Expression>                   parse_bitwise_and_expression();
		std::unique_ptr<ast::Expression>                   parse_equality_expression();
		std::unique_ptr<ast::Expression>                   parse_relational_expression();
		std::unique_ptr<ast::Expression>                   parse_bitshift_expression();
		std::unique_ptr<ast::Expression>                   parse_additive_expression();
		std::unique_ptr<ast::Expression>                   parse_multiplicative_expression();
		std::unique_ptr<ast::Expression>                   parse_unary_expression();
		std::unique_ptr<ast::Expression>                   parse_postfix_expression();
		std::unique_ptr<ast::Expression>                   parse_primary_expression();

		std::unique_ptr<ast::PrimitiveTypeInt>             parse_primitive_type_int();
		std::unique_ptr<ast::PrimitiveTypeFloat>           parse_primitive_type_float();
		std::unique_ptr<ast::TypeSpecifier>                parse_type_specifier();

		std::unique_ptr<ast::Statement>                    parse_statement();

		std::unique_ptr<ast::VariableDeclarationStatement> parse_variable_declaration();

		std::unique_ptr<ast::LogicalParameter>             parse_logical_parameter();
		std::unique_ptr<ast::LogicalParameterPack>         parse_logical_parameter_pack();

		std::unique_ptr<ast::FunctionDefinitionStatement>  parse_function_definition();

		std::unique_ptr<ast::CompoundStatement>            parse_compound_statement();

		std::unique_ptr<ast::WhileStatement>               parse_while_statement();

		std::unique_ptr<ast::IfStatement>                  parse_if_statement();

		std::unique_ptr<ast::ReturnStatement>              parse_return_statement();
		std::unique_ptr<ast::BreakStatement>               parse_break_statement();
		std::unique_ptr<ast::ContinueStatement>            parse_continue_statement();

		std::unique_ptr<ast::ExpressionStatement>          parse_expression_statement();

		std::unique_ptr<ast::Statement>                    parse_top_level_statement();
		std::unique_ptr<ast::CompilationUnit>              parse_compilation_unit();

	public:
		explicit CionParser(TokenStream & token_stream, ErrorHandler const& error_handler);

		std::unique_ptr<ast::CompilationUnit> parse();

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
