#ifndef CION_AST_CALL_EXPR_HEADER
#define CION_AST_CALL_EXPR_HEADER

#include "ast/expr.hpp"

#include <string>
#include <vector>
#include <memory>

namespace cion {
namespace ast {
	class CallExpr : public Expr {
	public:
		CallExpr(
			std::unique_ptr<Expr> callee,
			std::vector<std::unique_ptr<Expr>> args = {});

		Expr & callee();
		Expr const& callee() const;

		std::vector<std::unique_ptr<Expr>> & args();
		std::vector<std::unique_ptr<Expr>> const& args() const;

		virtual void accept(CompilerPass & pass) override;

	private:
		std::unique_ptr<Expr> m_callee;
		std::vector<std::unique_ptr<Expr>> m_args;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_CALL_EXPR_HEADER
