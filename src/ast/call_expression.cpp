#include "ast/call_expression.hpp"

namespace cion {
namespace ast {

	CallExpression::CallExpression(
		std::unique_ptr<Expression> callee,
		std::unique_ptr<ExpressionList> args
	):
		m_callee{std::move(callee)},
		m_args{std::move(args)}
	{}

	CallExpression::CallExpression(
		std::unique_ptr<Expression> callee
	):
		CallExpression{std::move(callee), nullptr}
	{}

} // namespace ast
} // namespace cion
