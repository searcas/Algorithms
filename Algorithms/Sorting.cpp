#include "Sorting.h"
#include <iostream>
Sorting::Sorting()
{
}

Sorting::~Sorting()
{
}

void Sorting::BubbleSort(std::vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = i; j < vec.size(); j++)
		{
			if (vec[i] > vec[j])
			{
				int temp = vec[i];
				vec[i] = vec[j];
				vec[j] = temp;
			}
		}
	}
}

int Sorting::BinarySearch(const int& num, std::vector<int>& vec)
{
	int lowerIndex = 0;
	int higherIndex = vec.size() - 1;
	while (lowerIndex <= higherIndex)
	{
		int middle = (lowerIndex + higherIndex) / 2;
	
			if (vec[middle] > num)
			{
				higherIndex = middle -1 ;
			}
			else if(vec[middle] < num)
			{
				lowerIndex = middle + 1;

			}
			else
			{
				std::cout << "Number found " << vec[middle] << std::endl;
				return vec[middle];
			}
	}
	
	
		std::cout << "Number not found" << std::endl;
		return 0;
}
// 3 5 1 7 
void Sorting::SelectionSort(std::vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		int min = i;
		for (int j = i; j < vec.size(); j++)
		{

			if (vec[min] > vec[j])
			{
				min = j;
			}
		}
		int temp = vec[i];  
		vec[i] = vec[min];
		vec[min] = temp;
		
	}
}
// 3 5 1 7 
void Sorting::InsertionSort(std::vector<int>& vec)
{
	for (int i = 1; i < vec.size(); i++)
	{
		int j = i;

		int toInsert = vec[i];

		while ((j > 0) && (vec[j - 1] > toInsert))
		{
			vec[j] = vec[j - 1];
			j--;
		}
			vec[j] = toInsert;
	}
}
void Sorting::ShellSort(std::vector<int>& vec)
{
	int inner;
	int outer;
	int temp ;
	int interval = 1;

	while (interval <= vec.size() / 3 )
	{
		interval = interval * 3 + 1;
		while (interval > 0)
		{
			for (outer = interval; outer < vec.size(); outer++)
			{
				temp = vec[outer];

				inner = outer;
				while (inner > interval - 1 && vec[inner -interval]>= temp)
				{
					vec[inner] = vec[inner - interval];
					inner -= interval;
				}
				vec[inner] = temp;
			}
			interval = (interval - 1) / 3;

		}
	}
}
