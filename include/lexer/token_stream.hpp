#ifndef CION_TOKEN_STREAM_HEADER
#define CION_TOKEN_STREAM_HEADER

#include "token/token.hpp"

#include <memory>

namespace cion {
	class TokenStream {
	public:
		virtual std::unique_ptr<Token> next_token() = 0;
	};
}

#endif // CION_TOKEN_STREAM_HEADER
