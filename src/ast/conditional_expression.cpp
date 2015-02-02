#include "conditional_expression.hpp"

#include <utility>
#include <cassert>

namespace cion {
namespace ast {

	ConditionalExpression::ConditionalExpression(
		std::unique_ptr<Expr> condition,
		std::unique_ptr<Expr> then_expression,
		std::unique_ptr<Expr> else_expression
	):
		m_condition{std::move(condition)},
		m_then_expression{std::move(then_expression)},
		m_else_expression{std::move(else_expression)}
	{}

	Expr & ConditionalExpression::condition() {
		assert(m_condition != nullptr);
		return *m_condition;
	}

	Expr const& ConditionalExpression::condition() const {
		assert(m_condition != nullptr);
		return *m_condition;
	}

	Expr & ConditionalExpression::then_expr() {
		assert(m_then_expression != nullptr);
		return *m_then_expression;
	}

	Expr const& ConditionalExpression::then_expr() const {
		assert(m_then_expression != nullptr);
		return *m_then_expression;
	}

	Expr & ConditionalExpression::else_expr() {
		assert(m_else_expression != nullptr);
		return *m_else_expression;
	}

	Expr const& ConditionalExpression::else_expr() const {
		assert(m_else_expression != nullptr);
		return *m_else_expression;
	}

	void ConditionalExpression::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void ConditionalExpression::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
