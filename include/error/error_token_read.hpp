#ifndef CION_ERROR_TOKEN_READ_HEADER
#define CION_ERROR_TOKEN_READ_HEADER

#include "error/lexer_error.hpp"
#include "error/source_location.hpp"

namespace cion {
	class error_token_read : public lexer_error {
	public:
		explicit error_token_read(
			//uint64_t line_num = 0,
			//uint64_t col_num = 0,
			SourceLocation const& source_location = {},
			std::string const& file_name = "",
			std::string const& buffer_content = "");
	};
}

#endif // CION_ERROR_TOKEN_READ_HEADER
