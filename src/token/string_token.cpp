#include "cion/token/string_token.hpp"

namespace cion {
	StringToken::StringToken(
		TokenType const& token_type,
		SourceLocation const& start_loc,
		SourceLocation const& end_loc,
		StringToken::value_type value
	) :
		Token{token_type, start_loc, end_loc},
		m_value{value}
	{}

	StringToken::value_type StringToken::get_string() const {
		return m_value;
	}
} // namespace cion
