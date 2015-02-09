#include "compiler_pass.hpp"

#include "ast/binary_assign_expr.hpp"
#include "ast/binary_expr.hpp"
#include "ast/boolean_expr.hpp"
#include "ast/break_stmnt.hpp"
#include "ast/call_expr.hpp"
#include "ast/char_expr.hpp"
#include "ast/compilation_unit_decl.hpp"
#include "ast/compound_stmnt.hpp"
#include "ast/conditional_expr.hpp"
#include "ast/continue_stmnt.hpp"
#include "ast/empty_stmnt.hpp"
#include "ast/expr.hpp"
#include "ast/expr_stmnt.hpp"
#include "ast/float_expr.hpp"
#include "ast/function_decl.hpp"
#include "ast/if_stmnt.hpp"
#include "ast/index_expr.hpp"
#include "ast/integer_expr.hpp"
#include "ast/param_decl.hpp"
#include "ast/nothing_expr.hpp"
#include "ast/nothing_type.hpp"
#include "ast/builtin_type.hpp"
#include "ast/return_stmnt.hpp"
#include "ast/stmnt.hpp"
#include "ast/string_expr.hpp"
#include "ast/type.hpp"
#include "ast/unary_expr.hpp"
#include "ast/var_decl.hpp"
#include "ast/var_expr.hpp"
#include "ast/while_stmnt.hpp"

namespace cion {

	// Statements
	void CompilerPass::visit(ast::Stmnt &) {}

	void CompilerPass::visit(ast::CompoundStmnt & s) {
		visit(dynamic_cast<ast::Stmnt &>(s)); }

	void CompilerPass::visit(ast::EmptyStmnt & s) {
		visit(static_cast<ast::Stmnt &>(s)); }

	void CompilerPass::visit(ast::ExprStmnt & s) {
		visit(static_cast<ast::Stmnt &>(s)); }

	void CompilerPass::visit(ast::IfStmnt & s) {
		visit(static_cast<ast::Stmnt &>(s)); }

	void CompilerPass::visit(ast::WhileStmnt & s) {
		visit(static_cast<ast::Stmnt &>(s)); }

	void CompilerPass::visit(ast::BreakStmnt & s) {
		visit(static_cast<ast::Stmnt &>(s)); }

	void CompilerPass::visit(ast::ContinueStmnt & s) {
		visit(static_cast<ast::Stmnt &>(s)); }

	void CompilerPass::visit(ast::ReturnStmnt & s) {
		visit(static_cast<ast::Stmnt &>(s)); }


	// Declarations
	void CompilerPass::visit(ast::Decl &) {}

	void CompilerPass::visit(ast::CompilationUnitDecl & d) {
		visit(static_cast<ast::Decl &>(d)); }

	void CompilerPass::visit(ast::ParamDecl & d) {
		visit(static_cast<ast::Decl &>(d)); }

	void CompilerPass::visit(ast::FunctionDecl & d) {
		visit(static_cast<ast::Decl &>(d)); }

	void CompilerPass::visit(ast::VarDecl & d) {
		visit(static_cast<ast::Decl &>(d)); }


	// Expressions
	void CompilerPass::visit(ast::Expr & e) {
		visit(static_cast<ast::Stmnt &>(e)); }

	void CompilerPass::visit(ast::ConditionalExpr & e) {
		visit(static_cast<ast::Expr &>(e)); }


	void CompilerPass::visit(ast::BinaryExpr & e) {
		visit(static_cast<ast::Expr &>(e)); }

	void CompilerPass::visit(ast::LogicalOrExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void CompilerPass::visit(ast::LogicalAndExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void CompilerPass::visit(ast::BitOrExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void CompilerPass::visit(ast::BitXorExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void CompilerPass::visit(ast::BitAndExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void CompilerPass::visit(ast::AddExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void CompilerPass::visit(ast::SubtractExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void CompilerPass::visit(ast::MultiplyExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void CompilerPass::visit(ast::DivideExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void CompilerPass::visit(ast::ModuloExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void CompilerPass::visit(ast::ShiftLeftExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void CompilerPass::visit(ast::ShiftRightExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void CompilerPass::visit(ast::EqualityExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void CompilerPass::visit(ast::InequalityExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void CompilerPass::visit(ast::LessThanExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void CompilerPass::visit(ast::LessEqualsExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void CompilerPass::visit(ast::GreaterThanExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void CompilerPass::visit(ast::GreaterEqualsExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }


	void CompilerPass::visit(ast::BinaryAssignExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void CompilerPass::visit(ast::AssignExpr & e) {
		visit(static_cast<ast::BinaryAssignExpr &>(e)); }

	void CompilerPass::visit(ast::AddAssignExpr & e) {
		visit(static_cast<ast::BinaryAssignExpr &>(e)); }

	void CompilerPass::visit(ast::SubtractAssignExpr & e) {
		visit(static_cast<ast::BinaryAssignExpr &>(e)); }

	void CompilerPass::visit(ast::MultiplyAssignExpr & e) {
		visit(static_cast<ast::BinaryAssignExpr &>(e)); }

	void CompilerPass::visit(ast::DivideAssignExpr & e) {
		visit(static_cast<ast::BinaryAssignExpr &>(e)); }

	void CompilerPass::visit(ast::ModuloAssignExpr & e) {
		visit(static_cast<ast::BinaryAssignExpr &>(e)); }

	void CompilerPass::visit(ast::LogicalOrAssignExpr & e) {
		visit(static_cast<ast::BinaryAssignExpr &>(e)); }

	void CompilerPass::visit(ast::LogicalAndAssignExpr & e) {
		visit(static_cast<ast::BinaryAssignExpr &>(e)); }

	void CompilerPass::visit(ast::BitOrAssignExpr & e) {
		visit(static_cast<ast::BinaryAssignExpr &>(e)); }

	void CompilerPass::visit(ast::BitXorAssignExpr & e) {
		visit(static_cast<ast::BinaryAssignExpr &>(e)); }

	void CompilerPass::visit(ast::BitAndAssignExpr & e) {
		visit(static_cast<ast::BinaryAssignExpr &>(e)); }

	void CompilerPass::visit(ast::ShiftLeftAssignExpr & e) {
		visit(static_cast<ast::BinaryAssignExpr &>(e)); }

	void CompilerPass::visit(ast::ShiftRightAssignExpr & e) {
		visit(static_cast<ast::BinaryAssignExpr &>(e)); }


	void CompilerPass::visit(ast::BooleanExpr & e) {
		visit(static_cast<ast::Expr &>(e)); }

	void CompilerPass::visit(ast::CallExpr & e) {
		visit(static_cast<ast::Expr &>(e)); }

	void CompilerPass::visit(ast::CharExpr & e) {
		visit(static_cast<ast::Expr &>(e)); }

	void CompilerPass::visit(ast::FloatExpr & e) {
		visit(static_cast<ast::Expr &>(e)); }

	void CompilerPass::visit(ast::IndexExpr & e) {
		visit(static_cast<ast::Expr &>(e)); }

	void CompilerPass::visit(ast::IntegerExpr & e) {
		visit(static_cast<ast::Expr &>(e)); }

	void CompilerPass::visit(ast::NothingExpr & e) {
		visit(static_cast<ast::Expr &>(e)); }

	void CompilerPass::visit(ast::StringExpr & e) {
		visit(static_cast<ast::Expr &>(e)); }


	void CompilerPass::visit(ast::UnaryExpr & e) {
		visit(static_cast<ast::Expr &>(e)); }

	void CompilerPass::visit(ast::BitNegateExpr & e) {
		visit(static_cast<ast::UnaryExpr &>(e)); }

	void CompilerPass::visit(ast::LogicalNegateExpr & e) {
		visit(static_cast<ast::UnaryExpr &>(e)); }

	void CompilerPass::visit(ast::PlusExpr & e) {
		visit(static_cast<ast::UnaryExpr &>(e)); }

	void CompilerPass::visit(ast::MinusExpr & e) {
		visit(static_cast<ast::UnaryExpr &>(e)); }

	void CompilerPass::visit(ast::IncrementExpr & e) {
		visit(static_cast<ast::UnaryExpr &>(e)); }

	void CompilerPass::visit(ast::DecrementExpr & e) {
		visit(static_cast<ast::UnaryExpr &>(e)); }

	void CompilerPass::visit(ast::PostIncrementExpr & e) {
		visit(static_cast<ast::UnaryExpr &>(e)); }

	void CompilerPass::visit(ast::PostDecrementExpr & e) {
		visit(static_cast<ast::UnaryExpr &>(e)); }


	void CompilerPass::visit(ast::VarExpr & e) {
		visit(static_cast<ast::Expr &>(e)); }


	// Types
	void CompilerPass::visit(ast::Type &) {}

	void CompilerPass::visit(ast::NothingType & t) {
		visit(static_cast<ast::Type &>(t)); }

	void CompilerPass::visit(ast::BuiltinType & t) {
		visit(static_cast<ast::Type &>(t)); }

	void CompilerPass::visit(ast::BuiltinBoolType & t) {
		visit(static_cast<ast::BuiltinType &>(t)); }

	void CompilerPass::visit(ast::BuiltinCharType & t) {
		visit(static_cast<ast::BuiltinType &>(t)); }

	void CompilerPass::visit(ast::BuiltinFloatType & t) {
		visit(static_cast<ast::BuiltinType &>(t)); }

	void CompilerPass::visit(ast::BuiltinIntType & t) {
		visit(static_cast<ast::BuiltinType &>(t)); }


} // namespace cion
