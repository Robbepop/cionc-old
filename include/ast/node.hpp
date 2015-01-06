#ifndef CION_AST_NODE_HEADER
#define CION_AST_NODE_HEADER

#include "parser/compiler_pass.hpp"

namespace cion {
namespace ast {
	class Node {
	public:
		virtual ~Node() = default;

		virtual void accept(MutatingCompilerPass & pass) = 0;
		virtual void accept(CompilerPass & pass) const = 0;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_NODE_HEADER
