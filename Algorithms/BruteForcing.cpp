#include "BruteForcing.h"

#include <iostream>

BruteForce::BruteForce(int numberOfBruteForcing) :_mNumberOfBruteForcing(numberOfBruteForcing)
{
}
bool BruteForce::isPrime(int num)
{
	if (num == 2)
		return true;
	if (num % 2 == 0 || num == 1)
		return false;
	for (int i = 3; i * i <= num; i += 2)
		if (num % i == 0)
			return false;
		return true;
}
int BruteForce::GetNextPrimeNumber(int& num)
{
	if (isPrime(num))
		return num;
	while (!isPrime(num))
	{
		num++;
	}
	return num;
}
void BruteForce::StartBruteForce(int startIndex, std::string hashMap[], std::string* items,int itemSize)
{

	delete[] hashMap;
	int* lowestCollision = new int[GetNextPrimeNumber(_mNumberOfBruteForcing)];
	//hackfix
	lowestCollision[0] = 9999999999999999;
	for (startIndex = 1; startIndex < _mNumberOfBruteForcing; startIndex++)
	{


		int newCtr = 0;
		hashMap = new std::string[_mNumberOfBruteForcing];
		for (int index = 0; index < itemSize; index++)
		{
			int num = stoi(items[index]) % startIndex;
			int stepDistance = 7 - (stoi(items[index])) % 7;

			if (hashMap[num] == "")
			{
				hashMap[num] = items[index];
			}
			else
			{
				while (hashMap[num] != "")
				{
					newCtr ++;

					if (num != _mNumberOfBruteForcing)
					{
						num+=stepDistance;
					}
					else
					{
						num = 0;
					}
				}
				std::cout << "NUMBER IS " << num << std::endl;
				hashMap[num] = items[index];
			}
		}
			lowestCollision[startIndex] = newCtr;
		
	}
	int lowestNumbOfCollision = lowestCollision[0];
	int indexofLowestNum;
	for (int i = 0; i < _mNumberOfBruteForcing; i++)
	{
		std::cout << "Number of collisions with index " << i << " is " << lowestCollision[i] << std::endl;
	}
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
}


