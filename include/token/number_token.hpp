#ifndef CION_NUMBER_TOKEN_HEADER
#define CION_NUMBER_TOKEN_HEADER

#include "token/token.hpp"

namespace cion {
	class NumberToken final : public Token {
	public:
		using value_type = double;

		// Creates a new instance of a NumberToken which is
		// a more specialized form of a Token.
		// Every NumberToken stores a double value.
		// Can provide an optional token type specifier.
		NumberToken(
			TokenType const& token_type,
			SourceLocation const& source_location,
			value_type value);

		NumberToken(
			TokenType const& token_type,
			SourceLocation const& source_location,
			std::string value);

		NumberToken(NumberToken const& token) = default;
		NumberToken(NumberToken && token) = default;

		NumberToken & operator=(NumberToken const& rhs) = default;

		~NumberToken() override = default;

		// Retrieves information about the number stored in
		// this NumberToken. The stored number within this instance
		// can't be mutated.
		value_type get_number() const override;

	private:
		value_type m_value;
	};
} // namespace cion

#endif // CION_NUMBER_TOKEN_HEADER
