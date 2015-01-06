#include "error/cion_warning_types.hpp"

#include <utility>

namespace cion {

	CionWarningTypes const& CionWarningTypes::get_instance() {
		static CionWarningTypes c_instance;
		return c_instance;
	}

	std::vector<WarningType> CionWarningTypes::get_warnings() const {
		return m_warnings;
	}

	WarningType CionWarningTypes::init_warning(WarningType warning_type) {
		m_warnings.push_back(warning_type);
		return std::move(warning_type);
	}

	CionWarningTypes::CionWarningTypes():
		m_warnings{},
		dummy_warning{init_warning({"dummy warning"})}
	{}

} // namespace cion
