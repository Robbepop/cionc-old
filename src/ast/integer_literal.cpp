#include "ast/integer_literal.hpp"

namespace cion {
namespace ast {

	IntegerLiteral::IntegerLiteral(IntegerLiteral::storage_type value) :
		m_value{value}
	{}

} // namespace ast
} // namespace cion
