#ifndef CION_TOKEN_TYPE_SET_HEADER
#define CION_TOKEN_TYPE_SET_HEADER

#include "cion/token/token_type.hpp"

#include <vector>

namespace cion {
	class TokenTypeSet {
	public:
		std::vector<TokenType const*> const& get_tokens() const;
	};
}

#endif // CION_TOKEN_TYPE_SET_HEADER
