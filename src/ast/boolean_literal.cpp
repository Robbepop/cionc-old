#include "ast/boolean_literal.hpp"

namespace cion {
namespace ast {

	BooleanLiteral::BooleanLiteral(BooleanLiteral::storage_type value) :
		m_value{value}
	{}

} // namespace ast
} // namespace cion
