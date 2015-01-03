#include "token/bool_token.hpp"

namespace cion {
	BoolToken::BoolToken(
		TokenType const& token_type,
		SourceLocation const& source_location,
		BoolToken::value_type value
	) :
		Token{token_type, source_location},
		m_value{value}
	{}

	BoolToken::BoolToken(
		TokenType const& token_type,
		SourceLocation const& source_location,
		std::string value
	) :
		Token{token_type, source_location},
		m_value{(value == "true") ? true : false}
	{}

	BoolToken::value_type BoolToken::get_bool() const {
		return m_value;
	}
} // namespace cion
