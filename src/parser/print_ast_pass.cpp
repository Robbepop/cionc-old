#include "parser/print_ast_pass.hpp"

#include <algorithm>
#include <limits>

namespace cion {

//////////////////////////////////////////////////////////////////////////////////////////
/// Helper Struct
//////////////////////////////////////////////////////////////////////////////////////////

	PrintASTPass::PrintBlock::PrintBlock(PrintASTPass & print_ast_pass):
		m_print_ast_pass{print_ast_pass}
	{
		inc_depth();
	}

	PrintASTPass::PrintBlock::~PrintBlock() {
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
		static const auto c_depth_figure = "--";
		std::stringstream ss;
		for (uint32_t i = 0; i < m_depth; ++i) {
			ss << c_depth_figure;
		}
		ss << s;
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

	void PrintASTPass::visit(ast::AssignmentExpression const& assignment_expression) {
		print_line("assignment expression");
		{
			auto block = create_block();
			assignment_expression.lhs().accept(*this);
			assignment_expression.rhs().accept(*this);
		}
	}

	void PrintASTPass::visit(ast::BinaryExpression const& binary_expression) {
		print_line("binary expression");
	}

	void PrintASTPass::visit(ast::BooleanLiteral const& boolean_literal) {
		print_line("boolean literal");
	}

	void PrintASTPass::visit(ast::BreakStatement const& break_statement) {
		print_line("break statement");
	}

	void PrintASTPass::visit(ast::CallExpression const& call_expression) {
		print_line("call expression");
	}

	void PrintASTPass::visit(ast::CharLiteral const& char_literal) {
		print_line("char literal");
	}

	void PrintASTPass::visit(ast::CompilationUnit const& compilation_unit) {
		print_line("compilation unit");
		{
			auto block = create_block();
			for (auto&& node : compilation_unit.statements()) {
				node->accept(*this);
			}
		}
	}

	void PrintASTPass::visit(ast::CompoundStatement const& compound_statement) {
		print_line("compound statement");
	}

	void PrintASTPass::visit(ast::ConditionalExpression const& conditional_expression) {
		print_line("conditional expression");
	}

	void PrintASTPass::visit(ast::ContinueStatement const& continue_statement) {
		print_line("continue statement");
	}

	void PrintASTPass::visit(ast::EmptyStatement const& empty_statement) {
		print_line("empty statement");
	}

	void PrintASTPass::visit(ast::Expression const& expression) {
		print_line("expression");
	}

	void PrintASTPass::visit(ast::ExpressionList const& expression_list) {
		print_line("expression list");
	}

	void PrintASTPass::visit(ast::ExpressionStatement const& expression_statement) {
		print_line("expression statement");
	}

	void PrintASTPass::visit(ast::FloatLiteral const& float_literal) {
		print_line("float literal");
	}

	void PrintASTPass::visit(ast::FunctionDefinitionStatement const& function_definition_statement) {
		print_line("function definition statement");
	}

	void PrintASTPass::visit(ast::IfStatement const& if_statement) {
		print_line("if statement");
	}

	void PrintASTPass::visit(ast::IndexExpression const& index_expression) {
		print_line("index expression");
	}

	void PrintASTPass::visit(ast::IntegerLiteral const& integer_literal) {
		print_line("integer literal");
	}

	void PrintASTPass::visit(ast::LogicalParameter const& logical_parameter) {
		print_line("logical parameter");
	}

	void PrintASTPass::visit(ast::LogicalParameterPack const& logical_parameter_pack) {
		print_line("logical parameter pack");
	}

	void PrintASTPass::visit(ast::Node const& node) {
		print_line("node");
	}

	void PrintASTPass::visit(ast::NothingExpression const& nothing_expression) {
		print_line("node");
	}

	void PrintASTPass::visit(ast::NothingType const& nothing_type) {
		print_line("node");
	}

	void PrintASTPass::visit(ast::PostfixExpression const& postfix_expression) {
		print_line("postfix expression");
	}

	void PrintASTPass::visit(ast::PrimitiveTypeBool const& primitive_type_bool) {
		print_line("primitive type bool");
	}

	void PrintASTPass::visit(ast::PrimitiveTypeChar const& primitive_type_char) {
		print_line("primitive type char");
	}

	void PrintASTPass::visit(ast::PrimitiveTypeFloat const& primitive_type_float) {
		print_line("primitive type float");
	}

	void PrintASTPass::visit(ast::PrimitiveTypeInt const& primitive_type_int) {
		print_line("primitive type int");
	}

	void PrintASTPass::visit(ast::ReturnStatement const& return_statement) {
		print_line("return statement");
	}

	void PrintASTPass::visit(ast::Statement const& statement) {
		print_line("statement");
	}

	void PrintASTPass::visit(ast::StatementList const& statement_list) {
		print_line("statement list");
	}

	void PrintASTPass::visit(ast::StringLiteral const& string_literal) {
		print_line("string literal");
	}

	void PrintASTPass::visit(ast::TypeSpecifier const& type_specifier) {
		print_line("type specifier");
	}

	void PrintASTPass::visit(ast::UnaryExpression const& unary_expression) {
		print_line("unary expression");
	}

	void PrintASTPass::visit(ast::VariableDeclarationStatement const& variable_declaration_statement) {
		print_line("variable declaration statement");
	}

	void PrintASTPass::visit(ast::VariableExpression const& variable_expression) {
		print_line("variable expression");
	}

	void PrintASTPass::visit(ast::WhileStatement const& while_statement) {
		print_line("while statement");
	}

} // namespace cion
