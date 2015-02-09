#include "ast/call_expr.hpp"

#include <cassert>

namespace cion {
namespace ast {

	CallExpr::CallExpr(
		std::unique_ptr<Expr> callee,
		std::vector<std::unique_ptr<Expr>> args
	):
		m_callee{std::move(callee)},
		m_args{std::move(args)}
	{}

	Expr & CallExpr::callee() {
		assert(m_callee != nullptr);
		return *m_callee;
	}

	Expr const& CallExpr::callee() const {
		assert(m_callee != nullptr);
		return *m_callee;
	}

	std::vector<std::unique_ptr<Expr>> & CallExpr::args() {
		return m_args;
	}

	std::vector<std::unique_ptr<Expr>> const& CallExpr::args() const {
		return m_args;
	}

	void CallExpr::accept(CompilerPass & pass) {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
