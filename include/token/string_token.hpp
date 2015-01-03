#ifndef CION_STRING_TOKEN_HEADER
#define CION_STRING_TOKEN_HEADER

#include "token/token.hpp"

namespace cion {
	class StringToken final : public Token {
	public:
		using value_type = std::string;

		// Creates a new instance of an IdentifierToken which is
		// a more specialized form of a Token.
		// Every IdentifierToken stores a std::string value.
		// Can provide an optional token type specifier.
		StringToken(
			TokenType const& token_type,
			SourceLocation const& source_location,
			value_type value);

		StringToken(StringToken const& token) = default;
		StringToken(StringToken && token) = default;

		StringToken & operator=(StringToken const& rhs) = default;

		~StringToken() override = default;

		// Retrieves information about the std::string stored in
		// this IdentifierToken. The stored std::string within this instance
		// can't be mutated.
		value_type get_string() const override;

	private:
		value_type m_value;
	};
} // namespace cion

#endif // CION_STRING_TOKEN_HEADER
