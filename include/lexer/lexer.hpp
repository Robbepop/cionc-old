#ifndef CION_LEXER_HEADER
#define CION_LEXER_HEADER

#include "token/token.hpp"
#include "lexer/token_stream.hpp"
#include "error/error_handler.hpp"
#include "error/source_location.hpp"

#include <boost/regex.hpp>

#include <iostream>
#include <deque>
#include <type_traits>
#include <cstdint>

namespace cion {
	class Lexer : public TokenStream {
	public:
		Lexer(
			std::istream & inputstream,
			std::vector<TokenType> const& token_types,
			ErrorHandler const& error_handler);

		std::unique_ptr<Token> next_token() override;

	private:
		struct IterationData {
		public:
			IterationData() = default;

			bool buffers_empty() const;
			void clear_buffers();
			std::vector<TokenType> & get_partial_matches();
			std::vector<TokenType> & get_full_matches_greedy();
			std::vector<TokenType> & get_full_matches_non_greedy();
			SourceLocation const& get_source_location() const;
			SourceLocation & get_source_location();

		private:
			std::vector<TokenType> m_partial_matches;
			std::vector<TokenType> m_full_matches_greedy;
			std::vector<TokenType> m_full_matches_non_greedy;
			SourceLocation m_source_location;
		};

		// Checks if all buffers are empty.
		// This is only true if the first token is to be read in;
		// OR if a new token is to be read in.
		bool buffers_empty();

		void check_match(TokenType const& token_type);

		// If all buffers are empty then it checks all matchable
		// token types if they partially match against the current buffer
		// content, else it checks the current partial match buffer.
		// If a token type's regex is partially matching against
		// the current buffers content it is further checked if it
		// even fully matches the content. If it does then it is put
		// in the current full match buffer, else in the
		// current partially match buffer.
		void check_matches();

		// Swaps buffers so that the current match buffers are
		// the last match buffers and empties the now-current match
		// buffers so that they can be filled in again without
		// the old token types from the last round.
		void swap_buffers();

		// Clears all match buffers since a completely new token
		// type is to be read in and operated on.
		void clear_buffers();

		// Clears only the current buffers.
		// This operation is required after every swap buffers operation.
		void clear_cur_buffers();

		// Updates the line and column numbers after every iteration.
		void update_lc_numbers();

		// Updates the line and column numbers after a step back has been taken.
		void step_back();

		// Return an error token on an invalid input sequence and
		// execute the associated error handler to handle this error.
		std::unique_ptr<Token> make_error_token(ErrorType type);

		std::istream & m_input;
		std::string m_buffer;
		char m_cur_symbol;
		IterationData m_it_data[2];
		IterationData *m_cur, *m_last;

		// A vector filled with token types which this lexer should check to
		// match against the given input stream.
		std::vector<TokenType> m_matchable_tokens;

		ErrorHandler const& m_error_handler;
	};
}

#endif // CION_LEXER_HEADER
