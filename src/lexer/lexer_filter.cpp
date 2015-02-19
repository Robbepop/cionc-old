#include "cion/lexer/lexer_filter.hpp"

#include <algorithm>

#include <iostream>

namespace cion {
	LexerFilter::LexerFilter(TokenStream & input, std::vector<TokenType> const& invalid_tokens) :
		m_input{input},
		m_invalid_tokens{invalid_tokens}
	{
		m_invalid_tokens.push_back(TokenType::error);
	}

	bool LexerFilter::is_valid(TokenType token_type) {
		const auto end = m_invalid_tokens.end();
		return std::find(m_invalid_tokens.begin(), end, token_type) == end;
	}

	std::unique_ptr<Token> LexerFilter::next_token() {
		auto token = m_input.next_token();
		while (!is_valid(token->get_type())) {
			std::cout << "LexerFilter::next_token() - invalid!\n";
			token = m_input.next_token();
		}
		return token;
	}
} // namespace cion
