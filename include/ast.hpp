#pragma once

#include <vector>

enum ASTNodeType {
	EXPRESSION,
	VARIABLE_DECLARATION
};

class ASTNode {
private:
	std::vector<ASTNode> children;
	ASTNodeType type;
};

class ASTTree {
private:
	std::vector<ASTNode> global;
};

class ASTGenerator {
public:
	ASTGenerator();
	ASTTree start();
};