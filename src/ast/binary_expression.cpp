#include "ast/binary_expression.hpp"

#include "cion_token_types.hpp"

#include <stdexcept>
#include <utility>

namespace cion {
namespace ast {

	BinaryExpression::Operator BinaryExpression::get_operator(
		TokenType const& tt
	) {
		using op = BinaryExpression::Operator;
		auto const& ctts = CionTokenTypes::get_instance();
		return
			tt == ctts.op_pipe_pipe           ? op::logical_or:
			tt == ctts.op_ampersand_ampersand ? op::logical_and:
			tt == ctts.op_pipe                ? op::inclusive_or:
			tt == ctts.op_caret               ? op::exclusive_or:
			tt == ctts.op_ampersand           ? op::bitwise_and:
			tt == ctts.op_equals_equals       ? op::equality:
			tt == ctts.op_not_equals          ? op::inequality:
			tt == ctts.op_less_than           ? op::less_than:
			tt == ctts.op_greater_than        ? op::greater_than:
			tt == ctts.op_less_equals         ? op::less_equals:
			tt == ctts.op_greater_equals      ? op::greater_equals:
			tt == ctts.op_plus                ? op::plus:
			tt == ctts.op_minus               ? op::minus:
			tt == ctts.op_star                ? op::multiplication:
			tt == ctts.op_slash               ? op::division:
			tt == ctts.op_percent             ? op::modulo:
			tt == ctts.op_left_left           ? op::shift_left:
			tt == ctts.op_right_right         ? op::shift_right:
			throw std::runtime_error("can not convert this token type into an assignment operator.");
	}

	bool BinaryExpression::is_operator(
		TokenType const& tt
	) {
		auto const& ctts = CionTokenTypes::get_instance();
		return
			tt == ctts.op_pipe_pipe ||
			tt == ctts.op_ampersand_ampersand ||
			tt == ctts.op_pipe ||
			tt == ctts.op_caret ||
			tt == ctts.op_ampersand ||
			tt == ctts.op_equals_equals ||
			tt == ctts.op_not_equals ||
			tt == ctts.op_less_than ||
			tt == ctts.op_greater_than ||
			tt == ctts.op_less_equals ||
			tt == ctts.op_greater_equals ||
			tt == ctts.op_plus ||
			tt == ctts.op_minus ||
			tt == ctts.op_star ||
			tt == ctts.op_slash ||
			tt == ctts.op_percent ||
			tt == ctts.op_left_left ||
			tt == ctts.op_right_right
			? true : false;
	}

	BinaryExpression::BinaryExpression(
		BinaryExpression::Operator op,
		std::unique_ptr<Expr> lhs,
		std::unique_ptr<Expr> rhs
	):
		m_op{op},
		m_lhs{std::move(lhs)},
		m_rhs{std::move(rhs)}
	{}

	BinaryExpression::BinaryExpression(
		TokenType const& tt,
		std::unique_ptr<Expr> lhs,
		std::unique_ptr<Expr> rhs
	):
		BinaryExpression{get_operator(tt), std::move(lhs), std::move(rhs)}
	{}

	BinaryExpression::Operator & BinaryExpression::op() {
		return m_op;
	}

	Expr & BinaryExpression::lhs() {
		assert(m_lhs != nullptr);
		return *m_lhs.get();
	}

	Expr & BinaryExpression::rhs() {
		assert(m_rhs != nullptr);
		return *m_rhs.get();
	}

	BinaryExpression::Operator const& BinaryExpression::op() const {
		return m_op;
	}

	Expr const& BinaryExpression::lhs() const {
		assert(m_lhs != nullptr);
		return *m_lhs;
	}

	Expr const& BinaryExpression::rhs() const {
		assert(m_rhs != nullptr);
		return *m_rhs.get();
	}

	void BinaryExpression::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void BinaryExpression::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
