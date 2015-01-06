#include "ast/string_literal.hpp"

namespace cion {
namespace ast {

	StringLiteral::StringLiteral(StringLiteral::storage_type value) :
		m_value{value}
	{}

	StringLiteral::storage_type & StringLiteral::value() {
		return m_value;
	}

	StringLiteral::storage_type const& StringLiteral::value() const {
		return m_value;
	}

	void StringLiteral::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void StringLiteral::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
