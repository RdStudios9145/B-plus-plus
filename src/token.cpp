#include "token.hpp"

Token::Token(int type, int data, uint line) {
	this->type = type;
	this->data = data;
	this->line = line;
}

TokenList::TokenList() {
	this->tokens = std::vector<Token>();
}

void TokenList::push(Token* tok) {
	this->tokens.push_back(*tok);
}

Token* TokenList::get(int index) {
	return &this->tokens.at(index);
}