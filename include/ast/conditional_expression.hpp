#ifndef CION_AST_CONDITIONAL_EXPRESSION_HEADER
#define CION_AST_CONDITIONAL_EXPRESSION_HEADER

#include "ast/expression.hpp"

#include <memory>

namespace cion {
namespace ast {

	class ConditionalExpression : public Expression {
	public:
		ConditionalExpression(
			std::unique_ptr<Expression> conditional,
			std::unique_ptr<Expression> then_expression,
			std::unique_ptr<Expression> else_expression);

		Expression & condition();
		Expression const& condition() const;

		Expression & then_expr();
		Expression const& then_expr() const;

		Expression & else_expr();
		Expression const& else_expr() const;

		virtual void accept(MutatingCompilerPass & pass) override;
		virtual void accept(CompilerPass & pass) const override;

	private:
		std::unique_ptr<Expression> m_condition;
		std::unique_ptr<Expression> m_then_expression;
		std::unique_ptr<Expression> m_else_expression;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_CONDITIONAL_EXPRESSION_HEADER
