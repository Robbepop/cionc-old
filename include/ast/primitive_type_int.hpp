#ifndef CION_AST_PRIMITIVE_TYPE_INT_HEADER
#define CION_AST_PRIMITIVE_TYPE_INT_HEADER

#include "ast/type_specifier.hpp"

#include <cstdint>

namespace cion {
namespace ast {

	class PrimitiveTypeInt : public TypeSpecifier {
	public:
		enum class Width : uint8_t {
			unspecified = 0,
			one_byte    = 8,
			two_bytes   = 16,
			four_bytes  = 32,
			eight_bytes = 64
		};

		PrimitiveTypeInt(bool is_signed = true, Width bit_width = Width::unspecified);

		virtual void accept(MutatingCompilerPass & pass) override;
		virtual void accept(CompilerPass & pass) const override;

	private:
		bool m_signed;
		Width m_width;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_PRIMITIVE_TYPE_INT_HEADER
