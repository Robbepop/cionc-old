#ifndef AMBIGUOUS_TOKEN_READ_HEADER
#define AMBIGUOUS_TOKEN_READ_HEADER

#include "error/lexer_error.hpp"
#include "error/source_location.hpp"

namespace cion {
	class ambiguous_token_read : public lexer_error {
	public:
		explicit ambiguous_token_read(
			//uint64_t line_num = 0,
			//uint64_t col_num = 0,
			SourceLocation const& source_location = {},
			std::string const& file_name = "",
			std::string const& buffer_content = "");
	};
} // namespace cion

#endif // AMBIGUOUS_TOKEN_READ_HEADER
