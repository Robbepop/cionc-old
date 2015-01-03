#include "token/string_token.hpp"

namespace cion {
	StringToken::StringToken(
		TokenType const& token_type,
		SourceLocation const& source_location,
		StringToken::value_type value
	) :
		Token{token_type, source_location},
		m_value{value}
	{}

	StringToken::value_type StringToken::get_string() const {
		return m_value;
	}
} // namespace cion
