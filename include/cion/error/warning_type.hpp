#ifndef CION_ERROR_WARNING_TYPE_HEADER
#define CION_ERROR_WARNING_TYPE_HEADER

#include "cion/error/debug_info_type.hpp"

#include <string>

namespace cion {

	class WarningType final : public DebugInfoType {
	public:
		WarningType(std::string const& name, bool default_activ = true);

		bool is_error() const override;
		bool is_warning() const override;
		bool is_activ() const override;

		bool set_activ(bool flag);

	private:
		bool m_activ;
	};

} // namespace cion

#endif // CION_ERROR_WARNING_TYPE_HEADER
