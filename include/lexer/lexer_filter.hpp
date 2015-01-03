#ifndef CION_LEXER_FILTER_HEADER
#define CION_LEXER_FILTER_HEADER

#include "lexer/lexer.hpp"
#include "lexer/token_stream.hpp"

#include <memory>

namespace cion {
	class LexerFilter : public TokenStream {
	private:
		bool is_valid(TokenType token_type);

	public:
		LexerFilter(Lexer & input, std::vector<TokenType> const& invalid_tokens);

		std::unique_ptr<Token> next_token() override;

	private:
		Lexer & m_input;
		std::vector<TokenType> m_invalid_tokens;
	};
}

#endif // CION_LEXER_FILTER_HEADER