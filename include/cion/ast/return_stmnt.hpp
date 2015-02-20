#ifndef CION_AST_RETURN_STMNT_HEADER
#define CION_AST_RETURN_STMNT_HEADER

#include "cion/ast/stmnt.hpp"

#include <memory>

namespace cion {
namespace ast {
	class Expr;

	class ReturnStmnt : public Stmnt {
	public:
		explicit ReturnStmnt(std::unique_ptr<Expr> expr);
		ReturnStmnt();

		Expr & expr();
		Expr const& expr() const;

		virtual void accept(IASTVisitor & pass) override;

	private:
		std::unique_ptr<Expr> m_expr;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_RETURN_STMNT_HEADER
