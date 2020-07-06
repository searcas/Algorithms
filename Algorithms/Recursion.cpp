#include "Recursion.h"

#include <iostream>
#include <vector>







Recursion::Recursion()
{
	

}

Recursion::~Recursion()
{

}

int Recursion::GetTriangularNumWhileLoop(int number)
{
	int triangularNumber = 0;

	while (number>0)
	{
		triangularNumber = triangularNumber + number;
		number--;
	}
	return triangularNumber;
}
int Recursion::GetTriangularNumRecursion(int number)
{
	std::cout << "Method " << number << std::endl;
	if (number==1)
	{
		std::cout << " returned 1"<<std::endl;
		return 1;
	}
	else
	{
		int result = number + GetTriangularNumRecursion(number - 1);
		std::cout << "Result "<< result << " : "<<number<<" + GetTN( "<<number<<" - 1)"<<std::endl;
		return result;
	}

}
int Recursion::Factorial(int number)
{
	std::cout << "Method " << number << std::endl;

	if (number == 1)
	{
		std::cout << "Returned 1" << std::endl;
		return 1;
	}
	else
	{
		int result = number * Factorial(number - 1);
		std::cout << "Result " << result << " : " << number << " * Factorial( " << number << " - 1)" << std::endl;
		return result;
	}
}


int Recursion::Fibonacci(int num)
{
	if (num < 2)
	{
		return num;
	}
	else
	{
		int result = Fibonacci(num - 1) + Fibonacci(num - 2);
		return result;
	}
}
void Recursion::MergeSort_srt(int array[], int lo, int n) 
{
	int low = lo;
	int high = n;

	if (low >= high) {
		return;
	}

	int middle = (low + high) / 2;

	MergeSort_srt(array, low, middle);

	MergeSort_srt(array, middle + 1, high);

	int end_low = middle;

	int start_high = middle + 1;

	while ((lo <= end_low) && (start_high <= high)) {

		std::cout << "Is " << array[low] << " < " << array[start_high]<<"? " << (array[low] < array[start_high])<<std::endl;

		if (array[low] < array[start_high]) {

			low++;
		}
		else {

			int Temp = array[start_high];

			std::cout << "Temp: " << Temp;


			for (int k = start_high - 1; k >= low; k--) {

				std::cout << "array[" << k << "] = " << array[k]<< " Stored in array index " << (k + 1)
					<<std::endl;

				array[k + 1] = array[k];
			}
			std::cout << Temp << " is stored in index " << low<<std::endl;
			array[low] = Temp;
			low++;
			end_low++;
			start_high++;
		}
	}


}
//Need memoization fix
int rec(std::vector<int>& vec, int total, int start, std::vector<int>& memo)
{
	if (total == 0)
	{
		return 1;
	}
	else if (total < 0)
	{
		return 0;
	}
	else if (start < 0)
	{
		return 0;
	}
	else if (memo[start] > 0)
	{
		return memo[start];
	}
	else if (total < vec[start])
	{
		memo[start] = rec(vec, total, start - 1, memo);
		return memo[start];
	}
	else
	{
		memo[start] = rec(vec, total - vec[start], start - 1, memo) + rec(vec, total, start - 1, memo);
		return memo[start];
	}
}


int count_sets(std::vector<int>vec, int total)
{
	std::vector<int>memo(vec.size());
	return rec(vec, total, vec.size() - 1, memo);
}