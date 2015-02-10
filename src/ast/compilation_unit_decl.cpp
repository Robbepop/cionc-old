#include "cion/ast/compilation_unit_decl.hpp"

#include <utility>

namespace cion {
namespace ast {

	CompilationUnitDecl::CompilationUnitDecl(
		std::vector<std::unique_ptr<Decl>> p_decls
	):
		m_decls{std::move(p_decls)}
	{}

	std::vector<std::unique_ptr<Decl>> & CompilationUnitDecl::decls() {
		return m_decls;
	}

	std::vector<std::unique_ptr<Decl>> const& CompilationUnitDecl::decls() const {
		return m_decls;
	}

	void CompilationUnitDecl::accept(IASTVisitor & pass) {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
