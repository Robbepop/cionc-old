#ifndef CION_AST_PRIMITIVE_TYPE_CHAR_HEADER
#define CION_AST_PRIMITIVE_TYPE_CHAR_HEADER

#include "ast/type_specifier.hpp"

namespace cion {
namespace ast {

	class PrimitiveTypeChar : public TypeSpecifier {
	public:
		PrimitiveTypeChar() = default;

		virtual void accept(MutatingCompilerPass & pass) override;
		virtual void accept(CompilerPass & pass) const override;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_PRIMITIVE_TYPE_CHAR_HEADER
