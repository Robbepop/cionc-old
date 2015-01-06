#ifndef CION_ERROR_DEBUG_INFO_TYPE_HEADER
#define CION_ERROR_DEBUG_INFO_TYPE_HEADER

#include <string>

namespace cion {

	class DebugInfoType {
	protected:
		DebugInfoType(std::string const& name);

	public:
		virtual bool is_error() const = 0;
		virtual bool is_warning() const = 0;
		virtual bool is_activ() const = 0;

		bool operator==(DebugInfoType const& rhs) const;
		bool operator!=(DebugInfoType const& rhs) const;

		std::string const& get_name() const;

	private:
		std::string m_name;
	};

} // namespace cion

#endif // CION_ERROR_DEBUG_INFO_TYPE_HEADER
