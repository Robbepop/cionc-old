#ifndef CION_AST_BINARY_EXPRESSION_HEADER
#define CION_AST_BINARY_EXPRESSION_HEADER

#include "ast/expression.hpp"
#include "token/token_type.hpp"

#include <cstdint>
#include <memory>

namespace cion {
namespace ast {
	class BinaryExpression : public Expression {
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
			std::unique_ptr<Expression> lhs,
			std::unique_ptr<Expression> rhs);

		BinaryExpression(
			TokenType const& tt,
			std::unique_ptr<Expression> lhs,
			std::unique_ptr<Expression> rhs);

		Operator & op();
		Operator const& op() const;

		Expression & lhs();
		Expression const& lhs() const;

		Expression & rhs();
		Expression const& rhs() const;

		virtual void accept(MutatingCompilerPass & pass) override;
		virtual void accept(CompilerPass & pass) const override;

	private:
		Operator m_op;
		std::unique_ptr<Expression> m_lhs;
		std::unique_ptr<Expression> m_rhs;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_BINARY_EXPRESSION_HEADER
