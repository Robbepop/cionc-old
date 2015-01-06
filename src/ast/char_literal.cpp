#include "ast/char_literal.hpp"

namespace cion {
namespace ast {

	CharLiteral::CharLiteral(CharLiteral::storage_type value) :
		m_value{value}
	{}

	CharLiteral::storage_type & CharLiteral::value() {
		return m_value;
	}

	CharLiteral::storage_type const& CharLiteral::value() const {
		return m_value;
	}

	void CharLiteral::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void CharLiteral::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
