#include <iostream>
#include <cstring>

#include "util.hpp"
#include "parser.hpp"
#include "compiler.hpp"
#include "token.hpp"

int main(int argc, char** argv) {
	if (argc < 3) {
		printf("Too few args, I need at least 2");
		return 1;
	}

	if (strcmp(argv[1], "compile") == 0) {
		char* source = read_ascii_file(argv[2]);
		TokenList tokens = TokenList();
		Parser parser(&tokens, source);
		ParserStatus pStat = parser.start();
		if (pStat != PARSER_SUCCESS) {
			printf("Parser threw an error");
			return 1;
		}

		Compiler compiler = Compiler();
		CompilerStatus cStat = compiler.start(&tokens);
		if (cStat == COMPILER_FAILURE) {
			printf("Compiler threw an error");
			return 1;
		}

		// free(source);
	}

	return 0;
}