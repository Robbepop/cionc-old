#ifndef CION_AST_ASSIGNMENT_EXPRESSION_HEADER
#define CION_AST_ASSIGNMENT_EXPRESSION_HEADER

#include "ast/expr.hpp"
#include "token/token_type.hpp"

#include <cstdint>
#include <memory>

namespace cion {
namespace ast {
	class AssignmentExpression : public Expr {
	public:
		enum class Operator : int8_t {
			equals,
			plus_equals,
			minus_equals,
			multiply_equals,
			divide_equals,
			modulo_equals,
			inclusive_or_equals,
			exclusive_or_equals,
			bitwise_and_equals,
			shift_left_equals,
			shift_right_equals
		};

		static Operator get_operator(TokenType const& tt);

		static bool is_operator(TokenType const& tt);

		AssignmentExpression(
			Operator op,
			std::unique_ptr<Expr> lhs,
			std::unique_ptr<Expr> rhs);

		AssignmentExpression(
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

#endif // CION_AST_ASSIGNMENT_EXPRESSION_HEADER
