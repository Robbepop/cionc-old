#ifndef CION_AST_BINARY_EXPRESSION_HEADER
#define CION_AST_BINARY_EXPRESSION_HEADER

#include "ast/expr.hpp"
#include "token/token_type.hpp"

#include <cstdint>
#include <memory>

namespace cion {
namespace ast {
	class BinaryExpression : public Expr {
	public:
		enum class Operator : int8_t {
			logical_or,
			logical_and,
			inclusive_or,
			exclusive_or,
			bitwise_and,
			equality,
			inequality,
			less_than,
			greater_than,
			less_equals,
			greater_equals,
			plus,
			minus,
			multiplication,
			division,
			modulo,
			shift_left,
			shift_right
		};

		static Operator get_operator(TokenType const& tt);

		static bool is_operator(TokenType const& tt);

		BinaryExpression(
			Operator op,
			std::unique_ptr<Expr> lhs,
			std::unique_ptr<Expr> rhs);

		BinaryExpression(
			TokenType const& tt,
			std::unique_ptr<Expr> lhs,
			std::unique_ptr<Expr> rhs);

		Operator & op();
		Operator const& op() const;

		Expr & lhs();
		Expr const& lhs() const;

		Expr & rhs();
		Expr const& rhs() const;

		virtual void accept(MutatingCompilerPass & pass) override;
		virtual void accept(CompilerPass & pass) const override;

	private:
		Operator m_op;
		std::unique_ptr<Expr> m_lhs;
		std::unique_ptr<Expr> m_rhs;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_BINARY_EXPRESSION_HEADER
