#ifndef CION_AST_EXPRESSION_STATEMENT_HEADER
#define CION_AST_EXPRESSION_STATEMENT_HEADER

#include "ast/statement.hpp"
#include "ast/expr.hpp"

#include <memory>

namespace cion {
namespace ast {

	class ExpressionStatement : public Statement {
	public:
		ExpressionStatement(std::unique_ptr<Expr> expr);

		Expr & expr();
		Expr const& expr() const;

		virtual void accept(MutatingCompilerPass & pass) override;
		virtual void accept(CompilerPass & pass) const override;

	private:
		std::unique_ptr<Expr> m_expr;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_EXPRESSION_STATEMENT_HEADER
