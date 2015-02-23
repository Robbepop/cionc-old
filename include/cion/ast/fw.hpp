#ifndef CION_AST_FORWARD_DECLARATIONS_HEADER
#define CION_AST_FORWARD_DECLARATIONS_HEADER

namespace cion {
namespace ast {

	// Assign Expressions
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

	// Binary Expressions
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
	class BoolType;
	class CharType;
	class FloatingType;
	class IntegerType;

	class ReturnStmnt;
	class Stmnt;
	class StringExpr;
	class Type;

	// Unary Expressions
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
} // namespace cion

#endif // CION_AST_FORWARD_DECLARATIONS_HEADER
