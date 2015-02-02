#include "token/char_token.hpp"

#include <iostream>

namespace cion {
	CharToken::CharToken(
		TokenType const& token_type,
		SourceLocation const& start_loc,
		SourceLocation const& end_loc,
		CharToken::value_type value
	) :
		Token{token_type, start_loc, end_loc},
		m_value{value}
	{}

	CharToken::CharToken(
		TokenType const& token_type,
		SourceLocation const& start_loc,
		SourceLocation const& end_loc,
		std::string value
	) :
		Token{token_type, start_loc, end_loc},
		m_value{(value.length() > 1) ? value[1] : '\0'}
	{}

	CharToken::value_type CharToken::get_char() const {
		return m_value;
	}
} // namespace cion
