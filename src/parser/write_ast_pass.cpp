#include "parser/write_ast_pass.hpp"

#include <sstream>

namespace cion {

//////////////////////////////////////////////////////////////////////////////////////////
/// WriteASTPass Constructor & Methods
//////////////////////////////////////////////////////////////////////////////////////////

	WriteASTPass::WriteASTPass(std::ostream & os):
		m_pre_pass{*this},
		m_post_pass{*this},
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

	void WriteASTPass::writeln(std::string const& s) {
		m_os << depth_str() << s << '\n';
	}

	void WriteASTPass::inc_depth() {
		++m_print_depth;
	}

	void WriteASTPass::dec_depth() {
		--m_print_depth;
	}

	IASTVisitor & WriteASTPass::pre_pass() {
		return m_pre_pass;
	}

	IASTVisitor & WriteASTPass::post_pass() {
		return m_post_pass;
	}

	void WriteASTPass::execute(std::ostream & p_os, ast::CompilationUnitDecl & p_root) {
		auto pass = WriteASTPass{p_os};
		auto traverser = PrePostTraverser{pass};
		traverser.visit(p_root);
	}

//////////////////////////////////////////////////////////////////////////////////////////
/// WriteASTPass::PrePass Constructor & Methods
//////////////////////////////////////////////////////////////////////////////////////////

	WriteASTPass::PrePass::PrePass(WriteASTPass & p_handler):
		m_handler{p_handler}
	{}

	// Statements
	void WriteASTPass::PrePass::visit(ast::Stmnt &) {
		m_handler.writeln("Stmnt");
	}

	void WriteASTPass::PrePass::visit(ast::CompoundStmnt &) {
		m_handler.writeln("CompoundStmnt");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::EmptyStmnt &) {
		m_handler.writeln("EmptyStmnt");
	}

	void WriteASTPass::PrePass::visit(ast::ExprStmnt &) {
		m_handler.writeln("ExprStmnt");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::DeclStmnt &) {
		m_handler.writeln("DeclStmnt");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::IfStmnt &) {
		m_handler.writeln("IfStmnt");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::WhileStmnt &) {
		m_handler.writeln("WhileStmnt");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::BreakStmnt &) {
		m_handler.writeln("BreakStmnt");
	}

	void WriteASTPass::PrePass::visit(ast::ContinueStmnt &) {
		m_handler.writeln("ContinueStmnt");
	}

	void WriteASTPass::PrePass::visit(ast::ReturnStmnt &) {
		m_handler.writeln("ReturnStmnt");
		m_handler.inc_depth();
	}


	// Declarations
	void WriteASTPass::PrePass::visit(ast::Decl &) {
		m_handler.writeln("Decl");
	}

	void WriteASTPass::PrePass::visit(ast::CompilationUnitDecl &) {
		m_handler.writeln("CompilationUnitDecl");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::ParamDecl & p_param_decl) {
		m_handler.writeln("ParamDecl: " + p_param_decl.name());
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::FunctionDecl & p_function_decl) {
		m_handler.writeln("FunctionDecl: " + p_function_decl.name());
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::VarDecl & p_var_decl) {
		m_handler.writeln("VarDecl: " + p_var_decl.name());
		m_handler.inc_depth();
	}


	// Expressions
	void WriteASTPass::PrePass::visit(ast::Expr &) {
		m_handler.writeln("Expr");
	}

	void WriteASTPass::PrePass::visit(ast::ConditionalExpr &) {
		m_handler.writeln("ConditionalExpr");
		m_handler.inc_depth();
	}


	void WriteASTPass::PrePass::visit(ast::BinaryExpr &) {
		m_handler.writeln("BinaryExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::LogicalOrExpr &) {
		m_handler.writeln("LogicalOrExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::LogicalAndExpr &) {
		m_handler.writeln("LogicalAndExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::BitOrExpr &) {
		m_handler.writeln("BitOrExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::BitXorExpr &) {
		m_handler.writeln("BitXorExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::BitAndExpr &) {
		m_handler.writeln("BitAndExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::AddExpr &) {
		m_handler.writeln("AddExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::SubtractExpr &) {
		m_handler.writeln("SubtractExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::MultiplyExpr &) {
		m_handler.writeln("MultiplyExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::DivideExpr &) {
		m_handler.writeln("DivideExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::ModuloExpr &) {
		m_handler.writeln("ModuloExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::ShiftLeftExpr &) {
		m_handler.writeln("ShiftLeftExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::ShiftRightExpr &) {
		m_handler.writeln("ShiftRightExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::EqualityExpr &) {
		m_handler.writeln("EqualityExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::InequalityExpr &) {
		m_handler.writeln("InequalityExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::LessThanExpr &) {
		m_handler.writeln("LessThanExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::LessEqualsExpr &) {
		m_handler.writeln("LessEqualsExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::GreaterThanExpr &) {
		m_handler.writeln("GreaterThanExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::GreaterEqualsExpr &) {
		m_handler.writeln("GreaterEqualsExpr");
		m_handler.inc_depth();
	}


	void WriteASTPass::PrePass::visit(ast::BinaryAssignExpr &) {
		m_handler.writeln("BinaryAssignExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::AssignExpr &) {
		m_handler.writeln("AssignExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::AddAssignExpr &) {
		m_handler.writeln("AddAssignExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::SubtractAssignExpr &) {
		m_handler.writeln("SubtractAssignExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::MultiplyAssignExpr &) {
		m_handler.writeln("MultiplyAssignExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::DivideAssignExpr &) {
		m_handler.writeln("DivideAssignExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::ModuloAssignExpr &) {
		m_handler.writeln("ModuloAssignExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::LogicalOrAssignExpr &) {
		m_handler.writeln("LogicalOrAssignExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::LogicalAndAssignExpr &) {
		m_handler.writeln("LogicalAndAssignExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::BitOrAssignExpr &) {
		m_handler.writeln("BitOrAssignExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::BitXorAssignExpr &) {
		m_handler.writeln("BitXorAssignExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::BitAndAssignExpr &) {
		m_handler.writeln("BitAndAssignExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::ShiftLeftAssignExpr &) {
		m_handler.writeln("ShiftLeftAssignExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::ShiftRightAssignExpr &) {
		m_handler.writeln("ShiftRightAssignExpr");
		m_handler.inc_depth();
	}


	void WriteASTPass::PrePass::visit(ast::BooleanExpr & p_boolean_expr) {
		using namespace std::string_literals;
		m_handler.writeln("BooleanExpr: " + (p_boolean_expr.value() ? "true"s : "false"s));
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::CallExpr &) {
		m_handler.writeln("CallExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::CharExpr & p_char_expr) {
		m_handler.writeln("CharExpr: " + p_char_expr.value());
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::FloatExpr & p_float_expr) {
		m_handler.writeln("FloatExpr: " + std::to_string(p_float_expr.value()));
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::IndexExpr &) {
		m_handler.writeln("IndexExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::IntegerExpr & p_int_expr) {
		m_handler.writeln("IntegerExpr: " + std::to_string(p_int_expr.value()));
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::NothingExpr &) {
		m_handler.writeln("NothingExpr");
	}

	void WriteASTPass::PrePass::visit(ast::StringExpr & p_string_expr) {
		using namespace std::string_literals;
		m_handler.writeln("StringExpr: "s + p_string_expr.value());
		m_handler.inc_depth();
	}


	void WriteASTPass::PrePass::visit(ast::UnaryExpr &) {
		m_handler.writeln("UnaryExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::BitNegateExpr &) {
		m_handler.writeln("BitNegateExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::LogicalNegateExpr &) {
		m_handler.writeln("LogicalNegateExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::PlusExpr &) {
		m_handler.writeln("PlusExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::MinusExpr &) {
		m_handler.writeln("MinusExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::IncrementExpr &) {
		m_handler.writeln("IncrementExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::DecrementExpr &) {
		m_handler.writeln("DecrementExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::PostIncrementExpr &) {
		m_handler.writeln("PostIncrementExpr");
		m_handler.inc_depth();
	}

	void WriteASTPass::PrePass::visit(ast::PostDecrementExpr &) {
		m_handler.writeln("PostDecrementExpr");
		m_handler.inc_depth();
	}


	void WriteASTPass::PrePass::visit(ast::VarExpr & p_var_expr) {
		m_handler.writeln("VarExpr: " + p_var_expr.name());
		m_handler.inc_depth();
	}


	// Types
	void WriteASTPass::PrePass::visit(ast::Type &) {
		m_handler.writeln("Type");
	}

	void WriteASTPass::PrePass::visit(ast::NothingType &) {
		m_handler.writeln("NothingType");
	}

	void WriteASTPass::PrePass::visit(ast::BuiltinType &) {
		m_handler.writeln("BuiltinType");
	}

	void WriteASTPass::PrePass::visit(ast::BuiltinBoolType &) {
		m_handler.writeln("BuiltinBoolType");
	}

	void WriteASTPass::PrePass::visit(ast::BuiltinCharType &) {
		m_handler.writeln("BuiltinCharType");
	}

	void WriteASTPass::PrePass::visit(ast::BuiltinFloatType &) {
		m_handler.writeln("BuiltinFloatType");
	}

	void WriteASTPass::PrePass::visit(ast::BuiltinIntType &) {
		m_handler.writeln("BuiltinIntType");
	}

//////////////////////////////////////////////////////////////////////////////////////////
/// WriteASTPass::PostPass Constructor & Methods
//////////////////////////////////////////////////////////////////////////////////////////

	WriteASTPass::PostPass::PostPass(WriteASTPass & p_handler):
		m_handler{p_handler}
	{}

	// Statements
	void WriteASTPass::PostPass::visit(ast::Stmnt &) {}

	void WriteASTPass::PostPass::visit(ast::CompoundStmnt &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::EmptyStmnt &) {}

	void WriteASTPass::PostPass::visit(ast::ExprStmnt &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::DeclStmnt &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::IfStmnt &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::WhileStmnt &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::BreakStmnt &) {}

	void WriteASTPass::PostPass::visit(ast::ContinueStmnt &) {}

	void WriteASTPass::PostPass::visit(ast::ReturnStmnt &) {
		m_handler.dec_depth();
	}


	// Declarations
	void WriteASTPass::PostPass::visit(ast::Decl &) {}

	void WriteASTPass::PostPass::visit(ast::CompilationUnitDecl &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::ParamDecl &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::FunctionDecl &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::VarDecl &) {
		m_handler.dec_depth();
	}


	// Expressions
	void WriteASTPass::PostPass::visit(ast::Expr &) {}

	void WriteASTPass::PostPass::visit(ast::ConditionalExpr &) {
		m_handler.dec_depth();
	}


	void WriteASTPass::PostPass::visit(ast::BinaryExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::LogicalOrExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::LogicalAndExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::BitOrExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::BitXorExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::BitAndExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::AddExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::SubtractExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::MultiplyExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::DivideExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::ModuloExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::ShiftLeftExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::ShiftRightExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::EqualityExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::InequalityExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::LessThanExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::LessEqualsExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::GreaterThanExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::GreaterEqualsExpr &) {
		m_handler.dec_depth();
	}


	void WriteASTPass::PostPass::visit(ast::BinaryAssignExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::AssignExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::AddAssignExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::SubtractAssignExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::MultiplyAssignExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::DivideAssignExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::ModuloAssignExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::LogicalOrAssignExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::LogicalAndAssignExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::BitOrAssignExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::BitXorAssignExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::BitAndAssignExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::ShiftLeftAssignExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::ShiftRightAssignExpr &) {
		m_handler.dec_depth();
	}


	void WriteASTPass::PostPass::visit(ast::BooleanExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::CallExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::CharExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::FloatExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::IndexExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::IntegerExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::NothingExpr &) {}

	void WriteASTPass::PostPass::visit(ast::StringExpr &) {
		m_handler.dec_depth();
	}


	void WriteASTPass::PostPass::visit(ast::UnaryExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::BitNegateExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::LogicalNegateExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::PlusExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::MinusExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::IncrementExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::DecrementExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::PostIncrementExpr &) {
		m_handler.dec_depth();
	}

	void WriteASTPass::PostPass::visit(ast::PostDecrementExpr &) {
		m_handler.dec_depth();
	}


	void WriteASTPass::PostPass::visit(ast::VarExpr &) {
		m_handler.dec_depth();
	}


	// Types
	void WriteASTPass::PostPass::visit(ast::Type &) {}
	void WriteASTPass::PostPass::visit(ast::NothingType &) {}
	void WriteASTPass::PostPass::visit(ast::BuiltinType &) {}
	void WriteASTPass::PostPass::visit(ast::BuiltinBoolType &) {}
	void WriteASTPass::PostPass::visit(ast::BuiltinCharType &) {}
	void WriteASTPass::PostPass::visit(ast::BuiltinFloatType &) {}
	void WriteASTPass::PostPass::visit(ast::BuiltinIntType &) {}

} // namespace cion
