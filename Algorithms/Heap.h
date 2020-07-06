#pragma once
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include "Sorting.h"
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
	void HeapSort();

	void MaxHeapify(std::vector<int>& A, int i, int heapsize);
	void MaxHeapify(std::vector<int>& A, int i);
	void MaxHeap(std::vector<int>& A, int i);

	void BuildMaxHeap(std::vector<int>& A);
	//friend class
public:
	static Heap& Get()
	{
		static Heap instance;
		return instance;
	}
	inline static void GetHeapSorting(std::vector<int>& vec) { return Get().HeapSortMax(vec); }
private:
	inline int Parent(int i)
	{
		return i / 2;
	}
	inline int Left(int i)
	{
		return i * 2 + 1;
	}
	inline int Right(int i)
	{
		return i * 2 + 2;
	}
public:
	void HeapSortMax(std::vector<int>& A);
public:
	Data**  theHeap;
	int _mItemsInArray = 0;
	int _mMaxSize;
};


