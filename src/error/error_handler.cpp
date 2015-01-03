#include "error/error_handler.hpp"

namespace cion {

	ErrorHandler::ErrorHandler(
		std::string const& translation_unit
	):
		m_translation_unit{translation_unit}
	{}

	std::string ErrorHandler::get_translation_unit() const {
		return m_translation_unit;
	}

} // namespace cion
