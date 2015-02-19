#include "cion/token/cion_token_types.hpp"
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
	TokenType CionTokenTypes::init_tt(
		TokenType token_type,
		bool skipped
	) {
		m_all_token_types.push_back(token_type);
		if (skipped) {
			m_skipped_token_types.push_back(token_type);
		}
		return std::move(token_type);
	}

	CionTokenTypes const& CionTokenTypes::get_instance() {
		static const CionTokenTypes c_instance;
		return c_instance;
	}

	std::vector<TokenType> const& CionTokenTypes::get_all() const {
		return m_all_token_types;
	}

	std::vector<TokenType> const& CionTokenTypes::get_skipped() const {
		return m_skipped_token_types;
	}

	CionTokenTypes::CionTokenTypes():
		m_all_token_types{},
		m_skipped_token_types{},

		whitespace{init_tt({
			"whitespace", "\\s+",
			TokenTypeStore::empty,
			TokenType::MatchType::greedy},
			true)},

		line_comment{init_tt({
			"line comment", "//[^\\r\\n]*(\\r?\\n)?",
			TokenTypeStore::string_t, TokenType::MatchType::greedy},
			true)},

		comment{init_tt({
			"comment", "/\\*([^*]|[\\r\\n]|(\\*+([^*/]|[\\r\\n])))*\\*+/",
			TokenTypeStore::string_t, TokenType::MatchType::greedy},
			true)},

		type_void   {init_tt({"builtin-type: void", "void"})},
		type_bool   {init_tt({"builtin-type: bool", "bool"})},
		type_char   {init_tt({"builtin-type: char", "char"})},

		type_int    {init_tt({"builtin-type: int"  , "int"})},
		type_int8   {init_tt({"builtin-type: int8" , "int8"})},
		type_int16  {init_tt({"builtin-type: int16", "int16"})},
		type_int32  {init_tt({"builtin-type: int32", "int32"})},
		type_int64  {init_tt({"builtin-type: int64", "int64"})},

		type_uint   {init_tt({"builtin-type: uint"  , "uint"})},
		type_uint8  {init_tt({"builtin-type: uint8" , "uint8"})},
		type_uint16 {init_tt({"builtin-type: uint16", "uint16"})},
		type_uint32 {init_tt({"builtin-type: uint32", "uint32"})},
		type_uint64 {init_tt({"builtin-type: uint64", "uint64"})},

		type_float  {init_tt({"builtin-type: float"  , "float"})},
		type_float16{init_tt({"builtin-type: float16", "float16"})},
		type_float32{init_tt({"builtin-type: float32", "float32"})},
		type_float64{init_tt({"builtin-type: float64", "float64"})},

		cmd_var      {init_tt({"statement: var", "var"})},
		cmd_val      {init_tt({"statement: val", "val"})},

		cmd_if       {init_tt({"statement: if"  , "if"})},
		cmd_else     {init_tt({"statement: else", "else"})},

		cmd_try      {init_tt({"statement: try"    , "try"})},
		cmd_catch    {init_tt({"statement: catch"  , "catch"})},
		cmd_finally  {init_tt({"statement: finally", "finally"})},

		cmd_switch   {init_tt({"statement: switch"  , "switch"})},
		cmd_break    {init_tt({"statement: break"   , "break"})},
		cmd_continue {init_tt({"statement: continue", "continue"})},
		cmd_return   {init_tt({"statement: return"  , "return"})},

		cmd_for      {init_tt({"statement: for"  , "for"})},
		cmd_while    {init_tt({"statement: while", "while"})},
		cmd_do       {init_tt({"statement: do"   , "do"})},

		cmd_module   {init_tt({"statement: module"   , "module"})},
		cmd_class    {init_tt({"statement: class"    , "class"})},
		cmd_struct   {init_tt({"statement: struct"   , "struct"})},
		cmd_interface{init_tt({"statement: interface", "interface"})},
		cmd_union    {init_tt({"statement: union"    , "union"})},

		op_plus      {init_tt({"operator: plus (+)"     , "\\+"})},
		op_minus     {init_tt({"operator: minus (-)"    , "-"})},
		op_star      {init_tt({"operator: star (*)"     , "\\*"})},
		op_slash     {init_tt({"operator: slash (/)"    , "/"})},
		op_percent   {init_tt({"operator: percent (%)"  , "%"})},
		op_pipe      {init_tt({"operator: pipe (|)"     , "\\|"})},
		op_and       {init_tt({"operator: and (&)"      , "&"})},
		op_caret     {init_tt({"operator: caret (^)"    , "\\^"})},
		op_tilde     {init_tt({"operator: tilde (~)"    , "~"})},

		op_left_left     {init_tt({"operator: shift-left (<<)"         , "<<"})},
		op_right_right   {init_tt({"operator: shift-right (>>)"        , ">>"})},
		op_pipe_pipe     {init_tt({"operator: pipe-pipe (||)"          , "\\|\\|"})},
		op_and_and       {init_tt({"operator: and-and (&&)", "&&"})},

		op_less_than     {init_tt({"operator: less than (<)"              , "<"})},
		op_less_equals   {init_tt({"operator: less than or equals (<=)"   , "<="})},
		op_greater_than  {init_tt({"operator: greater than (>)"           , ">"})},
		op_greater_equals{init_tt({"operator: greater than or equals (>=)", ">="})},
		op_equals_equals {init_tt({"operator: equals equals (==)"         , "=="})},
		op_not_equals    {init_tt({"operator: not equals (!=)"            , "!="})},

		op_equals            {init_tt({"operator: equals (=)"               , "="})},
		op_plus_equals       {init_tt({"operator: plus equals (+=)"         , "\\+="})},
		op_minus_equals      {init_tt({"operator: minus equals (-=)"        , "-="})},
		op_star_equals       {init_tt({"operator: star equals (*=)"         , "\\*="})},
		op_slash_equals      {init_tt({"operator: slash equals (/=)"        , "/="})},
		op_percent_equals    {init_tt({"operator: percent equals (%=)"      , "%="})},
		op_tilde_equals      {init_tt({"operator: tilde equals (~=)"        , "~="})},
		op_and_equals        {init_tt({"operator: and equals (&=)"          , "&="})},		
		op_and_and_equals    {init_tt({"operator: and-and equals (&&=)"     , "&&="})},
		op_pipe_equals       {init_tt({"operator: pipe equals (|=)"         , "\\|="})},
		op_pipe_pipe_equals  {init_tt({"operator: pipe-pipe equals (||=)"   , "\\|\\|="})},
		op_caret_equals      {init_tt({"operator: caret equals (^=)"        , "\\^="})},
		op_left_left_equals  {init_tt({"operator: left left equals (<<=)"   , "<<="})},
		op_right_right_equals{init_tt({"operator: right right equals (>>=)" , ">>="})},

		op_plus_plus    {init_tt({"operator: plus plus (++)"       , "\\+\\+"})},
		op_minus_minus  {init_tt({"operator: minus minus (--)"     , "--"})},

		op_exclam_mark  {init_tt({"operator: exclamation mark (!)" , "!"})},
		op_question_mark{init_tt({"operator: question mark (?)"    , "\\?"})},
		op_dot          {init_tt({"operator: dot (.)"              , "\\."})},
		op_arrow        {init_tt({"operator: arrow (->)"           , "->"})},
		op_colon        {init_tt({"operator: colon (:)"            , ":"})},
		op_colon_colon  {init_tt({"operator: colon colon (::)"     , "::"})},
		op_semi_colon   {init_tt({"operator: semi-colon (;)"       , ";"})},
		op_comma        {init_tt({"operator: comma (,)"            , ","})},

		identifier{init_tt({
			"identifier", "[_a-zA-Z]\\w*",
			TokenTypeStore::string_t, TokenType::MatchType::greedy})},

		lit_bool{init_tt({
			"literal: boolean", "(true)|(false)",
			TokenTypeStore::boolean_t})},

		lit_integral{init_tt({
			"literal: integral", "0|([1-9]\\d*)",
			TokenTypeStore::integral_t, TokenType::MatchType::greedy})},

		lit_number{init_tt({
			"literal: number",
			"(((0|([1-9](\\d)*))\\.(\\d)*|\\.(\\d)+)([eE][+-]?(\\d)+)?)|((0|([1-9](\\d)*))([eE][+-]?(\\d)+))",
			TokenTypeStore::number_t, TokenType::MatchType::greedy})},

		lit_char{init_tt({
			"literal: character", "'[^']+'",
			TokenTypeStore::character_t})},

		lit_string{init_tt({
			"literal: string", "\\\"([^\"\\\\]|\\\\.)*\\\"",
			TokenTypeStore::string_t, TokenType::MatchType::greedy})},

		cmd_function   {init_tt({"statement: function"   , "function"})},
		cmd_constructor{init_tt({"statement: constructor", "constructor"})},
		cmd_destructor {init_tt({"statement: destructor" , "destructor"})},
		cmd_mutable    {init_tt({"statement: mutable"    , "mutable"})},
		cmd_reference  {init_tt({"statement: ref"        , "ref"})},
		cmd_pointer    {init_tt({"statement: ptr"        , "ptr"})},

		cmd_private    {init_tt({"statement: private"  , "private"})},
		cmd_protected  {init_tt({"statement: protected", "protected"})},
		cmd_public     {init_tt({"statement: public"   , "public"})},

		cmd_extends    {init_tt({"statement: extends"   , "extends"})},
		cmd_implements {init_tt({"statement: implements", "implements"})},
		cmd_final      {init_tt({"statement: final"     , "final"})},
		cmd_virtual    {init_tt({"statement: virtual"   , "virtual"})},
		cmd_override   {init_tt({"statement: override"  , "override"})},
		cmd_abstract   {init_tt({"statement: abstract"  , "abstract"})},
		cmd_extern     {init_tt({"statement: extern"    , "extern"})},
		cmd_import     {init_tt({"statement: import"    , "import"})},

		opening_brace  {init_tt({"bracket: opening brace {"      , "{"})},
		opening_paren  {init_tt({"bracket: opening parenthesis (", "\\("})},
		opening_brack  {init_tt({"bracket: opening bracket ["    , "\\["})},
		closing_brace  {init_tt({"bracket: closing brace }"      , "}"})},
		closing_paren  {init_tt({"bracket: closing parenthesis )", "\\)"})},
		closing_brack  {init_tt({"bracket: closing bracket ]"    , "\\]"})}
	{}
} // namespace cion
