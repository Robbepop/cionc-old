#ifndef CION_AST_PRIMITIVE_TYPE_BOOL_HEADER
#define CION_AST_PRIMITIVE_TYPE_BOOL_HEADER

#include "ast/type_specifier.hpp"

namespace cion {
namespace ast {

	class PrimitiveTypeBool : public TypeSpecifier {
	public:
		PrimitiveTypeBool() = default;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_PRIMITIVE_TYPE_BOOL_HEADER
