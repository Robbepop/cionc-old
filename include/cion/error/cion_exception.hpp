#ifndef CION_ERROR_CION_EXCEPTION_HEADER
#define CION_ERROR_CION_EXCEPTION_HEADER

#include "cion/error/source_location.hpp"

#include <exception>
#include <stdexcept>
#include <string>
#include <memory>

namespace cion {
	class cion_exception : public std::runtime_error {
	public:
		cion_exception(
			std::string const& file_name,
			SourceLocation const& source_loc,
			std::string const& message);

		SourceLocation const& loc() const noexcept;

		std::string const& file_name() const noexcept;

		std::string message() const noexcept;

	private:
		std::string m_file_name;
		SourceLocation m_loc;
	};
} // namespace

#endif // CION_ERROR_CION_EXCEPTION_HEADER
