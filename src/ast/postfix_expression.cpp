#include "ast/postfix_expression.hpp"

#include "cion_token_types.hpp"

#include <stdexcept>
#include <utility>
#include <cassert>

namespace cion {
namespace ast {

	PostfixExpression::Operator PostfixExpression::get_operator(
		TokenType const& tt
	) {
		using op = PostfixExpression::Operator;
		auto const& ctts = CionTokenTypes::get_instance();
		return
			tt == ctts.op_plus_plus   ? op::increment:
			tt == ctts.op_minus_minus ? op::decrement:
			throw std::runtime_error("can not convert this token type into an assignment operator.");
	}

	bool PostfixExpression::is_operator(
		TokenType const& tt
	) {
		auto const& ctts = CionTokenTypes::get_instance();
		return
			tt == ctts.op_plus_plus ||
			tt == ctts.op_minus_minus
			? true : false;
	}

	PostfixExpression::PostfixExpression(
		PostfixExpression::Operator op,
		std::unique_ptr<Expr> expr
	):
		m_op{op},
		m_expr{std::move(expr)}
	{}

	PostfixExpression::PostfixExpression(
		TokenType const& tt,
		std::unique_ptr<Expr> expr
	):
		PostfixExpression{get_operator(tt), std::move(expr)}
	{}

	PostfixExpression::Operator & PostfixExpression::op() {
		return m_op;
	}

	PostfixExpression::Operator const& PostfixExpression::op() const {
		return m_op;
	}

	Expr & PostfixExpression::expr() {
		assert(m_expr != nullptr);
		return *m_expr;
	}

	Expr const& PostfixExpression::expr() const {
		assert(m_expr != nullptr);
		return *m_expr;
	}

	void PostfixExpression::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void PostfixExpression::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
