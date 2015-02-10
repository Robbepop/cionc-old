#include "cion/ast/conditional_expr.hpp"

#include <utility>
#include <cassert>

namespace cion {
namespace ast {

	ConditionalExpr::ConditionalExpr(
		std::unique_ptr<Expr> condition,
		std::unique_ptr<Expr> then_expression,
		std::unique_ptr<Expr> else_expression
	):
		m_condition{std::move(condition)},
		m_then_expression{std::move(then_expression)},
		m_else_expression{std::move(else_expression)}
	{}

	Expr & ConditionalExpr::condition() {
		assert(m_condition != nullptr);
		return *m_condition;
	}

	Expr const& ConditionalExpr::condition() const {
		assert(m_condition != nullptr);
		return *m_condition;
	}

	Expr & ConditionalExpr::then_expr() {
		assert(m_then_expression != nullptr);
		return *m_then_expression;
	}

	Expr const& ConditionalExpr::then_expr() const {
		assert(m_then_expression != nullptr);
		return *m_then_expression;
	}

	Expr & ConditionalExpr::else_expr() {
		assert(m_else_expression != nullptr);
		return *m_else_expression;
	}

	Expr const& ConditionalExpr::else_expr() const {
		assert(m_else_expression != nullptr);
		return *m_else_expression;
	}

	void ConditionalExpr::accept(IASTVisitor & pass) {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
