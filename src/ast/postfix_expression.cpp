#include "ast/postfix_expression.hpp"

#include "cion_token_types.hpp"

#include <stdexcept>
#include <utility>

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
		std::unique_ptr<Expression> expr
	):
		m_op{op},
		m_expr{std::move(expr)}
	{}

	PostfixExpression::PostfixExpression(
		TokenType const& tt,
		std::unique_ptr<Expression> expr
	):
		PostfixExpression{get_operator(tt), std::move(expr)}
	{}

	void PostfixExpression::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void PostfixExpression::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
