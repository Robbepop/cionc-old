#ifndef CION_AST_UNARY_EXPRESSION_HEADER
#define CION_AST_UNARY_EXPRESSION_HEADER

#include "ast/expression.hpp"
#include "token/token_type.hpp"

#include <cstdint>
#include <memory>

namespace cion {
namespace ast {
	class UnaryExpression : public Expression {
	public:
		enum class Operator : int8_t {
			bit_negate,
			logical_negate,
			plus,
			minus,
			increment,
			decrement
		};

		static Operator get_operator(TokenType const& tt);

		static bool is_operator(TokenType const& tt);

		UnaryExpression(
			Operator op,
			std::unique_ptr<Expression> expr);

		UnaryExpression(
			TokenType const& tt,
			std::unique_ptr<Expression> expr);

	private:
		Operator m_op;
		std::unique_ptr<Expression> m_expr;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_UNARY_EXPRESSION_HEADER
