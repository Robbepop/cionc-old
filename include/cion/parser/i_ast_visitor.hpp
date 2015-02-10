#ifndef CION_I_AST_VISITOR_HEADER
#define CION_I_AST_VISITOR_HEADER

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
		virtual void visit(ast::BuiltinBoolType &) = 0;
		virtual void visit(ast::BuiltinCharType &) = 0;
		virtual void visit(ast::BuiltinFloatType &) = 0;
		virtual void visit(ast::BuiltinIntType &) = 0;
	};

} // namespace

#endif // CION_I_AST_VISITOR_HEADER
