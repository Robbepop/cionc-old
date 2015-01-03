#ifndef CION_TOKEN_HEADER
#define CION_TOKEN_HEADER

#include "token/token_type.hpp"
#include "error/source_location.hpp"

#include <string>
#include <cstdint>
#include <unordered_map>

namespace cion {
	// Represents the base token with optional additional information
	// besides its token type. Other token subclasses may specialize
	// certain getter methods to grab for additional information of
	// a token instance if available.
	class Token {
	public:
		Token(TokenType const& type, SourceLocation const& source_location);
		Token(Token const& token) = default;
		Token(Token && token) = default;

		virtual ~Token() = default;

		Token & operator=(Token const& rhs) = default;

		bool operator==(Token const& other) const;
		bool operator!=(Token const& other) const;

		// Retrieves the TokenType of this token instance.
		// Every token instance has got a associated TokenType.
		TokenType const& get_type() const;

		// Retrieves the Token's source location information used
		// to improve error and debug information during parsing.
		SourceLocation const& get_source_location() const;

		// Retrieves optional information for a boolean value.
		virtual bool get_bool() const;

		// Retrieves optional information for a char value.
		virtual char get_char() const;

		// Retrieves optional information for an identifier value.
		virtual std::string get_string() const;

		// Retrieves optional information for an integral value.
		virtual int64_t get_integral() const;

		// Retrieves optional information for a number value.
		virtual double get_number() const;

	private:
		TokenType m_type;
		SourceLocation m_source_location;
	};
} // namespace cion

#endif // CION_TOKEN_HEADER
