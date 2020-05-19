#include <iostream>
#include <vector>
#include "LinkedList.h"
#include "HashTable.h"
#include "BruteForcing.h"
#include "HashTableMap.h"
#include"ExerciseMapHashing.h"
#include "Heap.h"
#include "BinarySearchTree.h"
	//std::string items[] = { "5","4","3","2","12","20","52","42","23","22","12","230","12","20","52","42","23","22","12","232" ,"323","333"};
int main()
{
	Heap heap(70);
	heap.GenerateFilledArray(9);
	heap.PrintTree(5);
	return 0;

}
