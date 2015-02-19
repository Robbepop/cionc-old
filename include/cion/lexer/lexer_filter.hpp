#ifndef CION_LEXER_FILTER_HEADER
#define CION_LEXER_FILTER_HEADER

#include "cion/lexer/lexer.hpp"
#include "cion/lexer/token_stream.hpp"

#include <memory>

namespace cion {
	class LexerFilter : public TokenStream {
	private:
		bool is_valid(TokenType token_type);

	public:
		LexerFilter(TokenStream & input, std::vector<TokenType> const& invalid_tokens);

		std::unique_ptr<Token> next_token() override;

	private:
		TokenStream & m_input;
		std::vector<TokenType> m_invalid_tokens;
	};
}

#endif // CION_LEXER_FILTER_HEADER
