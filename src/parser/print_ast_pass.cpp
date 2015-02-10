#include "cion/parser/print_ast_pass.hpp"

#include <algorithm>
#include <limits>
#include <sstream>

namespace cion {

//////////////////////////////////////////////////////////////////////////////////////////
/// Helper Struct
//////////////////////////////////////////////////////////////////////////////////////////

	PrintASTPass::PrintBlock::PrintBlock(PrintASTPass & print_ast_pass):
		m_print_ast_pass{print_ast_pass}
	{
		inc_depth();
	}

	PrintASTPass::PrintBlock::~PrintBlock() noexcept {
		dec_depth();
	}

	void PrintASTPass::PrintBlock::inc_depth() {
		std::min(++m_print_ast_pass.m_depth, std::numeric_limits<uint32_t>::max());
	}

	void PrintASTPass::PrintBlock::dec_depth() {
		std::max(--m_print_ast_pass.m_depth, std::numeric_limits<uint32_t>::min());
	}

//////////////////////////////////////////////////////////////////////////////////////////
/// Visitor Constructor
//////////////////////////////////////////////////////////////////////////////////////////

	PrintASTPass::PrintASTPass(std::ostream & os):
		m_os{os}
	{}

//////////////////////////////////////////////////////////////////////////////////////////
/// Helper methods for printing and generating strings for printing.
//////////////////////////////////////////////////////////////////////////////////////////

	PrintASTPass::PrintBlock PrintASTPass::create_block() {
		return PrintBlock(*this);
	}

	std::string PrintASTPass::gen_line(std::string const& s) {
		static const auto c_depth_figure = "----";
		std::stringstream ss;
		for (uint32_t i = 0; i < m_depth; ++i) {
			ss << c_depth_figure;
		}
		ss << '|' << s;
		return ss.str();
	}

	void PrintASTPass::print_line(std::string const& s) {
		m_os << gen_line(s) << '\n';
	}

	void PrintASTPass::print(std::string const& s) {
		m_os << gen_line(s);
	}

//////////////////////////////////////////////////////////////////////////////////////////
/// Visitor Methods
//////////////////////////////////////////////////////////////////////////////////////////

	void PrintASTPass::visit(ast::BinaryAssignExpr & assignment_expr) {
		print_line("assignment expr");
		{
			auto block = create_block();
			assignment_expr.lhs().accept(*this);
			assignment_expr.rhs().accept(*this);
		}
	}

	void PrintASTPass::visit(ast::BinaryExpr & binary_expr) {
		print_line("binary expr");
		{
			auto block = create_block();
			binary_expr.lhs().accept(*this);
			binary_expr.rhs().accept(*this);
		}
	}

	void PrintASTPass::visit(ast::BooleanExpr & boolean_expr) {
		std::string bool_str = boolean_expr.value() ? "true" : "false";
		print_line("boolean expr: " + bool_str);
	}

	void PrintASTPass::visit(ast::BreakStmnt & break_stmnt) {
		print_line("break stmnt");
		std::ignore = break_stmnt;
	}

	void PrintASTPass::visit(ast::CallExpr & call_expr) {
		print_line("call expr");
		{
			auto block = create_block();
			call_expr.callee().accept(*this);
			for (auto&& arg : call_expr.args()) {
				arg->accept(*this);
			}
			//call_expr.args().accept(*this);
		}
	}

	void PrintASTPass::visit(ast::CharExpr & char_expr) {
		print_line(std::string("char expr: ") + char_expr.value());
	}

	void PrintASTPass::visit(ast::CompilationUnitDecl & compilation_unit) {
		print_line("compilation unit decl");
		{
			auto block = create_block();
			for (auto&& node : compilation_unit.decls()) {
				node->accept(*this);
			}
		}
	}

	void PrintASTPass::visit(ast::CompoundStmnt & compound_stmnt) {
		print_line("compound stmnt");
		{
			auto block = create_block();
			for (auto&& stmnt : compound_stmnt.statements()) {
				stmnt->accept(*this);
			}
		}
	}

	void PrintASTPass::visit(ast::ConditionalExpr & conditional_expr) {
		print_line("conditional expr");
		{
			auto block = create_block();
			conditional_expr.condition().accept(*this);
			conditional_expr.then_expr().accept(*this);
			conditional_expr.else_expr().accept(*this);
		}
	}

	void PrintASTPass::visit(ast::ContinueStmnt & continue_stmnt) {
		print_line("continue stmnt");
		std::ignore = continue_stmnt;
	}

	void PrintASTPass::visit(ast::Decl & decl) {
		print_line("decl");
		std::ignore = decl;
	}

	void PrintASTPass::visit(ast::EmptyStmnt & empty_stmnt) {
		print_line("empty stmnt");
		std::ignore = empty_stmnt;
	}

	void PrintASTPass::visit(ast::Expr & expr) {
		print_line("expr");
		std::ignore = expr;
	}

	void PrintASTPass::visit(ast::ExprStmnt & expr_stmnt) {
		print_line("expr stmnt");
		{
			auto block = create_block();
			expr_stmnt.expr().accept(*this);
		}
	}

	void PrintASTPass::visit(ast::FloatExpr & float_expr) {
		print_line("float expr: " + std::to_string(float_expr.value()));
	}

	void PrintASTPass::visit(ast::FunctionDecl & function_decl) {
		print_line("function decl: " + function_decl.name());
		{
			auto block = create_block();
			for (auto&& param : function_decl.params()) {
				param->accept(*this);
			}
			function_decl.return_type().accept(*this);
			function_decl.body().accept(*this);
		}
	}

	void PrintASTPass::visit(ast::IfStmnt & if_stmnt) {
		print_line("if stmnt");
		{
			auto block = create_block();
			if_stmnt.condition().accept(*this);
			if_stmnt.then_stmnt().accept(*this);
			if_stmnt.else_stmnt().accept(*this);
		}
	}

	void PrintASTPass::visit(ast::IndexExpr & index_expr) {
		print_line("index expr");
		{
			auto block = create_block();
			index_expr.expr().accept(*this);
			for (auto&& index : index_expr.indices()) {
				index->accept(*this);
			}
		}
	}

	void PrintASTPass::visit(ast::IntegerExpr & integer_expr) {
		print_line("integer expr: " + std::to_string(integer_expr.value()));
	}

	void PrintASTPass::visit(ast::ParamDecl & param_decl) {
		print_line("param decl: " + param_decl.name());
		{
			auto block = create_block();
			param_decl.type().accept(*this);
		}
	}

	void PrintASTPass::visit(ast::NothingExpr & nothing_expr) {
		print_line("nothing expr");
		std::ignore = nothing_expr;
	}

	void PrintASTPass::visit(ast::NothingType & nothing_type) {
		print_line("nothing type");
		std::ignore = nothing_type;
	}

	void PrintASTPass::visit(ast::BuiltinBoolType & builtin_bool_type) {
		print_line("builtin int type");
		std::ignore = builtin_bool_type;
	}

	void PrintASTPass::visit(ast::BuiltinCharType & builtin_char_type) {
		print_line("builtin char type");
		std::ignore = builtin_char_type;
	}

	void PrintASTPass::visit(ast::BuiltinFloatType & builtin_float_type) {
		print_line("builtin float type");
		// TODO print float width
		std::ignore = builtin_float_type;
	}

	void PrintASTPass::visit(ast::BuiltinIntType & builtin_int_type) {
		print_line("builtin int type");
		// TODO print int width and signed flag
		std::ignore = builtin_int_type;
	}

	void PrintASTPass::visit(ast::ReturnStmnt & return_stmnt) {
		print_line("return stmnt");
		{
			auto block = create_block();
			return_stmnt.expr().accept(*this);
		}
	}

	void PrintASTPass::visit(ast::Stmnt & stmnt) {
		print_line("stmnt");
		std::ignore = stmnt;
	}

	void PrintASTPass::visit(ast::StringExpr & string_expr) {
		print_line("string expr: " + string_expr.value());
	}

	void PrintASTPass::visit(ast::Type & type_specifier) {
		print_line("type");
		std::ignore = type_specifier;
	}

	void PrintASTPass::visit(ast::UnaryExpr & unary_expr) {
		print_line("unary expr"); // TODO print operator
		{
			auto block = create_block();
			unary_expr.expr().accept(*this);
		}
	}

	void PrintASTPass::visit(ast::VarDecl & var_decl) {
		print_line("var decl: " + var_decl.name());
		{
			auto block = create_block();
			var_decl.type().accept(*this);
			var_decl.expr().accept(*this);
		}
	}

	void PrintASTPass::visit(ast::VarExpr & var_expr) {
		print_line("var expr: " + var_expr.name());
	}

	void PrintASTPass::visit(ast::WhileStmnt & while_stmnt) {
		print_line("while stmnt");
		{
			auto block = create_block();
			while_stmnt.condition().accept(*this);
			while_stmnt.body().accept(*this);
		}
	}

} // namespace cion
