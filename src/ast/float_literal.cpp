#include "ast/float_literal.hpp"

namespace cion {
namespace ast {

	FloatLiteral::FloatLiteral(FloatLiteral::storage_type value) :
		m_value{value}
	{}

	FloatLiteral::storage_type & FloatLiteral::value() {
		return m_value;
	}

	FloatLiteral::storage_type const& FloatLiteral::value() const {
		return m_value;
	}

	void FloatLiteral::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void FloatLiteral::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
