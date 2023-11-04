#include "compiler.hpp"

Compiler::Compiler() {
	this->m_Current_Inst = nullptr;
	this->m_Reqs = (InstRequirements*) malloc(sizeof(InstRequirements));
	this->m_Stack = new ProgramStack();
}

CompilerStatus Compiler::start(TokenList* tokens) {
	int i = 0;

	while (1) {
		Token* token = tokens->get(i);
		CompilerStatus status;

		switch (token->get_type()) {
			case INST:
				this->m_Current_Inst = token;
				status = this->manage_instruction();
				if (status != COMPILER_SUCCESS) return status;
				break;
			case NUMBER:
				status = this->manage_number(token);
				if (status != COMPILER_SUCCESS) return status;
				break;
		}

		i++;
		if (i == tokens->size()) break;
	}

	return CompilerStatus::COMPILER_SUCCESS;
}

CompilerStatus Compiler::manage_instruction() {
	std::vector<int> num;
	switch (this->m_Current_Inst->get_data()) {
		case PUSH:
			*this->m_Reqs = REQ_NUMBER;
			break;
		case ADD:
			if (this->m_Stack->size() < 2) return CompilerStatus::COMPILER_FAILURE;

			num.push_back(this->m_Stack->pop());
			if (num[0] == NULL) return COMPILER_FAILURE;
			num.push_back(this->m_Stack->pop());
			if (num[1] == NULL) return COMPILER_FAILURE;

			this->m_Stack->push(num[0] + num[1]);
			printf("Program printed: %i\n", num[0] + num[1]);
			break;
		case MULT:
			if (this->m_Stack->size() < 2) return COMPILER_FAILURE;

			num.push_back(this->m_Stack->pop());
			if (num[0] == NULL) return COMPILER_FAILURE;
			num.push_back(this->m_Stack->pop());
			if (num[1] == NULL) return COMPILER_FAILURE;

			this->m_Stack->push(num[0] * num[1]);
			printf("Program printed: %i\n", num[0] * num[1]);
			break;
		case DIV:
			if (this->m_Stack->size() < 2) return COMPILER_FAILURE;

			num.push_back(this->m_Stack->pop());
			if (num[0] == NULL) return COMPILER_FAILURE;
			num.push_back(this->m_Stack->pop());
			if (num[1] == NULL) return COMPILER_FAILURE;

			this->m_Stack->push(num[1] / num[0]);
			printf("Program printed: %i\n", num[1] / num[0]);
			break;
		case PRINT:
			for (int i = 0; i < this->m_Stack->size(); i++) {
				printf("Program printed stack (%i): %i\n", i, this->m_Stack->get_data().at(i));
			}
			break;
		case SINE:
			if (this->m_Stack->size() < 1) return COMPILER_FAILURE;

			num.push_back(this->m_Stack->pop());
			if (num[0] == NULL) return COMPILER_FAILURE;

			this->m_Stack->push((int)sin(num[0]));
			printf("Program printed: %i\n", (int)sin(num[0]));
			break;
		case HLT:
			return COMPILER_HALT;
	}

	return COMPILER_SUCCESS;
}

CompilerStatus Compiler::manage_number(Token* token) {
	if (*this->m_Reqs == NONE) return COMPILER_FAILURE;
	if (*this->m_Reqs & REQ_NUMBER == 0) return COMPILER_FAILURE;

	switch (this->m_Current_Inst->get_data()) {
		case PUSH:
			this->m_Stack->push(token->get_data());
	}

	return COMPILER_SUCCESS;
}