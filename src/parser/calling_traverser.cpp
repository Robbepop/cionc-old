#include "cion/parser/calling_traverser.hpp"

namespace cion {

//////////////////////////////////////////////////////////////////////////////////////////
/////// Constructor
//////////////////////////////////////////////////////////////////////////////////////////

	CallingTraverser::CallingTraverser(IASTVisitor & p_callee):
		m_callee{p_callee}
	{}

//////////////////////////////////////////////////////////////////////////////////////////
/////// Visit Methods
//////////////////////////////////////////////////////////////////////////////////////////

	// Statements
	void CallingTraverser::visit(ast::Stmnt & s) {
		m_callee.visit(s);
		traverse_stmnt(s);
	}

	void CallingTraverser::visit(ast::CompoundStmnt & s) {
		m_callee.visit(s);
		traverse_compound_stmnt(s);
	}

	void CallingTraverser::visit(ast::EmptyStmnt & s) {
		m_callee.visit(s);
		traverse_empty_stmnt(s);
	}

	void CallingTraverser::visit(ast::DeclStmnt & s) {
		m_callee.visit(s);
		traverse_decl_stmnt(s);
	}

	void CallingTraverser::visit(ast::ExprStmnt & s) {
		m_callee.visit(s);
		traverse_expr_stmnt(s);
	}

	void CallingTraverser::visit(ast::IfStmnt & s) {
		m_callee.visit(s);
		traverse_if_stmnt(s);
	}

	void CallingTraverser::visit(ast::WhileStmnt & s) {
		m_callee.visit(s);
		traverse_while_stmnt(s);
	}

	void CallingTraverser::visit(ast::BreakStmnt & s) {
		m_callee.visit(s);
		traverse_break_stmnt(s);
	}

	void CallingTraverser::visit(ast::ContinueStmnt & s) {
		m_callee.visit(s);
		traverse_continue_stmnt(s);
	}

	void CallingTraverser::visit(ast::ReturnStmnt & s) {
		m_callee.visit(s);
		traverse_return_stmnt(s);
	}


	// Declarations
	void CallingTraverser::visit(ast::Decl & d) {
		m_callee.visit(d);
		traverse_decl(d);
	}

	void CallingTraverser::visit(ast::CompilationUnitDecl & d) {
		m_callee.visit(d);
		traverse_compilation_unit_decl(d);
	}

	void CallingTraverser::visit(ast::ParamDecl & d) {
		m_callee.visit(d);
		traverse_param_decl(d);
	}

	void CallingTraverser::visit(ast::FunctionDecl & d) {
		m_callee.visit(d);
		traverse_function_decl(d);
	}

	void CallingTraverser::visit(ast::VarDecl & d) {
		m_callee.visit(d);
		traverse_var_decl(d);
	}


	// Expressions
	void CallingTraverser::visit(ast::Expr & e) {
		m_callee.visit(e);
		traverse_expr(e);
	}

	void CallingTraverser::visit(ast::ConditionalExpr & e) {
		m_callee.visit(e);
		traverse_conditional_expr(e);
	}


	void CallingTraverser::visit(ast::BinaryExpr & e) {
		m_callee.visit(e);
		traverse_binary_expr(e);
	}

	void CallingTraverser::visit(ast::LogicalOrExpr & e) {
		m_callee.visit(e);
		traverse_logical_or_expr(e);
	}

	void CallingTraverser::visit(ast::LogicalAndExpr & e) {
		m_callee.visit(e);
		traverse_logical_and_expr(e);
	}

	void CallingTraverser::visit(ast::BitOrExpr & e) {
		m_callee.visit(e);
		traverse_bit_or_expr(e);
	}

	void CallingTraverser::visit(ast::BitXorExpr & e) {
		m_callee.visit(e);
		traverse_bit_xor_expr(e);
	}

	void CallingTraverser::visit(ast::BitAndExpr & e) {
		m_callee.visit(e);
		traverse_bit_and_expr(e);
	}

	void CallingTraverser::visit(ast::AddExpr & e) {
		m_callee.visit(e);
		traverse_add_expr(e);
	}

	void CallingTraverser::visit(ast::SubtractExpr & e) {
		m_callee.visit(e);
		traverse_subtract_expr(e);
	}

	void CallingTraverser::visit(ast::MultiplyExpr & e) {
		m_callee.visit(e);
		traverse_multiply_expr(e);
	}

	void CallingTraverser::visit(ast::DivideExpr & e) {
		m_callee.visit(e);
		traverse_divide_expr(e);
	}

	void CallingTraverser::visit(ast::ModuloExpr & e) {
		m_callee.visit(e);
		traverse_modulo_expr(e);
	}

	void CallingTraverser::visit(ast::ShiftLeftExpr & e) {
		m_callee.visit(e);
		traverse_shift_left_expr(e);
	}

	void CallingTraverser::visit(ast::ShiftRightExpr & e) {
		m_callee.visit(e);
		traverse_shift_right_expr(e);
	}

	void CallingTraverser::visit(ast::EqualityExpr & e) {
		m_callee.visit(e);
		traverse_equality_expr(e);
	}

	void CallingTraverser::visit(ast::InequalityExpr & e) {
		m_callee.visit(e);
		traverse_inequality_expr(e);
	}

	void CallingTraverser::visit(ast::LessThanExpr & e) {
		m_callee.visit(e);
		traverse_less_than_expr(e);
	}

	void CallingTraverser::visit(ast::LessEqualsExpr & e) {
		m_callee.visit(e);
		traverse_less_equals_expr(e);
	}

	void CallingTraverser::visit(ast::GreaterThanExpr & e) {
		m_callee.visit(e);
		traverse_greater_than_expr(e);
	}

	void CallingTraverser::visit(ast::GreaterEqualsExpr & e) {
		m_callee.visit(e);
		traverse_greater_equals_expr(e);
	}


	void CallingTraverser::visit(ast::BinaryAssignExpr & e) {
		m_callee.visit(e);
		traverse_binary_assign_expr(e);
	}

	void CallingTraverser::visit(ast::AssignExpr & e) {
		m_callee.visit(e);
		traverse_assign_expr(e);
	}

	void CallingTraverser::visit(ast::AddAssignExpr & e) {
		m_callee.visit(e);
		traverse_add_assign_expr(e);
	}

	void CallingTraverser::visit(ast::SubtractAssignExpr & e) {
		m_callee.visit(e);
		traverse_subtract_assign_expr(e);
	}

	void CallingTraverser::visit(ast::MultiplyAssignExpr & e) {
		m_callee.visit(e);
		traverse_multiply_assign_expr(e);
	}

	void CallingTraverser::visit(ast::DivideAssignExpr & e) {
		m_callee.visit(e);
		traverse_divide_assign_expr(e);
	}

	void CallingTraverser::visit(ast::ModuloAssignExpr & e) {
		m_callee.visit(e);
		traverse_modulo_assign_expr(e);
	}

	void CallingTraverser::visit(ast::LogicalOrAssignExpr & e) {
		m_callee.visit(e);
		traverse_logical_or_assign_expr(e);
	}

	void CallingTraverser::visit(ast::LogicalAndAssignExpr & e) {
		m_callee.visit(e);
		traverse_logical_and_assign_expr(e);
	}

	void CallingTraverser::visit(ast::BitOrAssignExpr & e) {
		m_callee.visit(e);
		traverse_bit_or_assign_expr(e);
	}

	void CallingTraverser::visit(ast::BitXorAssignExpr & e) {
		m_callee.visit(e);
		traverse_bit_xor_assign_expr(e);
	}

	void CallingTraverser::visit(ast::BitAndAssignExpr & e) {
		m_callee.visit(e);
		traverse_bit_and_assign_expr(e);
	}

	void CallingTraverser::visit(ast::ShiftLeftAssignExpr & e) {
		m_callee.visit(e);
		traverse_shift_left_assign_expr(e);
	}

	void CallingTraverser::visit(ast::ShiftRightAssignExpr & e) {
		m_callee.visit(e);
		traverse_shift_right_assign_expr(e);
	}


	void CallingTraverser::visit(ast::BooleanExpr & e) {
		m_callee.visit(e);
		traverse_boolean_expr(e);
	}

	void CallingTraverser::visit(ast::CallExpr & e) {
		m_callee.visit(e);
		traverse_call_expr(e);
	}

	void CallingTraverser::visit(ast::CharExpr & e) {
		m_callee.visit(e);
		traverse_char_expr(e);
	}

	void CallingTraverser::visit(ast::FloatExpr & e) {
		m_callee.visit(e);
		traverse_float_expr(e);
	}

	void CallingTraverser::visit(ast::IndexExpr & e) {
		m_callee.visit(e);
		traverse_index_expr(e);
	}

	void CallingTraverser::visit(ast::IntegerExpr & e) {
		m_callee.visit(e);
		traverse_integer_expr(e);
	}

	void CallingTraverser::visit(ast::NothingExpr & e) {
		m_callee.visit(e);
		traverse_nothing_expr(e);
	}

	void CallingTraverser::visit(ast::StringExpr & e) {
		m_callee.visit(e);
		traverse_string_expr(e);
	}


	void CallingTraverser::visit(ast::UnaryExpr & e) {
		m_callee.visit(e);
		traverse_unary_expr(e);
	}

	void CallingTraverser::visit(ast::BitNegateExpr & e) {
		m_callee.visit(e);
		traverse_bit_negate_expr(e);
	}

	void CallingTraverser::visit(ast::LogicalNegateExpr & e) {
		m_callee.visit(e);
		traverse_logical_negate_expr(e);
	}

	void CallingTraverser::visit(ast::PlusExpr & e) {
		m_callee.visit(e);
		traverse_plus_expr(e);
	}

	void CallingTraverser::visit(ast::MinusExpr & e) {
		m_callee.visit(e);
		traverse_minus_expr(e);
	}

	void CallingTraverser::visit(ast::IncrementExpr & e) {
		m_callee.visit(e);
		traverse_increment_expr(e);
	}

	void CallingTraverser::visit(ast::DecrementExpr & e) {
		m_callee.visit(e);
		traverse_decrement_expr(e);
	}

	void CallingTraverser::visit(ast::PostIncrementExpr & e) {
		m_callee.visit(e);
		traverse_post_increment_expr(e);
	}

	void CallingTraverser::visit(ast::PostDecrementExpr & e) {
		m_callee.visit(e);
		traverse_post_decrement_expr(e);
	}


	void CallingTraverser::visit(ast::VarExpr & e) {
		m_callee.visit(e);
		traverse_var_expr(e);
	}


	// Types
	void CallingTraverser::visit(ast::Type & t) {
		m_callee.visit(t);
		traverse_type(t);
	}

	void CallingTraverser::visit(ast::NothingType & t) {
		m_callee.visit(t);
		traverse_nothing_type(t);
	}

	void CallingTraverser::visit(ast::BuiltinType & t) {
		m_callee.visit(t);
		traverse_builtin_type(t);
	}

	void CallingTraverser::visit(ast::BoolType & t) {
		m_callee.visit(t);
		traverse_bool_type(t);
	}

	void CallingTraverser::visit(ast::CharType & t) {
		m_callee.visit(t);
		traverse_char_type(t);
	}

	void CallingTraverser::visit(ast::FloatingType & t) {
		m_callee.visit(t);
		traverse_floating_type(t);
	}

	void CallingTraverser::visit(ast::IntegerType & t) {
		m_callee.visit(t);
		traverse_integer_type(t);
	}

} // namespace cion
