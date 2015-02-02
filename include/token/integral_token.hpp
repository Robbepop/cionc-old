#ifndef CION_INTEGRAL_TOKEN_HEADER
#define CION_INTEGRAL_TOKEN_HEADER

#include "token/token.hpp"

namespace cion {
	class IntegralToken final : public Token {
	public:
		using value_type = int64_t;

		// Creates a new instance of an IntegralToken which is
		// a more specialized form of a Token.
		// Every CharToken stores an integral value.
		// Can provide an optional token type specifier.
		IntegralToken(
			TokenType const& token_type,
			SourceLocation const& start_loc,
			SourceLocation const& end_loc,
			value_type value);

		IntegralToken(
			TokenType const& token_type,
			SourceLocation const& start_loc,
			SourceLocation const& end_loc,
			std::string value);

		IntegralToken(IntegralToken const& token) = default;
		IntegralToken(IntegralToken && token) = default;

		IntegralToken & operator=(IntegralToken const& rhs) = default;

		~IntegralToken() override = default;

		// Retrieves information about the integral stored in
		// this IntegralToken. The stored integral within this instance
		// can't be mutated.
		value_type get_integral() const override;

	private:
		value_type m_value;
	};
} // namespace cion

#endif // CION_CHAR_TOKEN_HEADER
