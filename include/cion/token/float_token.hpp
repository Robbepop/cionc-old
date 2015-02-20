#ifndef CION_FLOAT_TOKEN_HEADER
#define CION_FLOAT_TOKEN_HEADER

#include "cion/token/token.hpp"

namespace cion {
	class FloatToken final : public Token {
	public:
		using value_type = double;

		// Creates a new instance of a FloatToken which is
		// a more specialized form of a Token.
		// Every FloatToken stores a double value.
		// Can provide an optional token type specifier.
		FloatToken(
			TokenType const& token_type,
			SourceLocation const& start_loc,
			SourceLocation const& end_loc,
			value_type value);

		FloatToken(
			TokenType const& token_type,
			SourceLocation const& start_loc,
			SourceLocation const& end_loc,
			std::string value);

		FloatToken(FloatToken const& token) = default;
		FloatToken(FloatToken && token) = default;

		FloatToken & operator=(FloatToken const& rhs) = default;

		~FloatToken() override = default;

		// Retrieves information about the number stored in
		// this FloatToken. The stored number within this instance
		// can't be mutated.
		value_type get_number() const override;

	private:
		value_type m_value;
	};
} // namespace cion

#endif // CION_NUMBER_TOKEN_HEADER
