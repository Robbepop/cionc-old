#include "token/token.hpp"

#include <limits>
#include <stdexcept>

namespace cion {
	Token::Token(
		TokenType const& token_type,
		SourceLocation const& start_loc,
		SourceLocation const& end_loc
	) :
		m_type{token_type},
		m_start_loc{start_loc},
		m_end_loc{end_loc}
	{}

	bool Token::operator==(Token const& rhs) const {
		return m_type == rhs.m_type;
	}

	bool Token::operator!=(Token const& rhs) const {
		return m_type != rhs.m_type;
	}

	TokenType const& Token::get_type() const {
		return m_type;
	}

	SourceLocation const& Token::get_source_location() const {
		return m_start_loc;
	}

	SourceLocation const& Token::start_loc() const {
		return m_start_loc;
	}

	SourceLocation const& Token::end_loc() const {
		return m_end_loc;
	}

	bool Token::get_bool() const {
		throw std::runtime_error("can't receive a bool from a non-bool token.\n");
	}

	char Token::get_char() const {		
		throw std::runtime_error("can't receive a char from a non-char token.\n");
	}

	std::string Token::get_string() const {
		throw std::runtime_error("can't receive a string from a non-string token.\n");
	}

	int64_t Token::get_integral() const {
		throw std::runtime_error("can't receive an integral from a non-integral token.\n");
	}

	double Token::get_number() const {
		throw std::runtime_error("can't receive a number from a non-number token.\n");
	}
} // namespace cion
