#include "ast/compound_statement.hpp"

#include <utility>

namespace cion {
namespace ast {

	CompoundStatement::CompoundStatement(
		std::vector<std::unique_ptr<Statement>> statements
	):
		m_statements{std::move(statements)}
	{}

	std::vector<std::unique_ptr<Statement>> & CompoundStatement::statements() {
		return m_statements;
	}

	std::vector<std::unique_ptr<Statement>> const& CompoundStatement::statements() const {
		return m_statements;
	}

	void CompoundStatement::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void CompoundStatement::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
