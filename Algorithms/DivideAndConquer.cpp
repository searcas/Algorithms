#include "DivideAndConquer.h"




//0   1    2   3   4   5   6  7   8   9    10
//100 113  110 85  105 102 86 63  81  101  94
Props FindMaxCrossingSubArray(std::vector<int>&A, int low, int mid, int high)
{
	int summ = 0;
	int maxleftSumm = 0;
	int max_left = 0;
	for (int i = mid; i >= low; i--)
	{
		summ = summ + A[i];
		if (summ > maxleftSumm)
		{
			maxleftSumm = summ;
			max_left = i;
		}
	}
	summ = 0;
	int maxRightSumm = 0;
	int max_right = 0;

	for (int i = mid + 1; i < high; i++)
	{
		summ = summ + A[i];
		if (summ > maxRightSumm)
		{
			maxRightSumm = summ;
			max_right= i;
		}
	}
	return { max_left, max_right, maxleftSumm + maxRightSumm };
}

Results FindMaximumSubArray(std::vector<int>& A, int low, int high)
{
	if (high == low)
	{
		return { low, high, A[low] };
	}
	else
	{
		int mid = (low + high) / 2;
		Results left  = FindMaximumSubArray(A, low, mid);
		Results right = FindMaximumSubArray(A, mid+1, high);
		Props cross = FindMaxCrossingSubArray(A, low, mid, high);
		if (left.summ >= right.summ && left.summ >= cross.summ)
		{
			return { left.low,left.high,left.summ };
		}
		else if (right.summ >= left.summ && right.summ >= cross.summ)
		{
			return { right.low,right.high,right.summ };
		}
		else
		{
			return { cross.max_left, cross.max_right, cross.summ };
		}
	}
}

void Merge(std::vector<int>& A, int p, int q, int r)
{
	int n1 = q - p ;
	int n2 = r - q;

	std::vector<int> left(n1);
	std::vector<int> right(n2);

	for (int i = 0; i < n1; i++)
	{
		left[i] = A[p + i];
	}
	for (int i = 0; i < n2; i++)
	{
		right[i] = A[q + i ];

	}
	int i = 0;
	int j = 0;
	for (int k = p; k < r; k++)
	{
		if (left[i]<=right[j])
		{
			A[k] = left[i];
			i++;
		}
		else
		{
			A[k] = right[j];
			j++;
		}
	}
}
