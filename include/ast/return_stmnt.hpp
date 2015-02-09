#ifndef CION_AST_RETURN_STMNT_HEADER
#define CION_AST_RETURN_STMNT_HEADER

#include "ast/stmnt.hpp"
#include "ast/expr.hpp"
#include "ast/nothing_expr.hpp"

#include <memory>

namespace cion {
namespace ast {

	class ReturnStmnt : public Stmnt {
	public:
		ReturnStmnt(
			std::unique_ptr<Expr> expr = {std::make_unique<NothingExpr>()});

		Expr & expr();
		Expr const& expr() const;

		virtual void accept(CompilerPass & pass) override;

	private:
		std::unique_ptr<Expr> m_expr;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_RETURN_STMNT_HEADER
