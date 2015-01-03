#include "ast/compilation_unit.hpp"

#include <utility>

namespace cion {
namespace ast {

	CompilationUnit::CompilationUnit(
		std::vector<std::unique_ptr<Statement>> top_level_statements
	):
		m_top_level_statements{std::move(top_level_statements)}
	{}

} // namespace ast
} // namespace cion
