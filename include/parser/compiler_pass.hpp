#ifndef CION_PARSER_COMPILER_PASS_HEADER
#define CION_PARSER_COMPILER_PASS_HEADER

#include <type_traits>

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

	class CompilerPass {
	public:
		// Statements
		virtual void visit(ast::Stmnt &);
		virtual void visit(ast::CompoundStmnt &);
		virtual void visit(ast::EmptyStmnt &);
		virtual void visit(ast::ExprStmnt &);
		virtual void visit(ast::IfStmnt &);
		virtual void visit(ast::WhileStmnt &);
		virtual void visit(ast::BreakStmnt &);
		virtual void visit(ast::ContinueStmnt &);
		virtual void visit(ast::ReturnStmnt &);

		// Declarations
		virtual void visit(ast::Decl &);
		virtual void visit(ast::CompilationUnitDecl &);
		virtual void visit(ast::ParamDecl &);
		virtual void visit(ast::FunctionDecl &);
		virtual void visit(ast::VarDecl &);

		// Expressions
		virtual void visit(ast::Expr &);
		virtual void visit(ast::ConditionalExpr &);

		virtual void visit(ast::BinaryExpr &);
		virtual void visit(ast::LogicalOrExpr &);
		virtual void visit(ast::LogicalAndExpr &);
		virtual void visit(ast::BitOrExpr &);
		virtual void visit(ast::BitXorExpr &);
		virtual void visit(ast::BitAndExpr &);
		virtual void visit(ast::AddExpr &);
		virtual void visit(ast::SubtractExpr &);
		virtual void visit(ast::MultiplyExpr &);
		virtual void visit(ast::DivideExpr &);
		virtual void visit(ast::ModuloExpr &);
		virtual void visit(ast::ShiftLeftExpr &);
		virtual void visit(ast::ShiftRightExpr &);
		virtual void visit(ast::EqualityExpr &);
		virtual void visit(ast::InequalityExpr &);
		virtual void visit(ast::LessThanExpr &);
		virtual void visit(ast::LessEqualsExpr &);
		virtual void visit(ast::GreaterThanExpr &);
		virtual void visit(ast::GreaterEqualsExpr &);

		virtual void visit(ast::BinaryAssignExpr &);
		virtual void visit(ast::AssignExpr &);
		virtual void visit(ast::AddAssignExpr &);
		virtual void visit(ast::SubtractAssignExpr &);
		virtual void visit(ast::MultiplyAssignExpr &);
		virtual void visit(ast::DivideAssignExpr &);
		virtual void visit(ast::ModuloAssignExpr &);
		virtual void visit(ast::LogicalOrAssignExpr &);
		virtual void visit(ast::LogicalAndAssignExpr &);
		virtual void visit(ast::BitOrAssignExpr &);
		virtual void visit(ast::BitXorAssignExpr &);
		virtual void visit(ast::BitAndAssignExpr &);
		virtual void visit(ast::ShiftLeftAssignExpr &);
		virtual void visit(ast::ShiftRightAssignExpr &);

		virtual void visit(ast::BooleanExpr &);
		virtual void visit(ast::CallExpr &);
		virtual void visit(ast::CharExpr &);
		virtual void visit(ast::FloatExpr &);
		virtual void visit(ast::IndexExpr &);
		virtual void visit(ast::IntegerExpr &);
		virtual void visit(ast::NothingExpr &);
		virtual void visit(ast::StringExpr &);

		virtual void visit(ast::UnaryExpr &);
		virtual void visit(ast::BitNegateExpr &);
		virtual void visit(ast::LogicalNegateExpr &);
		virtual void visit(ast::PlusExpr &);
		virtual void visit(ast::MinusExpr &);
		virtual void visit(ast::IncrementExpr &);
		virtual void visit(ast::DecrementExpr &);
		virtual void visit(ast::PostIncrementExpr &);
		virtual void visit(ast::PostDecrementExpr &);

		virtual void visit(ast::VarExpr &);

		// Types
		virtual void visit(ast::Type &);
		virtual void visit(ast::NothingType &);
		virtual void visit(ast::BuiltinType &);
		virtual void visit(ast::BuiltinBoolType &);
		virtual void visit(ast::BuiltinCharType &);
		virtual void visit(ast::BuiltinFloatType &);
		virtual void visit(ast::BuiltinIntType &);
	};
} // namespace cion

#endif // CION_PARSER_COMPILER_PASS_HEADER
