#include "ast/assignment_expression.hpp"

#include "cion_token_types.hpp"

#include <stdexcept>
#include <utility>

namespace cion {
namespace ast {

	AssignmentExpression::Operator AssignmentExpression::get_operator(
		TokenType const& tt
	) {
		using op = AssignmentExpression::Operator;
		auto const& ctts = CionTokenTypes::get_instance();
		return
			tt == ctts.op_equals             ? op::equals:
			tt == ctts.op_plus_equals        ? op::plus_equals:
			tt == ctts.op_minus_equals       ? op::minus_equals:
			tt == ctts.op_star_equals        ? op::multiply_equals:
			tt == ctts.op_slash_equals       ? op::divide_equals:
			tt == ctts.op_percent_equals     ? op::modulo_equals:
			tt == ctts.op_pipe_equals        ? op::inclusive_or_equals:
			tt == ctts.op_caret_equals       ? op::exclusive_or_equals:
			tt == ctts.op_ampersand_equals   ? op::bitwise_and_equals:
			tt == ctts.op_left_left_equals   ? op::shift_left_equals:
			tt == ctts.op_right_right_equals ? op::shift_right_equals:
			throw std::runtime_error("can not convert this token type into an assignment operator.");
	}

	bool AssignmentExpression::is_operator(
		TokenType const& tt
	) {
		auto const& ctts = CionTokenTypes::get_instance();
		return
			tt == ctts.op_equals ||
			tt == ctts.op_plus_equals ||
			tt == ctts.op_minus_equals ||
			tt == ctts.op_star_equals ||
			tt == ctts.op_slash_equals ||
			tt == ctts.op_percent_equals ||
			tt == ctts.op_pipe_equals ||
			tt == ctts.op_caret_equals ||
			tt == ctts.op_ampersand_equals ||
			tt == ctts.op_left_left_equals ||
			tt == ctts.op_right_right_equals
			? true : false;
	}

	AssignmentExpression::AssignmentExpression(
		AssignmentExpression::Operator op,
		std::unique_ptr<Expression> lhs,
		std::unique_ptr<Expression> rhs
	):
		m_op{op},
		m_lhs{std::move(lhs)},
		m_rhs{std::move(rhs)}
	{}

	AssignmentExpression::AssignmentExpression(
		TokenType const& tt,
		std::unique_ptr<Expression> lhs,
		std::unique_ptr<Expression> rhs
	):
		AssignmentExpression{get_operator(tt), std::move(lhs), std::move(rhs)}
	{}

} // namespace ast
} // namespace cion
