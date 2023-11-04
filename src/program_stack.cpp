#include "program_stack.hpp"

ProgramStack::ProgramStack() {
}

void ProgramStack::push(int data) {
	this->m_Data.push_back(data);
}

int ProgramStack::pop() {
	if (this->m_Data.size() == 0) return NULL;
	int val = this->m_Data.back();
	this->m_Data.pop_back();
	return val;
}