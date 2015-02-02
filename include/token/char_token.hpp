#ifndef CION_CHAR_TOKEN_HEADER
#define CION_CHAR_TOKEN_HEADER

#include "token/token.hpp"

namespace cion {
	class CharToken final : public Token {
	public:
		using value_type = char;

		// Creates a new instance of a CharToken which is
		// a more specialized form of a Token.
		// Every CharToken stores a char value.
		// Can provide an optional token type specifier.
		CharToken(
			TokenType const& token_type,
			SourceLocation const& start_loc,
			SourceLocation const& end_loc,
			value_type value);

		CharToken(
			TokenType const& token_type,
			SourceLocation const& start_loc,
			SourceLocation const& end_loc,
			std::string value);

		CharToken(CharToken const& token) = default;
		CharToken(CharToken && token) = default;

		CharToken & operator=(CharToken const& rhs) = default;

		~CharToken() override = default;

		// Retrieves information about the char stored in
		// this CharToken. The stored char within this instance
		// can't be mutated.
		value_type get_char() const override;

	private:
		value_type m_value;
	};
} // namespace cion

#endif // CION_CHAR_TOKEN_HEADER
