#include "cion/error/error_handler.hpp"
#include "cion/error/source_location.hpp"

#include <iostream>
#include <tuple>

namespace cion {

	ErrorHandler::ErrorHandler(
		std::string const& p_file_name
	):
		m_file_name{p_file_name}
	{}

	std::string const& ErrorHandler::file_name() const {
		return m_file_name;
	}

	void ErrorHandler::error(
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

	void ErrorHandler::warning(
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
