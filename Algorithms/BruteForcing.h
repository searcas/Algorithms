#pragma once
#include <string>






class BruteForce
{
public:
	BruteForce(int numberOfBruteForcing);
	void StartBruteForce(int startIndex, std::string hashMap[],std::string* items, int itemSize);
	bool isPrime(int num);
	int GetNextPrimeNumber(int& num);
private:
	int _mNumberOfBruteForcing;
};

