#ifndef CION_RECURSIVE_TRAVERSER_HEADER
#define CION_RECURSIVE_TRAVERSER_HEADER

#include "cion/parser/basic_ast_visitor.hpp"

namespace cion {

	class RecursiveTraverser : public BasicASTVisitor {
	public:
		RecursiveTraverser() = default;

//////////////////////////////////////////////////////////////////////////////////////////
/////// Visit Methods
//////////////////////////////////////////////////////////////////////////////////////////

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
		virtual void visit(ast::BuiltinBoolType &) override;
		virtual void visit(ast::BuiltinCharType &) override;
		virtual void visit(ast::BuiltinFloatType &) override;
		virtual void visit(ast::BuiltinIntType &) override;

//////////////////////////////////////////////////////////////////////////////////////////
/////// Traverse Methods
//////////////////////////////////////////////////////////////////////////////////////////

	protected:

		// Statements
		virtual void traverse_stmnt(ast::Stmnt &);
		virtual void traverse_compound_stmnt(ast::CompoundStmnt &);
		virtual void traverse_empty_stmnt(ast::EmptyStmnt &);
		virtual void traverse_decl_stmnt(ast::DeclStmnt &);
		virtual void traverse_expr_stmnt(ast::ExprStmnt &);
		virtual void traverse_if_stmnt(ast::IfStmnt &);
		virtual void traverse_while_stmnt(ast::WhileStmnt &);
		virtual void traverse_break_stmnt(ast::BreakStmnt &);
		virtual void traverse_continue_stmnt(ast::ContinueStmnt &);
		virtual void traverse_return_stmnt(ast::ReturnStmnt &);

		// Declarations
		virtual void traverse_decl(ast::Decl &);
		virtual void traverse_compilation_unit_decl(ast::CompilationUnitDecl &);
		virtual void traverse_param_decl(ast::ParamDecl &);
		virtual void traverse_function_decl(ast::FunctionDecl &);
		virtual void traverse_var_decl(ast::VarDecl &);

		// Expressions
		virtual void traverse_expr(ast::Expr &);
		virtual void traverse_conditional_expr(ast::ConditionalExpr &);

		virtual void traverse_binary_expr(ast::BinaryExpr &);
		virtual void traverse_logical_or_expr(ast::LogicalOrExpr &);
		virtual void traverse_logical_and_expr(ast::LogicalAndExpr &);
		virtual void traverse_bit_or_expr(ast::BitOrExpr &);
		virtual void traverse_bit_xor_expr(ast::BitXorExpr &);
		virtual void traverse_bit_and_expr(ast::BitAndExpr &);
		virtual void traverse_add_expr(ast::AddExpr &);
		virtual void traverse_subtract_expr(ast::SubtractExpr &);
		virtual void traverse_multiply_expr(ast::MultiplyExpr &);
		virtual void traverse_divide_expr(ast::DivideExpr &);
		virtual void traverse_modulo_expr(ast::ModuloExpr &);
		virtual void traverse_shift_left_expr(ast::ShiftLeftExpr &);
		virtual void traverse_shift_right_expr(ast::ShiftRightExpr &);
		virtual void traverse_equality_expr(ast::EqualityExpr &);
		virtual void traverse_inequality_expr(ast::InequalityExpr &);
		virtual void traverse_less_than_expr(ast::LessThanExpr &);
		virtual void traverse_less_equals_expr(ast::LessEqualsExpr &);
		virtual void traverse_greater_than_expr(ast::GreaterThanExpr &);
		virtual void traverse_greater_equals_expr(ast::GreaterEqualsExpr &);

		virtual void traverse_binary_assign_expr(ast::BinaryAssignExpr &);
		virtual void traverse_assign_expr(ast::AssignExpr &);
		virtual void traverse_add_assign_expr(ast::AddAssignExpr &);
		virtual void traverse_subtract_assign_expr(ast::SubtractAssignExpr &);
		virtual void traverse_multiply_assign_expr(ast::MultiplyAssignExpr &);
		virtual void traverse_divide_assign_expr(ast::DivideAssignExpr &);
		virtual void traverse_modulo_assign_expr(ast::ModuloAssignExpr &);
		virtual void traverse_logical_or_assign_expr(ast::LogicalOrAssignExpr &);
		virtual void traverse_logical_and_assign_expr(ast::LogicalAndAssignExpr &);
		virtual void traverse_bit_or_assign_expr(ast::BitOrAssignExpr &);
		virtual void traverse_bit_xor_assign_expr(ast::BitXorAssignExpr &);
		virtual void traverse_bit_and_assign_expr(ast::BitAndAssignExpr &);
		virtual void traverse_shift_left_assign_expr(ast::ShiftLeftAssignExpr &);
		virtual void traverse_shift_right_assign_expr(ast::ShiftRightAssignExpr &);

		virtual void traverse_boolean_expr(ast::BooleanExpr &);
		virtual void traverse_call_expr(ast::CallExpr &);
		virtual void traverse_char_expr(ast::CharExpr &);
		virtual void traverse_float_expr(ast::FloatExpr &);
		virtual void traverse_index_expr(ast::IndexExpr &);
		virtual void traverse_integer_expr(ast::IntegerExpr &);
		virtual void traverse_nothing_expr(ast::NothingExpr &);
		virtual void traverse_string_expr(ast::StringExpr &);

		virtual void traverse_unary_expr(ast::UnaryExpr &);
		virtual void traverse_bit_negate_expr(ast::BitNegateExpr &);
		virtual void traverse_logical_negate_expr(ast::LogicalNegateExpr &);
		virtual void traverse_plus_expr(ast::PlusExpr &);
		virtual void traverse_minus_expr(ast::MinusExpr &);
		virtual void traverse_increment_expr(ast::IncrementExpr &);
		virtual void traverse_decrement_expr(ast::DecrementExpr &);
		virtual void traverse_post_increment_expr(ast::PostIncrementExpr &);
		virtual void traverse_post_decrement_expr(ast::PostDecrementExpr &);

		virtual void traverse_var_expr(ast::VarExpr &);

		// Types
		virtual void traverse_type(ast::Type &);
		virtual void traverse_nothing_type(ast::NothingType &);
		virtual void traverse_builtin_type(ast::BuiltinType &);
		virtual void traverse_builtin_bool_type(ast::BuiltinBoolType &);
		virtual void traverse_builtin_char_type(ast::BuiltinCharType &);
		virtual void traverse_builtin_float_type(ast::BuiltinFloatType &);
		virtual void traverse_builtin_int_type(ast::BuiltinIntType &);
	};

} // namespace cion

#endif // CION_RECURSIVE_TRAVERSER_HEADER
