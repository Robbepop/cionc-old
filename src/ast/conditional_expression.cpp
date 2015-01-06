#include "conditional_expression.hpp"

#include <utility>
#include <cassert>

namespace cion {
namespace ast {

	ConditionalExpression::ConditionalExpression(
		std::unique_ptr<Expression> condition,
		std::unique_ptr<Expression> then_expression,
		std::unique_ptr<Expression> else_expression
	):
		m_condition{std::move(condition)},
		m_then_expression{std::move(then_expression)},
		m_else_expression{std::move(else_expression)}
	{}

	Expression & ConditionalExpression::condition() {
		assert(m_condition != nullptr);
		return *m_condition;
	}

	Expression const& ConditionalExpression::condition() const {
		assert(m_condition != nullptr);
		return *m_condition;
	}

	Expression & ConditionalExpression::then_expression() {
		assert(m_then_expression != nullptr);
		return *m_then_expression;
	}

	Expression const& ConditionalExpression::then_expression() const {
		assert(m_then_expression != nullptr);
		return *m_then_expression;
	}

	Expression & ConditionalExpression::else_expression() {
		assert(m_else_expression != nullptr);
		return *m_else_expression;
	}

	Expression const& ConditionalExpression::else_expression() const {
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
