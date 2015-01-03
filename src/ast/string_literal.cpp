#include "ast/string_literal.hpp"

namespace cion {
namespace ast {

	StringLiteral::StringLiteral(StringLiteral::storage_type value) :
		m_value{value}
	{}

} // namespace ast
} // namespace cion
