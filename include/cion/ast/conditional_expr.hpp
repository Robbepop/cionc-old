#ifndef CION_AST_CONDITIONAL_EXPR_HEADER
#define CION_AST_CONDITIONAL_EXPR_HEADER

#include "cion/ast/expr.hpp"

#include <memory>

namespace cion {
namespace ast {

	class ConditionalExpr : public Expr {
	public:
		ConditionalExpr(
			std::unique_ptr<Expr> conditional,
			std::unique_ptr<Expr> then_expression,
			std::unique_ptr<Expr> else_expression);

		Expr & condition();
		Expr const& condition() const;

		Expr & then_expr();
		Expr const& then_expr() const;

		Expr & else_expr();
		Expr const& else_expr() const;

		virtual void accept(IASTVisitor & pass) override;

	private:
		std::unique_ptr<Expr> m_condition;
		std::unique_ptr<Expr> m_then_expression;
		std::unique_ptr<Expr> m_else_expression;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_CONDITIONAL_EXPR_HEADER
