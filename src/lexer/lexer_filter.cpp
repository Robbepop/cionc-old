#include "cion/lexer/lexer_filter.hpp"

#include <algorithm>

#include <iostream>

namespace cion {
	LexerFilter::LexerFilter(TokenStream & input) :
		m_input{input}
	{}

	std::unique_ptr<Token> LexerFilter::next_token() {
		auto token = m_input.next_token();
		while (token->get_type() == TokenType::error) {
			token = m_input.next_token();
		}
		return token;
	}
} // namespace cion
