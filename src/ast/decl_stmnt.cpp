#include "ast/decl_stmnt.hpp"

#include <utility>
#include <cassert>

namespace cion {
namespace ast {

	DeclStmnt::DeclStmnt(
		std::unique_ptr<Decl> p_decl
	):
		m_decl{std::move(p_decl)}
	{}

	Decl & DeclStmnt::decl() {
		assert(m_decl != nullptr);
		return *m_decl;
	}

	Decl const& DeclStmnt::decl() const {
		assert(m_decl != nullptr);
		return *m_decl;
	}

	void DeclStmnt::accept(CompilerPass & pass) {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
