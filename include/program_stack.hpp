#pragma once

#include <vector>

class ProgramStack {
public:
	ProgramStack();
	void push(int data);
	int pop();
private:
	std::vector<int> m_Data;
public:
	std::vector<int> get_data() { return this->m_Data; }
	size_t size() { return this->m_Data.size(); }
};