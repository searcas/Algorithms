#pragma once
#include <iostream>
#include <vector>

class Word
{
public:
	Word(std::string theWord, std::string definition);
	~Word();
	inline std::string ToString()
	{
		return _mTheWord + " : " + _mDefinition;
	}

public:
	std::string _mTheWord;
	std::string _mDefinition;
	int _mKey;
	Word* _mNext;
};

class WordList
{
public:
	WordList() { _mFirstWord = nullptr; }
	~WordList() {}
	void Insert(Word* newWord, int hashKey);
	void DisplayWordList();
	Word* Find(int hashKey);
public:
	Word* _mFirstWord;

};

class HashMap
{
public:
	HashMap(int size); 
	int StringHasFunc(std::string wordToHas);
	void Insert(Word* newWord);
	Word* FindWord(std::string wordToFind);
	void DisplayArray();
	void AddtheArray(const std::vector<std::vector<std::string>>& elemntsToAdd);
public:
	int _mArraySize;
	WordList* _mWordList[];

};




