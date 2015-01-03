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

} // namespace ast
} // namespace cion
