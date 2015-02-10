#include "cion/token/token_type.hpp"

namespace cion {
	const TokenType TokenType::undefined = {"undefined"};
	const TokenType TokenType::error = {"error"};
	const TokenType TokenType::eof = {"end of file (eof)"};

	TokenType::Data::Data(
		std::string const& name,
		std::string const& regex,
		TokenTypeStore store_type,
		TokenType::MatchType match_type
	):
		m_name{name},
		m_regex{boost::regex(regex, boost::regex_constants::optimize)},
		m_store_type{store_type},
		m_match_type{match_type}
	{}

	std::string const& TokenType::Data::get_name() const {
		return m_name;
	}

	boost::regex const& TokenType::Data::get_regex() const {
		return m_regex;
	}

	TokenType::MatchType TokenType::Data::get_match_type() const {
		return m_match_type;
	}

	TokenTypeStore TokenType::Data::get_store_type() const {
		return m_store_type;
	}

	TokenType::TokenType(
		std::string const& name,
		std::string const& regex,
		TokenTypeStore store_type,
		TokenType::MatchType match_type
	):
		m_data{
			std::make_shared<TokenType::Data>(
				name,
				regex,
				store_type,
				match_type
			)
		}
	{}

	TokenType::MatchType TokenType::get_match_type() const {
		return m_data->get_match_type();
	}

	std::string const& TokenType::get_name() const {
		return m_data->get_name();
	}

	boost::regex const& TokenType::get_regex() const {
		return m_data->get_regex();
	}

	TokenTypeStore TokenType::get_store_type() const {
		return m_data->get_store_type();
	}

	bool TokenType::operator==(TokenType const& rhs) const {
		return m_data == rhs.m_data;
	}

	bool TokenType::operator!=(TokenType const& rhs) const {
		return m_data != rhs.m_data;
	}
} // namespace cion
