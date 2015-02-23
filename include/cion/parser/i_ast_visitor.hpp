#ifndef CION_I_AST_VISITOR_HEADER
#define CION_I_AST_VISITOR_HEADER

#include "cion/ast/fw.hpp"

namespace cion {

	class IASTVisitor {
	public:
		// Statements
		virtual void visit(ast::Stmnt &) = 0;
		virtual void visit(ast::CompoundStmnt &) = 0;
		virtual void visit(ast::EmptyStmnt &) = 0;
		virtual void visit(ast::ExprStmnt &) = 0;
		virtual void visit(ast::DeclStmnt &) = 0;
		virtual void visit(ast::IfStmnt &) = 0;
		virtual void visit(ast::WhileStmnt &) = 0;
		virtual void visit(ast::BreakStmnt &) = 0;
		virtual void visit(ast::ContinueStmnt &) = 0;
		virtual void visit(ast::ReturnStmnt &) = 0;

		// Declarations
		virtual void visit(ast::Decl &) = 0;
		virtual void visit(ast::CompilationUnitDecl &) = 0;
		virtual void visit(ast::ParamDecl &) = 0;
		virtual void visit(ast::FunctionDecl &) = 0;
		virtual void visit(ast::VarDecl &) = 0;

		// Expressions
		virtual void visit(ast::Expr &) = 0;
		virtual void visit(ast::ConditionalExpr &) = 0;

		virtual void visit(ast::BinaryExpr &) = 0;
		virtual void visit(ast::LogicalOrExpr &) = 0;
		virtual void visit(ast::LogicalAndExpr &) = 0;
		virtual void visit(ast::BitOrExpr &) = 0;
		virtual void visit(ast::BitXorExpr &) = 0;
		virtual void visit(ast::BitAndExpr &) = 0;
		virtual void visit(ast::AddExpr &) = 0;
		virtual void visit(ast::SubtractExpr &) = 0;
		virtual void visit(ast::MultiplyExpr &) = 0;
		virtual void visit(ast::DivideExpr &) = 0;
		virtual void visit(ast::ModuloExpr &) = 0;
		virtual void visit(ast::ShiftLeftExpr &) = 0;
		virtual void visit(ast::ShiftRightExpr &) = 0;
		virtual void visit(ast::EqualityExpr &) = 0;
		virtual void visit(ast::InequalityExpr &) = 0;
		virtual void visit(ast::LessThanExpr &) = 0;
		virtual void visit(ast::LessEqualsExpr &) = 0;
		virtual void visit(ast::GreaterThanExpr &) = 0;
		virtual void visit(ast::GreaterEqualsExpr &) = 0;

		virtual void visit(ast::BinaryAssignExpr &) = 0;
		virtual void visit(ast::AssignExpr &) = 0;
		virtual void visit(ast::AddAssignExpr &) = 0;
		virtual void visit(ast::SubtractAssignExpr &) = 0;
		virtual void visit(ast::MultiplyAssignExpr &) = 0;
		virtual void visit(ast::DivideAssignExpr &) = 0;
		virtual void visit(ast::ModuloAssignExpr &) = 0;
		virtual void visit(ast::LogicalOrAssignExpr &) = 0;
		virtual void visit(ast::LogicalAndAssignExpr &) = 0;
		virtual void visit(ast::BitOrAssignExpr &) = 0;
		virtual void visit(ast::BitXorAssignExpr &) = 0;
		virtual void visit(ast::BitAndAssignExpr &) = 0;
		virtual void visit(ast::ShiftLeftAssignExpr &) = 0;
		virtual void visit(ast::ShiftRightAssignExpr &) = 0;

		virtual void visit(ast::BooleanExpr &) = 0;
		virtual void visit(ast::CallExpr &) = 0;
		virtual void visit(ast::CharExpr &) = 0;
		virtual void visit(ast::FloatExpr &) = 0;
		virtual void visit(ast::IndexExpr &) = 0;
		virtual void visit(ast::IntegerExpr &) = 0;
		virtual void visit(ast::NothingExpr &) = 0;
		virtual void visit(ast::StringExpr &) = 0;

		virtual void visit(ast::UnaryExpr &) = 0;
		virtual void visit(ast::BitNegateExpr &) = 0;
		virtual void visit(ast::LogicalNegateExpr &) = 0;
		virtual void visit(ast::PlusExpr &) = 0;
		virtual void visit(ast::MinusExpr &) = 0;
		virtual void visit(ast::IncrementExpr &) = 0;
		virtual void visit(ast::DecrementExpr &) = 0;
		virtual void visit(ast::PostIncrementExpr &) = 0;
		virtual void visit(ast::PostDecrementExpr &) = 0;

		virtual void visit(ast::VarExpr &) = 0;

		// Types
		virtual void visit(ast::Type &) = 0;
		virtual void visit(ast::NothingType &) = 0;
		virtual void visit(ast::BuiltinType &) = 0;
		virtual void visit(ast::BoolType &) = 0;
		virtual void visit(ast::CharType &) = 0;
		virtual void visit(ast::FloatingType &) = 0;
		virtual void visit(ast::IntegerType &) = 0;
	};

} // namespace

#endif // CION_I_AST_VISITOR_HEADER
