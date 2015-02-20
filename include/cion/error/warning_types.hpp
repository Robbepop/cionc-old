#ifndef CION_ERROR_WARNING_TYPES_HEADER
#define CION_ERROR_WARNING_TYPES_HEADER

#include "cion/error/warning_type.hpp"

#include <vector>
#include <string>

namespace cion {

	class WarningTypes {
	public:
		static WarningTypes const& instance();

		std::vector<WarningType> get_warnings() const;

	private:
		WarningTypes();
		WarningTypes(WarningTypes const&) = delete;
		WarningTypes(WarningTypes &&) = delete;

		WarningTypes & operator=(WarningTypes const&) = delete;
		WarningTypes & operator=(WarningTypes &&) = delete;

		WarningType init_warning(WarningType warning_type);

		std::vector<WarningType> m_warnings;

	public:
		WarningType const
			dummy_warning;
	};

} // namespace cion

#endif // CION_ERROR_CION_WARNING_TYPES_HEADER
