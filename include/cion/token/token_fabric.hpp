#ifndef CION_TOKEN_FABRIC_HEADER
#define CION_TOKEN_FABRIC_HEADER

#include "cion/token/token.hpp"
#include "cion/token/bool_token.hpp"
#include "cion/token/char_token.hpp"
#include "cion/token/integral_token.hpp"
#include "cion/token/number_token.hpp"
#include "cion/token/string_token.hpp"
#include "cion/error/source_location.hpp"

#include <memory>

namespace cion {
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
