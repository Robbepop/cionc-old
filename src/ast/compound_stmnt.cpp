#include "ast/compound_stmnt.hpp"

#include <utility>

namespace cion {
namespace ast {

	CompoundStmnt::CompoundStmnt(
		std::vector<std::unique_ptr<Stmnt>> statements
	):
		m_statements{std::move(statements)}
	{}

	std::vector<std::unique_ptr<Stmnt>> & CompoundStmnt::statements() {
		return m_statements;
	}

	std::vector<std::unique_ptr<Stmnt>> const& CompoundStmnt::statements() const {
		return m_statements;
	}

	void CompoundStmnt::accept(IASTVisitor & pass) {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
