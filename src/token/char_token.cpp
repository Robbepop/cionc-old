#include "token/char_token.hpp"

#include <iostream>

namespace cion {
	CharToken::CharToken(
		TokenType const& token_type,
		SourceLocation const& source_location,
		CharToken::value_type value
	) :
		Token{token_type, source_location},
		m_value{value}
	{}

	CharToken::CharToken(
		TokenType const& token_type,
		SourceLocation const& source_location,
		std::string value
	) :
		Token{token_type, source_location},
		m_value{(value.length() > 0) ? value[0] : '\0'}
	{}

	CharToken::value_type CharToken::get_char() const {
		return m_value;
	}
} // namespace cion
