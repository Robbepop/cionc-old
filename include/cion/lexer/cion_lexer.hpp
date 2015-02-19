#ifndef CION_CION_LEXER_HEADER
#define CION_CION_LEXER_HEADER

#include "cion/lexer/token_stream.hpp"
#include "cion/token/token_type.hpp"
#include "cion/error/error_handler.hpp"
#include "cion/error/source_location.hpp"

#include <string>
#include <unordered_map>
#include <memory>
#include <iosfwd>

namespace cion {
	class Token;
	class CionTokenTypes;

	class CionLexer : public TokenStream {
	public:
		CionLexer(std::istream & p_input, ErrorHandler & p_error_handler);

		virtual std::unique_ptr<Token> next_token() override;

	private:
		void add_keyword(std::string const& p_key, TokenType const& p_tt);

		bool is_digit(char p_char) const;
		bool is_non_zero_digit(char p_char) const;
		bool is_alpha(char p_char) const;
		bool is_alpha_num(char p_char) const;
		bool is_keyword(std::string p_word) const;

		bool is_digit() const;
		bool is_non_zero_digit() const;
		bool is_alpha() const;
		bool is_alpha_num() const;
		bool is_keyword() const;

		SourceLocation & cur_end_loc();
		SourceLocation & prv_end_loc();

		void update_loc();

		/// Returns a valid buffer from the current character buffer
		/// which is exactly the character buffer but its last character.
		std::string valid_buffer() const;

		/// Getter for the current character.
		char cur_char() const;

		/// This function reads in the next character from
		/// the input stream. It also fills the character buffer
		/// and adjusts the current end location.
		char next_char();

		/// This is a specialized version of the next_char() function
		/// which basically does the same but won't put the read
		/// input into the buffer as this function is only called
		/// when any input is ignore such as in comments.
		char next_char_ignore();

		/// Creates a token via the token fabric and the given token type.
		/// This will also update and reset the current character buffer to
		/// its last character and will return the newly created token.
		std::unique_ptr<Token> make_token(TokenType const& p_tt);

		/// Besides calling the make_token function this will call
		/// next_token() beforehand which makes it useful as a helper function
		/// for those tokens which are created by their last read character
		/// as next_token() function has to be called with a filled pipeline.
		std::unique_ptr<Token> make_token_next(TokenType const& p_tt);

		/// This function will be called after a line comment has been detected
		/// and will skip any character until it successfully reads a line break.
		std::unique_ptr<Token> scan_line_comment();

		/// This function will be called after a multi-line comment has been detected
		/// and will skip any character until it successfully reads its end.
		std::unique_ptr<Token> scan_comment();

		/// This function will be called after a character literal start (') has been
		/// detected and will read any character (but line breaks) until it successfully
		/// reads its ending character. (')
		std::unique_ptr<Token> scan_char();

		/// This function will be called after a string literal start (") has been
		/// detected and will read any character (but line breaks) until it successfully
		/// reads its ending character. (")
		std::unique_ptr<Token> scan_string();

		/// This function will be called whenever a digit [0-9] is read as this indicates
		/// the starting point for any number token in Cion. The function will
		/// delegate to the scan_float function whenever it detects that its read
		/// number is in fact a float literal.
		std::unique_ptr<Token> scan_number();

		/// This function will be called whenever a float literal has been detected
		/// and represents the detection of a float literal after a dot has been read.
		/// p_req_digits indicates whether it is a requirement for this function to read
		/// at least a single digit after the dot.
		std::unique_ptr<Token> scan_float(bool p_req_digits);

		/// This function will be called whenever an identifier could have been detected.
		/// It iteratively scans the input for a generic identifier and checks the
		/// resulting buffer if it is a keyword. Returns either identifier tokens or
		/// any keyword token.
		std::unique_ptr<Token> scan_identifier();

//////////////////////////////////////////////////////////////////////////////////////////
/////// Member Variables
//////////////////////////////////////////////////////////////////////////////////////////

		std::istream & m_input;
		ErrorHandler & m_error_handler;
		std::string m_buffer;
		std::unordered_map<std::string, TokenType> m_keywords;
		SourceLocation m_start_loc;
		SourceLocation m_end_loc_0;
		SourceLocation m_end_loc_1;
		SourceLocation * m_cur_end_loc;
		SourceLocation * m_prv_end_loc;
		char m_cur_char;
		CionTokenTypes const& ctts;
	};
} // namespace cion

#endif // CION_CION_LEXER_HEADER
