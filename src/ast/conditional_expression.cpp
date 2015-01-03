#include "conditional_expression.hpp"

#include <utility>

namespace cion {
namespace ast {

	ConditionalExpression::ConditionalExpression(
		std::unique_ptr<Expression> conditional,
		std::unique_ptr<Expression> then_expression,
		std::unique_ptr<Expression> else_expression
	):
		m_conditional{std::move(conditional)},
		m_then_expression{std::move(then_expression)},
		m_else_expression{std::move(else_expression)}
	{}

} // namespace ast
} // namespace cion
