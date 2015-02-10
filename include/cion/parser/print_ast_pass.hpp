#ifndef CION_PARSER_PRINT_AST_PASS_HEADER
#define CION_PARSER_PRINT_AST_PASS_HEADER

#include "cion/parser/basic_ast_visitor.hpp"
#include "cion/ast/all.hpp"

#include <iostream>

namespace cion {
	class PrintASTPass final : public BasicASTVisitor {
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

		// Statements
		void visit(ast::Stmnt &) override;
		void visit(ast::CompoundStmnt &) override;
		void visit(ast::EmptyStmnt &) override;
		void visit(ast::ExprStmnt &) override;
		void visit(ast::IfStmnt &) override;
		void visit(ast::WhileStmnt &) override;
		void visit(ast::BreakStmnt &) override;
		void visit(ast::ContinueStmnt &) override;
		void visit(ast::ReturnStmnt &) override;

		// Declarations
		void visit(ast::Decl &) override;
		void visit(ast::CompilationUnitDecl &) override;
		void visit(ast::ParamDecl &) override;
		void visit(ast::FunctionDecl &) override;
		void visit(ast::VarDecl &) override;

		// Expressions
		void visit(ast::Expr &) override;
		void visit(ast::ConditionalExpr &) override;
		void visit(ast::BinaryExpr &) override;
		void visit(ast::BinaryAssignExpr &) override;
		void visit(ast::BooleanExpr &) override;
		void visit(ast::CallExpr &) override;
		void visit(ast::CharExpr &) override;
		void visit(ast::FloatExpr &) override;
		void visit(ast::IndexExpr &) override;
		void visit(ast::IntegerExpr &) override;
		void visit(ast::NothingExpr &) override;
		void visit(ast::StringExpr &) override;
		void visit(ast::UnaryExpr &) override;
		void visit(ast::VarExpr &) override;

		// Types
		void visit(ast::Type &) override;
		void visit(ast::NothingType &) override;
		void visit(ast::BuiltinBoolType &) override;
		void visit(ast::BuiltinCharType &) override;
		void visit(ast::BuiltinFloatType &) override;
		void visit(ast::BuiltinIntType &) override;

	private:
		std::ostream & m_os;
		uint32_t m_depth = 0;
	};

} // namespace cion

#endif // CION_PARSER_PRINT_AST_PASS_HEADER
