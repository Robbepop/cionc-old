#include "error/source_location.hpp"

namespace cion {

	SourceLocation::SourceLocation(loc_type line, loc_type col) :
		m_line{line},
		m_col{col}
	{}

	SourceLocation::loc_type SourceLocation::set_line(
		SourceLocation::loc_type new_value)
	{
		return m_line = new_value;
	}

	SourceLocation::loc_type SourceLocation::set_col(
		SourceLocation::loc_type new_value
	) {
		return m_col = new_value;
	}

	SourceLocation::loc_type SourceLocation::get_line() const {
		return m_line;
	}

	SourceLocation::loc_type SourceLocation::get_col() const {
		return m_col;
	}

	std::pair<SourceLocation::loc_type, SourceLocation::loc_type>
	SourceLocation::get_loc() const {
		return std::make_pair(get_line(), get_col());
	}

} // namespace cion
