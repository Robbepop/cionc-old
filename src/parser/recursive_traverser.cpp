#include "recursive_traverser.hpp"

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

//////////////////////////////////////////////////////////////////////////////////////////
/////// Constructor
//////////////////////////////////////////////////////////////////////////////////////////

	RecursiveTraverser::RecursiveTraverser(CompilerPass & p_pass):
		m_pass{p_pass}
	{}

//////////////////////////////////////////////////////////////////////////////////////////
/////// Visit Methods
//////////////////////////////////////////////////////////////////////////////////////////

	// Statements
	void RecursiveTraverser::visit(ast::Stmnt & s) {
		m_pass.visit(s);
		traverse(s);
	}

	void RecursiveTraverser::visit(ast::CompoundStmnt & s) {
		m_pass.visit(s);
		traverse(s);
	}

	void RecursiveTraverser::visit(ast::EmptyStmnt & s) {
		m_pass.visit(s);
		traverse(s);
	}

	void RecursiveTraverser::visit(ast::ExprStmnt & s) {
		m_pass.visit(s);
		traverse(s);
	}

	void RecursiveTraverser::visit(ast::IfStmnt & s) {
		m_pass.visit(s);
		traverse(s);
	}

	void RecursiveTraverser::visit(ast::WhileStmnt & s) {
		m_pass.visit(s);
		traverse(s);
	}

	void RecursiveTraverser::visit(ast::BreakStmnt & s) {
		m_pass.visit(s);
		traverse(s);
	}

	void RecursiveTraverser::visit(ast::ContinueStmnt & s) {
		m_pass.visit(s);
		traverse(s);
	}

	void RecursiveTraverser::visit(ast::ReturnStmnt & s) {
		m_pass.visit(s);
		traverse(s);
	}


	// Declarations
	void RecursiveTraverser::visit(ast::Decl & d) {
		m_pass.visit(d);
		traverse(d);
	}

	void RecursiveTraverser::visit(ast::CompilationUnitDecl & d) {
		m_pass.visit(d);
		traverse(d);
	}

	void RecursiveTraverser::visit(ast::ParamDecl & d) {
		m_pass.visit(d);
		traverse(d);
	}

	void RecursiveTraverser::visit(ast::FunctionDecl & d) {
		m_pass.visit(d);
		traverse(d);
	}

	void RecursiveTraverser::visit(ast::VarDecl & d) {
		m_pass.visit(d);
		traverse(d);
	}


	// Expressions
	void RecursiveTraverser::visit(ast::Expr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::ConditionalExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}


	void RecursiveTraverser::visit(ast::BinaryExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::LogicalOrExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::LogicalAndExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::BitOrExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::BitXorExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::BitAndExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::AddExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::SubtractExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::MultiplyExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::DivideExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::ModuloExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::ShiftLeftExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::ShiftRightExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::EqualityExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::InequalityExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::LessThanExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::LessEqualsExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::GreaterThanExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::GreaterEqualsExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}


	void RecursiveTraverser::visit(ast::BinaryAssignExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::AssignExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::AddAssignExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::SubtractAssignExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::MultiplyAssignExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::DivideAssignExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::ModuloAssignExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::LogicalOrAssignExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::LogicalAndAssignExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::BitOrAssignExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::BitXorAssignExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::BitAndAssignExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::ShiftLeftAssignExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::ShiftRightAssignExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}


	void RecursiveTraverser::visit(ast::BooleanExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::CallExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::CharExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::FloatExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::IndexExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::IntegerExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::NothingExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::StringExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}


	void RecursiveTraverser::visit(ast::UnaryExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::BitNegateExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::LogicalNegateExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::PlusExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::MinusExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::IncrementExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::DecrementExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::PostIncrementExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}

	void RecursiveTraverser::visit(ast::PostDecrementExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}


	void RecursiveTraverser::visit(ast::VarExpr & e) {
		m_pass.visit(e);
		traverse(e);
	}


	// Types
	void RecursiveTraverser::visit(ast::Type & t) {
		m_pass.visit(t);
		traverse(t);
	}

	void RecursiveTraverser::visit(ast::NothingType & t) {
		m_pass.visit(t);
		traverse(t);
	}

	void RecursiveTraverser::visit(ast::BuiltinType & t) {
		m_pass.visit(t);
		traverse(t);
	}

	void RecursiveTraverser::visit(ast::BuiltinBoolType & t) {
		m_pass.visit(t);
		traverse(t);
	}

	void RecursiveTraverser::visit(ast::BuiltinCharType & t) {
		m_pass.visit(t);
		traverse(t);
	}

	void RecursiveTraverser::visit(ast::BuiltinFloatType & t) {
		m_pass.visit(t);
		traverse(t);
	}

	void RecursiveTraverser::visit(ast::BuiltinIntType & t) {
		m_pass.visit(t);
		traverse(t);
	}


//////////////////////////////////////////////////////////////////////////////////////////
/////// Traverse Methods
//////////////////////////////////////////////////////////////////////////////////////////

	// Statements
	void RecursiveTraverser::traverse(ast::Stmnt &) {}

	void RecursiveTraverser::traverse(ast::CompoundStmnt & s) {
		for (auto&& stmnt : s.statements()) {
			stmnt->accept(*this);
		}
	}

	void RecursiveTraverser::traverse(ast::EmptyStmnt &) {}

	void RecursiveTraverser::traverse(ast::ExprStmnt & s) {
		s.expr().accept(*this);
	}

	void RecursiveTraverser::traverse(ast::IfStmnt & s) {
		s.condition().accept(*this);
		s.then_stmnt().accept(*this);
		s.else_stmnt().accept(*this);
	}

	void RecursiveTraverser::traverse(ast::WhileStmnt & s) {
		s.condition().accept(*this);
		s.body().accept(*this);
	}

	void RecursiveTraverser::traverse(ast::BreakStmnt &) {}

	void RecursiveTraverser::traverse(ast::ContinueStmnt &) {}

	void RecursiveTraverser::traverse(ast::ReturnStmnt & s) {
		s.expr().accept(*this);
	}


	// Declarations
	void RecursiveTraverser::traverse(ast::Decl & d) {

	}

	void RecursiveTraverser::traverse(ast::CompilationUnitDecl & d) {

	}

	void RecursiveTraverser::traverse(ast::ParamDecl & d) {

	}

	void RecursiveTraverser::traverse(ast::FunctionDecl & d) {

	}

	void RecursiveTraverser::traverse(ast::VarDecl & d) {

	}


	// Expressions
	void RecursiveTraverser::traverse(ast::Expr & e) {

	}

	void RecursiveTraverser::traverse(ast::ConditionalExpr & e) {

	}


	void RecursiveTraverser::traverse(ast::BinaryExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::LogicalOrExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::LogicalAndExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::BitOrExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::BitXorExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::BitAndExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::AddExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::SubtractExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::MultiplyExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::DivideExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::ModuloExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::ShiftLeftExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::ShiftRightExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::EqualityExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::InequalityExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::LessThanExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::LessEqualsExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::GreaterThanExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::GreaterEqualsExpr & e) {

	}


	void RecursiveTraverser::traverse(ast::BinaryAssignExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::AssignExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::AddAssignExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::SubtractAssignExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::MultiplyAssignExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::DivideAssignExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::ModuloAssignExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::LogicalOrAssignExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::LogicalAndAssignExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::BitOrAssignExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::BitXorAssignExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::BitAndAssignExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::ShiftLeftAssignExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::ShiftRightAssignExpr & e) {

	}


	void RecursiveTraverser::traverse(ast::BooleanExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::CallExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::CharExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::FloatExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::IndexExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::IntegerExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::NothingExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::StringExpr & e) {

	}


	void RecursiveTraverser::traverse(ast::UnaryExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::BitNegateExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::LogicalNegateExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::PlusExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::MinusExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::IncrementExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::DecrementExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::PostIncrementExpr & e) {

	}

	void RecursiveTraverser::traverse(ast::PostDecrementExpr & e) {

	}


	void RecursiveTraverser::traverse(ast::VarExpr & e) {

	}


	// Types
	void RecursiveTraverser::traverse(ast::Type & t) {

	}

	void RecursiveTraverser::traverse(ast::NothingType & t) {

	}

	void RecursiveTraverser::traverse(ast::BuiltinType & t) {

	}

	void RecursiveTraverser::traverse(ast::BuiltinBoolType & t) {

	}

	void RecursiveTraverser::traverse(ast::BuiltinCharType & t) {

	}

	void RecursiveTraverser::traverse(ast::BuiltinFloatType & t) {

	}

	void RecursiveTraverser::traverse(ast::BuiltinIntType & t) {

	}


} // namespace cion
