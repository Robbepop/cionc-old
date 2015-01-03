#include "ast/char_literal.hpp"

namespace cion {
namespace ast {

	CharLiteral::CharLiteral(CharLiteral::storage_type value) :
		m_value{value}
	{}

} // namespace ast
} // namespace cion
