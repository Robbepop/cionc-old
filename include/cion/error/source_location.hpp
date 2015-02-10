#ifndef CION_SOURCE_LOCATION_HEADER
#define CION_SOURCE_LOCATION_HEADER

#include <cstdint>
#include <utility>

namespace cion {
	class SourceLocation {
	public:
		using loc_type = uint64_t;

		SourceLocation() = default;
		SourceLocation(loc_type line, loc_type col);

		SourceLocation & operator=(SourceLocation const& rhs) = default;

		loc_type const& line() const;
		loc_type const& col() const;

		loc_type & line();
		loc_type & col();

	private:
		loc_type m_line = 1;
		loc_type m_col = 1;
	};
}

#endif // CION_SOURCE_LOCATION_HEADER
