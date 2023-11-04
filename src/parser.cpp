#include "parser.hpp"

Parser::Parser(TokenList* list, const char* source)
: list{list}, source{source} {
	
}

ParserStatus Parser::start() {
	char lex[256];
	int lexi = 0;
	int i = 0;
	int line = 1;

	while (1) {
		while (source[i] != ' ' && source[i] != '\n' && source[i] != '\0') {
			lex[lexi++] = source[i++];
		}
		lex[lexi] = '\0';

		if (lex[0] == '\0') break;

		if (lex[0] == '#') {
			int num = this->get_number(lex);
			Token* token = new Token(TokenType::NUMBER, num, line);
			this->list->push(token);
		} else {
			int inst = this->get_inst(lex);

			if (inst < 0) {
				printf("Syntax error: No such instruction '%s' at line %i\n", lex, line);
				return PARSER_SYNTAX_ERROR;
			}

			Token* token = new Token(TokenType::INST, inst, line);
			this->list->push(token);
		}

		if (source[i] == '\n') line++;
		else if (source[i] == '\0') break;

		lexi = 0;
		i++;
	}

	return PARSER_SUCCESS;
}

uint32_t Parser::get_number(const char* buf) {
	long num = atoi(&buf[1]);
	return (num <= UINT32_MAX) ? num : 0;
}

TokenInst Parser::get_inst(const char* buf) {
	if (strcmp(buf, "push") == 0) return PUSH;
	if (strcmp(buf, "add") == 0) return ADD;
	if (strcmp(buf, "mult") == 0) return MULT;
	if (strcmp(buf, "div") == 0) return DIV;
	if (strcmp(buf, "print") == 0) return PRINT;
	if (strcmp(buf, "sine") == 0) return SINE;
	if (strcmp(buf, "hlt") == 0) return HLT;
	return (TokenInst) -1;
}