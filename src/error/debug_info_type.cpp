#include "cion/error/debug_info_type.hpp"

namespace cion {

	DebugInfoType::DebugInfoType(std::string const& name) :
		m_name{name}
	{}

	bool DebugInfoType::operator==(DebugInfoType const& other) const {
		return m_name == other.get_name();	
	}

	bool DebugInfoType::operator!=(DebugInfoType const& other) const {
		return m_name != other.get_name();
	}

	std::string const& DebugInfoType::get_name() const {
		return m_name;
	}

} // namespace cion
