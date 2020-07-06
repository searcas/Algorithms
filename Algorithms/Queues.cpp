#include "Queues.h"
#include <iostream>


TheQueue::TheQueue(int size) : queueSize(size)
{
	queueArray = new std::string[size];
	front = 0;
	rear = 0;
	numberOfitems = 0;
}
void TheQueue::Insert(std::string input)
{
	if (numberOfitems + 1 <= queueSize)
	{
		queueArray[rear] = input;
		rear++;
		numberOfitems++;
	}
	else
	{
		std::cout << "Sorry but the Queue is full" << std::endl;
	}
}
// 1 2 3 4 5
// 2 1 = 3?
// 3 1 2
void TheQueue::PriorityInsert(std::string input)
{
	int num = std::stoi(input);

	if (numberOfitems == 0)
	{
		Insert(input);
	}
	else
	{
		if (std::stoi(queueArray[front]) < num)
		{
			int temp = std::stoi(queueArray[front]);
			queueArray[front] = std::to_string(num);
			for (int i = 1; i < numberOfitems; i++)
			{
				if (std::stoi(queueArray[i]) > std::stoi(queueArray[i + 1]))
				{

				}
			}
		}
	}
}
void TheQueue::Remove()
{
	if (numberOfitems > 0)
	{
		queueArray[front] = "0";
		front++;
		numberOfitems--;
	}
	else
	{
		std::cout << "Sorry but there is nothing to be removed " << std::endl;
	}
}
void TheQueue::Peek()
{
	std::cout << "Top item in Stack is " << queueArray[front] << std::endl;

}
void TheQueue::DisplayQueue()
{
	for (int i = 0; i < queueSize; i++)
	{
		std::cout << "All Queue elements are " << i << " " << queueArray[i] << std::endl;
	}
}

TheQueue::~TheQueue()
{
}