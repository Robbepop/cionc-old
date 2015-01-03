#include "error/parser_error.hpp"

#include <sstream>

namespace cion {
	parser_error::parser_error(
		Token const& token,
		std::string const& file_name,
		std::string const& message
	):
		std::runtime_error{message},
		m_token{token},
		m_file_name{file_name}
	{
		std::ostringstream oss;
		oss << get_file_name()
		    << ":" << token.get_source_location().get_line()
		    << ":" << token.get_source_location().get_col()
		    << ":" << message;
		m_message = oss.str();
	}

	Token const& parser_error::get_token() const noexcept {
		return m_token;
	}

	std::string const& parser_error::get_file_name() const noexcept {
		return m_file_name;
	}

	std::string const& parser_error::get_message() const noexcept {
		return m_message;
	}

	char const* parser_error::what() const noexcept {
		return get_message().c_str();
	}
} // namespace cion
