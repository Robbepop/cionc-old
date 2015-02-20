#include "cion/ast/if_stmnt.hpp"
#include "cion/ast/compound_stmnt.hpp"
#include "cion/ast/empty_stmnt.hpp"
#include "cion/ast/expr.hpp"

#include <utility>
#include <cassert>
#include <memory>

namespace cion {
namespace ast {

	IfStmnt::IfStmnt(
		std::unique_ptr<Expr> p_condition,
		std::unique_ptr<CompoundStmnt> p_then_stmnt,
		std::unique_ptr<Stmnt> p_else_stmnt
	):
		m_condition{std::move(p_condition)},
		m_then_stmnt{std::move(p_then_stmnt)},
		m_else_stmnt{std::move(p_else_stmnt)}
	{}

	IfStmnt::IfStmnt(
		std::unique_ptr<Expr> p_condition,
		std::unique_ptr<CompoundStmnt> p_then_stmnt
	):
		IfStmnt{
			std::move(p_condition),
			std::move(p_then_stmnt),
			std::unique_ptr<Stmnt>{std::make_unique<EmptyStmnt>()}}
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
