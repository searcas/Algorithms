#pragma once
#include <string>

class HashTable
{
public:
	HashTable(int size);
	~HashTable();
	void FillArray(const char* item = "-1");
	void HashFuncNumOne(std::string array[], std::string* value);
	void HashFuncNumTwo(std::string array[], std::string* value,int sizeOfItems,int bestMod);


private:
	std::string* _mTheArray;
	int _mArraySize;
	int itemsInArray = 0;
	int collisionCtr = 0;
};