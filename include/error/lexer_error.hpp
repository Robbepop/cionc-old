#ifndef CION_LEXER_ERROR_HEADER
#define CION_LEXER_ERROR_HEADER

#include "error/source_location.hpp"

#include <exception>
#include <stdexcept>
#include <string>

namespace cion {
	class lexer_error : public std::runtime_error {
	public:
		explicit lexer_error(
			SourceLocation const& source_location = {},
			std::string const& file_name = "",
			std::string const& message = "");

		uint64_t get_line_num() const noexcept;

		uint64_t get_column_num() const noexcept;

		std::string const& get_file_name() const noexcept;

		std::string const& get_message() const noexcept;

		virtual char const* what() const noexcept override;
	private:
		SourceLocation m_source_location;
		std::string m_file_name;

	protected:
		std::string m_message;
	};
} // namespace

#endif // CION_LEXER_ERROR_HEADER
