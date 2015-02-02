#ifndef CION_PARSER_PRINT_AST_PASS_HEADER
#define CION_PARSER_PRINT_AST_PASS_HEADER

#include "parser/compiler_pass.hpp"

#include "ast/assignment_expression.hpp"
#include "ast/binary_expression.hpp"
#include "ast/boolean_expr.hpp"
#include "ast/break_statement.hpp"
#include "ast/call_expression.hpp"
#include "ast/char_literal.hpp"
#include "ast/compilation_unit.hpp"
#include "ast/compound_statement.hpp"
#include "ast/conditional_expression.hpp"
#include "ast/continue_statement.hpp"
#include "ast/empty_statement.hpp"
#include "ast/expr.hpp"
#include "ast/expression_list.hpp"
#include "ast/expression_statement.hpp"
#include "ast/float_literal.hpp"
#include "ast/function_definition_statement.hpp"
#include "ast/if_statement.hpp"
#include "ast/index_expression.hpp"
#include "ast/integer_literal.hpp"
#include "ast/logical_parameter.hpp"
#include "ast/logical_parameter_pack.hpp"
#include "ast/node.hpp"
#include "ast/nothing_expression.hpp"
#include "ast/nothing_type.hpp"
#include "ast/postfix_expression.hpp"
#include "ast/primitive_type_bool.hpp"
#include "ast/primitive_type_char.hpp"
#include "ast/primitive_type_float.hpp"
#include "ast/primitive_type_int.hpp"
#include "ast/return_statement.hpp"
#include "ast/statement.hpp"
#include "ast/statement_list.hpp"
#include "ast/string_literal.hpp"
#include "ast/type_specifier.hpp"
#include "ast/unary_expression.hpp"
#include "ast/variable_declaration_statement.hpp"
#include "ast/variable_expression.hpp"
#include "ast/while_statement.hpp"

#include <iostream>

namespace cion {
	class PrintASTPass final : public CompilerPass {
	public:
		struct PrintBlock final {
		public:
			PrintBlock(PrintASTPass & print_ast_pass);
			~PrintBlock() noexcept;

		private:
			void inc_depth();
			void dec_depth();

			PrintASTPass & m_print_ast_pass;
		};

		PrintASTPass(std::ostream & os = std::cout);

		PrintBlock create_block();
		std::string gen_line(std::string const& s);
		void print_line(std::string const& s);
		void print(std::string const& s);

		void visit(ast::AssignmentExpression const&) override;
		void visit(ast::BinaryExpression const&) override;
		void visit(ast::BooleanExpr const&) override;
		void visit(ast::BreakStatement const&) override;
		void visit(ast::CallExpression const&) override;
		void visit(ast::CharLiteral const&) override;
		void visit(ast::CompilationUnit const&) override;
		void visit(ast::CompoundStatement const&) override;
		void visit(ast::ConditionalExpression const&) override;
		void visit(ast::ContinueStatement const&) override;
		void visit(ast::EmptyStatement const&) override;
		void visit(ast::Expression const&) override;
		void visit(ast::ExpressionList const&) override;
		void visit(ast::ExpressionStatement const&) override;
		void visit(ast::FloatLiteral const&) override;
		void visit(ast::FunctionDefinitionStatement const&) override;
		void visit(ast::IfStatement const&) override;
		void visit(ast::IndexExpression const&) override;
		void visit(ast::IntegerLiteral const&) override;
		void visit(ast::LogicalParameter const&) override;
		void visit(ast::LogicalParameterPack const&) override;
		void visit(ast::Node const&) override;
		void visit(ast::NothingExpression const&) override;
		void visit(ast::NothingType const&) override;
		void visit(ast::PostfixExpression const&) override;
		void visit(ast::PrimitiveTypeBool const&) override;
		void visit(ast::PrimitiveTypeChar const&) override;
		void visit(ast::PrimitiveTypeFloat const&) override;
		void visit(ast::PrimitiveTypeInt const&) override;
		void visit(ast::ReturnStatement const&) override;
		void visit(ast::Statement const&) override;
		void visit(ast::StatementList const&) override;
		void visit(ast::StringLiteral const&) override;
		void visit(ast::TypeSpecifier const&) override;
		void visit(ast::UnaryExpression const&) override;
		void visit(ast::VariableDeclarationStatement const&) override;
		void visit(ast::VariableExpression const&) override;
		void visit(ast::WhileStatement const&) override;

	private:
		std::ostream & m_os;
		uint32_t m_depth = 0;
	};

} // namespace cion

#endif // CION_PARSER_PRINT_AST_PASS_HEADER
