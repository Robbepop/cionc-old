#ifndef CION_CION_ERROR_HANDLER_HEADER
#define CION_CION_ERROR_HANDLER_HEADER

#include "cion/error/error_handler.hpp"

#include <string>

namespace cion {

	class CionErrorHandler : public ErrorHandler {
	public:
		CionErrorHandler(std::string const& translation_unit);

		void error(
			ErrorType const& type,
			SourceLocation const& loc,
			std::string const& message = "") const override;

		void warning(
			WarningType const& type,
			SourceLocation const& loc,
			std::string const& message = "") const override;
	};

} // namespace cion

#endif // CION_CION_ERROR_HANDLER_HEADER
