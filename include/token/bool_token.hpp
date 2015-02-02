#ifndef CION_BOOL_TOKEN_HEADER
#define CION_BOOL_TOKEN_HEADER

#include "token/token.hpp"

namespace cion {
	class BoolToken final : public Token {
	public:
		using value_type = bool;

		// Creates a new instance of a BoolToken which is
		// a more specialized form of a Token.
		// Every BoolToken stores a boolean value.
		// Can provide an optional token type specifier.
		BoolToken(
			TokenType const& token_type,
			SourceLocation const& start_loc,
			SourceLocation const& end_loc,
			value_type value);

		BoolToken(
			TokenType const& token_type,
			SourceLocation const& start_loc,
			SourceLocation const& end_loc,
			std::string value);

		BoolToken(BoolToken const& token_type) = default;
		BoolToken(BoolToken && token) = default;

		BoolToken & operator=(BoolToken const& rhs) = default;

		~BoolToken() override = default;

		// Retrieves information about the boolean stored in
		// this BoolToken. The stored boolean within this instance
		// can't be mutated.
		value_type get_bool() const override;

	private:
		value_type m_value;
	};
} // namespace cion

#endif // CION_BOOL_TOKEN_HEADER
