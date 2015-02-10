#include "cion/token/number_token.hpp"

#include <stdexcept>
#include <iostream>

namespace cion {
	NumberToken::NumberToken(
		TokenType const& token_type,
		SourceLocation const& start_loc,
		SourceLocation const& end_loc,
		NumberToken::value_type value
	) :
		Token{token_type, start_loc, end_loc},
		m_value{value}
	{}

	NumberToken::NumberToken(
		TokenType const& token_type,
		SourceLocation const& start_loc,
		SourceLocation const& end_loc,
		std::string value
	) try :
		Token{token_type, start_loc, end_loc},
		m_value{std::stod(value)}
	{} catch (std::invalid_argument const& e) {
		std::cerr << "read NumberToken with invalid value format: " << e.what() << "\n";
	}  catch (std::out_of_range const& e) {
		std::cerr << "read NumberToken with its value out of bounds of its binary representation: " << e.what() << "\n";
	}

	NumberToken::value_type NumberToken::get_number() const {
		return m_value;
	}
} // namespace cion
