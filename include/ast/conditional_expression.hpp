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

	private:
		std::unique_ptr<Expression> m_conditional;
		std::unique_ptr<Expression> m_then_expression;
		std::unique_ptr<Expression> m_else_expression;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_CONDITIONAL_EXPRESSION_HEADER
