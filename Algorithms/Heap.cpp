#include "Heap.h"
#include <algorithm>
#include <iomanip>




Heap::Heap(int maxSize) :_mMaxSize(maxSize)
{
	theHeap = new Data*[maxSize];

	for (int i = 0; i <_mMaxSize; i++)
	{
		*theHeap = new Data;
	}
}

Heap::~Heap()
{
	for (int i = 0; i < _mMaxSize; i++)
	{
		delete[]*theHeap;
	}
	delete[]theHeap;
}
void Heap::Insert(int index, Data* newData)
{
	theHeap[index] = newData;
}
void Heap::IncrementTheArray()
{
	_mItemsInArray++;

}
Data* Heap::Pop()
{
	if (!_mItemsInArray != 0)
	{
		Data* root = theHeap[0];
		theHeap[0] = theHeap[--_mItemsInArray];
		HeapTheArray(0);
		return root;
	}
	return nullptr;

}
void Heap::HeapTheArray(int index)
{
	int largestChild;
	Data* root = theHeap[index];

	while (index < _mItemsInArray / 2)
	{
		int leftChild = 2 * index + 1;
		int rightChild = leftChild + 1;

		if (rightChild < _mItemsInArray && theHeap[leftChild]->_mKey < theHeap[rightChild]->_mKey)
		{
			largestChild = rightChild;
		}
		else
		{
			largestChild = leftChild;
		}

		if (root->_mKey >= theHeap[largestChild]->_mKey)
			break;
		theHeap[index] = theHeap[largestChild];

		index = largestChild;
		
	}
	theHeap[index] = root;

}
void Heap::HeapSort()
{
	for (int  i = _mMaxSize; i >= 0; i--)
	{
		Data* largestnode = Pop();
		Insert(i, largestnode);
	}

}


void Heap::GenerateFilledArray(int randNum)
{
	
	Data* randomData;

	for (int i = 0; i < _mMaxSize; i++)
	{
		randomData = new Data( (int)(rand() % randNum) + 1);

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
				std::cout << theHeap[i]->_mKey;
				for (int k = 0; k < spaces; k++)
					std::cout << " ";
			}
		}
		spaces = indent[iterator -1];
		iterator++;
		std::cout << std::endl;

	}
	delete[] indent;
}
 void Heap::MaxHeapify(std::vector<int>& A, int i, int heapsize)
 {
	 int l = Left(i);
	 int r = Right(i);
	 int largest = 0;
	 if (l < heapsize && A[l] > A[i])
		 largest = l;
	 else largest = i;

	 if (r < heapsize && A[r] > A[largest])
		 largest = r;
	 if (largest != i)
	 {
		 int temp = A[largest];
		 A[largest] = A[i];
		 A[i] = temp;
		 MaxHeapify(A, largest, heapsize);
	 }
 }
 void Heap::MaxHeapify(std::vector<int>& A, int i)
 {
	 int l = Left(i);
	 int r = Right(i);
	 int largest = 0;
	 if (l < A.size() && A[l] > A[i])
		 largest = l;
	 else largest = i;

	 if (r < A.size() && A[r] > A[largest])
		 largest = r;
	 if (largest != i)
	 {
		 int temp = A[largest];
		 A[largest] = A[i];
		 A[i] = temp;
		 MaxHeapify(A, largest);
	 }
 }
 void Heap::BuildMaxHeap(std::vector<int>& A)
 {
	 for (int i = A.size() / 2; i >= 0; i--)
	 {
		 MaxHeapify(A, i);
		 //MaxHeap(A, i);
	 }

 }
 void Heap::HeapSort(std::vector<int>& A)
 {
	 BuildMaxHeap(A);
	 int heapSize = A.size() - 1;
	 for (int i = heapSize; i >= 1; i--)
	 {
		 int temp = A[0];
		 A[0] = A[i];
		 A[i] = temp;
		 MaxHeapify(A, 0, i);
		 //	MaxHeap(A, 0);
	 }
 }

 void Heap::MaxHeap(std::vector<int>& A, int i)
 {
	 int largest = i;
	 int heapsize = A.size() - 1;
	 while (i <= heapsize) {
		 int le = i * 2;
		 int ri = i * 2 + 1;
		 if ((le <= heapsize) && (A[le] > A[i]))
			 largest = le;
		 else
			 largest = i;
		 if ((ri <= heapsize) && (A[ri] > A[largest]))
			 largest = ri;
		 if (largest != i)
		 {
			 int temp = A[i];
			 A[i] = A[largest];
			 A[largest] = temp;
			 i = largest;
		 }
		 else
			 break;
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
