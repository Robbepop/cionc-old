#include "ast/primitive_type_float.hpp"

namespace cion {
namespace ast {

	PrimitiveTypeFloat::PrimitiveTypeFloat(
		PrimitiveTypeFloat::Width bit_width
	):
		m_width{bit_width}
	{}

	PrimitiveTypeFloat::Width & PrimitiveTypeFloat::width() {
		return m_width;
	}

	PrimitiveTypeFloat::Width const& PrimitiveTypeFloat::width() const {
		return m_width;
	}

	void PrimitiveTypeFloat::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void PrimitiveTypeFloat::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
