#include "ast/expr_stmnt.hpp"

#include <utility>
#include <cassert>

namespace cion {
namespace ast {

	ExprStmnt::ExprStmnt(
		std::unique_ptr<Expr> expr
	):
		m_expr{std::move(expr)}
	{}

	Expr & ExprStmnt::expr() {
		assert(m_expr != nullptr);
		return *m_expr;
	}

	Expr const& ExprStmnt::expr() const {
		assert(m_expr != nullptr);
		return *m_expr;
	}

	void ExprStmnt::accept(CompilerPass & pass) {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
