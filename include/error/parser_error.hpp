#ifndef CION_PARSER_ERROR_HEADER
#define CION_PARSER_ERROR_HEADER

#include "token/token.hpp"

#include <exception>
#include <stdexcept>
#include <string>
#include <memory>

namespace cion {
	class parser_error : public std::runtime_error {
	public:
		explicit parser_error(
			Token const& token,
			std::string const& file_name = "",
			std::string const& message = "");

		Token const& get_token() const noexcept;

		std::string const& get_file_name() const noexcept;

		std::string const& get_message() const noexcept;

		virtual char const* what() const noexcept override;
	private:
		Token const& m_token;
		std::string m_file_name;

	protected:
		std::string m_message;
	};
} // namespace

#endif // CION_PARSER_ERROR_HEADER
