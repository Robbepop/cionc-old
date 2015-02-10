#include "cion/parser/pre_post_traverser.hpp"
#include "cion/parser/i_pre_post_compiler_pass.hpp"

#include "cion/ast/all.hpp"

namespace cion {

//////////////////////////////////////////////////////////////////////////////////////////
/////// Constructor
//////////////////////////////////////////////////////////////////////////////////////////

	PrePostTraverser::PrePostTraverser(
		IASTVisitor & p_pass
	):
		RecursiveTraverser{p_pass},
		m_post_pass{p_pass}
	{}

	PrePostTraverser::PrePostTraverser(
		IASTVisitor & p_pre_pass,
		IASTVisitor & p_post_pass
	):
		RecursiveTraverser{p_pre_pass},
		m_post_pass{p_post_pass}
	{}

	PrePostTraverser::PrePostTraverser(
		IPrePostCompilerPass & p_pre_post_pass
	):
		PrePostTraverser{p_pre_post_pass.pre_pass(), p_pre_post_pass.post_pass()}
	{}

//////////////////////////////////////////////////////////////////////////////////////////
/////// Visit Methods
//////////////////////////////////////////////////////////////////////////////////////////

	// Statements
	void PrePostTraverser::visit(ast::Stmnt & s) {
		m_pass.visit(s);
		traverse_stmnt(s);
		m_post_pass.visit(s);
	}

	void PrePostTraverser::visit(ast::CompoundStmnt & s) {
		m_pass.visit(s);
		traverse_compound_stmnt(s);
		m_post_pass.visit(s);
	}

	void PrePostTraverser::visit(ast::EmptyStmnt & s) {
		m_pass.visit(s);
		traverse_empty_stmnt(s);
		m_post_pass.visit(s);
	}

	void PrePostTraverser::visit(ast::ExprStmnt & s) {
		m_pass.visit(s);
		traverse_expr_stmnt(s);
		m_post_pass.visit(s);
	}

	void PrePostTraverser::visit(ast::IfStmnt & s) {
		m_pass.visit(s);
		traverse_if_stmnt(s);
		m_post_pass.visit(s);
	}

	void PrePostTraverser::visit(ast::WhileStmnt & s) {
		m_pass.visit(s);
		traverse_while_stmnt(s);
		m_post_pass.visit(s);
	}

	void PrePostTraverser::visit(ast::BreakStmnt & s) {
		m_pass.visit(s);
		traverse_break_stmnt(s);
		m_post_pass.visit(s);
	}

	void PrePostTraverser::visit(ast::ContinueStmnt & s) {
		m_pass.visit(s);
		traverse_continue_stmnt(s);
		m_post_pass.visit(s);
	}

	void PrePostTraverser::visit(ast::ReturnStmnt & s) {
		m_pass.visit(s);
		traverse_return_stmnt(s);
		m_post_pass.visit(s);
	}


	// Declarations
	void PrePostTraverser::visit(ast::Decl & d) {
		m_pass.visit(d);
		traverse_decl(d);
		m_post_pass.visit(d);
	}

	void PrePostTraverser::visit(ast::CompilationUnitDecl & d) {
		m_pass.visit(d);
		traverse_compilation_unit_decl(d);
		m_post_pass.visit(d);
	}

	void PrePostTraverser::visit(ast::ParamDecl & d) {
		m_pass.visit(d);
		traverse_param_decl(d);
		m_post_pass.visit(d);
	}

	void PrePostTraverser::visit(ast::FunctionDecl & d) {
		m_pass.visit(d);
		traverse_function_decl(d);
		m_post_pass.visit(d);
	}

	void PrePostTraverser::visit(ast::VarDecl & d) {
		m_pass.visit(d);
		traverse_var_decl(d);
		m_post_pass.visit(d);
	}


	// Expressions
	void PrePostTraverser::visit(ast::Expr & e) {
		m_pass.visit(e);
		traverse_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::ConditionalExpr & e) {
		m_pass.visit(e);
		traverse_conditional_expr(e);
		m_post_pass.visit(e);
	}


	void PrePostTraverser::visit(ast::BinaryExpr & e) {
		m_pass.visit(e);
		traverse_binary_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::LogicalOrExpr & e) {
		m_pass.visit(e);
		traverse_logical_or_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::LogicalAndExpr & e) {
		m_pass.visit(e);
		traverse_logical_and_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::BitOrExpr & e) {
		m_pass.visit(e);
		traverse_bit_or_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::BitXorExpr & e) {
		m_pass.visit(e);
		traverse_bit_xor_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::BitAndExpr & e) {
		m_pass.visit(e);
		traverse_bit_and_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::AddExpr & e) {
		m_pass.visit(e);
		traverse_add_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::SubtractExpr & e) {
		m_pass.visit(e);
		traverse_subtract_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::MultiplyExpr & e) {
		m_pass.visit(e);
		traverse_multiply_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::DivideExpr & e) {
		m_pass.visit(e);
		traverse_divide_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::ModuloExpr & e) {
		m_pass.visit(e);
		traverse_modulo_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::ShiftLeftExpr & e) {
		m_pass.visit(e);
		traverse_shift_left_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::ShiftRightExpr & e) {
		m_pass.visit(e);
		traverse_shift_right_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::EqualityExpr & e) {
		m_pass.visit(e);
		traverse_equality_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::InequalityExpr & e) {
		m_pass.visit(e);
		traverse_inequality_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::LessThanExpr & e) {
		m_pass.visit(e);
		traverse_less_than_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::LessEqualsExpr & e) {
		m_pass.visit(e);
		traverse_less_equals_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::GreaterThanExpr & e) {
		m_pass.visit(e);
		traverse_greater_than_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::GreaterEqualsExpr & e) {
		m_pass.visit(e);
		traverse_greater_equals_expr(e);
		m_post_pass.visit(e);
	}


	void PrePostTraverser::visit(ast::BinaryAssignExpr & e) {
		m_pass.visit(e);
		traverse_binary_assign_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::AssignExpr & e) {
		m_pass.visit(e);
		traverse_assign_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::AddAssignExpr & e) {
		m_pass.visit(e);
		traverse_add_assign_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::SubtractAssignExpr & e) {
		m_pass.visit(e);
		traverse_subtract_assign_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::MultiplyAssignExpr & e) {
		m_pass.visit(e);
		traverse_multiply_assign_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::DivideAssignExpr & e) {
		m_pass.visit(e);
		traverse_divide_assign_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::ModuloAssignExpr & e) {
		m_pass.visit(e);
		traverse_modulo_assign_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::LogicalOrAssignExpr & e) {
		m_pass.visit(e);
		traverse_logical_or_assign_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::LogicalAndAssignExpr & e) {
		m_pass.visit(e);
		traverse_logical_and_assign_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::BitOrAssignExpr & e) {
		m_pass.visit(e);
		traverse_bit_or_assign_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::BitXorAssignExpr & e) {
		m_pass.visit(e);
		traverse_bit_xor_assign_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::BitAndAssignExpr & e) {
		m_pass.visit(e);
		traverse_bit_and_assign_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::ShiftLeftAssignExpr & e) {
		m_pass.visit(e);
		traverse_shift_left_assign_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::ShiftRightAssignExpr & e) {
		m_pass.visit(e);
		traverse_shift_right_assign_expr(e);
		m_post_pass.visit(e);
	}


	void PrePostTraverser::visit(ast::BooleanExpr & e) {
		m_pass.visit(e);
		traverse_boolean_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::CallExpr & e) {
		m_pass.visit(e);
		traverse_call_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::CharExpr & e) {
		m_pass.visit(e);
		traverse_char_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::FloatExpr & e) {
		m_pass.visit(e);
		traverse_float_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::IndexExpr & e) {
		m_pass.visit(e);
		traverse_index_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::IntegerExpr & e) {
		m_pass.visit(e);
		traverse_integer_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::NothingExpr & e) {
		m_pass.visit(e);
		traverse_nothing_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::StringExpr & e) {
		m_pass.visit(e);
		traverse_string_expr(e);
		m_post_pass.visit(e);
	}


	void PrePostTraverser::visit(ast::UnaryExpr & e) {
		m_pass.visit(e);
		traverse_unary_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::BitNegateExpr & e) {
		m_pass.visit(e);
		traverse_bit_negate_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::LogicalNegateExpr & e) {
		m_pass.visit(e);
		traverse_logical_negate_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::PlusExpr & e) {
		m_pass.visit(e);
		traverse_plus_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::MinusExpr & e) {
		m_pass.visit(e);
		traverse_minus_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::IncrementExpr & e) {
		m_pass.visit(e);
		traverse_increment_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::DecrementExpr & e) {
		m_pass.visit(e);
		traverse_decrement_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::PostIncrementExpr & e) {
		m_pass.visit(e);
		traverse_post_increment_expr(e);
		m_post_pass.visit(e);
	}

	void PrePostTraverser::visit(ast::PostDecrementExpr & e) {
		m_pass.visit(e);
		traverse_post_decrement_expr(e);
		m_post_pass.visit(e);
	}


	void PrePostTraverser::visit(ast::VarExpr & e) {
		m_pass.visit(e);
		traverse_var_expr(e);
		m_post_pass.visit(e);
	}


	// Types
	void PrePostTraverser::visit(ast::Type & t) {
		m_pass.visit(t);
		traverse_type(t);
		m_post_pass.visit(t);
	}

	void PrePostTraverser::visit(ast::NothingType & t) {
		m_pass.visit(t);
		traverse_nothing_type(t);
		m_post_pass.visit(t);
	}

	void PrePostTraverser::visit(ast::BuiltinType & t) {
		m_pass.visit(t);
		traverse_builtin_type(t);
		m_post_pass.visit(t);
	}

	void PrePostTraverser::visit(ast::BuiltinBoolType & t) {
		m_pass.visit(t);
		traverse_builtin_bool_type(t);
		m_post_pass.visit(t);
	}

	void PrePostTraverser::visit(ast::BuiltinCharType & t) {
		m_pass.visit(t);
		traverse_builtin_char_type(t);
		m_post_pass.visit(t);
	}

	void PrePostTraverser::visit(ast::BuiltinFloatType & t) {
		m_pass.visit(t);
		traverse_builtin_float_type(t);
		m_post_pass.visit(t);
	}

	void PrePostTraverser::visit(ast::BuiltinIntType & t) {
		m_pass.visit(t);
		traverse_builtin_int_type(t);
		m_post_pass.visit(t);
	}
} // namespace cion
