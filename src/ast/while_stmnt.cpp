#include "ast/while_stmnt.hpp"

#include <utility>
#include <cassert>

namespace cion {
namespace ast {

	WhileStmnt::WhileStmnt(
		std::unique_ptr<Expr> condition,
		std::unique_ptr<CompoundStmnt> body
	):
		m_condition{std::move(condition)},
		m_body{std::move(body)}
	{}

	Expr & WhileStmnt::condition() {
		assert(m_condition != nullptr);
		return *m_condition;
	}

	Expr const& WhileStmnt::condition() const {
		assert(m_condition != nullptr);
		return *m_condition;
	}

	CompoundStmnt & WhileStmnt::body() {
		assert(m_body != nullptr);
		return *m_body;
	}

	CompoundStmnt const& WhileStmnt::body() const {
		assert(m_body != nullptr);
		return *m_body;
	}

	void WhileStmnt::accept(CompilerPass & pass) {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
