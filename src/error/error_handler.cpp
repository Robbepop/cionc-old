#include "error/error_handler.hpp"

namespace cion {

	ErrorHandler::ErrorHandler(
		std::string const& file_name
	):
		m_file_name{file_name}
	{}

	std::string const& ErrorHandler::file_name() const {
		return m_file_name;
	}

} // namespace cion
