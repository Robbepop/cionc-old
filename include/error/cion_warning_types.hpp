#ifndef CION_ERROR_CION_WARNING_TYPES_HEADER
#define CION_ERROR_CION_WARNING_TYPES_HEADER

#include "error/warning_type.hpp"

#include <vector>
#include <string>

namespace cion {

	class CionWarningTypes {
	public:
		static CionWarningTypes const& get_instance();

		std::vector<WarningType> get_warnings() const;

	private:
		CionWarningTypes();
		CionWarningTypes(CionWarningTypes const&) = delete;
		CionWarningTypes(CionWarningTypes &&) = delete;

		CionWarningTypes & operator=(CionWarningTypes const&) = delete;
		CionWarningTypes & operator=(CionWarningTypes &&) = delete;

		WarningType init_warning(WarningType warning_type);

		std::vector<WarningType> m_warnings;

	public:
		WarningType const
			dummy_warning;
	};

} // namespace cion

#endif // CION_ERROR_CION_WARNING_TYPES_HEADER
