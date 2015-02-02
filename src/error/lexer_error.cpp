#include "error/lexer_error.hpp"

#include <sstream>

namespace cion {
	lexer_error::lexer_error(
		SourceLocation const& source_location,
		std::string const& file_name,
		std::string const& message
	):
		std::runtime_error{message},
		m_source_location{source_location},
		m_file_name{file_name}
	{
		std::ostringstream oss;
		oss << m_file_name
		    << ":" << m_source_location.line()
		    << ":" << m_source_location.col()
		    << ":" << message;
		m_message = oss.str();
	}

	SourceLocation const& lexer_error::loc() const noexcept {
		return m_source_location;
	}

	std::string const& lexer_error::file_name() const noexcept {
		return m_file_name;
	}

	std::string const& lexer_error::message() const noexcept {
		return m_message;
	}

	char const* lexer_error::what() const noexcept {
		return message().c_str();
	}
} // namespace cion
