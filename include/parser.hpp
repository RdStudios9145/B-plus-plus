#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

#include "token.hpp"

enum _ParserStatus {
    PARSER_SUCCESS,
    PARSER_SYNTAX_ERROR
};
typedef enum _ParserStatus ParserStatus;

class Parser {
public:
	Parser(TokenList* list, const char* source);
	ParserStatus start();
	uint32_t get_number(const char* buf);
	TokenInst get_inst(const char* buf);
private:
	TokenList* list;
	const char* source;
};