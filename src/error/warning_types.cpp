#include "cion/error/warning_types.hpp"

#include <utility>

namespace cion {

	WarningTypes const& WarningTypes::instance() {
		static WarningTypes c_instance;
		return c_instance;
	}

	std::vector<WarningType> WarningTypes::get_warnings() const {
		return m_warnings;
	}

	WarningType WarningTypes::init_warning(WarningType warning_type) {
		m_warnings.push_back(warning_type);
		return std::move(warning_type);
	}

	WarningTypes::WarningTypes():
		m_warnings{},
		dummy_warning{init_warning({"dummy warning"})}
	{}

} // namespace cion
