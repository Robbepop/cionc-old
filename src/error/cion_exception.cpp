#include "cion/error/cion_exception.hpp"

#include <sstream>

namespace cion {

	cion_exception::cion_exception(		
		std::string const& file_name,
		SourceLocation const& source_location,
		std::string const& message
	):
		std::runtime_error{message},
		m_file_name{file_name},
		m_loc{source_location}
	{}

	SourceLocation const& cion_exception::loc() const noexcept {
		return m_loc;
	}

	std::string const& cion_exception::file_name() const noexcept {
		return m_file_name;
	}

	std::string cion_exception::message() const noexcept {
		std::stringstream ss;
		ss
			<< file_name() << ":"
			<< loc().line() << ":" << loc().col() << ": "
			<< what();
		return ss.str();
	}

} // namespace cion
