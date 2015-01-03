#include "token/cion_token_types.hpp"

#include <memory>

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
	std::vector<TokenType> const& CionTokenTypes::get_skipped() {
		DEBUG_STDERR("get_skipped: start\n");
		static std::vector<TokenType> skipped_token_types;
		if (skipped_token_types.empty()) {
			DEBUG_STDERR("get_skipped: fill skipped_token_types vector initially -> start\n");
			using ctts = CionTokenTypes;
			skipped_token_types = {
				ctts::whitespace,
				ctts::line_comment,
				ctts::comment,
				TokenType::error
			};
			DEBUG_STDERR("get_skipped: fill skipped_token_types vector initially -> end\n");
		}
		DEBUG_STDERR("get_skipped: end\n");
		return skipped_token_types;
	}

	std::vector<TokenType> const& CionTokenTypes::get_all() {
		DEBUG_STDERR("get_all: start\n");
		static std::vector<TokenType> all_token_types;
		if (all_token_types.empty()) {
			DEBUG_STDERR("get_all: fill all_token_types vector initially -> start\n");
			using ctts = CionTokenTypes;
			all_token_types = {
				ctts::whitespace,
				ctts::line_comment,
				ctts::comment,

				ctts::type_void,
				ctts::type_bool,
				ctts::type_char,

				ctts::type_int,
				ctts::type_int8,
				ctts::type_int16,
				ctts::type_int32,
				ctts::type_int64,

				ctts::type_uint,
				ctts::type_uint8,
				ctts::type_uint16,
				ctts::type_uint32,
				ctts::type_uint64,

				ctts::type_float,
				ctts::type_float16,
				ctts::type_float32,
				ctts::type_float64,

				ctts::cmd_var,
				ctts::cmd_val,

				ctts::cmd_if,
				ctts::cmd_else,

				ctts::cmd_try,
				ctts::cmd_catch,
				ctts::cmd_finally,

				ctts::cmd_switch,
				ctts::cmd_break,
				ctts::cmd_continue,
				ctts::cmd_return,

				ctts::cmd_for,
				ctts::cmd_while,
				ctts::cmd_do,

				ctts::cmd_module,
				ctts::cmd_class,
				ctts::cmd_struct,
				ctts::cmd_interface,
				ctts::cmd_union,

				ctts::op_plus,
				ctts::op_minus,
				ctts::op_star,
				ctts::op_slash,
				ctts::op_percent,
				ctts::op_pipe,
				ctts::op_ampersand,
				ctts::op_caret,
				ctts::op_tilde,

				ctts::op_left_left,
				ctts::op_right_right,
				ctts::op_pipe_pipe,
				ctts::op_ampersand_ampersand,

				ctts::op_less_than,
				ctts::op_less_equals,
				ctts::op_greater_than,
				ctts::op_greater_equals,
				ctts::op_equals_equals,
				ctts::op_not_equals,
				ctts::op_equals,
				ctts::op_plus_equals,
				ctts::op_minus_equals,
				ctts::op_star_equals,
				ctts::op_slash_equals,
				ctts::op_percent_equals,
				ctts::op_left_left_equals,
				ctts::op_right_right_equals,
				ctts::op_tilde_equals,
				ctts::op_ampersand_equals,
				ctts::op_pipe_equals,
				ctts::op_caret_equals,
				ctts::op_plus_plus,
				ctts::op_minus_minus,
				ctts::op_exclam_mark,
				ctts::op_question_mark,
				ctts::op_dot,
				ctts::op_arrow,
				ctts::op_colon,
				ctts::op_colon_colon,
				ctts::op_semi_colon,
				ctts::op_comma,

				ctts::identifier,

				ctts::lit_bool,
				ctts::lit_integral,
				ctts::lit_number,
				ctts::lit_char,
				ctts::lit_string,

				ctts::cmd_function,
				ctts::cmd_constructor,
				ctts::cmd_destructor,
				ctts::cmd_mutable,
				ctts::cmd_reference,
				ctts::cmd_pointer,

				ctts::cmd_private,
				ctts::cmd_protected,
				ctts::cmd_public,

				ctts::cmd_extends,
				ctts::cmd_implements,
				ctts::cmd_final,
				ctts::cmd_virtual,
				ctts::cmd_override,
				ctts::cmd_abstract,
				ctts::cmd_extern,
				ctts::cmd_import,

				ctts::opening_brace,
				ctts::opening_paren,
				ctts::opening_brack,
				ctts::closing_brace,
				ctts::closing_paren,
				ctts::closing_brack
			};
			DEBUG_STDERR("get_all: fill all_token_types vector initially -> end\n");
		}
		DEBUG_STDERR("get_all: end\n");
		return all_token_types;
	}

	const TokenType
		CionTokenTypes::whitespace    = {"whitespace", "\\s+",
		                                 TokenTypeStore::empty, TokenType::MatchType::greedy},
		CionTokenTypes::line_comment  = {"line comment", "//[^\\r\\n]*(\\r?\\n)?",
		                                 TokenTypeStore::string_t, TokenType::MatchType::greedy},
		CionTokenTypes::comment       = {"comment",
		                                 "/\\*([^*]|[\\r\\n]|(\\*+([^*/]|[\\r\\n])))*\\*+/",
		                                 TokenTypeStore::string_t, TokenType::MatchType::greedy},

		CionTokenTypes::type_void     = {"primitive type: void", "void"},
		CionTokenTypes::type_bool     = {"primitive type: bool", "bool"},
		CionTokenTypes::type_char     = {"primitive type: char", "char"},

		CionTokenTypes::type_int      = {"primitive type: int"  , "int"},
		CionTokenTypes::type_int8     = {"primitive type: int8" , "int8"},
		CionTokenTypes::type_int16    = {"primitive type: int16", "int16"},
		CionTokenTypes::type_int32    = {"primitive type: int32", "int32"},
		CionTokenTypes::type_int64    = {"primitive type: int64", "int64"},

		CionTokenTypes::type_uint     = {"primitive type: uint"  , "uint"},
		CionTokenTypes::type_uint8    = {"primitive type: uint8" , "uint8"},
		CionTokenTypes::type_uint16   = {"primitive type: uint16", "uint16"},
		CionTokenTypes::type_uint32   = {"primitive type: uint32", "uint32"},
		CionTokenTypes::type_uint64   = {"primitive type: uint64", "uint64"},

		CionTokenTypes::type_float    = {"primitive type: float"  , "float"},
		CionTokenTypes::type_float16  = {"primitive type: float16", "float16"},
		CionTokenTypes::type_float32  = {"primitive type: float32", "float32"},
		CionTokenTypes::type_float64  = {"primitive type: float64", "float64"},

		CionTokenTypes::cmd_var       = {"statement: var", "var"},
		CionTokenTypes::cmd_val       = {"statement: val", "val"},

		CionTokenTypes::cmd_if        = {"statement: if"  , "if"},
		CionTokenTypes::cmd_else      = {"statement: else", "else"},

		CionTokenTypes::cmd_try       = {"statement: try"    , "try"},
		CionTokenTypes::cmd_catch     = {"statement: catch"  , "catch"},
		CionTokenTypes::cmd_finally   = {"statement: finally", "finally"},

		CionTokenTypes::cmd_switch    = {"statement: switch"  , "switch"},
		CionTokenTypes::cmd_break     = {"statement: break"   , "break"},
		CionTokenTypes::cmd_continue  = {"statement: continue", "continue"},
		CionTokenTypes::cmd_return    = {"statement: return"  , "return"},

		CionTokenTypes::cmd_for       = {"statement: for"  , "for"},
		CionTokenTypes::cmd_while     = {"statement: while", "while"},
		CionTokenTypes::cmd_do        = {"statement: do"   , "do"},

		CionTokenTypes::cmd_module    = {"statement: module"   , "module"},
		CionTokenTypes::cmd_class     = {"statement: class"    , "class"},
		CionTokenTypes::cmd_struct    = {"statement: struct"   , "struct"},
		CionTokenTypes::cmd_interface = {"statement: interface", "interface"},
		CionTokenTypes::cmd_union     = {"statement: union"    , "union"},

		CionTokenTypes::op_plus       = {"operator: plus (+)"     , "\\+"},
		CionTokenTypes::op_minus      = {"operator: minus (-)"    , "-"},
		CionTokenTypes::op_star       = {"operator: star (*)"     , "\\*"},
		CionTokenTypes::op_slash      = {"operator: slash (/)"    , "/"},
		CionTokenTypes::op_percent    = {"operator: percent (%)"  , "%"},
		CionTokenTypes::op_pipe       = {"operator: pipe (|)"     , "\\|"},
		CionTokenTypes::op_ampersand  = {"operator: ampersand (&)", "&"},
		CionTokenTypes::op_caret      = {"operator: caret (^)"    , "\\^"},
		CionTokenTypes::op_tilde      = {"operator: tilde (~)"    , "~"},

		CionTokenTypes::op_left_left   = {"operator: shift-left (<<)" , "<<"},
		CionTokenTypes::op_right_right = {"operator: shift-right (>>)", ">>"},
		CionTokenTypes::op_pipe_pipe   = {"operator: pipe-pipe (||)"  , "\\|\\|"},
		CionTokenTypes::op_ampersand_ampersand = {"operator: ampersand-ampersand (&&)", "&&"},

		CionTokenTypes::op_less_than        = {"operator: less than (<)"              , "<"},
		CionTokenTypes::op_greater_than     = {"operator: greater than (>)"           , ">"},
		CionTokenTypes::op_less_equals      = {"operator: less than or equals (<=)"   , "<="},
		CionTokenTypes::op_greater_equals   = {"operator: greater than or equals (>=)", ">="},
		CionTokenTypes::op_equals_equals    = {"operator: equals equals (==)"         , "=="},
		CionTokenTypes::op_not_equals       = {"operator: not equals (!=)"            , "!="},

		CionTokenTypes::op_equals             = {"operator: equals (=)"               , "="},
		CionTokenTypes::op_plus_equals        = {"operator: plus equals (+=)"         , "\\+="},
		CionTokenTypes::op_minus_equals       = {"operator: minus equals (-=)"        , "-="},
		CionTokenTypes::op_star_equals        = {"operator: star equals (*=)"         , "\\*="},
		CionTokenTypes::op_slash_equals       = {"operator: slash equals (/=)"        , "/="},
		CionTokenTypes::op_percent_equals     = {"operator: percent equals (%=)"      , "%="},
		CionTokenTypes::op_tilde_equals       = {"operator: tilde equals (~=)"        , "~="},
		CionTokenTypes::op_left_left_equals   = {"operator: left left equals (<<=)"   , "<<="},
		CionTokenTypes::op_right_right_equals = {"operator: right right equals (>>=)" , ">>="},
		CionTokenTypes::op_ampersand_equals   = {"operator: ampersand equals (&=)"    , "&="},
		CionTokenTypes::op_pipe_equals        = {"operator: pipe equals (|=)"         , "\\|="},
		CionTokenTypes::op_caret_equals       = {"operator: caret equals (^=)"        , "\\^="},

		CionTokenTypes::op_plus_plus        = {"operator: plus plus (++)"       , "\\+\\+"},
		CionTokenTypes::op_minus_minus      = {"operator: minus minus (--)"     , "--"},

		CionTokenTypes::op_exclam_mark      = {"operator: exclamation mark (!)" , "!"},
		CionTokenTypes::op_question_mark    = {"operator: question mark (?)"    , "\\?"},
		CionTokenTypes::op_dot              = {"operator: dot (.)"              , "\\."},
		CionTokenTypes::op_arrow            = {"operator: arrow (->)"           , "->"},
		CionTokenTypes::op_colon            = {"operator: colon (:)"            , ":"},
		CionTokenTypes::op_colon_colon      = {"operator: colon colon (::)"     , "::"},
		CionTokenTypes::op_semi_colon       = {"operator: semi-colon (;)"       , ";"},
		CionTokenTypes::op_comma            = {"operator: comma (,)"            , ","},

		CionTokenTypes::identifier   = {"identifier", "[_a-zA-Z]\\w*",
		                                TokenTypeStore::string_t, TokenType::MatchType::greedy},

		CionTokenTypes::lit_bool     = {"literal: boolean", "(true)|(false)", TokenTypeStore::boolean_t},
		CionTokenTypes::lit_integral = {"literal: integral", "0|([1-9]\\d*)",
		                                TokenTypeStore::integral_t, TokenType::MatchType::greedy},
		CionTokenTypes::lit_number   = {"literal: number",
		                                "(((0|([1-9](\\d)*))\\.(\\d)*|\\.(\\d)+)([eE][+-]?(\\d)+)?)|((0|([1-9](\\d)*))([eE][+-]?(\\d)+))",
		                                TokenTypeStore::number_t, TokenType::MatchType::greedy},
		CionTokenTypes::lit_char     = {"literal: character", "'[^']+'", TokenTypeStore::character_t},
		CionTokenTypes::lit_string   = {"literal: string",
		                                "\\\"([^\"\\\\]|\\\\.)*\\\"",
		                                TokenTypeStore::string_t, TokenType::MatchType::greedy},

		CionTokenTypes::cmd_function    = {"statement: function"   , "function"},
		CionTokenTypes::cmd_constructor = {"statement: constructor", "constructor"},
		CionTokenTypes::cmd_destructor  = {"statement: destructor" , "destructor"},
		CionTokenTypes::cmd_mutable     = {"statement: mutable"    , "mutable"},
		CionTokenTypes::cmd_reference   = {"statement: ref"        , "ref"},
		CionTokenTypes::cmd_pointer     = {"statement: ptr"        , "ptr"},

		CionTokenTypes::cmd_private     = {"statement: private"  , "private"},
		CionTokenTypes::cmd_protected   = {"statement: protected", "protected"},
		CionTokenTypes::cmd_public      = {"statement: public"   , "public"},

		CionTokenTypes::cmd_extends     = {"statement: extends"   , "extends"},
		CionTokenTypes::cmd_implements  = {"statement: implements", "implements"},
		CionTokenTypes::cmd_final       = {"statement: final"     , "final"},
		CionTokenTypes::cmd_virtual     = {"statement: virtual"   , "virtual"},
		CionTokenTypes::cmd_override    = {"statement: override"  , "override"},
		CionTokenTypes::cmd_abstract    = {"statement: abstract"  , "abstract"},
		CionTokenTypes::cmd_extern      = {"statement: extern"    , "extern"},
		CionTokenTypes::cmd_import      = {"statement: import"    , "import"},

		CionTokenTypes::opening_brace   = {"bracket: opening brace {"      , "{"},
		CionTokenTypes::opening_paren   = {"bracket: opening parenthesis (", "\\("},
		CionTokenTypes::opening_brack   = {"bracket: opening bracket ["    , "\\["},
		CionTokenTypes::closing_brace   = {"bracket: closing brace }"      , "}"},
		CionTokenTypes::closing_paren   = {"bracket: closing parenthesis )", "\\)"},
		CionTokenTypes::closing_brack   = {"bracket: closing bracket ]"    , "\\]"};
} // namespace cion
