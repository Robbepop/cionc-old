#ifndef CION_AST_PRIMITIVE_TYPE_FLOAT_HEADER
#define CION_AST_PRIMITIVE_TYPE_FLOAT_HEADER

#include "ast/type_specifier.hpp"

#include <cstdint>

namespace cion {
namespace ast {

	class PrimitiveTypeFloat : public TypeSpecifier {
	public:
		enum class Width : uint8_t {
			unspecified = 0,
			two_bytes   = 16,
			four_bytes  = 32,
			eight_bytes = 64
		};

		PrimitiveTypeFloat(Width bit_width = Width::unspecified);

	private:
		Width m_width;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_PRIMITIVE_TYPE_FLOAT_HEADER
