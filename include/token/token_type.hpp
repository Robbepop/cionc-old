#ifndef CION_TOKEN_TYPE_HEADER
#define CION_TOKEN_TYPE_HEADER

#include "token/token_type_store.hpp"

#include <cstdint>
#include <functional>
#include <string>
#include <memory>

#include <boost/regex.hpp>

namespace cion {
	class TokenType final {
	public:
		enum class MatchType : uint8_t {
			non_greedy,
			greedy
		};

		static const TokenType undefined;
		static const TokenType error;
		static const TokenType eof;

	private:
		struct Data {
		private:
			std::string m_name;
			boost::regex m_regex;
			TokenTypeStore m_store_type;
			MatchType m_match_type;

		public:
			std::string const& get_name() const;
			boost::regex const& get_regex() const;
			MatchType get_match_type() const;
			TokenTypeStore get_store_type() const;

			Data(
				std::string const& name,
				std::string const& regex,
				TokenTypeStore store_type,
				MatchType match_type
			);
		};

		std::shared_ptr<Data> m_data;

	public:
		TokenType(
			std::string const& name,
			std::string const& regex = "",
			TokenTypeStore store_type = TokenTypeStore::empty,
			MatchType match_type = MatchType::non_greedy);

		TokenType() = delete;
		TokenType(TokenType const& other) = default;
		TokenType(TokenType && other) = default;
		TokenType & operator=(TokenType const& other) = default;
		TokenType & operator=(TokenType && other) = default;

		std::string const& get_name() const;
		boost::regex const& get_regex() const;
		MatchType get_match_type() const;
		TokenTypeStore get_store_type() const;

		bool operator==(TokenType const& rhs) const;
		bool operator!=(TokenType const& rhs) const;
	};
}

#endif // CION_TOKEN_TYPE_HEADER
