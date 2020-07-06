#pragma once
#include <vector>

class Sorting
{
public:
	Sorting();
	~Sorting();
	void BubbleSort(std::vector<int>&vec);
	int BinarySearch(const int& value, std::vector<int>& vec);
	
	void SelectionSort(std::vector<int>& vec);
	void InsertionSort(std::vector<int>& vec);
	void ShellSort(std::vector<int>& vec);
	void HeapSort(std::vector<int>&vec);
//HeapSorting
public:
	
private:

};



