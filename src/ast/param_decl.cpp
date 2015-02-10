#include "ast/param_decl.hpp"

#include <utility>
#include <cassert>

namespace cion {
namespace ast {

	ParamDecl::ParamDecl(
		std::string const& p_name,
		std::unique_ptr<Type> p_type
	):
		m_name{p_name},
		m_type{std::move(p_type)}
	{}

	std::string & ParamDecl::name() {
		return m_name;
	}

	std::string const& ParamDecl::name() const {
		return m_name;
	}

	Type & ParamDecl::type() {
		assert(m_type != nullptr);
		return *m_type;
	}

	Type const& ParamDecl::type() const {
		assert(m_type != nullptr);
		return *m_type;
	}

	void ParamDecl::accept(IASTVisitor & pass) {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
