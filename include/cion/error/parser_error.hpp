#ifndef CION_PARSER_ERROR_HEADER
#define CION_PARSER_ERROR_HEADER

#include "cion/token/token.hpp"

#include <exception>
#include <stdexcept>
#include <string>

namespace cion {
	class parser_error final : public std::runtime_error {
	public:
		explicit parser_error(
			SourceLocation const& source_location = {},
			std::string const& file_name = "",
			std::string const& message = "");

		SourceLocation const& loc() const noexcept;

		std::string const& file_name() const noexcept;

		std::string const& message() const noexcept;

		virtual char const* what() const noexcept override;
	private:
		SourceLocation m_source_location;
		std::string m_file_name;
		std::string m_message;
	};
} // namespace

#endif // CION_PARSER_ERROR_HEADER
