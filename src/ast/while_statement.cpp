#include "ast/while_statement.hpp"

#include <utility>
#include <cassert>

namespace cion {
namespace ast {

	WhileStatement::WhileStatement(
		std::unique_ptr<Expr> condition,
		std::unique_ptr<CompoundStatement> body
	):
		m_condition{std::move(condition)},
		m_body{std::move(body)}
	{}

	Expr & WhileStatement::condition() {
		assert(m_condition != nullptr);
		return *m_condition;
	}

	Expr const& WhileStatement::condition() const {
		assert(m_condition != nullptr);
		return *m_condition;
	}

	CompoundStatement & WhileStatement::body() {
		assert(m_body != nullptr);
		return *m_body;
	}

	CompoundStatement const& WhileStatement::body() const {
		assert(m_body != nullptr);
		return *m_body;
	}

	void WhileStatement::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void WhileStatement::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
