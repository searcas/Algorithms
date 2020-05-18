#pragma once
#include <string>

class HashTable
{
public:
	HashTable(std::string items[], int sizeOfItems, int hashTableSize);
	~HashTable();
	void FillArray(const char* item = "-1");
	void HashFuncNumOne(std::string array[], std::string* value);
	void HashFuncNumTwo(std::string array[], std::string* value, unsigned int sizeOfItems, unsigned int bestMod);
	void HashFuncNumThree(std::string array[], std::string* value, unsigned int sizeOfItems,unsigned int bestMod);
	std::string FindanItem(std::string);


private:
	std::string* _mTheArray;
	std::string* _mItems;

	int _mHashTableSize;
	int itemsInArray = 0;
	int collisionCtr = 0;
};

class HashTableV
{
public:
	HashTableV();
	~HashTableV();

private:

};

