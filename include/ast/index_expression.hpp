#ifndef CION_AST_INDEX_EXPRESSION_HEADER
#define CION_AST_INDEX_EXPRESSION_HEADER

#include "ast/expression.hpp"
#include "ast/expression_list.hpp"

#include <string>
#include <memory>

namespace cion {
namespace ast {
	class IndexExpression : public Expression {
	public:
		IndexExpression(
			std::unique_ptr<Expression> expr,
			std::unique_ptr<ExpressionList> indices);

		Expression & expr();
		Expression const& expr() const;

		ExpressionList & indices();
		ExpressionList const& indices() const;

		virtual void accept(MutatingCompilerPass & pass) override;
		virtual void accept(CompilerPass & pass) const override;

	private:
		std::unique_ptr<Expression> m_expr;
		std::unique_ptr<ExpressionList> m_indices;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_INDEX_EXPRESSION_HEADER
