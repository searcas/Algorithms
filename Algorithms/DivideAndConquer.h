#pragma once
#include <vector>



struct Props
{
	int max_left = 0;
	int max_right = 0;

	int summ = 0;
};

struct Results
{
	int low = 0;
	int high = 0;

	int summ = 0;
};

Props FindMaxCrossingSubArray(std::vector<int>&A, int low, int mid, int high);
Results FindMaximumSubArray(std::vector<int>& A, int low, int high);

void Merge(std::vector<int>&A, int p, int q, int r);
inline void MergeSort(std::vector<int>& A, int p, int r)
{
	if (p < r)
	{
		int q = (p + r ) / 2;
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);

	}

}
