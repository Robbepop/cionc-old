#include "cion/token/token_types.hpp"
#include "cion/token/token_type.hpp"

#include <memory>
#include <utility>

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

	TokenTypes const& TokenTypes::instance() {
		static const TokenTypes c_instance;
		return c_instance;
	}

	TokenTypes::TokenTypes():
		type_void   {"builtin-type: void"},
		type_bool   {"builtin-type: bool"},
		type_char   {"builtin-type: char"},

		type_int    {"builtin-type: int"},
		type_int8   {"builtin-type: int8"},
		type_int16  {"builtin-type: int16"},
		type_int32  {"builtin-type: int32"},
		type_int64  {"builtin-type: int64"},

		type_uint   {"builtin-type: uint"},
		type_uint8  {"builtin-type: uint8"},
		type_uint16 {"builtin-type: uint16"},
		type_uint32 {"builtin-type: uint32"},
		type_uint64 {"builtin-type: uint64"},

		type_float  {"builtin-type: float"},
		type_float16{"builtin-type: float16"},
		type_float32{"builtin-type: float32"},
		type_float64{"builtin-type: float64"},

		cmd_var     {"stmnt: var"},
		cmd_function{"stmnt: function"},

		cmd_if      {"stmnt: if"},
		cmd_else    {"stmnt: else"},
		cmd_for     {"stmnt: for"},
		cmd_while   {"stmnt: while"},

		cmd_break   {"stmnt: break"},
		cmd_continue{"stmnt: continue"},
		cmd_return  {"stmnt: return"},

		opening_brace  {"bracket: opening brace {"},
		opening_paren  {"bracket: opening parenthesis ("},
		opening_brack  {"bracket: opening bracket ["},
		closing_brace  {"bracket: closing brace }"},
		closing_paren  {"bracket: closing parenthesis )"},
		closing_brack  {"bracket: closing bracket ]"},

		op_plus      {"operator: plus (+)"},
		op_minus     {"operator: minus (-)"},
		op_star      {"operator: star (*)"},
		op_slash     {"operator: slash (/)"},
		op_percent   {"operator: percent (%)"},
		op_pipe      {"operator: pipe (|)"},
		op_and       {"operator: and (&)"},
		op_caret     {"operator: caret (^)"},
		op_tilde     {"operator: tilde (~)"},

		op_left_left     {"operator: shift-left (<<)"},
		op_right_right   {"operator: shift-right (>>)"},
		op_pipe_pipe     {"operator: pipe-pipe (||)"},
		op_and_and       {"operator: and-and (&&)"},

		op_less_than     {"operator: less than (<)"},
		op_less_equals   {"operator: less than or equals (<=)"},
		op_greater_than  {"operator: greater than (>)"},
		op_greater_equals{"operator: greater than or equals (>=)"},
		op_equals_equals {"operator: equals equals (==)"},
		op_not_equals    {"operator: not equals (!=)"},

		op_equals            {"operator: equals (=)"},
		op_plus_equals       {"operator: plus equals (+=)"},
		op_minus_equals      {"operator: minus equals (-=)"},
		op_star_equals       {"operator: star equals (*=)"},
		op_slash_equals      {"operator: slash equals (/=)"},
		op_percent_equals    {"operator: percent equals (%=)"},
		op_tilde_equals      {"operator: tilde equals (~=)"},
		op_and_equals        {"operator: and equals (&=)"},
		op_and_and_equals    {"operator: and-and equals (&&=)"},
		op_pipe_equals       {"operator: pipe equals (|=)"},
		op_pipe_pipe_equals  {"operator: pipe-pipe equals (||=)"},
		op_caret_equals      {"operator: caret equals (^=)"},
		op_left_left_equals  {"operator: left left equals (<<=)"},
		op_right_right_equals{"operator: right right equals (>>=)"},

		op_plus_plus    {"operator: plus plus (++)"},
		op_minus_minus  {"operator: minus minus (--)"},

		op_exclam_mark  {"operator: exclamation mark (!)"},
		op_question_mark{"operator: question mark (?)"},
		op_dot          {"operator: dot (.)"},
		op_arrow        {"operator: arrow (->)"},
		op_colon        {"operator: colon (:)"},
		op_colon_colon  {"operator: colon colon (::)"},
		op_semi_colon   {"operator: semi-colon (;)"},
		op_comma        {"operator: comma (,)"},

		identifier{"identifier", TokenType::Storage::string_t},

		lit_bool    {"literal: bool"   , TokenType::Storage::bool_t},
		lit_integral{"literal: integer", TokenType::Storage::integer_t},
		lit_number  {"literal: float"  , TokenType::Storage::float_t},
		lit_char    {"literal: char"   , TokenType::Storage::char_t},
		lit_string  {"literal: string" , TokenType::Storage::string_t}
	{}
} // namespace cion
