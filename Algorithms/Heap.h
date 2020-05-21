#pragma once
#include <cmath>
#include <string>
#include <iostream>
class Data
{
public:
	Data();
	Data(int key);
	~Data();

public:
	int _mKey;
};


class Heap
{
public:
	Heap(int maxSize);
	Heap() {}

	~Heap();
	void Insert(int index, Data* newData);
	void GenerateFilledArray(int index);
	void PrintTree(int rows);
	int* GetIndentArray(int rows);
	int* ReverseArray(int* theArray,int length);
	void IncrementTheArray();
	Data* Pop();
	void HeapTheArray(int index);
	void HeapSort()


public:
	Data**  theHeap;
	int _mItemsInArray = 0;
	int _mMaxSize;

};


