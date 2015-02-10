#include "cion/error/cion_error_handler.hpp"

#include <iostream>
#include <tuple>

namespace cion {

	CionErrorHandler::CionErrorHandler(
		std::string const& file_name
	):
		ErrorHandler{file_name}
	{}

	void CionErrorHandler::error(
		ErrorType const& type,
		SourceLocation const& loc,
		std::string const& message
	) const {
		std::ignore = type;
		std::cerr
			<< "error in "
			<< file_name()
			<< ':' << loc.line() << ':' << loc.col() << ": "
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
			<< file_name()
			<< ':' << loc.line() << ':' << loc.col() << ": "
			<< message << "\n";
	}

} // namespace cion
