#include "cion/token/float_token.hpp"

#include <stdexcept>
#include <iostream>

namespace cion {
	FloatToken::FloatToken(
		TokenType const& token_type,
		SourceLocation const& start_loc,
		SourceLocation const& end_loc,
		FloatToken::value_type value
	) :
		Token{token_type, start_loc, end_loc},
		m_value{value}
	{}

	FloatToken::FloatToken(
		TokenType const& token_type,
		SourceLocation const& start_loc,
		SourceLocation const& end_loc,
		std::string value
	) try :
		Token{token_type, start_loc, end_loc},
		m_value{std::stod(value)}
	{} catch (std::invalid_argument const& e) {
		std::cerr << "read FloatToken with invalid value format: " << e.what() << "\n";
	}  catch (std::out_of_range const& e) {
		std::cerr << "read FloatToken with its value out of bounds of its binary representation: " << e.what() << "\n";
	}

	FloatToken::value_type FloatToken::get_number() const {
		return m_value;
	}
} // namespace cion
