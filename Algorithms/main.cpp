#include <iostream>
#include <vector>
#include "LinkedList.h"
#include "HashTable.h"
#include "BruteForcing.h"
#include "HashTableMap.h"

#include"ExerciseMapHashing.h"
	//std::string items[] = { "5","4","3","2","12","20","52","42","23","22","12","230","12","20","52","42","23","22","12","232" ,"323","333"};
int main()
{
	/*HashMap test(11);

	std::string wordLookup = "a";

		std::cout << "Word to lookup" << wordLookup << std::endl;
		test.FindWord(wordLookup);
		test.DisplayArray();
		*/

	std::vector<int>vec{ 2,7,11,15 };
	Hashing hashing(vec.size(), 9);
	
	const std::vector<int>&ref = hashing.AddElements(vec);
	
	std::cout << "index " << ref[0] << " : " << ref[1] << std::endl;
	return 0;

}
