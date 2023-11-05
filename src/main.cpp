#include <iostream>
#include <limits>
#include <cstring>
#include <string>

#include "util.hpp"
#include "parser.hpp"
#include "compiler.hpp"
#include "token.hpp"

int main(int argc, char** argv) {
	if (argc == 1) {
		ProgramStack stack = ProgramStack();
		std::string inst;

		while (true) {
			std::cout << "> ";
			std::getline(std::cin, inst);

			TokenList tokens = TokenList();
			Parser parser(&tokens, inst.c_str());
			ParserStatus pstat = parser.start();
			if (pstat != PARSER_SUCCESS) {
				std::cout << "ERROR PARSING INSTRUCTION \"" << inst << "\"" << std::endl;
				return 1;
			}

			Compiler compiler = Compiler(&stack);
			CompilerStatus cStat = compiler.start(&tokens);
			if (cStat == COMPILER_FAILURE) {
				printf("Compiler threw an error");
				return 1;
			}

			if (cStat == COMPILER_HALT) return 0;

			// std::cin.clear();
			// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

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