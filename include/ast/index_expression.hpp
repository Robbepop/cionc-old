#ifndef CION_AST_INDEX_EXPRESSION_HEADER
#define CION_AST_INDEX_EXPRESSION_HEADER

#include "ast/expr.hpp"
#include "ast/expression_list.hpp"

#include <string>
#include <memory>

namespace cion {
namespace ast {
	class IndexExpression : public Expr {
	public:
		IndexExpression(
			std::unique_ptr<Expr> expr,
			std::unique_ptr<ExpressionList> indices);

		Expr & expr();
		Expr const& expr() const;

		ExpressionList & indices();
		ExpressionList const& indices() const;

		virtual void accept(MutatingCompilerPass & pass) override;
		virtual void accept(CompilerPass & pass) const override;

	private:
		std::unique_ptr<Expr> m_expr;
		std::unique_ptr<ExpressionList> m_indices;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_INDEX_EXPRESSION_HEADER
