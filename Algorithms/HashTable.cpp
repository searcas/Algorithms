#include "HashTable.h"
#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include "BruteForcing.h"

HashTableV::HashTableV()
{
}

HashTableV::~HashTableV()
{
}


HashTable::HashTable(std::string items[], int sizeOfItems,int hashTableSize) : _mItems(items), _mHashTableSize(hashTableSize)
{
	_mTheArray = new std::string[hashTableSize];
	HashFuncNumThree(_mTheArray, items, sizeOfItems, 34);
}
void HashTable::FillArray(const char* item)
{
	for (int i = 0; i < _mHashTableSize; i++)
	{
		_mTheArray[i] = item;
	}
	for (int i = 0; i < _mHashTableSize; i++)
	{
		std::cout << "elemen " << i << " is: " << _mTheArray[i] << std::endl;
	}
}
void HashTable::HashFuncNumOne(std::string hashMap[], std::string* items)
{
	for (int index = 0; index < _mHashTableSize; index++)
	{
		int temp = stoi(items[index]);
		hashMap[temp] = items[index];
	}

}

void HashTable::HashFuncNumThree(std::string hashMap[], std::string* items, unsigned int sizeOfItems, unsigned int bestMod)
{
	BruteForce br(201);
	br.StartBruteForce(1, hashMap, items, sizeOfItems);

	for (int index = 0; index < sizeOfItems; index++)
	{
		int num = stoi(items[index]) % 34;
		int stepDistance = 7 - num % 7;
		if (hashMap[num] == "-1" || hashMap[num] == "")
		{
			hashMap[num] = items[index];
			//std::cout << "HashMap inserted new number "<<items[index]<<" -> on index -> " << num << std::endl;
		}
		else
		{
			while (hashMap[num] != "")
			{
				collisionCtr++;
				if (num != _mHashTableSize)
				{
					//	std::cout << "Collision on index " << num << " index is already taken." << std::endl;
					num += stepDistance;
				}
				else
				{
					num = num % _mHashTableSize;
				}
			}
			hashMap[num] = items[index];
			//	std::cout << "HashMap inserted new number " << items[index] << " -> on index ->" << num << std::endl;

		}
	}

	for (int i = 0; i < _mHashTableSize; i++)
	{
		std::cout << "Item " << i << " is: " << _mTheArray[i] << std::endl;
	}
	std::cout << "TOTAL NUMBERS OF COLLISIONS IS >>>>>>>>>>( " << collisionCtr << " )<<<<<<<<<<<<<<<< " << std::endl;
}

void HashTable::HashFuncNumTwo(std::string hashMap[], std::string* items, unsigned int sizeOfItems,unsigned int bestMod)
{
	
	
	
		for (int index = 0; index < sizeOfItems; index++)
		{
			int num = stoi(items[index]) % 34;
			if (hashMap[num] == "-1" || hashMap[num] =="")
			{
				hashMap[num] = items[index];
			//std::cout << "HashMap inserted new number "<<items[index]<<" -> on index -> " << num << std::endl;
			}
			else
			{
				while (hashMap[num] !="")
				{
					collisionCtr++;
					if (num != _mHashTableSize)
					{
					//	std::cout << "Collision on index " << num << " index is already taken." << std::endl;
						num++;
					}
					else
					{
						num = num %_mHashTableSize; 
					}
				}
				hashMap[num] = items[index];
			//	std::cout << "HashMap inserted new number " << items[index] << " -> on index ->" << num << std::endl;

			}
		}
	
	for (int i = 0; i < _mHashTableSize; i++)
	{
		std::cout << "Item " << i << " is: " << _mTheArray[i] << std::endl;
	}
	std::cout << "TOTAL NUMBERS OF COLLISIONS IS >>>>>>>>>>( " << collisionCtr << " )<<<<<<<<<<<<<<<< "<< std::endl;
}

std::string HashTable::FindanItem(std::string key)
{
	int mod = stoi(key) % 34;

	while (_mTheArray[mod] != key)
	{
		if (mod<_mHashTableSize)
		{
			mod++;
		}
		else
		{
			std::cout << "Key does not exist." << std::endl;
			return "";
		}
	}
	if (key ==_mTheArray[mod])
	{
		std::cout << "Key "<< _mTheArray[mod] <<" is found on index "<<mod<<"." << std::endl;
		return _mTheArray[mod];
	}
	else
	{
		std::cout << "Key does not exist." << std::endl;
		return "";
	}
}
HashTable::~HashTable()
{
}