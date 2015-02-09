#ifndef CION_AST_WHILE_STMNT_HEADER
#define CION_AST_WHILE_STMNT_HEADER

#include "ast/stmnt.hpp"
#include "ast/compound_stmnt.hpp"
#include "ast/expr.hpp"

#include <memory>

namespace cion {
namespace ast {

	class WhileStmnt : public Stmnt {
	public:
		WhileStmnt(
			std::unique_ptr<Expr> condition,
			std::unique_ptr<CompoundStmnt> body);

		Expr & condition();
		Expr const& condition() const;

		CompoundStmnt & body();
		CompoundStmnt const& body() const;

		virtual void accept(CompilerPass & pass) override;

	private:
		std::unique_ptr<Expr> m_condition;
		std::unique_ptr<CompoundStmnt> m_body;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_WHILE_STMNT_HEADER
