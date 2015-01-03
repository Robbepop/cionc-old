#include "ast/unary_expression.hpp"

#include "cion_token_types.hpp"

#include <stdexcept>
#include <utility>

namespace cion {
namespace ast {

	UnaryExpression::Operator UnaryExpression::get_operator(
		TokenType const& tt
	) {
		using op = UnaryExpression::Operator;
		auto const& ctts = CionTokenTypes::get_instance();
		return
			tt == ctts.op_tilde       ? op::bit_negate:
			tt == ctts.op_exclam_mark ? op::logical_negate:
			tt == ctts.op_pipe        ? op::plus:
			tt == ctts.op_minus       ? op::minus:
			tt == ctts.op_plus_plus   ? op::increment:
			tt == ctts.op_minus_minus ? op::decrement:
			throw std::runtime_error("can not convert this token type into an assignment operator.");
	}

	bool UnaryExpression::is_operator(
		TokenType const& tt
	) {
		auto const& ctts = CionTokenTypes::get_instance();
		return
			tt == ctts.op_tilde ||
			tt == ctts.op_exclam_mark ||
			tt == ctts.op_pipe ||
			tt == ctts.op_minus ||
			tt == ctts.op_plus_plus ||
			tt == ctts.op_minus_minus
			? true : false;
	}

	UnaryExpression::UnaryExpression(
		UnaryExpression::Operator op,
		std::unique_ptr<Expression> expr
	):
		m_op{op},
		m_expr{std::move(expr)}
	{}

	UnaryExpression::UnaryExpression(
		TokenType const& tt,
		std::unique_ptr<Expression> expr
	):
		UnaryExpression{get_operator(tt), std::move(expr)}
	{}

} // namespace ast
} // namespace cion
