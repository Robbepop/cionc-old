#ifndef CION_RECURSIVE_TRAVERSER_HEADER
#define CION_RECURSIVE_TRAVERSER_HEADER

#include "compiler_pass.hpp"

namespace cion {

	class RecursiveTraverser : public CompilerPass {
	public:

		explicit RecursiveTraverser(CompilerPass & p_pass);

//////////////////////////////////////////////////////////////////////////////////////////
/////// Visit Methods
//////////////////////////////////////////////////////////////////////////////////////////

		// Statements
		virtual void visit(ast::Stmnt &) override;
		virtual void visit(ast::CompoundStmnt &) override;
		virtual void visit(ast::EmptyStmnt &) override;
		virtual void visit(ast::ExprStmnt &) override;
		virtual void visit(ast::IfStmnt &) override;
		virtual void visit(ast::WhileStmnt &) override;
		virtual void visit(ast::BreakStmnt &) override;
		virtual void visit(ast::ContinueStmnt &) override;
		virtual void visit(ast::ReturnStmnt &) override;

		// Declarations
		virtual void visit(ast::Decl &) override;
		virtual void visit(ast::CompilationUnitDecl &) override;
		virtual void visit(ast::ParamDecl &) override;
		virtual void visit(ast::FunctionDecl &) override;
		virtual void visit(ast::VarDecl &) override;

		// Expressions
		virtual void visit(ast::Expr &) override;
		virtual void visit(ast::ConditionalExpr &) override;

		virtual void visit(ast::BinaryExpr &) override;
		virtual void visit(ast::LogicalOrExpr &) override;
		virtual void visit(ast::LogicalAndExpr &) override;
		virtual void visit(ast::BitOrExpr &) override;
		virtual void visit(ast::BitXorExpr &) override;
		virtual void visit(ast::BitAndExpr &) override;
		virtual void visit(ast::AddExpr &) override;
		virtual void visit(ast::SubtractExpr &) override;
		virtual void visit(ast::MultiplyExpr &) override;
		virtual void visit(ast::DivideExpr &) override;
		virtual void visit(ast::ModuloExpr &) override;
		virtual void visit(ast::ShiftLeftExpr &) override;
		virtual void visit(ast::ShiftRightExpr &) override;
		virtual void visit(ast::EqualityExpr &) override;
		virtual void visit(ast::InequalityExpr &) override;
		virtual void visit(ast::LessThanExpr &) override;
		virtual void visit(ast::LessEqualsExpr &) override;
		virtual void visit(ast::GreaterThanExpr &) override;
		virtual void visit(ast::GreaterEqualsExpr &) override;

		virtual void visit(ast::BinaryAssignExpr &) override;
		virtual void visit(ast::AssignExpr &) override;
		virtual void visit(ast::AddAssignExpr &) override;
		virtual void visit(ast::SubtractAssignExpr &) override;
		virtual void visit(ast::MultiplyAssignExpr &) override;
		virtual void visit(ast::DivideAssignExpr &) override;
		virtual void visit(ast::ModuloAssignExpr &) override;
		virtual void visit(ast::LogicalOrAssignExpr &) override;
		virtual void visit(ast::LogicalAndAssignExpr &) override;
		virtual void visit(ast::BitOrAssignExpr &) override;
		virtual void visit(ast::BitXorAssignExpr &) override;
		virtual void visit(ast::BitAndAssignExpr &) override;
		virtual void visit(ast::ShiftLeftAssignExpr &) override;
		virtual void visit(ast::ShiftRightAssignExpr &) override;

		virtual void visit(ast::BooleanExpr &) override;
		virtual void visit(ast::CallExpr &) override;
		virtual void visit(ast::CharExpr &) override;
		virtual void visit(ast::FloatExpr &) override;
		virtual void visit(ast::IndexExpr &) override;
		virtual void visit(ast::IntegerExpr &) override;
		virtual void visit(ast::NothingExpr &) override;
		virtual void visit(ast::StringExpr &) override;

		virtual void visit(ast::UnaryExpr &) override;
		virtual void visit(ast::BitNegateExpr &) override;
		virtual void visit(ast::LogicalNegateExpr &) override;
		virtual void visit(ast::PlusExpr &) override;
		virtual void visit(ast::MinusExpr &) override;
		virtual void visit(ast::IncrementExpr &) override;
		virtual void visit(ast::DecrementExpr &) override;
		virtual void visit(ast::PostIncrementExpr &) override;
		virtual void visit(ast::PostDecrementExpr &) override;

		virtual void visit(ast::VarExpr &) override;

		// Types
		virtual void visit(ast::Type &) override;
		virtual void visit(ast::NothingType &) override;
		virtual void visit(ast::BuiltinType &) override;
		virtual void visit(ast::BuiltinBoolType &) override;
		virtual void visit(ast::BuiltinCharType &) override;
		virtual void visit(ast::BuiltinFloatType &) override;
		virtual void visit(ast::BuiltinIntType &) override;

//////////////////////////////////////////////////////////////////////////////////////////
/////// Traverse Methods
//////////////////////////////////////////////////////////////////////////////////////////

	protected:

		// Statements
		virtual void traverse(ast::Stmnt &);
		virtual void traverse(ast::CompoundStmnt &);
		virtual void traverse(ast::EmptyStmnt &);
		virtual void traverse(ast::ExprStmnt &);
		virtual void traverse(ast::IfStmnt &);
		virtual void traverse(ast::WhileStmnt &);
		virtual void traverse(ast::BreakStmnt &);
		virtual void traverse(ast::ContinueStmnt &);
		virtual void traverse(ast::ReturnStmnt &);

		// Declarations
		virtual void traverse(ast::Decl &);
		virtual void traverse(ast::CompilationUnitDecl &);
		virtual void traverse(ast::ParamDecl &);
		virtual void traverse(ast::FunctionDecl &);
		virtual void traverse(ast::VarDecl &);

		// Expressions
		virtual void traverse(ast::Expr &);
		virtual void traverse(ast::ConditionalExpr &);

		virtual void traverse(ast::BinaryExpr &);
		virtual void traverse(ast::LogicalOrExpr &);
		virtual void traverse(ast::LogicalAndExpr &);
		virtual void traverse(ast::BitOrExpr &);
		virtual void traverse(ast::BitXorExpr &);
		virtual void traverse(ast::BitAndExpr &);
		virtual void traverse(ast::AddExpr &);
		virtual void traverse(ast::SubtractExpr &);
		virtual void traverse(ast::MultiplyExpr &);
		virtual void traverse(ast::DivideExpr &);
		virtual void traverse(ast::ModuloExpr &);
		virtual void traverse(ast::ShiftLeftExpr &);
		virtual void traverse(ast::ShiftRightExpr &);
		virtual void traverse(ast::EqualityExpr &);
		virtual void traverse(ast::InequalityExpr &);
		virtual void traverse(ast::LessThanExpr &);
		virtual void traverse(ast::LessEqualsExpr &);
		virtual void traverse(ast::GreaterThanExpr &);
		virtual void traverse(ast::GreaterEqualsExpr &);

		virtual void traverse(ast::BinaryAssignExpr &);
		virtual void traverse(ast::AssignExpr &);
		virtual void traverse(ast::AddAssignExpr &);
		virtual void traverse(ast::SubtractAssignExpr &);
		virtual void traverse(ast::MultiplyAssignExpr &);
		virtual void traverse(ast::DivideAssignExpr &);
		virtual void traverse(ast::ModuloAssignExpr &);
		virtual void traverse(ast::LogicalOrAssignExpr &);
		virtual void traverse(ast::LogicalAndAssignExpr &);
		virtual void traverse(ast::BitOrAssignExpr &);
		virtual void traverse(ast::BitXorAssignExpr &);
		virtual void traverse(ast::BitAndAssignExpr &);
		virtual void traverse(ast::ShiftLeftAssignExpr &);
		virtual void traverse(ast::ShiftRightAssignExpr &);

		virtual void traverse(ast::BooleanExpr &);
		virtual void traverse(ast::CallExpr &);
		virtual void traverse(ast::CharExpr &);
		virtual void traverse(ast::FloatExpr &);
		virtual void traverse(ast::IndexExpr &);
		virtual void traverse(ast::IntegerExpr &);
		virtual void traverse(ast::NothingExpr &);
		virtual void traverse(ast::StringExpr &);

		virtual void traverse(ast::UnaryExpr &);
		virtual void traverse(ast::BitNegateExpr &);
		virtual void traverse(ast::LogicalNegateExpr &);
		virtual void traverse(ast::PlusExpr &);
		virtual void traverse(ast::MinusExpr &);
		virtual void traverse(ast::IncrementExpr &);
		virtual void traverse(ast::DecrementExpr &);
		virtual void traverse(ast::PostIncrementExpr &);
		virtual void traverse(ast::PostDecrementExpr &);

		virtual void traverse(ast::VarExpr &);

		// Types
		virtual void traverse(ast::Type &);
		virtual void traverse(ast::NothingType &);
		virtual void traverse(ast::BuiltinType &);
		virtual void traverse(ast::BuiltinBoolType &);
		virtual void traverse(ast::BuiltinCharType &);
		virtual void traverse(ast::BuiltinFloatType &);
		virtual void traverse(ast::BuiltinIntType &);

	private:
		CompilerPass & m_pass;
	};

} // namespace cion

#endif // CION_RECURSIVE_TRAVERSER_HEADER
