#ifndef CION_AST_INTEGER_LITERAL_HEADER
#define CION_AST_INTEGER_LITERAL_HEADER

#include "ast/expression.hpp"

#include <cstdint>

namespace cion {
namespace ast {
	class IntegerLiteral : public Expression {
	public:
		using storage_type = int64_t;

		IntegerLiteral(storage_type value);
	private:
		storage_type m_value;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_INTEGER_LITERAL_HEADER
