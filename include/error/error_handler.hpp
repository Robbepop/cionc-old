#ifndef CION_ERROR_HANDLER_HEADER
#define CION_ERROR_HANDLER_HEADER

#include "error/error_type.hpp"
#include "error/warning_type.hpp"
#include "error/source_location.hpp"

#include <string>

namespace cion {

	class ErrorHandler {
	public:
		ErrorHandler(std::string const& translation_unit);

		std::string get_translation_unit() const;

		virtual void error(
			ErrorType const& type,
			SourceLocation const& loc,
			std::string const& message = "") const = 0;

		virtual void warning(
			WarningType const& type,
			SourceLocation const& loc,
			std::string const& message = "") const = 0;

	private:
		std::string m_translation_unit;
	};

} // namespace cion

#endif // CION_ERROR_HANDLER_HEADER
