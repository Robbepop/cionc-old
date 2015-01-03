#include "error/cion_error_handler.hpp"

#include <iostream>
#include <tuple>

namespace cion {

	CionErrorHandler::CionErrorHandler(
		std::string const& translation_unit
	):
		ErrorHandler{translation_unit}
	{}

	void CionErrorHandler::error(
		ErrorType const& type,
		SourceLocation const& loc,
		std::string const& message
	) const {
		std::ignore = type;
		std::cerr
			<< "error in "
			<< get_translation_unit()
			<< ':' << loc.get_line() << ':' << loc.get_col() << ": "
			<< message << "\n";
	}

	void CionErrorHandler::warning(
		WarningType const& type,
		SourceLocation const& loc,
		std::string const& message
	) const {
		std::ignore = type;
		std::cerr
			<< "warning in "
			<< get_translation_unit()
			<< ':' << loc.get_line() << ':' << loc.get_col() << ": "
			<< message << "\n";
	}

} // namespace cion
