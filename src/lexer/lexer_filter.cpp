#include "lexer/lexer_filter.hpp"

#include <algorithm>

namespace cion {
	LexerFilter::LexerFilter(Lexer & input, std::vector<TokenType> const& invalid_tokens) :
		m_input{input},
		m_invalid_tokens{invalid_tokens}
	{}

	bool LexerFilter::is_valid(TokenType token_type) {
		const auto end = m_invalid_tokens.end();
		return std::find(m_invalid_tokens.begin(), end, token_type) == end;
	}

	std::unique_ptr<Token> LexerFilter::next_token() {
		auto token = m_input.next_token();
		while (!is_valid(token->get_type())) {
			token = m_input.next_token();
		}
		return token;
	}
} // namespace cion
