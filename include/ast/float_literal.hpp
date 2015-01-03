#ifndef CION_AST_FLOAT_LITERAL_HEADER
#define CION_AST_FLOAT_LITERAL_HEADER

#include "ast/expression.hpp"

namespace cion {
namespace ast {
	class FloatLiteral : public Expression {
	public:
		using storage_type = double;

		FloatLiteral(storage_type value);
	private:
		storage_type m_value;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_FLOAT_LITERAL_HEADER
