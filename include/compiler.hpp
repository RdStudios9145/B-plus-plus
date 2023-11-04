#pragma once

#include "stdio.h"
#include <math.h>

#include "defs.hpp"
#include "token.hpp"
#include "program_stack.hpp"

enum _CompilerStatus {
	COMPILER_SUCCESS,
	COMPILER_FAILURE,
	COMPILER_HALT
};
typedef enum _CompilerStatus CompilerStatus;

enum _InstRequirements {
	NONE = 0,
	REQ_NUMBER = BIT(0)
};
typedef enum _InstRequirements InstRequirements;

// CompilerStatus compiler_start(TokenList* tokens);
// void compiler_manage_instruction(Token* token, InstRequirements* reqs, Stack* stack);
// void compiler_manage_number(Token* token, InstRequirements* reqs, Stack* stack, Token* current_inst);

class Compiler {
public:
	Compiler();
	CompilerStatus start(TokenList* tokens);
	CompilerStatus manage_instruction();
	CompilerStatus manage_number(Token* token);
private:
	Token* m_Current_Inst;
	ProgramStack* m_Stack;
	InstRequirements* m_Reqs;
};