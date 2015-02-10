#include "ast/if_stmnt.hpp"

#include <utility>
#include <cassert>
#include <memory>

namespace cion {
namespace ast {

	IfStmnt::IfStmnt(
		std::unique_ptr<Expr> condition,
		std::unique_ptr<CompoundStmnt> then_stmnt,
		std::unique_ptr<Stmnt> else_stmnt
	):
		m_condition{std::move(condition)},
		m_then_stmnt{std::move(then_stmnt)},
		m_else_stmnt{std::move(else_stmnt)}
	{}

	Expr & IfStmnt::condition() {
		assert(m_condition != nullptr);
		return *m_condition;
	}

	Expr const& IfStmnt::condition() const {
		assert(m_condition != nullptr);
		return *m_condition;
	}

	Stmnt & IfStmnt::then_stmnt() {
		assert(m_then_stmnt != nullptr);
		return *m_then_stmnt;
	}

	Stmnt const& IfStmnt::then_stmnt() const {
		assert(m_then_stmnt != nullptr);
		return *m_then_stmnt;
	}

	Stmnt & IfStmnt::else_stmnt() {
		assert(m_else_stmnt != nullptr);
		return *m_else_stmnt;
	}

	Stmnt const& IfStmnt::else_stmnt() const {
		assert(m_else_stmnt != nullptr);
		return *m_else_stmnt;
	}

	void IfStmnt::accept(IASTVisitor & pass) {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
