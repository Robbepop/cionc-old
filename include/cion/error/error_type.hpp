#ifndef CION_ERROR_ERROR_TYPE_HEADER
#define CION_ERROR_ERROR_TYPE_HEADER

#include "cion/error/debug_info_type.hpp"

#include <string>

namespace cion {

	class ErrorType final : public DebugInfoType {
	public:
		ErrorType(std::string const& name);

		bool is_error() const override;
		bool is_warning() const override;
		bool is_activ() const override;
	};

} // namespace cion

#endif // CION_ERROR_ERROR_TYPE_HEADER
