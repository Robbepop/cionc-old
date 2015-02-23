#include "cion/parser/write_ast_pass.hpp"

#include <sstream>

namespace cion {

//////////////////////////////////////////////////////////////////////////////////////////
/// WriteASTPass Block - for controlling the depth automatically
//////////////////////////////////////////////////////////////////////////////////////////

	WriteASTPass::Block::Block(WriteASTPass & p_writer):
		m_writer{p_writer}
	{
		m_writer.inc_depth();
	}

	WriteASTPass::Block::~Block() {
		m_writer.dec_depth();
	}

//////////////////////////////////////////////////////////////////////////////////////////
/// WriteASTPass Constructor & Helper Methods
//////////////////////////////////////////////////////////////////////////////////////////

	WriteASTPass::Block WriteASTPass::create_block() {
		return Block{*this};
	}

	WriteASTPass::WriteASTPass(std::ostream & os):
		m_os{os}
	{}

	std::string WriteASTPass::depth_str() {
		static const auto c_depth_figure = "   .";
		std::stringstream ss;
		for (uint32_t i = 0; i < m_print_depth; ++i) {
			ss << c_depth_figure;
		}
		//ss << '|';
		return ss.str();
	}

	WriteASTPass::Block WriteASTPass::writeln(std::string const& s) {
		m_os << depth_str() << s << '\n';
		return Block{*this};
	}

	void WriteASTPass::inc_depth() {
		++m_print_depth;
	}

	void WriteASTPass::dec_depth() {
		--m_print_depth;
	}

	void WriteASTPass::execute(
		std::ostream & p_os,
		ast::CompilationUnitDecl & p_root
	) {
		auto writer = WriteASTPass{p_os};
		writer.visit(p_root);
	}

//////////////////////////////////////////////////////////////////////////////////////////
/// WriteASTPass Constructor & Methods
//////////////////////////////////////////////////////////////////////////////////////////

	// Statements
	void WriteASTPass::visit(ast::Stmnt &) {
		writeln("Stmnt");
	}

	void WriteASTPass::visit(ast::CompoundStmnt & p_compound_stmnt) {
		auto const block = writeln("CompoundStmnt");
		traverse_compound_stmnt(p_compound_stmnt);
	}

	void WriteASTPass::visit(ast::EmptyStmnt &) {
		writeln("EmptyStmnt");
	}

	void WriteASTPass::visit(ast::ExprStmnt & p_expr_stmnt) {
		auto const block = writeln("ExprStmnt");
		traverse_expr_stmnt(p_expr_stmnt);
	}

	void WriteASTPass::visit(ast::DeclStmnt & p_decl_stmnt) {
		auto const block = writeln("DeclStmnt");
		traverse_decl_stmnt(p_decl_stmnt);
	}

	void WriteASTPass::visit(ast::IfStmnt & p_if_stmnt) {
		auto const block = writeln("IfStmnt");
		traverse_if_stmnt(p_if_stmnt);
	}

	void WriteASTPass::visit(ast::WhileStmnt & p_while_stmnt) {
		auto const block = writeln("WhileStmnt");
		traverse_while_stmnt(p_while_stmnt);
	}

	void WriteASTPass::visit(ast::BreakStmnt &) {
		writeln("BreakStmnt");
	}

	void WriteASTPass::visit(ast::ContinueStmnt &) {
		writeln("ContinueStmnt");
	}

	void WriteASTPass::visit(ast::ReturnStmnt & p_return_stmnt) {
		auto const block = writeln("ReturnStmnt");
		traverse_return_stmnt(p_return_stmnt);
	}


	// Declarations
	void WriteASTPass::visit(ast::Decl &) {
		writeln("Decl");
	}

	void WriteASTPass::visit(ast::CompilationUnitDecl & p_compilation_unit_decl) {
		auto const block = writeln("CompilationUnitDecl");
		traverse_compilation_unit_decl(p_compilation_unit_decl);
	}

	void WriteASTPass::visit(ast::ParamDecl & p_param_decl) {
		auto const block = writeln("ParamDecl: " + p_param_decl.name());
		traverse_param_decl(p_param_decl);
	}

	void WriteASTPass::visit(ast::FunctionDecl & p_function_decl) {
		auto const block = writeln("FunctionDecl: " + p_function_decl.name());
		traverse_function_decl(p_function_decl);
	}

	void WriteASTPass::visit(ast::VarDecl & p_var_decl) {
		auto const block = writeln("VarDecl: " + p_var_decl.name());
		traverse_var_decl(p_var_decl);
	}


	// Expressions
	void WriteASTPass::visit(ast::Expr &) {
		writeln("Expr");
	}

	void WriteASTPass::visit(ast::ConditionalExpr & p_conditional_expr) {
		auto const block = writeln("ConditionalExpr");
		traverse_conditional_expr(p_conditional_expr);
	}


	void WriteASTPass::visit(ast::BinaryExpr & p_binary_expr) {
		auto const block = writeln("BinaryExpr");
		traverse_binary_expr(p_binary_expr);
	}

	void WriteASTPass::visit(ast::LogicalOrExpr & p_logical_or_expr) {
		auto const block = writeln("LogicalOrExpr");
		traverse_logical_or_expr(p_logical_or_expr);
	}

	void WriteASTPass::visit(ast::LogicalAndExpr & p_logical_and_expr) {
		auto const block = writeln("LogicalAndExpr");
		traverse_logical_and_expr(p_logical_and_expr);
	}

	void WriteASTPass::visit(ast::BitOrExpr & p_bit_or_expr) {
		auto const block = writeln("BitOrExpr");
		traverse_bit_or_expr(p_bit_or_expr);
	}

	void WriteASTPass::visit(ast::BitXorExpr & p_bit_xor_expr) {
		auto const block = writeln("BitXorExpr");
		traverse_bit_xor_expr(p_bit_xor_expr);
	}

	void WriteASTPass::visit(ast::BitAndExpr & p_bit_and_expr) {
		auto const block = writeln("BitAndExpr");
		traverse_bit_and_expr(p_bit_and_expr);
	}

	void WriteASTPass::visit(ast::AddExpr & p_add_expr) {
		auto const block = writeln("AddExpr");
		traverse_add_expr(p_add_expr);
	}

	void WriteASTPass::visit(ast::SubtractExpr & p_subtract_expr) {
		auto const block = writeln("SubtractExpr");
		traverse_subtract_expr(p_subtract_expr);
	}

	void WriteASTPass::visit(ast::MultiplyExpr & p_multiply_expr) {
		auto const block = writeln("MultiplyExpr");
		traverse_multiply_expr(p_multiply_expr);
	}

	void WriteASTPass::visit(ast::DivideExpr & p_divide_expr) {
		auto const block = writeln("DivideExpr");
		traverse_divide_expr(p_divide_expr);
	}

	void WriteASTPass::visit(ast::ModuloExpr & p_modulo_expr) {
		auto const block = writeln("ModuloExpr");
		traverse_modulo_expr(p_modulo_expr);
	}

	void WriteASTPass::visit(ast::ShiftLeftExpr & p_shift_left_expr) {
		auto const block = writeln("ShiftLeftExpr");
		traverse_shift_left_expr(p_shift_left_expr);
	}

	void WriteASTPass::visit(ast::ShiftRightExpr & p_shift_right_expr) {
		auto const block = writeln("ShiftRightExpr");
		traverse_shift_right_expr(p_shift_right_expr);
	}

	void WriteASTPass::visit(ast::EqualityExpr & p_equality_expr) {
		auto const block = writeln("EqualityExpr");
		traverse_equality_expr(p_equality_expr);
	}

	void WriteASTPass::visit(ast::InequalityExpr & p_inequality_expr) {
		auto const block = writeln("InequalityExpr");
		traverse_inequality_expr(p_inequality_expr);
	}

	void WriteASTPass::visit(ast::LessThanExpr & p_less_than_expr) {
		auto const block = writeln("LessThanExpr");
		traverse_less_than_expr(p_less_than_expr);
	}

	void WriteASTPass::visit(ast::LessEqualsExpr & p_less_equals_expr) {
		auto const block = writeln("LessEqualsExpr");
		traverse_less_equals_expr(p_less_equals_expr);
	}

	void WriteASTPass::visit(ast::GreaterThanExpr & p_greater_than_expr) {
		auto const block = writeln("GreaterThanExpr");
		traverse_greater_than_expr(p_greater_than_expr);
	}

	void WriteASTPass::visit(ast::GreaterEqualsExpr & p_greater_equals_expr) {
		auto const block = writeln("GreaterEqualsExpr");
		traverse_greater_equals_expr(p_greater_equals_expr);
	}


	void WriteASTPass::visit(ast::BinaryAssignExpr & p_binary_assign_expr) {
		auto const block = writeln("BinaryAssignExpr");
		traverse_binary_assign_expr(p_binary_assign_expr);
	}

	void WriteASTPass::visit(ast::AssignExpr & p_assign_expr) {
		auto const block = writeln("AssignExpr");
		traverse_assign_expr(p_assign_expr);
	}

	void WriteASTPass::visit(ast::AddAssignExpr & p_add_assign_expr) {
		auto const block = writeln("AddAssignExpr");
		traverse_add_assign_expr(p_add_assign_expr);
	}

	void WriteASTPass::visit(ast::SubtractAssignExpr & p_subtract_assign_expr) {
		auto const block = writeln("SubtractAssignExpr");
		traverse_subtract_assign_expr(p_subtract_assign_expr);
	}

	void WriteASTPass::visit(ast::MultiplyAssignExpr & p_multiply_assign_expr) {
		auto const block = writeln("MultiplyAssignExpr");
		traverse_multiply_assign_expr(p_multiply_assign_expr);
	}

	void WriteASTPass::visit(ast::DivideAssignExpr & p_divide_assign_expr) {
		auto const block = writeln("DivideAssignExpr");
		traverse_divide_assign_expr(p_divide_assign_expr);
	}

	void WriteASTPass::visit(ast::ModuloAssignExpr & p_modulo_assign_expr) {
		auto const block = writeln("ModuloAssignExpr");
		traverse_modulo_assign_expr(p_modulo_assign_expr);
	}

	void WriteASTPass::visit(ast::LogicalOrAssignExpr & p_logical_or_assign_expr) {
		auto const block = writeln("LogicalOrAssignExpr");
		traverse_logical_or_assign_expr(p_logical_or_assign_expr);
	}

	void WriteASTPass::visit(ast::LogicalAndAssignExpr & p_logical_and_assign_expr) {
		auto const block = writeln("LogicalAndAssignExpr");
		traverse_logical_and_assign_expr(p_logical_and_assign_expr);
	}

	void WriteASTPass::visit(ast::BitOrAssignExpr & p_bit_or_assign_expr) {
		auto const block = writeln("BitOrAssignExpr");
		traverse_bit_or_assign_expr(p_bit_or_assign_expr);
	}

	void WriteASTPass::visit(ast::BitXorAssignExpr & p_bit_xor_assign_expr) {
		auto const block = writeln("BitXorAssignExpr");
		traverse_bit_xor_assign_expr(p_bit_xor_assign_expr);
	}

	void WriteASTPass::visit(ast::BitAndAssignExpr & p_bit_and_assign_expr) {
		auto const block = writeln("BitAndAssignExpr");
		traverse_bit_and_assign_expr(p_bit_and_assign_expr);
	}

	void WriteASTPass::visit(ast::ShiftLeftAssignExpr & p_shift_left_assign_expr) {
		auto const block = writeln("ShiftLeftAssignExpr");
		traverse_shift_left_assign_expr(p_shift_left_assign_expr);
	}

	void WriteASTPass::visit(ast::ShiftRightAssignExpr & p_shift_right_assign_expr) {
		auto const block = writeln("ShiftRightAssignExpr");
		traverse_shift_right_assign_expr(p_shift_right_assign_expr);
	}


	void WriteASTPass::visit(ast::BooleanExpr & p_boolean_expr) {
		using namespace std::string_literals;
		auto const block = writeln("BooleanExpr: " + (p_boolean_expr.value() ? "true"s : "false"s));
		traverse_boolean_expr(p_boolean_expr);
	}

	void WriteASTPass::visit(ast::CallExpr & p_call_expr) {
		auto const block = writeln("CallExpr");
		traverse_call_expr(p_call_expr);
	}

	void WriteASTPass::visit(ast::CharExpr & p_char_expr) {
		auto const block = writeln("CharExpr: " + p_char_expr.value());
		traverse_char_expr(p_char_expr);
	}

	void WriteASTPass::visit(ast::FloatExpr & p_float_expr) {
		auto const block = writeln("FloatExpr: " + std::to_string(p_float_expr.value()));
		traverse_float_expr(p_float_expr);
	}

	void WriteASTPass::visit(ast::IndexExpr & p_index_expr) {
		auto const block = writeln("IndexExpr");
		traverse_index_expr(p_index_expr);
	}

	void WriteASTPass::visit(ast::IntegerExpr & p_integer_expr) {
		auto const block = writeln("IntegerExpr: " + std::to_string(p_integer_expr.value()));
		traverse_integer_expr(p_integer_expr);
	}

	void WriteASTPass::visit(ast::NothingExpr &) {
		writeln("NothingExpr");
	}

	void WriteASTPass::visit(ast::StringExpr & p_string_expr) {
		using namespace std::string_literals;
		auto const block = writeln("StringExpr: "s + p_string_expr.value());
		traverse_string_expr(p_string_expr);
	}


	void WriteASTPass::visit(ast::UnaryExpr & p_unary_expr) {
		auto const block = writeln("UnaryExpr");
		traverse_unary_expr(p_unary_expr);
	}

	void WriteASTPass::visit(ast::BitNegateExpr & p_bit_negate_expr) {
		auto const block = writeln("BitNegateExpr");
		traverse_bit_negate_expr(p_bit_negate_expr);
	}

	void WriteASTPass::visit(ast::LogicalNegateExpr & p_logical_negate_expr) {
		auto const block = writeln("LogicalNegateExpr");
		traverse_logical_negate_expr(p_logical_negate_expr);
	}

	void WriteASTPass::visit(ast::PlusExpr & p_plus_expr) {
		auto const block = writeln("PlusExpr");
		traverse_plus_expr(p_plus_expr);
	}

	void WriteASTPass::visit(ast::MinusExpr & p_minus_expr) {
		auto const block = writeln("MinusExpr");
		traverse_minus_expr(p_minus_expr);
	}

	void WriteASTPass::visit(ast::IncrementExpr & p_increment_expr) {
		auto const block = writeln("IncrementExpr");
		traverse_increment_expr(p_increment_expr);
	}

	void WriteASTPass::visit(ast::DecrementExpr & p_decrement_expr) {
		auto const block = writeln("DecrementExpr");
		traverse_decrement_expr(p_decrement_expr);
	}

	void WriteASTPass::visit(ast::PostIncrementExpr & p_post_increment_expr) {
		auto const block = writeln("PostIncrementExpr");
		traverse_post_increment_expr(p_post_increment_expr);
	}

	void WriteASTPass::visit(ast::PostDecrementExpr & p_post_decrement_expr) {
		auto const block = writeln("PostDecrementExpr");
		traverse_post_decrement_expr(p_post_decrement_expr);
	}


	void WriteASTPass::visit(ast::VarExpr & p_var_expr) {
		auto const block = writeln("VarExpr: " + p_var_expr.name());
		traverse_var_expr(p_var_expr);
	}


	// Types
	void WriteASTPass::visit(ast::Type &) {
		writeln("Type");
	}

	void WriteASTPass::visit(ast::NothingType &) {
		writeln("NothingType");
	}

	void WriteASTPass::visit(ast::BuiltinType &) {
		writeln("BuiltinType");
	}

	void WriteASTPass::visit(ast::BoolType &) {
		writeln("BoolType");
	}

	void WriteASTPass::visit(ast::CharType &) {
		writeln("CharType");
	}

	void WriteASTPass::visit(ast::FloatingType &) {
		writeln("FloatingType");
	}

	void WriteASTPass::visit(ast::IntegerType &) {
		writeln("IntegerType");
	}
} // namespace cion
