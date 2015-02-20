#ifndef CION_TOKEN_FABRIC_HEADER
#define CION_TOKEN_FABRIC_HEADER

#include <memory>

namespace cion {
	class Token;
	class TokenType;
	class SourceLocation;

	class TokenFabric final {
	public:
		static std::unique_ptr<Token> make_token(
			TokenType const& token_type,
			SourceLocation const& start_loc,
			SourceLocation const& end_loc,
			std::string const& value = "");
	};
} // namespace cion

#endif // CION_TOKEN_FABRIC_HEADER
