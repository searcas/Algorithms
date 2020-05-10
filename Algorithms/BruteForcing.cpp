#include "BruteForcing.h"

#include <iostream>

BruteForce::BruteForce(int numberOfBruteForcing) :_mNumberOfBruteForcing(numberOfBruteForcing)
{
}

void BruteForce::StartBruteForce(int startIndex, std::string hashMap[], std::string* items,int itemSize)
{

	delete[] hashMap;
	int* lowestCollision = new int[_mNumberOfBruteForcing];
	//hackfix
	lowestCollision[0] = 9999999999;
	for (startIndex = 1; startIndex < _mNumberOfBruteForcing; startIndex++)
	{

		int newCtr = 0;
		hashMap = new std::string[_mNumberOfBruteForcing];
		for (int index = 0; index < itemSize; index++)
		{
			int num = stoi(items[index]) % startIndex;
			if (hashMap[num] == "")
			{
				hashMap[num] = items[index];
			}
			else
			{
				while (hashMap[num] != "")
				{
					newCtr++;

					if (num != _mNumberOfBruteForcing)
					{
						num++;
					}
					else
					{
						num = num % _mNumberOfBruteForcing;
					}
				}
				hashMap[num] = items[index];
			}
		}
		
			lowestCollision[startIndex] = newCtr;
	}
	int lowestNumbOfCollision = lowestCollision[0];
	int indexofLowestNum;
	for (int i = 0; i < _mNumberOfBruteForcing; i++)
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

	
	std::cout << "TOTAL NUMBERS OF COLLISIONS IS >>>>>>>>>>( " << lowestNumbOfCollision << " with index " << indexofLowestNum << " )<<<<<<<<<<<<<<<< " << std::endl;
	delete[]lowestCollision;
	delete[] hashMap;
}


