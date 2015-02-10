#include "cion/lexer/lexer.hpp"
#include "cion/lexer/lexer_filter.hpp"
#include "cion/lexer/token_stream.hpp"
#include "cion/parser/cion_parser.hpp"
#include "cion/token/cion_token_types.hpp"

#include "cion/error/cion_error_handler.hpp"

#include "cion/parser/print_ast_pass.hpp"
#include "cion/parser/write_ast_pass.hpp"

#include <iostream>
#include <fstream>
#include <chrono>
#include <string>

#include <tuple>

#define DEBUG
#ifdef DEBUG
#include <iostream>
#define DEBUG_STDOUT(x) (std::cout << x)
#define DEBUG_STDERR(x) (std::cerr << x)
#undef DEBUG
#else
#define DEBUG_STDOUT(x)
#define DEBUG_STDERR(x)
#endif

int main() {
	const std::string file_name = "../test/input.cion";

	DEBUG_STDERR("Opening " << file_name << " ...\n");

	std::fstream f;
	f.open(file_name, std::ios::in);

	DEBUG_STDERR("\n");

	DEBUG_STDERR("Initializing cion token types ...\n");

	auto& ctts = cion::CionTokenTypes::get_instance();

	DEBUG_STDERR("Initializing error handler ...\n");

	auto error_handler = cion::CionErrorHandler{file_name};

	DEBUG_STDERR("Initializing lexer ...\n");

	auto lexer = cion::Lexer(f, ctts.get_all(), error_handler);

	DEBUG_STDERR("Initializing lexer filter ...\n");

	auto lexer_filter = cion::LexerFilter(lexer, ctts.get_skipped());

	DEBUG_STDERR("Initializing parser ...\n");

	auto parser = cion::CionParser(lexer_filter, error_handler);

	DEBUG_STDERR("\nParsing " << file_name << " ...\n");

	auto start = std::chrono::steady_clock::now();
	auto root = parser.parse();
	auto end = std::chrono::steady_clock::now();
	auto diff = end - start;

	auto req_time = std::chrono::duration<double, std::milli>(diff).count();
	DEBUG_STDERR("\ttime required = " << req_time << " ms\n");

	DEBUG_STDERR("\nPrinting generated AST ...\n\n");

	start = std::chrono::steady_clock::now();

	//auto printer = cion::PrintASTPass{};
	//printer.visit(*root);
	cion::WriteASTPass::execute(std::cout, *root);

	end = std::chrono::steady_clock::now();
	diff = end - start;

	req_time = std::chrono::duration<double, std::milli>(diff).count();
	DEBUG_STDERR("\ttime required to print AST = " << req_time << " ms\n");

	return 0;
}
