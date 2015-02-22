#ifndef CION_ERROR_REPORT_TYPE_HEADER
#define CION_ERROR_REPORT_TYPE_HEADER

#include <string>

namespace cion {

	class ReportType {
	protected:
		ReportType(std::string const& name);

	public:
		virtual bool is_error() const = 0;
		virtual bool is_warning() const = 0;
		virtual bool is_activ() const = 0;

		bool operator==(ReportType const& rhs) const;
		bool operator!=(ReportType const& rhs) const;

		std::string const& get_name() const;

	private:
		std::string m_name;
	};

	class ErrorType final : public ReportType {
	public:
		ErrorType(std::string const& name);

		bool is_error() const override;
		bool is_warning() const override;
		bool is_activ() const override;
	};

	class WarningType final : public ReportType {
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

#endif // CION_ERROR_REPORT_TYPE_HEADER
