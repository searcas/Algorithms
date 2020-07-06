#pragma once


#include <vector>





class Recursion
{
public:
	Recursion();
	~Recursion();
	int GetTriangularNumWhileLoop(int number);
	int GetTriangularNumRecursion(int number);
	void MergeSort_srt(int array[], int lo, int n);
	int Fibonacci(int num);

	int Factorial(int number);
public:
	

};

int rec(std::vector<int>& vec, int total, int start, std::vector<int>& memo);

int count_sets(std::vector<int>vec, int total);



