#include <iostream>
#include <vector>
#include "LinkedList.h"
#include "HashTable.h"
#include "BruteForcing.h"
#include "HashTableMap.h"
#include"ExerciseMapHashing.h"

#include "BinarySearchTree.h"
	//std::string items[] = { "5","4","3","2","12","20","52","42","23","22","12","230","12","20","52","42","23","22","12","232" ,"323","333"};
int main()
{
	BinaryTree binaryT;
	binaryT.addNode(50, "Boss");
	binaryT.addNode(25, "Vice Pres");
	binaryT.addNode(15, "Office Manager");
	binaryT.addNode(30, "Secretary");
	binaryT.addNode(75, "Sales Manager");
	binaryT.addNode(85, "Salesman 1");
	std::cout << "Remove Key 25" << std::endl;
	binaryT.Remove(30); 
	binaryT.PostOrderTraverseTree(binaryT._mRoot);

	std::cout << "Search for 30" << std::endl;
	Node* tree = binaryT.FindNode(30);

	std::cout << tree->toString() << std::endl;
	return 0;

}
