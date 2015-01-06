#include "lexer/lexer.hpp"
#include "token/token_fabric.hpp"
#include "error/cion_error_types.hpp"
#include "error/lexer_exception.hpp"

#include <exception>
#include <memory>

//#define DEBUG
#ifdef DEBUG
#include <iostream>
#define DEBUG_STDOUT(x) (std::cout << x)
#define DEBUG_STDERR(x) (std::cerr << x)
#undef DEBUG
#else
#define DEBUG_STDOUT(x)
#define DEBUG_STDERR(x)
#endif

namespace cion {

//////////////////////////////////////////////////////////////////////////////////////////
/// LEXER CONSTRUCTORS
//////////////////////////////////////////////////////////////////////////////////////////

	Lexer::Lexer(
		std::istream & inputstream,
		std::vector<TokenType> const& matchable_tokens,
		ErrorHandler const& error_handler
	) :
		m_input{inputstream},
		m_matchable_tokens{matchable_tokens},
		m_error_handler{error_handler}
	{
		m_cur = std::addressof(m_it_data[0]);
		m_last = std::addressof(m_it_data[1]);
	}

//////////////////////////////////////////////////////////////////////////////////////////
/// LEXER ITERATION DATA METHODS
//////////////////////////////////////////////////////////////////////////////////////////

	bool Lexer::IterationData::buffers_empty() const {
		return m_partial_matches.empty() && m_full_matches_greedy.empty() && m_full_matches_non_greedy.empty();
	}

	std::vector<TokenType> & Lexer::IterationData::get_partial_matches() {
		return m_partial_matches;
	}

	std::vector<TokenType> & Lexer::IterationData::get_full_matches_greedy() {
		return m_full_matches_greedy;
	}

	std::vector<TokenType> & Lexer::IterationData::get_full_matches_non_greedy() {
		return m_full_matches_non_greedy;
	}

	void Lexer::IterationData::clear_buffers() {
		m_partial_matches.clear();
		m_full_matches_greedy.clear();
		m_full_matches_non_greedy.clear();
	}

	SourceLocation const& Lexer::IterationData::get_source_location() const {
		return m_source_location;
	}

	SourceLocation & Lexer::IterationData::get_source_location() {
		return m_source_location;
	}

//////////////////////////////////////////////////////////////////////////////////////////
/// LEXER PRIVATE METHODS
//////////////////////////////////////////////////////////////////////////////////////////

	bool Lexer::buffers_empty() {
		return m_cur->buffers_empty() && m_last->buffers_empty();
	}

	void Lexer::check_match(TokenType const& token_type) {
		static boost::match_results<std::string::const_iterator> what;
		if (boost::regex_match(m_buffer, what, token_type.get_regex(), boost::match_default | boost::match_partial)) {
			if (what[0].matched) {
				if (token_type.get_match_type() == TokenType::MatchType::greedy) {
					DEBUG_STDERR("\tcheck_match: " << token_type.get_name() << " (full, greedy)\n");
					m_cur->get_full_matches_greedy().push_back(token_type);
				} else {
					DEBUG_STDERR("\tcheck_match: " << token_type.get_name() << " (full, non-greedy)\n");
					m_cur->get_full_matches_non_greedy().push_back(token_type);
				}
			} else {
				DEBUG_STDERR("\tcheck_match: " << token_type.get_name() << " (partial)\n");
				m_cur->get_partial_matches().push_back(token_type);
			}
		}
	}

	void Lexer::check_matches() {
		DEBUG_STDERR("check_matches: ");
		if (buffers_empty()) {
			//DEBUG_STDERR("check_matches: full check.");
			for (auto&& token_type : m_matchable_tokens) {
				check_match(token_type);
			}
		} else {
			//DEBUG_STDERR("check_matches: only checked last buffers.");
			for (auto&& token_type : m_last->get_partial_matches()) {
				check_match(token_type);
			}
			for (auto&& token_type : m_last->get_full_matches_greedy()) {
				//check_match(token_type);
				if (boost::regex_match(m_buffer, token_type.get_regex())) {
					DEBUG_STDERR("\tcheck_match: " << token_type.get_name() << " (full, greedy)\n");
					m_cur->get_full_matches_greedy().push_back(token_type);
				}
			}
		}
	}

	void Lexer::swap_buffers() {
		//DEBUG_STDERR("swap_buffers: start\n");
		std::swap(m_cur, m_last);
		m_cur->get_source_location() = m_last->get_source_location();
		//DEBUG_STDERR("swap_buffers: end\n");
	}

	void Lexer::clear_cur_buffers() {
		//DEBUG_STDERR("clear_cur_buffers: start\n");
		m_cur->clear_buffers();
		//DEBUG_STDERR("clear_cur_buffers: end\n");
	}

	void Lexer::clear_buffers() {
		//DEBUG_STDERR("clear_buffers: start\n");
		m_buffer.clear();
		m_cur->clear_buffers();
		m_last->clear_buffers();
		//DEBUG_STDERR("clear_buffers: end\n");
	}

	void Lexer::update_lc_numbers() {
		//DEBUG_STDERR("update_lc_numbers: start\n");
		if (m_cur_symbol == '\n') {
			m_cur->get_source_location().line() =
				m_last->get_source_location().line() + 1;
			m_cur->get_source_location().col() = 1;
		} else {
			m_cur->get_source_location().col() =
				m_last->get_source_location().col() + 1;
		}
		//DEBUG_STDERR("update_lc_numbers: end\n);
	}

	void Lexer::step_back() {
		m_input.unget();
		m_cur->get_source_location() = m_last->get_source_location();
		m_buffer.pop_back();
	}

	std::unique_ptr<Token> Lexer::make_error_token(ErrorType type) {
		const auto loc = m_cur->get_source_location();
		m_error_handler.error(type, loc, m_buffer);
		return TokenFabric::make_token(TokenType::error, loc);
	}

//////////////////////////////////////////////////////////////////////////////////////////
/// LEXER PUBLIC METHODS
//////////////////////////////////////////////////////////////////////////////////////////

	// When this function is called it can assume the following states:
	//    - m_buffer is empty
	//    - m_input will read in the last non-comsumed character
	//    - all other buffers are empty
	std::unique_ptr<Token> Lexer::next_token() {
		auto const& errors = CionErrorTypes::get_instance();

		// always return eof token if parser wants next_token while
		// this input stream is known to be fully read already.
		if (m_input.eof()) {
			DEBUG_STDERR("next_token: reached eof -> return eof token\n");
			return TokenFabric::make_token(
				TokenType::eof, m_cur->get_source_location());
		}

		// empty all match buffers
		clear_buffers();

		// read new characters from input stream and check them against
		// the token type's regexes for partial and full match.
		while (m_input.get(m_cur_symbol)) {
			// update buffer, swap match buffers and clear current match buffers
			m_buffer += m_cur_symbol;
			swap_buffers();
			clear_cur_buffers();
			DEBUG_STDERR("\tnext_token - buffer = \"" << m_buffer << "\"\n");

			// count line and column numbers
			update_lc_numbers();

			// check for matches with updated buffer
			check_matches();

			const auto count_partial = m_cur->get_partial_matches().size();
			const auto count_greedy = m_cur->get_full_matches_greedy().size();
			const auto count_non_greedy = m_cur->get_full_matches_non_greedy().size();

			DEBUG_STDERR("\tnext_token: count_partial = " << count_partial << "\n");
			DEBUG_STDERR("\tnext_token: count_greedy = " << count_greedy << "\n");
			DEBUG_STDERR("\tnext_token: count_non_greedy = " << count_non_greedy << "\n");

			if (count_partial > 0 || count_greedy > 0) continue;

			if (count_non_greedy == 1) {
				return TokenFabric::make_token(
					m_cur->get_full_matches_non_greedy()[0],
					m_cur->get_source_location(),
					m_buffer);
			}
			if (count_non_greedy == 0) {
				const auto count_last_greedy =
					m_last->get_full_matches_greedy().size();
				const auto count_last_non_greedy =
					m_last->get_full_matches_non_greedy().size();
				if (count_last_non_greedy == 1) {
					step_back();
					return TokenFabric::make_token(
						m_last->get_full_matches_non_greedy()[0],
						m_last->get_source_location(),
						m_buffer);
				}
				if (count_last_greedy == 1) {
					step_back();
					return TokenFabric::make_token(
						m_last->get_full_matches_greedy()[0],
						m_last->get_source_location(),
						m_buffer);
				}
				if (count_last_greedy == 0 || count_last_non_greedy == 0) {
					DEBUG_STDERR("throw error_token_read since no matching token was found. (1)\n");
					return make_error_token(errors.unknown_token_type);
					//return TokenFabric::make_token(
					//	TokenType::error, m_cur->get_source_location());
					//throw error_token_read(
					//	m_last->get_source_location(), "asd", m_buffer);
				}
				if (count_last_non_greedy >= 2) {
					DEBUG_STDERR("throw ambigous_token_read since multiple same-priority matches were found. (1)\n");
					throw lexer_exception(
						m_error_handler.file_name(),
						m_last->get_source_location(),
						m_buffer);
				}
			}
		}

		if (m_input.eof()) {
			const auto count_partial = m_cur->get_partial_matches().size();
			const auto count_greedy = m_cur->get_full_matches_greedy().size();
			const auto count_non_greedy = m_cur->get_full_matches_non_greedy().size();
			if (count_non_greedy == 1) {
				return TokenFabric::make_token(
					m_cur->get_full_matches_non_greedy()[0],
					m_cur->get_source_location(),
					m_buffer);
			}
			if (count_greedy == 1) {
				return TokenFabric::make_token(
					m_cur->get_full_matches_greedy()[0],
					m_cur->get_source_location(),
					m_buffer);
			}
			if (count_greedy >= 2 || count_non_greedy >= 2) {
				DEBUG_STDERR("throw ambigous_token_read since multiple same-priority matches were found. (2)\n");
				throw lexer_exception(
					m_error_handler.file_name(),
					m_cur->get_source_location(),
					m_buffer);
			}
			if (count_partial > 0) {
				DEBUG_STDERR("throw error_token_read since no matching token was found. (2)\n");
				return make_error_token(errors.unknown_token_type);
				//return TokenFabric::make_token(
				//	TokenType::error, m_cur->get_source_location());
				//throw error_token_read(
				//	m_cur->get_source_location(), "123", m_buffer);
			}
			return TokenFabric::make_token(TokenType::eof, m_cur->get_source_location());
		}

		// since no constraint has fit to any buffer set-up above
		// it is safe to assume that the read token was errornous.
		DEBUG_STDERR("throw error_token_read since no matching token was found. (3)\n");
		return make_error_token(errors.unknown_token_type);
		//return TokenFabric::make_token(
		//	TokenType::error, m_cur->get_source_location());
		//throw error_token_read(
		//	m_cur->get_source_location(), "yxc", m_buffer);
	}
}
