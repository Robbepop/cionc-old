#ifndef CION_AST_IF_STMNT_HEADER
#define CION_AST_IF_STMNT_HEADER

#include "ast/stmnt.hpp"
#include "ast/compound_stmnt.hpp"
#include "ast/empty_stmnt.hpp"
#include "ast/expr.hpp"

#include <memory>

namespace cion {
namespace ast {

	class IfStmnt : public Stmnt {
	public:
		IfStmnt(
			std::unique_ptr<Expr> condition,
			std::unique_ptr<CompoundStmnt> then_stmnt,
			std::unique_ptr<Stmnt> else_stmnt = {std::make_unique<EmptyStmnt>()});

		Expr & condition();
		Expr const& condition() const;

		Stmnt & then_stmnt();
		Stmnt const& then_stmnt() const;

		Stmnt & else_stmnt();
		Stmnt const& else_stmnt() const;

		virtual void accept(IASTVisitor & pass) override;

	private:
		std::unique_ptr<Expr> m_condition;
		std::unique_ptr<CompoundStmnt> m_then_stmnt;
		std::unique_ptr<Stmnt> m_else_stmnt;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_IF_STMNT_HEADER
