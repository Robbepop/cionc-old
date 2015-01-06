#ifndef CION_AST_NOTHING_TYPE_HEADER
#define CION_AST_NOTHING_TYPE_HEADER

#include "ast/type_specifier.hpp"

namespace cion {
namespace ast {

	class NothingType : public TypeSpecifier {
	public:
		NothingType() = default;

		virtual void accept(MutatingCompilerPass & pass) override;
		virtual void accept(CompilerPass & pass) const override;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_NOTHING_TYPE_HEADER
