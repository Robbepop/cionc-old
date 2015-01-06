#ifndef CION_AST_STATEMENT_HEADER
#define CION_AST_STATEMENT_HEADER

#include "ast/node.hpp"

namespace cion {
namespace ast {
	class Statement : public Node {
	public:
		virtual void accept(MutatingCompilerPass & pass) = 0;
		virtual void accept(CompilerPass & pass) const = 0;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_STATEMENT_HEADER
