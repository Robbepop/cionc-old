#include "ast/index_expression.hpp"

namespace cion {
namespace ast {

	IndexExpression::IndexExpression(
		std::unique_ptr<Expression> expr,
		std::unique_ptr<ExpressionList> indices
	):
		m_expr{std::move(expr)},
		m_indices{std::move(indices)}
	{}

} // namespace ast
} // namespace cion
