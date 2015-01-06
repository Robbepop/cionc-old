#include "ast/primitive_type_int.hpp"

namespace cion {
namespace ast {

	PrimitiveTypeInt::PrimitiveTypeInt(
		bool is_signed,
		PrimitiveTypeInt::Width bit_width
	):
		m_signed{is_signed},
		m_width{bit_width}
	{}

	bool & PrimitiveTypeInt::sig() {
		return m_signed;
	}

	bool const& PrimitiveTypeInt::sig() const {
		return m_signed;
	}

	PrimitiveTypeInt::Width & PrimitiveTypeInt::width() {
		return m_width;
	}

	PrimitiveTypeInt::Width const& PrimitiveTypeInt::width() const {
		return m_width;
	}

	void PrimitiveTypeInt::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void PrimitiveTypeInt::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
