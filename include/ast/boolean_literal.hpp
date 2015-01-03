#ifndef CION_AST_BOOLEAN_LITERAL_HEADER
#define CION_AST_BOOLEAN_LITERAL_HEADER

#include "ast/expression.hpp"

namespace cion {
namespace ast {
	class BooleanLiteral : public Expression {
	public:
		using storage_type = bool;

		BooleanLiteral(storage_type value);
	private:
		storage_type m_value;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_BOOLEAN_LITERAL_HEADER
