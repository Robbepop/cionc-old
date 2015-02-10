#include "cion/token/bool_token.hpp"

namespace cion {
	BoolToken::BoolToken(
		TokenType const& token_type,
		SourceLocation const& start_loc,
		SourceLocation const& end_loc,
		BoolToken::value_type value
	) :
		Token{token_type, start_loc, end_loc},
		m_value{value}
	{}

	BoolToken::BoolToken(
		TokenType const& token_type,
		SourceLocation const& start_loc,
		SourceLocation const& end_loc,
		std::string value
	) :
		Token{token_type, start_loc, end_loc},
		m_value{(value == "true") ? true : false}
	{}

	BoolToken::value_type BoolToken::get_bool() const {
		return m_value;
	}
} // namespace cion
