#include "cion/lexer/cion_lexer.hpp"
#include "cion/token/cion_token_types.hpp"
#include "cion/error/cion_error_types.hpp"
#include "cion/token/token_fabric.hpp"

#include <cassert>
#include <cstdint>
#include <iostream>
#include <string>
#include <algorithm>

namespace cion {
	CionLexer::CionLexer(
		std::istream & p_input,
		ErrorHandler & p_error_handler
	):
		m_input{p_input},
		m_error_handler{p_error_handler},
		m_buffer{""},
		m_keywords{},
		m_start_loc{1,0},
		m_end_loc_0{1,0},
		m_end_loc_1{1,0},
		m_cur_end_loc{std::addressof(m_end_loc_0)},
		m_prv_end_loc{std::addressof(m_end_loc_1)},
		m_cur_char{'\0'},
		ctts{CionTokenTypes::get_instance()},
		errors{CionErrorTypes::get_instance()}
	{
		next_char();
		add_keyword("var", ctts.cmd_var);
		add_keyword("val", ctts.cmd_val);
		add_keyword("function", ctts.cmd_function);

		add_keyword("true", ctts.lit_bool);
		add_keyword("false", ctts.lit_bool);

		add_keyword("void", ctts.type_void);
		add_keyword("bool", ctts.type_bool);
		add_keyword("char", ctts.type_char);

		add_keyword("int", ctts.type_int);
		add_keyword("int8", ctts.type_int8);
		add_keyword("int16", ctts.type_int16);
		add_keyword("int32", ctts.type_int32);
		add_keyword("int64", ctts.type_int64);
		add_keyword("uint", ctts.type_uint);
		add_keyword("uint8", ctts.type_uint8);
		add_keyword("uint16", ctts.type_uint16);
		add_keyword("uint32", ctts.type_uint32);
		add_keyword("uint64", ctts.type_uint64);
		add_keyword("float", ctts.type_float);
		add_keyword("float16", ctts.type_float16);
		add_keyword("float32", ctts.type_float32);
		add_keyword("float64", ctts.type_float64);

		add_keyword("if", ctts.cmd_if);
		add_keyword("else", ctts.cmd_else);
		add_keyword("while", ctts.cmd_while);

		add_keyword("break", ctts.cmd_break);
		add_keyword("continue", ctts.cmd_continue);
		add_keyword("return", ctts.cmd_return);
	}

	void CionLexer::add_keyword(std::string const& p_key, TokenType const& p_tt) {
		assert(m_keywords.insert({p_key, p_tt}).second);
	}

	bool CionLexer::is_digit(char p_char) const {
		return p_char >= '0' && p_char <= '9';
	}

	bool CionLexer::is_digit() const {
		return is_digit(cur_char());
	}

	bool CionLexer::is_non_zero_digit(char p_char) const {
		return p_char >= '1' && p_char <= '9';
	}

	bool CionLexer::is_non_zero_digit() const {
		return is_non_zero_digit(cur_char());
	}

	bool CionLexer::is_alpha(char p_char) const {
		return (p_char >= 'a' && p_char <= 'z')
			|| (p_char >= 'A' && p_char <= 'Z')
			|| (p_char == '_');
	}

	bool CionLexer::is_alpha() const {
		return is_alpha(cur_char());
	}

	bool CionLexer::is_alpha_num(char p_char) const {
		return is_alpha(p_char) || is_digit(p_char);
	}

	bool CionLexer::is_alpha_num() const {
		return is_alpha_num(cur_char());
	}

	bool CionLexer::is_keyword(std::string p_word) const {
		return m_keywords.find(p_word) != m_keywords.end();
	}

	bool CionLexer::is_keyword() const {
		return is_keyword(valid_buffer());
	}

	SourceLocation & CionLexer::cur_end_loc() {
		return *m_cur_end_loc;
	}

	SourceLocation & CionLexer::prv_end_loc() {
		return *m_prv_end_loc;
	}

	void CionLexer::update_loc() {
		std::swap(m_cur_end_loc, m_prv_end_loc);
		if (cur_char() == '\n') {
			cur_end_loc().col() = 0;
			cur_end_loc().line() = prv_end_loc().line() + 1;
		} else {
			cur_end_loc().col() = prv_end_loc().col() + 1;
			cur_end_loc().line() = prv_end_loc().line();
		}
	}

	char CionLexer::next_char() {
		m_input.get(m_cur_char);
		m_buffer.push_back(cur_char());
		update_loc();
		return cur_char();
	}

	char CionLexer::next_char_ignore() {
		m_input.get(m_cur_char);
		update_loc();
		return cur_char();
	}

	std::string CionLexer::valid_buffer() const {
		return m_buffer.substr(0, m_buffer.length() - 1);
	}

	char CionLexer::cur_char() const {
		return m_cur_char;
	}

	std::unique_ptr<Token> CionLexer::make_token(TokenType const& p_tt) {
		auto token =
			TokenFabric::make_token(p_tt, m_start_loc, cur_end_loc(), valid_buffer());

		//std::cout << "make_token() = " << p_tt.get_name() << ", " << valid_buffer() <<
		//	" (" << m_start_loc.line() << "," << m_start_loc.col() << ") -> " <<
		//	"(" << prv_end_loc().line() << "," << prv_end_loc().col() << ")\n";

		m_buffer = m_buffer.back();
		return token;
	}

	std::unique_ptr<Token> CionLexer::make_token_next(TokenType const& p_tt) {
		next_char();
		return make_token(p_tt);
	}

	std::unique_ptr<Token> CionLexer::make_error(
		ErrorType p_error_type,
		std::string const& p_message
	) {
		m_error_handler.error(p_error_type, m_start_loc, p_message);
		return make_token(TokenType::error);
	}

	std::unique_ptr<Token> CionLexer::make_error(
		ErrorType p_error_type
	) {
		return make_error(p_error_type, valid_buffer());
	}

	std::unique_ptr<Token> CionLexer::make_error_next(
		ErrorType p_error_type,
		std::string const& p_message
	) {
		next_char();
		return make_error(p_error_type, p_message);
	}

	std::unique_ptr<Token> CionLexer::make_error_next(
		ErrorType p_error_type
	) {
		return make_error_next(p_error_type, valid_buffer());
	}

	std::unique_ptr<Token> CionLexer::next_token() {
		m_start_loc = cur_end_loc();
		if (m_input.eof()) {
			return make_token(TokenType::eof);
		}
		switch (cur_char()) {
			// handle case for eof token
			case -1: return make_token(TokenType::eof);

			// skip whitespace
			case ' ':
			case '\r':
			case '\n':
			case '\t':
				m_buffer.pop_back();
				next_char();
				return next_token();

			// parens, brackets and braces
			case '(': return make_token_next(ctts.opening_paren);
			case '[': return make_token_next(ctts.opening_brack);
			case '{': return make_token_next(ctts.opening_brace);
			case ')': return make_token_next(ctts.closing_paren);
			case ']': return make_token_next(ctts.closing_brack);
			case '}': return make_token_next(ctts.closing_brace);

			// tokens which aren't a prefix of any other token type
			case '?': return make_token_next(ctts.op_question_mark);
			case ';': return make_token_next(ctts.op_semi_colon);
			case ':': return make_token_next(ctts.op_colon); // no op_colon_colon !
			case ',': return make_token_next(ctts.op_comma);

			// operator + / ++ / +=
			case '+':
				switch (next_char()) {
					case '+': return make_token_next(ctts.op_plus_plus);
					case '=': return make_token_next(ctts.op_plus_equals);
					default : return make_token(ctts.op_plus);
				}

			// operator - / -- / -= / ->
			case '-':
				switch (next_char()) {
					case '-': return make_token_next(ctts.op_minus_minus);
					case '=': return make_token_next(ctts.op_minus_equals);
					case '>': return make_token_next(ctts.op_arrow);
					default : return make_token(ctts.op_minus);
				}

			// operator * / *=
			case '*':
				switch (next_char()) {
					case '=': return make_token_next(ctts.op_star_equals);
					default : return make_token(ctts.op_star);
				}

			// operator / and /= aswell as line-comment and multi-line comment
			case '/':
				switch (next_char()) {
					case '=': return make_token_next(ctts.op_slash_equals);
					case '/': return scan_line_comment();
					case '*': return scan_comment();
					default : return make_token(ctts.op_slash);
				}

			// operator % / %=
			case '%':
				switch (next_char()) {
					case '=': return make_token_next(ctts.op_percent_equals);
					default : return make_token(ctts.op_percent);
				}

			// operator ^ / ^=
			case '^':
				switch (next_char()) {
					case '=': return make_token_next(ctts.op_caret_equals);
					default : return make_token(ctts.op_caret);
				}

			// operator ~ / ~=
			case '~':
				switch (next_char()) {
					case '=': return make_token_next(ctts.op_tilde_equals);
					default : return make_token(ctts.op_tilde);
				}

			// operator ! / !=
			case '!':
				switch (next_char()) {
					case '=': return make_token_next(ctts.op_not_equals);
					default : return make_token(ctts.op_exclam_mark);
				}

			// operator = / ==
			case '=':
				switch (next_char()) {
					case '=': return make_token_next(ctts.op_equals_equals);
					default : return make_token(ctts.op_equals);
				}

			// operator & / &= / && / &&=
			case '&':
				switch (next_char()) {
					case '=': return make_token_next(ctts.op_and_equals);
					case '&':
						switch (next_char()) {
							case '=': return make_token_next(ctts.op_and_and_equals);
							default : return make_token(ctts.op_and_and);
						}
					default : return make_token(ctts.op_and);
				}

			// operator | / |= / || / ||=
			case '|':
				switch (next_char()) {
					case '=': return make_token_next(ctts.op_pipe_equals);
					case '|':
						switch (next_char()) {
							case '=': return make_token_next(ctts.op_pipe_pipe_equals);
							default : return make_token(ctts.op_pipe_pipe);
						}
					default : return make_token(ctts.op_pipe);
				}

			// operator < / <= / << / <<=
			case '<':
				switch (next_char()) {
					case '=': return make_token_next(ctts.op_less_equals);
					case '<':
						switch (next_char()) {
							case '=': return make_token_next(ctts.op_left_left_equals);
							default : return make_token(ctts.op_left_left);
						}
					default : return make_token(ctts.op_less_than);
				}

			// operator > / >= / >> / >>=
			case '>':
				switch (next_char()) {
					case '=': return make_token_next(ctts.op_greater_equals);
					case '>':
						switch (next_char()) {
							case '=': return make_token_next(ctts.op_right_right_equals);
							default : return make_token(ctts.op_right_right);
						}
					default : return make_token(ctts.op_greater_than);
				}

			// parse char literal
			case '\'': return scan_char();

			// parse string literal
			case '\"': return scan_string();

			// parse identifier or number
			default:
				if (is_alpha()) {
					return scan_identifier();
				} else if (is_digit()) {
					return scan_number();
				}
		}
		return make_error_next(errors.unknown_token_type);
	}

	std::unique_ptr<Token> CionLexer::scan_line_comment() {
		assert(cur_char() == '/');
		next_char_ignore();
		while (cur_char() != '\r' && cur_char() != '\n') {
			next_char_ignore();
		}
		m_buffer.clear();
		next_char();
		return next_token();
	}

	std::unique_ptr<Token> CionLexer::scan_comment() {
		assert(cur_char() == '*');
		next_char_ignore();
		while (true) {
			if (cur_char() == '*') {
				if (next_char_ignore() == '/') {
					m_buffer.clear();
					next_char();
					return next_token();
				}
			} else {
				next_char_ignore();
			}
		}
	}

	std::unique_ptr<Token> CionLexer::scan_char() {
		assert(cur_char() == '\'');
		next_char();
		while (cur_char() != '\n' && cur_char() != '\r' && cur_char() != '\'') {
			next_char();
		}
		if (cur_char() == '\'') {
			return make_token_next(ctts.lit_char);
		}
		return make_error(errors.broken_char_literal);
	}

	std::unique_ptr<Token> CionLexer::scan_string() {
		assert(cur_char() == '\"');
		next_char();
		while (cur_char() != '\n' && cur_char() != '\r' && cur_char() != '\"') {
			next_char();
		}
		if (cur_char() == '\"') {
			return make_token_next(ctts.lit_string);
		}
		return make_error(errors.broken_string_literal);
	}

	std::unique_ptr<Token> CionLexer::scan_number() {
		assert(is_digit());

		// number sequence begins with [1-9]
		if (is_non_zero_digit()) {
			while (is_digit()) {
				next_char();
			}
			if (cur_char() == '.') {
				return scan_float(false);
			} else {
				return make_token(ctts.lit_integral);
			}

		// number sequence begins with '0'
		} else {
			next_char();
			if (cur_char() == '.') {
				return scan_float(false);
			} else if (is_digit()) {
				return make_error(
					errors.broken_number_literal,
					"no digits may follow a '0' number literal");
			} else {
				return make_token(ctts.lit_integral);
			}
		}
	}

	std::unique_ptr<Token> CionLexer::scan_float(bool p_req_digits) {
		assert(cur_char() == '.');
		next_char();
		auto count_digits = uint32_t{0};
		while (is_digit()) {
			next_char(); ++count_digits;
		}
		if (p_req_digits && count_digits == 0) {
			return make_error(
				errors.broken_number_literal,
				"since no digits are before the '.' there must be digits afterwards in a number literal.");
		}
		if (cur_char() == 'e') {
			next_token();
			if (cur_char() == '+' || cur_char() == '-') {
				next_token();
			} else {
				return make_error(
					errors.broken_number_literal,
					"explicit exponent must be followed by a +/- sign");
			}
			if (is_non_zero_digit()) {
				next_char();
				while (is_digit()) {
					next_char();
				}
			} else {
				return make_error(
					errors.broken_number_literal,
					"explicit exponent must be followed by a valid number.");
			}
		}
		return make_token(ctts.lit_number);
	}

	std::unique_ptr<Token> CionLexer::scan_identifier() {
		assert(is_alpha());
		next_char();
		while (is_alpha_num()) {
			next_char();
		}
		if (is_keyword(valid_buffer())) {
			return make_token(m_keywords.at(valid_buffer()));
		}
		return make_token(ctts.identifier);
	}
} // namespace cion
