#include "cion/parser/recursive_traverser.hpp"

#include "cion/ast/all.hpp"

namespace cion {

//////////////////////////////////////////////////////////////////////////////////////////
/////// Constructor
//////////////////////////////////////////////////////////////////////////////////////////

	RecursiveTraverser::RecursiveTraverser(IASTVisitor & p_pass):
		m_pass{p_pass}
	{}

//////////////////////////////////////////////////////////////////////////////////////////
/////// Visit Methods
//////////////////////////////////////////////////////////////////////////////////////////

	// Statements
	void RecursiveTraverser::visit(ast::Stmnt & s) {
		m_pass.visit(s);
		traverse_stmnt(s);
	}

	void RecursiveTraverser::visit(ast::CompoundStmnt & s) {
		m_pass.visit(s);
		traverse_compound_stmnt(s);
	}

	void RecursiveTraverser::visit(ast::EmptyStmnt & s) {
		m_pass.visit(s);
		traverse_empty_stmnt(s);
	}

	void RecursiveTraverser::visit(ast::DeclStmnt & s) {
		m_pass.visit(s);
		traverse_decl_stmnt(s);
	}

	void RecursiveTraverser::visit(ast::ExprStmnt & s) {
		m_pass.visit(s);
		traverse_expr_stmnt(s);
	}

	void RecursiveTraverser::visit(ast::IfStmnt & s) {
		m_pass.visit(s);
		traverse_if_stmnt(s);
	}

	void RecursiveTraverser::visit(ast::WhileStmnt & s) {
		m_pass.visit(s);
		traverse_while_stmnt(s);
	}

	void RecursiveTraverser::visit(ast::BreakStmnt & s) {
		m_pass.visit(s);
		traverse_break_stmnt(s);
	}

	void RecursiveTraverser::visit(ast::ContinueStmnt & s) {
		m_pass.visit(s);
		traverse_continue_stmnt(s);
	}

	void RecursiveTraverser::visit(ast::ReturnStmnt & s) {
		m_pass.visit(s);
		traverse_return_stmnt(s);
	}


	// Declarations
	void RecursiveTraverser::visit(ast::Decl & d) {
		m_pass.visit(d);
		traverse_decl(d);
	}

	void RecursiveTraverser::visit(ast::CompilationUnitDecl & d) {
		m_pass.visit(d);
		traverse_compilation_unit_decl(d);
	}

	void RecursiveTraverser::visit(ast::ParamDecl & d) {
		m_pass.visit(d);
		traverse_param_decl(d);
	}

	void RecursiveTraverser::visit(ast::FunctionDecl & d) {
		m_pass.visit(d);
		traverse_function_decl(d);
	}

	void RecursiveTraverser::visit(ast::VarDecl & d) {
		m_pass.visit(d);
		traverse_var_decl(d);
	}


	// Expressions
	void RecursiveTraverser::visit(ast::Expr & e) {
		m_pass.visit(e);
		traverse_expr(e);
	}

	void RecursiveTraverser::visit(ast::ConditionalExpr & e) {
		m_pass.visit(e);
		traverse_conditional_expr(e);
	}


	void RecursiveTraverser::visit(ast::BinaryExpr & e) {
		m_pass.visit(e);
		traverse_binary_expr(e);
	}

	void RecursiveTraverser::visit(ast::LogicalOrExpr & e) {
		m_pass.visit(e);
		traverse_logical_or_expr(e);
	}

	void RecursiveTraverser::visit(ast::LogicalAndExpr & e) {
		m_pass.visit(e);
		traverse_logical_and_expr(e);
	}

	void RecursiveTraverser::visit(ast::BitOrExpr & e) {
		m_pass.visit(e);
		traverse_bit_or_expr(e);
	}

	void RecursiveTraverser::visit(ast::BitXorExpr & e) {
		m_pass.visit(e);
		traverse_bit_xor_expr(e);
	}

	void RecursiveTraverser::visit(ast::BitAndExpr & e) {
		m_pass.visit(e);
		traverse_bit_and_expr(e);
	}

	void RecursiveTraverser::visit(ast::AddExpr & e) {
		m_pass.visit(e);
		traverse_add_expr(e);
	}

	void RecursiveTraverser::visit(ast::SubtractExpr & e) {
		m_pass.visit(e);
		traverse_subtract_expr(e);
	}

	void RecursiveTraverser::visit(ast::MultiplyExpr & e) {
		m_pass.visit(e);
		traverse_multiply_expr(e);
	}

	void RecursiveTraverser::visit(ast::DivideExpr & e) {
		m_pass.visit(e);
		traverse_divide_expr(e);
	}

	void RecursiveTraverser::visit(ast::ModuloExpr & e) {
		m_pass.visit(e);
		traverse_modulo_expr(e);
	}

	void RecursiveTraverser::visit(ast::ShiftLeftExpr & e) {
		m_pass.visit(e);
		traverse_shift_left_expr(e);
	}

	void RecursiveTraverser::visit(ast::ShiftRightExpr & e) {
		m_pass.visit(e);
		traverse_shift_right_expr(e);
	}

	void RecursiveTraverser::visit(ast::EqualityExpr & e) {
		m_pass.visit(e);
		traverse_equality_expr(e);
	}

	void RecursiveTraverser::visit(ast::InequalityExpr & e) {
		m_pass.visit(e);
		traverse_inequality_expr(e);
	}

	void RecursiveTraverser::visit(ast::LessThanExpr & e) {
		m_pass.visit(e);
		traverse_less_than_expr(e);
	}

	void RecursiveTraverser::visit(ast::LessEqualsExpr & e) {
		m_pass.visit(e);
		traverse_less_equals_expr(e);
	}

	void RecursiveTraverser::visit(ast::GreaterThanExpr & e) {
		m_pass.visit(e);
		traverse_greater_than_expr(e);
	}

	void RecursiveTraverser::visit(ast::GreaterEqualsExpr & e) {
		m_pass.visit(e);
		traverse_greater_equals_expr(e);
	}


	void RecursiveTraverser::visit(ast::BinaryAssignExpr & e) {
		m_pass.visit(e);
		traverse_binary_assign_expr(e);
	}

	void RecursiveTraverser::visit(ast::AssignExpr & e) {
		m_pass.visit(e);
		traverse_assign_expr(e);
	}

	void RecursiveTraverser::visit(ast::AddAssignExpr & e) {
		m_pass.visit(e);
		traverse_add_assign_expr(e);
	}

	void RecursiveTraverser::visit(ast::SubtractAssignExpr & e) {
		m_pass.visit(e);
		traverse_subtract_assign_expr(e);
	}

	void RecursiveTraverser::visit(ast::MultiplyAssignExpr & e) {
		m_pass.visit(e);
		traverse_multiply_assign_expr(e);
	}

	void RecursiveTraverser::visit(ast::DivideAssignExpr & e) {
		m_pass.visit(e);
		traverse_divide_assign_expr(e);
	}

	void RecursiveTraverser::visit(ast::ModuloAssignExpr & e) {
		m_pass.visit(e);
		traverse_modulo_assign_expr(e);
	}

	void RecursiveTraverser::visit(ast::LogicalOrAssignExpr & e) {
		m_pass.visit(e);
		traverse_logical_or_assign_expr(e);
	}

	void RecursiveTraverser::visit(ast::LogicalAndAssignExpr & e) {
		m_pass.visit(e);
		traverse_logical_and_assign_expr(e);
	}

	void RecursiveTraverser::visit(ast::BitOrAssignExpr & e) {
		m_pass.visit(e);
		traverse_bit_or_assign_expr(e);
	}

	void RecursiveTraverser::visit(ast::BitXorAssignExpr & e) {
		m_pass.visit(e);
		traverse_bit_xor_assign_expr(e);
	}

	void RecursiveTraverser::visit(ast::BitAndAssignExpr & e) {
		m_pass.visit(e);
		traverse_bit_and_assign_expr(e);
	}

	void RecursiveTraverser::visit(ast::ShiftLeftAssignExpr & e) {
		m_pass.visit(e);
		traverse_shift_left_assign_expr(e);
	}

	void RecursiveTraverser::visit(ast::ShiftRightAssignExpr & e) {
		m_pass.visit(e);
		traverse_shift_right_assign_expr(e);
	}


	void RecursiveTraverser::visit(ast::BooleanExpr & e) {
		m_pass.visit(e);
		traverse_boolean_expr(e);
	}

	void RecursiveTraverser::visit(ast::CallExpr & e) {
		m_pass.visit(e);
		traverse_call_expr(e);
	}

	void RecursiveTraverser::visit(ast::CharExpr & e) {
		m_pass.visit(e);
		traverse_char_expr(e);
	}

	void RecursiveTraverser::visit(ast::FloatExpr & e) {
		m_pass.visit(e);
		traverse_float_expr(e);
	}

	void RecursiveTraverser::visit(ast::IndexExpr & e) {
		m_pass.visit(e);
		traverse_index_expr(e);
	}

	void RecursiveTraverser::visit(ast::IntegerExpr & e) {
		m_pass.visit(e);
		traverse_integer_expr(e);
	}

	void RecursiveTraverser::visit(ast::NothingExpr & e) {
		m_pass.visit(e);
		traverse_nothing_expr(e);
	}

	void RecursiveTraverser::visit(ast::StringExpr & e) {
		m_pass.visit(e);
		traverse_string_expr(e);
	}


	void RecursiveTraverser::visit(ast::UnaryExpr & e) {
		m_pass.visit(e);
		traverse_unary_expr(e);
	}

	void RecursiveTraverser::visit(ast::BitNegateExpr & e) {
		m_pass.visit(e);
		traverse_bit_negate_expr(e);
	}

	void RecursiveTraverser::visit(ast::LogicalNegateExpr & e) {
		m_pass.visit(e);
		traverse_logical_negate_expr(e);
	}

	void RecursiveTraverser::visit(ast::PlusExpr & e) {
		m_pass.visit(e);
		traverse_plus_expr(e);
	}

	void RecursiveTraverser::visit(ast::MinusExpr & e) {
		m_pass.visit(e);
		traverse_minus_expr(e);
	}

	void RecursiveTraverser::visit(ast::IncrementExpr & e) {
		m_pass.visit(e);
		traverse_increment_expr(e);
	}

	void RecursiveTraverser::visit(ast::DecrementExpr & e) {
		m_pass.visit(e);
		traverse_decrement_expr(e);
	}

	void RecursiveTraverser::visit(ast::PostIncrementExpr & e) {
		m_pass.visit(e);
		traverse_post_increment_expr(e);
	}

	void RecursiveTraverser::visit(ast::PostDecrementExpr & e) {
		m_pass.visit(e);
		traverse_post_decrement_expr(e);
	}


	void RecursiveTraverser::visit(ast::VarExpr & e) {
		m_pass.visit(e);
		traverse_var_expr(e);
	}


	// Types
	void RecursiveTraverser::visit(ast::Type & t) {
		m_pass.visit(t);
		traverse_type(t);
	}

	void RecursiveTraverser::visit(ast::NothingType & t) {
		m_pass.visit(t);
		traverse_nothing_type(t);
	}

	void RecursiveTraverser::visit(ast::BuiltinType & t) {
		m_pass.visit(t);
		traverse_builtin_type(t);
	}

	void RecursiveTraverser::visit(ast::BuiltinBoolType & t) {
		m_pass.visit(t);
		traverse_builtin_bool_type(t);
	}

	void RecursiveTraverser::visit(ast::BuiltinCharType & t) {
		m_pass.visit(t);
		traverse_builtin_char_type(t);
	}

	void RecursiveTraverser::visit(ast::BuiltinFloatType & t) {
		m_pass.visit(t);
		traverse_builtin_float_type(t);
	}

	void RecursiveTraverser::visit(ast::BuiltinIntType & t) {
		m_pass.visit(t);
		traverse_builtin_int_type(t);
	}


//////////////////////////////////////////////////////////////////////////////////////////
/////// Traverse Methods
//////////////////////////////////////////////////////////////////////////////////////////

	// Statements
	void RecursiveTraverser::traverse_stmnt(ast::Stmnt &) {}

	void RecursiveTraverser::traverse_compound_stmnt(ast::CompoundStmnt & s) {
		for (auto&& stmnt : s.statements()) {
			stmnt->accept(*this);
		}
	}

	void RecursiveTraverser::traverse_empty_stmnt(ast::EmptyStmnt &) {}

	void RecursiveTraverser::traverse_decl_stmnt(ast::DeclStmnt & s) {
		s.decl().accept(*this);
	}

	void RecursiveTraverser::traverse_expr_stmnt(ast::ExprStmnt & s) {
		s.expr().accept(*this);
	}

	void RecursiveTraverser::traverse_if_stmnt(ast::IfStmnt & s) {
		s.condition().accept(*this);
		s.then_stmnt().accept(*this);
		s.else_stmnt().accept(*this);
	}

	void RecursiveTraverser::traverse_while_stmnt(ast::WhileStmnt & s) {
		s.condition().accept(*this);
		s.body().accept(*this);
	}

	void RecursiveTraverser::traverse_break_stmnt(ast::BreakStmnt &) {}

	void RecursiveTraverser::traverse_continue_stmnt(ast::ContinueStmnt &) {}

	void RecursiveTraverser::traverse_return_stmnt(ast::ReturnStmnt & s) {
		s.expr().accept(*this);
	}


	// Declarations
	void RecursiveTraverser::traverse_decl(ast::Decl &) {}

	void RecursiveTraverser::traverse_compilation_unit_decl(ast::CompilationUnitDecl & d) {
		for (auto&& decl : d.decls()) {
			decl->accept(*this);
		}
	}

	void RecursiveTraverser::traverse_param_decl(ast::ParamDecl & d) {
		d.type().accept(*this);
	}

	void RecursiveTraverser::traverse_function_decl(ast::FunctionDecl & d) {
		for (auto&& param : d.params()) {
			param->accept(*this);
		}
		d.return_type().accept(*this);
		d.body().accept(*this);
	}

	void RecursiveTraverser::traverse_var_decl(ast::VarDecl & d) {
		d.type().accept(*this);
		d.expr().accept(*this);
	}


	// Expressions
	void RecursiveTraverser::traverse_expr(ast::Expr & e) {
		e.type().accept(*this);
	}

	void RecursiveTraverser::traverse_conditional_expr(ast::ConditionalExpr & e) {
		traverse_expr(e);
		e.condition().accept(*this);
		e.then_expr().accept(*this);
		e.else_expr().accept(*this);
	}


	void RecursiveTraverser::traverse_binary_expr(ast::BinaryExpr & e) {
		traverse_expr(e);
		e.lhs().accept(*this);
		e.rhs().accept(*this);
	}

	void RecursiveTraverser::traverse_logical_or_expr(ast::LogicalOrExpr & e) {
		traverse_binary_expr(e);
	}

	void RecursiveTraverser::traverse_logical_and_expr(ast::LogicalAndExpr & e) {
		traverse_binary_expr(e);
	}

	void RecursiveTraverser::traverse_bit_or_expr(ast::BitOrExpr & e) {
		traverse_binary_expr(e);
	}

	void RecursiveTraverser::traverse_bit_xor_expr(ast::BitXorExpr & e) {
		traverse_binary_expr(e);
	}

	void RecursiveTraverser::traverse_bit_and_expr(ast::BitAndExpr & e) {
		traverse_binary_expr(e);
	}

	void RecursiveTraverser::traverse_add_expr(ast::AddExpr & e) {
		traverse_binary_expr(e);
	}

	void RecursiveTraverser::traverse_subtract_expr(ast::SubtractExpr & e) {
		traverse_binary_expr(e);
	}

	void RecursiveTraverser::traverse_multiply_expr(ast::MultiplyExpr & e) {
		traverse_binary_expr(e);
	}

	void RecursiveTraverser::traverse_divide_expr(ast::DivideExpr & e) {
		traverse_binary_expr(e);
	}

	void RecursiveTraverser::traverse_modulo_expr(ast::ModuloExpr & e) {
		traverse_binary_expr(e);
	}

	void RecursiveTraverser::traverse_shift_left_expr(ast::ShiftLeftExpr & e) {
		traverse_binary_expr(e);
	}

	void RecursiveTraverser::traverse_shift_right_expr(ast::ShiftRightExpr & e) {
		traverse_binary_expr(e);
	}

	void RecursiveTraverser::traverse_equality_expr(ast::EqualityExpr & e) {
		traverse_binary_expr(e);
	}

	void RecursiveTraverser::traverse_inequality_expr(ast::InequalityExpr & e) {
		traverse_binary_expr(e);
	}

	void RecursiveTraverser::traverse_less_than_expr(ast::LessThanExpr & e) {
		traverse_binary_expr(e);
	}

	void RecursiveTraverser::traverse_less_equals_expr(ast::LessEqualsExpr & e) {
		traverse_binary_expr(e);
	}

	void RecursiveTraverser::traverse_greater_than_expr(ast::GreaterThanExpr & e) {
		traverse_binary_expr(e);
	}

	void RecursiveTraverser::traverse_greater_equals_expr(ast::GreaterEqualsExpr & e) {
		traverse_binary_expr(e);
	}


	void RecursiveTraverser::traverse_binary_assign_expr(ast::BinaryAssignExpr & e) {
		traverse_binary_expr(e);
	}

	void RecursiveTraverser::traverse_assign_expr(ast::AssignExpr & e) {
		traverse_binary_assign_expr(e);
	}

	void RecursiveTraverser::traverse_add_assign_expr(ast::AddAssignExpr & e) {
		traverse_binary_assign_expr(e);
	}

	void RecursiveTraverser::traverse_subtract_assign_expr(ast::SubtractAssignExpr & e) {
		traverse_binary_assign_expr(e);
	}

	void RecursiveTraverser::traverse_multiply_assign_expr(ast::MultiplyAssignExpr & e) {
		traverse_binary_assign_expr(e);
	}

	void RecursiveTraverser::traverse_divide_assign_expr(ast::DivideAssignExpr & e) {
		traverse_binary_assign_expr(e);
	}

	void RecursiveTraverser::traverse_modulo_assign_expr(ast::ModuloAssignExpr & e) {
		traverse_binary_assign_expr(e);
	}

	void RecursiveTraverser::traverse_logical_or_assign_expr(ast::LogicalOrAssignExpr & e) {
		traverse_binary_assign_expr(e);
	}

	void RecursiveTraverser::traverse_logical_and_assign_expr(ast::LogicalAndAssignExpr & e) {
		traverse_binary_assign_expr(e);
	}

	void RecursiveTraverser::traverse_bit_or_assign_expr(ast::BitOrAssignExpr & e) {
		traverse_binary_assign_expr(e);
	}

	void RecursiveTraverser::traverse_bit_xor_assign_expr(ast::BitXorAssignExpr & e) {
		traverse_binary_assign_expr(e);
	}

	void RecursiveTraverser::traverse_bit_and_assign_expr(ast::BitAndAssignExpr & e) {
		traverse_binary_assign_expr(e);
	}

	void RecursiveTraverser::traverse_shift_left_assign_expr(ast::ShiftLeftAssignExpr & e) {
		traverse_binary_assign_expr(e);
	}

	void RecursiveTraverser::traverse_shift_right_assign_expr(ast::ShiftRightAssignExpr & e) {
		traverse_binary_assign_expr(e);
	}


	void RecursiveTraverser::traverse_boolean_expr(ast::BooleanExpr & e) {
		traverse_expr(e);
	}

	void RecursiveTraverser::traverse_call_expr(ast::CallExpr & e) {
		traverse_expr(e);
		e.callee().accept(*this);
		for (auto&& arg : e.args()) {
			arg->accept(*this);
		}
	}

	void RecursiveTraverser::traverse_char_expr(ast::CharExpr & e) {
		traverse_expr(e);
	}

	void RecursiveTraverser::traverse_float_expr(ast::FloatExpr & e) {
		traverse_expr(e);
	}

	void RecursiveTraverser::traverse_index_expr(ast::IndexExpr & e) {
		traverse_expr(e);
		e.expr().accept(*this);
		for (auto&& index : e.indices()) {
			index->accept(*this);
		}
	}

	void RecursiveTraverser::traverse_integer_expr(ast::IntegerExpr & e) {
		traverse_expr(e);
	}

	void RecursiveTraverser::traverse_nothing_expr(ast::NothingExpr & e) {
		traverse_expr(e);
	}

	void RecursiveTraverser::traverse_string_expr(ast::StringExpr & e) {
		traverse_expr(e);
	}


	void RecursiveTraverser::traverse_unary_expr(ast::UnaryExpr & e) {
		traverse_expr(e);
		e.expr().accept(*this);
	}

	void RecursiveTraverser::traverse_bit_negate_expr(ast::BitNegateExpr & e) {
		traverse_unary_expr(e);
	}

	void RecursiveTraverser::traverse_logical_negate_expr(ast::LogicalNegateExpr & e) {
		traverse_unary_expr(e);
	}

	void RecursiveTraverser::traverse_plus_expr(ast::PlusExpr & e) {
		traverse_unary_expr(e);
	}

	void RecursiveTraverser::traverse_minus_expr(ast::MinusExpr & e) {
		traverse_unary_expr(e);
	}

	void RecursiveTraverser::traverse_increment_expr(ast::IncrementExpr & e) {
		traverse_unary_expr(e);
	}

	void RecursiveTraverser::traverse_decrement_expr(ast::DecrementExpr & e) {
		traverse_unary_expr(e);
	}

	void RecursiveTraverser::traverse_post_increment_expr(ast::PostIncrementExpr & e) {
		traverse_unary_expr(e);
	}

	void RecursiveTraverser::traverse_post_decrement_expr(ast::PostDecrementExpr & e) {
		traverse_unary_expr(e);
	}


	void RecursiveTraverser::traverse_var_expr(ast::VarExpr & e) {
		traverse_expr(e);
	}


	// Types
	void RecursiveTraverser::traverse_type(ast::Type &) {}

	void RecursiveTraverser::traverse_nothing_type(ast::NothingType &) {}

	void RecursiveTraverser::traverse_builtin_type(ast::BuiltinType &) {}

	void RecursiveTraverser::traverse_builtin_bool_type(ast::BuiltinBoolType &) {}

	void RecursiveTraverser::traverse_builtin_char_type(ast::BuiltinCharType &) {}

	void RecursiveTraverser::traverse_builtin_float_type(ast::BuiltinFloatType &) {}

	void RecursiveTraverser::traverse_builtin_int_type(ast::BuiltinIntType &) {}


} // namespace cion
