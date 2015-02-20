#ifndef CION_AST_IF_STMNT_HEADER
#define CION_AST_IF_STMNT_HEADER

#include "cion/ast/stmnt.hpp"

#include <memory>

namespace cion {
namespace ast {
	class CompoundStmnt;
	class EmptyStmnt;
	class Expr;

	class IfStmnt : public Stmnt {
	public:
		IfStmnt(
			std::unique_ptr<Expr> p_condition,
			std::unique_ptr<CompoundStmnt> p_then_stmnt,
			std::unique_ptr<Stmnt> p_else_stmnt);

		IfStmnt(
			std::unique_ptr<Expr> p_condition,
			std::unique_ptr<CompoundStmnt> p_then_stmnt);

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
