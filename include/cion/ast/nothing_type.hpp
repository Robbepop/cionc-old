#ifndef CION_AST_NOTHING_TYPE_HEADER
#define CION_AST_NOTHING_TYPE_HEADER

#include "cion/ast/type.hpp"

namespace cion {
namespace ast {

	class NothingType : public Type {
	public:
		NothingType() = default;

		virtual void accept(IASTVisitor & pass) override;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_NOTHING_TYPE_HEADER
