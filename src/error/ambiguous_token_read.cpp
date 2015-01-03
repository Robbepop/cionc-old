#include "error/ambiguous_token_read.hpp"

#include <sstream>

namespace cion {
	ambiguous_token_read::ambiguous_token_read(
		SourceLocation const& source_location,
		std::string const& file_name,
		std::string const& buffer_content
	):
		lexer_error{source_location, file_name, buffer_content}
	{
		std::ostringstream oss;
		oss << get_file_name()
		    << ":" << get_line_num()
		    << ":" << get_column_num()
		    << ": lexer read ambiguous token with content: " << buffer_content;
		m_message = oss.str();
	}
} // namespace cion
