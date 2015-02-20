#ifndef CION_INTEGER_TOKEN_HEADER
#define CION_INTEGER_TOKEN_HEADER

#include "cion/token/token.hpp"

namespace cion {
	class IntegerToken final : public Token {
	public:
		using value_type = int64_t;

		// Creates a new instance of an IntegerToken which is
		// a more specialized form of a Token.
		// Every CharToken stores an integral value.
		// Can provide an optional token type specifier.
		IntegerToken(
			TokenType const& token_type,
			SourceLocation const& start_loc,
			SourceLocation const& end_loc,
			value_type value);

		IntegerToken(
			TokenType const& token_type,
			SourceLocation const& start_loc,
			SourceLocation const& end_loc,
			std::string value);

		IntegerToken(IntegerToken const& token) = default;
		IntegerToken(IntegerToken && token) = default;

		IntegerToken & operator=(IntegerToken const& rhs) = default;

		~IntegerToken() override = default;

		// Retrieves information about the integral stored in
		// this IntegerToken. The stored integral within this instance
		// can't be mutated.
		value_type get_integral() const override;

	private:
		value_type m_value;
	};
} // namespace cion

#endif // CION_CHAR_TOKEN_HEADER
