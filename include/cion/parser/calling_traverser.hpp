#ifndef CION_PARSER_CALLING_TRAVERSER_HEADER
#define CION_PARSER_CALLING_TRAVERSER_HEADER

#include "cion/parser/recursive_traverser.hpp"

namespace cion {

	class CallingTraverser : public RecursiveTraverser {
	public:
		CallingTraverser(IASTVisitor & p_callee);

		// Statements
		virtual void visit(ast::Stmnt &) override;
		virtual void visit(ast::CompoundStmnt &) override;
		virtual void visit(ast::EmptyStmnt &) override;
		virtual void visit(ast::DeclStmnt &) override;
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
		virtual void visit(ast::BoolType &) override;
		virtual void visit(ast::CharType &) override;
		virtual void visit(ast::FloatingType &) override;
		virtual void visit(ast::IntegerType &) override;

//////////////////////////////////////////////////////////////////////////////////////////
/////// Members
//////////////////////////////////////////////////////////////////////////////////////////
		IASTVisitor & m_callee;
	};

} // namespace cion

#endif // CION_PARSER_CALLING_TRAVERSER_HEADER
