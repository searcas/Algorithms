#pragma once

#include <string>


class TheQueue
{
public:
	TheQueue(int size);
	~TheQueue();
	void Insert(std::string input);
	void PriorityInsert(std::string input);
	void Remove();
	void Peek();
	void DisplayQueue();

private:
	std::string* queueArray;
	int queueSize;
	int front;
	int rear;
	int numberOfitems = 0;

};

