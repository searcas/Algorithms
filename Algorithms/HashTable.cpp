#include "HashTable.h"
#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include "BruteForcing.h"



HashTable::HashTable(int size)
{
	_mArraySize = size;
	_mTheArray = new std::string[size];
	std::string numbers []= { "5","4","3","2","12","20","52","42","23","22","12","230","12","20","52","42","23","22","12","232"};

	HashFuncNumTwo(_mTheArray, numbers, 20, 33);
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
void HashTable::HashFuncNumTwo(std::string hashMap[], std::string* items, int sizeOfItems, int bestMod)
{
	
		for (int index = 0; index < sizeOfItems; index++)
		{
			int num = stoi(items[index]) % 34;
			if (hashMap[num] == "-1" || hashMap[num] =="")
			{
				hashMap[num] = items[index];
			//	std::cout << "HashMap inserted new number "<<items[index]<<" -> on index -> " << num << std::endl;
			}
			else
			{
				while (hashMap[num] !="")
				{
					collisionCtr++;
					if (num != _mArraySize)
					{
					//	std::cout << "Collision on index " << num << " index is already taken." << std::endl;
						num++;
					}
					else
					{
						num = num %_mArraySize; 
					}
				}
				hashMap[num] = items[index];
			//	std::cout << "HashMap inserted new number " << items[index] << " -> on index ->" << num << std::endl;

			}
		}
	
	for (int i = 0; i < _mArraySize; i++)
	{
		std::cout << "elemen " << i << " is: " << _mTheArray[i] << std::endl;
	}
	std::cout << "TOTAL NUMBERS OF COLLISIONS IS >>>>>>>>>>( " << collisionCtr << " )<<<<<<<<<<<<<<<< "<< std::endl;
}
HashTable::~HashTable()
{
}