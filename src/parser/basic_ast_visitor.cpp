#include "parser/basic_ast_visitor.hpp"

#include "ast/all.hpp"

namespace cion {

	// Statements
	void BasicASTVisitor::visit(ast::Stmnt &) {}

	void BasicASTVisitor::visit(ast::CompoundStmnt & s) {
		visit(dynamic_cast<ast::Stmnt &>(s)); }

	void BasicASTVisitor::visit(ast::EmptyStmnt & s) {
		visit(static_cast<ast::Stmnt &>(s)); }

	void BasicASTVisitor::visit(ast::ExprStmnt & s) {
		visit(static_cast<ast::Stmnt &>(s)); }

	void BasicASTVisitor::visit(ast::DeclStmnt & s) {
		visit(static_cast<ast::Stmnt &>(s)); }

	void BasicASTVisitor::visit(ast::IfStmnt & s) {
		visit(static_cast<ast::Stmnt &>(s)); }

	void BasicASTVisitor::visit(ast::WhileStmnt & s) {
		visit(static_cast<ast::Stmnt &>(s)); }

	void BasicASTVisitor::visit(ast::BreakStmnt & s) {
		visit(static_cast<ast::Stmnt &>(s)); }

	void BasicASTVisitor::visit(ast::ContinueStmnt & s) {
		visit(static_cast<ast::Stmnt &>(s)); }

	void BasicASTVisitor::visit(ast::ReturnStmnt & s) {
		visit(static_cast<ast::Stmnt &>(s)); }


	// Declarations
	void BasicASTVisitor::visit(ast::Decl &) {}

	void BasicASTVisitor::visit(ast::CompilationUnitDecl & d) {
		visit(static_cast<ast::Decl &>(d)); }

	void BasicASTVisitor::visit(ast::ParamDecl & d) {
		visit(static_cast<ast::Decl &>(d)); }

	void BasicASTVisitor::visit(ast::FunctionDecl & d) {
		visit(static_cast<ast::Decl &>(d)); }

	void BasicASTVisitor::visit(ast::VarDecl & d) {
		visit(static_cast<ast::Decl &>(d)); }


	// Expressions
	void BasicASTVisitor::visit(ast::Expr & e) {
		visit(static_cast<ast::Stmnt &>(e)); }

	void BasicASTVisitor::visit(ast::ConditionalExpr & e) {
		visit(static_cast<ast::Expr &>(e)); }


	void BasicASTVisitor::visit(ast::BinaryExpr & e) {
		visit(static_cast<ast::Expr &>(e)); }

	void BasicASTVisitor::visit(ast::LogicalOrExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void BasicASTVisitor::visit(ast::LogicalAndExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void BasicASTVisitor::visit(ast::BitOrExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void BasicASTVisitor::visit(ast::BitXorExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void BasicASTVisitor::visit(ast::BitAndExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void BasicASTVisitor::visit(ast::AddExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void BasicASTVisitor::visit(ast::SubtractExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void BasicASTVisitor::visit(ast::MultiplyExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void BasicASTVisitor::visit(ast::DivideExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void BasicASTVisitor::visit(ast::ModuloExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void BasicASTVisitor::visit(ast::ShiftLeftExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void BasicASTVisitor::visit(ast::ShiftRightExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void BasicASTVisitor::visit(ast::EqualityExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void BasicASTVisitor::visit(ast::InequalityExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void BasicASTVisitor::visit(ast::LessThanExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void BasicASTVisitor::visit(ast::LessEqualsExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void BasicASTVisitor::visit(ast::GreaterThanExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void BasicASTVisitor::visit(ast::GreaterEqualsExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }


	void BasicASTVisitor::visit(ast::BinaryAssignExpr & e) {
		visit(static_cast<ast::BinaryExpr &>(e)); }

	void BasicASTVisitor::visit(ast::AssignExpr & e) {
		visit(static_cast<ast::BinaryAssignExpr &>(e)); }

	void BasicASTVisitor::visit(ast::AddAssignExpr & e) {
		visit(static_cast<ast::BinaryAssignExpr &>(e)); }

	void BasicASTVisitor::visit(ast::SubtractAssignExpr & e) {
		visit(static_cast<ast::BinaryAssignExpr &>(e)); }

	void BasicASTVisitor::visit(ast::MultiplyAssignExpr & e) {
		visit(static_cast<ast::BinaryAssignExpr &>(e)); }

	void BasicASTVisitor::visit(ast::DivideAssignExpr & e) {
		visit(static_cast<ast::BinaryAssignExpr &>(e)); }

	void BasicASTVisitor::visit(ast::ModuloAssignExpr & e) {
		visit(static_cast<ast::BinaryAssignExpr &>(e)); }

	void BasicASTVisitor::visit(ast::LogicalOrAssignExpr & e) {
		visit(static_cast<ast::BinaryAssignExpr &>(e)); }

	void BasicASTVisitor::visit(ast::LogicalAndAssignExpr & e) {
		visit(static_cast<ast::BinaryAssignExpr &>(e)); }

	void BasicASTVisitor::visit(ast::BitOrAssignExpr & e) {
		visit(static_cast<ast::BinaryAssignExpr &>(e)); }

	void BasicASTVisitor::visit(ast::BitXorAssignExpr & e) {
		visit(static_cast<ast::BinaryAssignExpr &>(e)); }

	void BasicASTVisitor::visit(ast::BitAndAssignExpr & e) {
		visit(static_cast<ast::BinaryAssignExpr &>(e)); }

	void BasicASTVisitor::visit(ast::ShiftLeftAssignExpr & e) {
		visit(static_cast<ast::BinaryAssignExpr &>(e)); }

	void BasicASTVisitor::visit(ast::ShiftRightAssignExpr & e) {
		visit(static_cast<ast::BinaryAssignExpr &>(e)); }


	void BasicASTVisitor::visit(ast::BooleanExpr & e) {
		visit(static_cast<ast::Expr &>(e)); }

	void BasicASTVisitor::visit(ast::CallExpr & e) {
		visit(static_cast<ast::Expr &>(e)); }

	void BasicASTVisitor::visit(ast::CharExpr & e) {
		visit(static_cast<ast::Expr &>(e)); }

	void BasicASTVisitor::visit(ast::FloatExpr & e) {
		visit(static_cast<ast::Expr &>(e)); }

	void BasicASTVisitor::visit(ast::IndexExpr & e) {
		visit(static_cast<ast::Expr &>(e)); }

	void BasicASTVisitor::visit(ast::IntegerExpr & e) {
		visit(static_cast<ast::Expr &>(e)); }

	void BasicASTVisitor::visit(ast::NothingExpr & e) {
		visit(static_cast<ast::Expr &>(e)); }

	void BasicASTVisitor::visit(ast::StringExpr & e) {
		visit(static_cast<ast::Expr &>(e)); }


	void BasicASTVisitor::visit(ast::UnaryExpr & e) {
		visit(static_cast<ast::Expr &>(e)); }

	void BasicASTVisitor::visit(ast::BitNegateExpr & e) {
		visit(static_cast<ast::UnaryExpr &>(e)); }

	void BasicASTVisitor::visit(ast::LogicalNegateExpr & e) {
		visit(static_cast<ast::UnaryExpr &>(e)); }

	void BasicASTVisitor::visit(ast::PlusExpr & e) {
		visit(static_cast<ast::UnaryExpr &>(e)); }

	void BasicASTVisitor::visit(ast::MinusExpr & e) {
		visit(static_cast<ast::UnaryExpr &>(e)); }

	void BasicASTVisitor::visit(ast::IncrementExpr & e) {
		visit(static_cast<ast::UnaryExpr &>(e)); }

	void BasicASTVisitor::visit(ast::DecrementExpr & e) {
		visit(static_cast<ast::UnaryExpr &>(e)); }

	void BasicASTVisitor::visit(ast::PostIncrementExpr & e) {
		visit(static_cast<ast::UnaryExpr &>(e)); }

	void BasicASTVisitor::visit(ast::PostDecrementExpr & e) {
		visit(static_cast<ast::UnaryExpr &>(e)); }


	void BasicASTVisitor::visit(ast::VarExpr & e) {
		visit(static_cast<ast::Expr &>(e)); }


	// Types
	void BasicASTVisitor::visit(ast::Type &) {}

	void BasicASTVisitor::visit(ast::NothingType & t) {
		visit(static_cast<ast::Type &>(t)); }

	void BasicASTVisitor::visit(ast::BuiltinType & t) {
		visit(static_cast<ast::Type &>(t)); }

	void BasicASTVisitor::visit(ast::BuiltinBoolType & t) {
		visit(static_cast<ast::BuiltinType &>(t)); }

	void BasicASTVisitor::visit(ast::BuiltinCharType & t) {
		visit(static_cast<ast::BuiltinType &>(t)); }

	void BasicASTVisitor::visit(ast::BuiltinFloatType & t) {
		visit(static_cast<ast::BuiltinType &>(t)); }

	void BasicASTVisitor::visit(ast::BuiltinIntType & t) {
		visit(static_cast<ast::BuiltinType &>(t)); }


} // namespace cion
