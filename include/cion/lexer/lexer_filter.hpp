#ifndef CION_LEXER_FILTER_HEADER
#define CION_LEXER_FILTER_HEADER

#include "cion/lexer/lexer.hpp"
#include "cion/lexer/token_stream.hpp"

#include <memory>

namespace cion {
	class LexerFilter : public TokenStream {
	public:
		explicit LexerFilter(TokenStream & input);

		std::unique_ptr<Token> next_token() override;

	private:
		TokenStream & m_input;
	};
}

#endif // CION_LEXER_FILTER_HEADER
