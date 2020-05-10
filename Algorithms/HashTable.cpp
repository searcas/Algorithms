#include "HashTable.h"
#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 




HashTable::HashTable(int size)
{
	_mArraySize = size;
	_mTheArray = new std::string[size];
	std::string numbers []= { "5","4","3","2","12","20","52","42","23","22","12","230","12","20","52","42","23","22","12","232"};

	HashFuncNumTwo(_mTheArray, numbers, 20);
}
void HashTable::FillArray(const char* item)
{
	for (int i = 0; i < _mArraySize; i++)
	{
		_mTheArray[i] = item;
	}
	for (int i = 0; i < _mArraySize; i++)
	{
		std::cout << "elemen " << i << " is: " << _mTheArray[i] << std::endl;
	}
}
void HashTable::HashFuncNumOne(std::string hashMap[], std::string* items)
{
	for (int index = 0; index < _mArraySize; index++)
	{
		int temp = stoi(items[index]);
		hashMap[temp] = items[index];
	}

}
void HashTable::HashFuncNumTwo(std::string hashMap[], std::string* items, int sizeOfItems)
{
	
	int* lowestCollision = new int[_mArraySize];
	delete[]hashMap;
	//bruteForcing
	for (int bruteForcing = 0; bruteForcing < _mArraySize; bruteForcing++)
	{
		int newCtr = 0;
		hashMap = new std::string[_mArraySize];
		for (int index = 0; index < sizeOfItems; index++)
		{
			int num = stoi(items[index]) % (bruteForcing + 1);
			if (hashMap[num] == "-1" || hashMap[num] =="")
			{
				hashMap[num] = items[index];
				//std::cout << "HashMap inserted new number "<<items[index]<<" -> on index -> " << num << std::endl;
			}
			else
			{
				while (hashMap[num] !="")
				{
					newCtr++;
					if (num != _mArraySize)
					{
						//std::cout << "Collision on index " << num << " index is already taken." << std::endl;
						num++;
					}
					else
					{
						num = num %_mArraySize; 
					}
				}
				hashMap[num] = items[index];
				//std::cout << "HashMap inserted new number " << items[index] << " -> on index ->" << num << std::endl;

			}
			lowestCollision[bruteForcing] = newCtr;
		}
	}
	int lowestNumbOfCollision = lowestCollision[0];
	int indexofLowestNum;
	for (int i = 0; i < _mArraySize; i++)
	{
		if (lowestNumbOfCollision < lowestCollision[i])
		{
			continue;
		}
		else
		{
			lowestNumbOfCollision = lowestCollision[i];
			indexofLowestNum = i;
		}
	}

	for (int i = 0; i < _mArraySize; i++)
	{
		std::cout << "elemen " << i << " is: " << _mTheArray[i] << std::endl;
	}
	std::cout << "TOTAL NUMBERS OF COLLISION IS >>>>>>>>>> " << lowestNumbOfCollision << " <<<<<<<<<<<<<<<" << std::endl;
	delete[]lowestCollision;
}
HashTable::~HashTable()
{
}