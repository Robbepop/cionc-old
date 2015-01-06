#include "ast/if_statement.hpp"
#include "ast/empty_statement.hpp"

#include <utility>
#include <cassert>
#include <memory>

namespace cion {
namespace ast {

	IfStatement::IfStatement(
		std::unique_ptr<Expression> condition,
		std::unique_ptr<Statement> then_stmnt,
		std::unique_ptr<Statement> else_stmnt
	):
		m_condition{std::move(condition)},
		m_then_stmnt{std::move(then_stmnt)},
		m_else_stmnt{std::move(else_stmnt)}
	{}

	IfStatement::IfStatement(
		std::unique_ptr<Expression> condition,
		std::unique_ptr<Statement> then_stmnt
	):
		IfStatement{std::move(condition), std::move(then_stmnt),
			std::unique_ptr<Statement>{std::make_unique<EmptyStatement>()}}
	{}

	Expression & IfStatement::condition() {
		assert(m_condition != nullptr);
		return *m_condition;
	}

	Expression const& IfStatement::condition() const {
		assert(m_condition != nullptr);
		return *m_condition;
	}

	Statement & IfStatement::then_stmnt() {
		assert(m_then_stmnt != nullptr);
		return *m_then_stmnt;
	}

	Statement const& IfStatement::then_stmnt() const {
		assert(m_then_stmnt != nullptr);
		return *m_then_stmnt;
	}

	Statement & IfStatement::else_stmnt() {
		assert(m_else_stmnt != nullptr);
		return *m_else_stmnt;
	}

	Statement const& IfStatement::else_stmnt() const {
		assert(m_else_stmnt != nullptr);
		return *m_else_stmnt;
	}

	void IfStatement::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void IfStatement::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
