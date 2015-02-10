#ifndef CION_AST_INDEX_EXPR_HEADER
#define CION_AST_INDEX_EXPR_HEADER

#include "ast/expr.hpp"

#include <string>
#include <vector>
#include <memory>

namespace cion {
namespace ast {
	class IndexExpr : public Expr {
	public:
		IndexExpr(
			std::unique_ptr<Expr> expr,
			std::vector<std::unique_ptr<Expr>> indices);

		Expr & expr();
		Expr const& expr() const;

		std::vector<std::unique_ptr<Expr>> & indices();
		std::vector<std::unique_ptr<Expr>> const& indices() const;

		virtual void accept(IASTVisitor & pass) override;

	private:
		std::unique_ptr<Expr> m_expr;
		std::vector<std::unique_ptr<Expr>> m_indices;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_INDEX_EXPR_HEADER
