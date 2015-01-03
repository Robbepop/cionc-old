#include "ast/expression_statement.hpp"

#include <utility>

namespace cion {
namespace ast {

	ExpressionStatement::ExpressionStatement(
		std::unique_ptr<Expression> expr
	):
		m_expr{std::move(expr)}
	{}

} // namespace ast
} // namespace cion
