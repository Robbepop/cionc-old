#include "ast/boolean_literal.hpp"

namespace cion {
namespace ast {

	BooleanLiteral::BooleanLiteral(BooleanLiteral::storage_type value) :
		m_value{value}
	{}

	BooleanLiteral::storage_type & BooleanLiteral::value() {
		return m_value;
	}

	BooleanLiteral::storage_type const& BooleanLiteral::value() const {
		return m_value;
	}

	void BooleanLiteral::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void BooleanLiteral::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
