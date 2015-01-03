#include "ast/expression_list.hpp"

#include <utility>

namespace cion {
namespace ast {

	ExpressionList::ExpressionList(
		std::vector<std::unique_ptr<Expression>> expressions
	):
		m_expressions{std::move(expressions)}
	{}

	ExpressionList::ExpressionList() :
		m_expressions{}
	{}

} // namespace ast
} // namespace cion
