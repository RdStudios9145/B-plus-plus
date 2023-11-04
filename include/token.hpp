#pragma once

#ifndef uint
#define uint unsigned int
#endif

#include <stdlib.h>
#include <vector>
#include <cstdio>

enum _TokenType {
	INST,
	NUMBER
};
typedef enum _TokenType TokenType;

enum _TokenInst {
	PUSH,
	ADD,
	MULT,
	DIV,
	PRINT,
	SINE,
	HLT
};
typedef enum _TokenInst TokenInst;

// struct _Token {
//     int type;
//     int data;
//     int line;
// };
// // typedef struct _Token Token;

// _Token* token_create(int type, int data, int line);
// void token_destroy(Token* tok);

class Token {
public:
	Token(int type, int data, uint line);
	// ~Token();
	int get_type() { return this->type; }
	int get_data() { return this->data; }
	uint get_line() { return this->line; }
private:
	int type;
	int data;
	uint line;
};

// struct _TokenList {
//     Token** data;
//     int ptr;
//     int size;
// 	uint count;
// };
// // typedef struct _TokenList TokenList;

// void token_list_create(TokenList* list, int size);
// void token_list_add(TokenList* list, Token* tok);
// Token* token_list_get(TokenList* list, int index);
// void token_list_destroy(TokenList* list);

class TokenList {
public:
	TokenList();
	void push(Token* tok);
	Token* get(int index);
	size_t size() { return this->tokens.size(); }
private:
	std::vector<Token> tokens;
};