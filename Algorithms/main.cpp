#include <iostream>
#include <vector>
#include "LinkedList.h"
#include "HashTable.h"
#include "BruteForcing.h"
#include "HashTableMap.h"
#include"ExerciseMapHashing.h"
#include "Heap.h"
#include "BinarySearchTree.h"
#include <numeric>
#include <algorithm>
#include "Recursion.h"
#include <functional>

int maxProfit(std::vector<int>& prices) {
    const auto& valueMin = std::min_element(prices.begin(), prices.end());
    const auto& minIndex = std::distance(prices.begin(), valueMin);
    const auto& max = std::max_element(valueMin, prices.end());
    
    const auto& secMin = std::find_if(prices.begin(), valueMin, [=](const int& num) {return num != valueMin[0]; });
    const auto& secMax = std::max_element(secMin, prices.end());

    int BestValue = (max[0] - valueMin[0]) > secMax[0] - secMin[0] ? (max[0] - valueMin[0]) : secMax[0] - secMin[0];
    if (prices.empty())
        return 0;
    return BestValue;
}
int rec(std::vector<int>& vec, int total, int start,std::vector<int>&memo)
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
int main()
{
    std::vector<int>in{ 2,4,6,10 };
	const int& test = count_sets(in,16);
    std::cout << test << std::endl;
    return 0;

}
