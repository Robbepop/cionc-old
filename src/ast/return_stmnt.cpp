#include "ast/return_stmnt.hpp"
#include "ast/nothing_expr.hpp"

#include <utility>
#include <cassert>

namespace cion {
namespace ast {

	ReturnStmnt::ReturnStmnt(
		std::unique_ptr<Expr> expr
	):
		m_expr{std::move(expr)}
	{}

	Expr & ReturnStmnt::expr() {
		assert(m_expr != nullptr);
		return *m_expr;
	}

	Expr const& ReturnStmnt::expr() const {
		assert(m_expr != nullptr);
		return *m_expr;
	}

	void ReturnStmnt::accept(CompilerPass & pass) {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
