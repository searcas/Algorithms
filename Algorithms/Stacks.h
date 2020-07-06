#pragma once
#include <string>
class TheStack
{
public:
	TheStack(int size);
	~TheStack();
	void Push(std::string input);
	void DisplayStack();
	void Pop();
	void Peek();

private:
	std::string* stackArray;
	int _mStackSize = 0;
	int topOfStack = -1;

};

