#include "Heap.h"
#include <algorithm>
#include <iomanip>
Heap::Heap(int maxSize) :_mMaxSize(maxSize)
{
	theHeap = new Data[maxSize];
}

Heap::~Heap()
{
}
void Heap::Insert(int index, Data newData)
{
	theHeap[index] = newData;
	_mItemsInArray++;
}
void Heap::GenerateFilledArray(int randNum)
{
	Data randomData;

	for (int i = 0; i < _mMaxSize; i++)
	{
		randomData = ( (int)(rand() * randNum) + 1);

		this->Insert(i, randomData); 
	}
}
int* Heap::GetIndentArray(int rows)
{
	int* indentArray = new int[rows];
	for (int i = 0; i < rows; i++)
	{
		indentArray[i] = (int)std::abs((0.5 * (-2 + (std::pow(2, i + 1)))));

	}
	std::sort(indentArray, indentArray + rows);
	indentArray = ReverseArray(indentArray,rows);
	return indentArray; 
}
int* Heap::ReverseArray(int* theArray, int length)
{
	int leftIndex = 0;
	int rightIndex = length - 1;

	while (leftIndex < rightIndex)
	{
		int temp = theArray[leftIndex];

		theArray[leftIndex] = theArray[rightIndex];
		theArray[rightIndex] = temp;

		rightIndex--;
		leftIndex++;
	}
	return theArray;
}
 void Heap::PrintTree(int rows)
{
	int spaces = 0;

	int iterator = 1;

	int* indent = GetIndentArray(rows);

	while (iterator <= rows)
	{

		int indexToprint = (int)(0.5 * (-2 + (std::pow(2, iterator))));

		int itemsPerRow = (int)std::pow(2, iterator - 1);

		int maxIndexToPrint = indexToprint + itemsPerRow;
		for (int j = 0; j < indent[iterator -1]; j++)
		{
			std::cout << " ";
		}
		for (int i = indexToprint; i < maxIndexToPrint; i++)
		{
			if (i < _mItemsInArray)
			{
				std::cout <<std::setprecision(2)<<theHeap[i]._mKey;
				for (int k = 0; k < spaces; k++)
					std::cout << " ";
			}
		}
		spaces = indent[iterator -1];
		iterator++;
		std::cout << std::endl;

	}
}
Data::Data(int key) : _mKey(key) 
{
}
Data::Data()
{
}

Data::~Data()
{
}
