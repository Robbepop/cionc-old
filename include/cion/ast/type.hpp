#ifndef CION_AST_TYPE_HEADER
#define CION_AST_TYPE_HEADER

#include "cion/parser/i_ast_visitor.hpp"

namespace cion {
	class IASTVisitor;

namespace ast {
	class Type {
	public:
		virtual void accept(IASTVisitor & pass) = 0;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_TYPE_HEADER
