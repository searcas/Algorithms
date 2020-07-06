#include "Stacks.h"
#include <iostream>



TheStack::TheStack(int size) : _mStackSize(size)
{
	stackArray = new std::string[size];

}
void TheStack::Push(std::string input)
{
	if ((topOfStack + 1) < _mStackSize)
	{
		topOfStack++;
		stackArray[topOfStack] = input;
	}
	else
	{
		std::cout << "Sorry but Stack Room is Full" << std::endl;
	}
}
void TheStack::DisplayStack()
{
	for (int i = 0; i < _mStackSize; i++)
	{
		std::cout << "Stack Element " << i << " is " << stackArray[i] << std::endl;
	}
}
void TheStack::Pop()
{
	if (topOfStack >= 0)
	{
		std::cout << "Item " << stackArray[topOfStack] << " has been removed." << std::endl;
		stackArray[topOfStack--] = "";
	}
	else
	{
		std::cout << "Stack is Empty "<< std::endl;
	}
}
void TheStack::Peek()
{
	std::cout << "Top item in Stack is " << stackArray[topOfStack] << std::endl;

}
TheStack::~TheStack()
{
}