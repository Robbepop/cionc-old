#include "error/lexer_error.hpp"

namespace cion {
	lexer_error::lexer_error(
		SourceLocation const& source_location,
		std::string const& file_name,
		std::string const& message
	):
		std::runtime_error{message},
		m_source_location{source_location},
		m_file_name{file_name}
	{}

	SourceLocation::loc_type lexer_error::get_line_num() const noexcept {
		return m_source_location.get_line();
	}

	SourceLocation::loc_type lexer_error::get_column_num() const noexcept {
		return m_source_location.get_col();
	}

	std::string const& lexer_error::get_file_name() const noexcept {
		return m_file_name;
	}

	std::string const& lexer_error::get_message() const noexcept {
		return m_message;
	}

	char const* lexer_error::what() const noexcept {
		return get_message().c_str();
	}
} // namespace cion
