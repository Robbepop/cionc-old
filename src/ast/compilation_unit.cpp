#include "ast/compilation_unit.hpp"

#include <utility>

namespace cion {
namespace ast {

	CompilationUnit::CompilationUnit(
		std::vector<std::unique_ptr<Statement>> top_level_statements
	):
		m_top_level_statements{std::move(top_level_statements)}
	{}

	std::vector<std::unique_ptr<Statement>> & CompilationUnit::statements() {
		return m_top_level_statements;
	}

	std::vector<std::unique_ptr<Statement>> const& CompilationUnit::statements() const {
		return m_top_level_statements;
	}

	void CompilationUnit::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void CompilationUnit::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
