#include "compiler_pass.hpp"

namespace cion {

	// Statements
	void CompilerPass::visit(ast::Stmnt &) {

	}

	void CompilerPass::visit(ast::CompoundStmnt &) {

	}

	void CompilerPass::visit(ast::EmptyStmnt &) {

	}

	void CompilerPass::visit(ast::ExprStmnt &) {

	}

	void CompilerPass::visit(ast::IfStmnt &) {

	}

	void CompilerPass::visit(ast::WhileStmnt &) {

	}

	void CompilerPass::visit(ast::BreakStmnt &) {

	}

	void CompilerPass::visit(ast::ContinueStmnt &) {

	}

	void CompilerPass::visit(ast::ReturnStmnt &) {

	}


	// Declarations
	void CompilerPass::visit(ast::Decl &) {

	}

	void CompilerPass::visit(ast::CompilationUnitDecl &) {

	}

	void CompilerPass::visit(ast::ParamDecl &) {

	}

	void CompilerPass::visit(ast::FunctionDecl &) {

	}

	void CompilerPass::visit(ast::VarDecl &) {

	}


	// Expressions
	void CompilerPass::visit(ast::Expr &) {

	}

	void CompilerPass::visit(ast::ConditionalExpr &) {

	}

	void CompilerPass::visit(ast::BinaryExpr &) {

	}

	void CompilerPass::visit(ast::BinaryAssignExpr &) {

	}

	void CompilerPass::visit(ast::BooleanExpr &) {

	}

	void CompilerPass::visit(ast::CallExpr &) {

	}

	void CompilerPass::visit(ast::CharExpr &) {

	}

	void CompilerPass::visit(ast::FloatExpr &) {

	}

	void CompilerPass::visit(ast::IndexExpr &) {

	}

	void CompilerPass::visit(ast::IntegerExpr &) {

	}

	void CompilerPass::visit(ast::NothingExpr &) {

	}

	void CompilerPass::visit(ast::StringExpr &) {

	}

	void CompilerPass::visit(ast::UnaryExpr &) {

	}

	void CompilerPass::visit(ast::VarExpr &) {

	}


	// Types
	void CompilerPass::visit(ast::Type &) {

	}

	void CompilerPass::visit(ast::NothingType &) {

	}

	void CompilerPass::visit(ast::BuiltinBoolType &) {

	}

	void CompilerPass::visit(ast::BuiltinCharType &) {

	}

	void CompilerPass::visit(ast::BuiltinFloatType &) {

	}

	void CompilerPass::visit(ast::BuiltinIntType &) {

	}


} // namespace cion
