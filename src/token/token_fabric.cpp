#include "cion/token/token_fabric.hpp"

#include <memory>
#include <stdexcept>

#include "cion/token/token.hpp"
#include "cion/token/bool_token.hpp"
#include "cion/token/char_token.hpp"
#include "cion/token/integer_token.hpp"
#include "cion/token/float_token.hpp"
#include "cion/token/string_token.hpp"
#include "cion/error/source_location.hpp"

//#define DEBUG
#ifdef DEBUG
#include <iostream>
#define DEBUG_STDOUT(x) (std::cout << x)
#define DEBUG_STDERR(x) (std::cerr << x)
#undef DEBUG
#else
#define DEBUG_STDOUT(x)
#define DEBUG_STDERR(x)
#endif

namespace cion {
	std::unique_ptr<Token> TokenFabric::make_token(
		TokenType const& token_type,
		SourceLocation const& start_loc,
		SourceLocation const& end_loc,
		std::string const& value
	) {
		using tts = TokenType::Storage;
		switch (token_type.storage())
		{
			case tts::empty:
				DEBUG_STDERR("token_fabric: create empty_token()\n");
				return std::make_unique<Token>(
					token_type, start_loc, end_loc);
			case tts::bool_t:
				DEBUG_STDERR("token_fabric: create boolean_token()\n");
				return {std::make_unique<BoolToken>(
						token_type, start_loc, end_loc, value)};
			case tts::char_t:
				DEBUG_STDERR("token_fabric: create char_token()\n");
				return {std::make_unique<CharToken>(
						token_type, start_loc, end_loc, value)};
			case tts::integer_t:
				DEBUG_STDERR("token_fabric: create integral_token()\n");
				return {std::make_unique<IntegerToken>(
						token_type, start_loc, end_loc, value)};
			case tts::float_t:
				DEBUG_STDERR("token_fabric: create number_token()\n");
				return {std::make_unique<FloatToken>(
						token_type, start_loc, end_loc, value)};
			case tts::string_t:
				DEBUG_STDERR("token_fabric: create string_token()\n");
				return {std::make_unique<StringToken>(
						token_type, start_loc, end_loc, value)};
			default:
				throw std::invalid_argument{"unknown type store"};
		}
	}
} // namespace cion
