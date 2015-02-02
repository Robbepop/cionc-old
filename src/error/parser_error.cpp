#include "error/parser_error.hpp"

#include <sstream>

namespace cion {
	parser_error::parser_error(
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

	SourceLocation const& parser_error::loc() const noexcept {
		return m_source_location;
	}

	std::string const& parser_error::file_name() const noexcept {
		return m_file_name;
	}

	std::string const& parser_error::message() const noexcept {
		return m_message;
	}

	char const* parser_error::what() const noexcept {
		return message().c_str();
	}
} // namespace cion
