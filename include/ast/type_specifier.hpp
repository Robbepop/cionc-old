#ifndef CION_AST_TYPE_SPECIFIER_HEADER
#define CION_AST_TYPE_SPECIFIER_HEADER

#include "ast/node.hpp"

namespace cion {
namespace ast {

	class TypeSpecifier : public Node {
		virtual void accept(MutatingCompilerPass & pass) = 0;
		virtual void accept(CompilerPass & pass) const = 0;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_TYPE_SPECIFIER_HEADER
