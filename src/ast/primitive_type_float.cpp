#include "ast/primitive_type_float.hpp"

namespace cion {
namespace ast {

	PrimitiveTypeFloat::PrimitiveTypeFloat(
		PrimitiveTypeFloat::Width bit_width
	):
		m_width{bit_width}
	{}

} // namespace ast
} // namespace cion
