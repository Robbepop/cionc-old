#ifndef CION_AST_UNARY_EXPRESSION_HEADER
#define CION_AST_UNARY_EXPRESSION_HEADER

#include "ast/expr.hpp"
#include "token/token_type.hpp"

#include <cstdint>
#include <memory>

namespace cion {
namespace ast {
	class UnaryExpression : public Expr {
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
			std::unique_ptr<Expr> expr);

		UnaryExpression(
			TokenType const& tt,
			std::unique_ptr<Expr> expr);

		Operator & op();
		Operator const& op() const;

		Expr & expr();
		Expr const& expr() const;

		virtual void accept(MutatingCompilerPass & pass) override;
		virtual void accept(CompilerPass & pass) const override;

	private:
		Operator m_op;
		std::unique_ptr<Expr> m_expr;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_UNARY_EXPRESSION_HEADER
