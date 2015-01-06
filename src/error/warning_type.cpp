#include "error/warning_type.hpp"

namespace cion {

	WarningType::WarningType(std::string const& name, bool default_activ):
		DebugInfoType{name},
		m_activ{default_activ}
	{}

	bool WarningType::is_error() const {
		return false;
	}

	bool WarningType::is_warning() const {
		return !is_error();
	}

	bool WarningType::is_activ() const {
		return m_activ;
	}

} // namespace cion
