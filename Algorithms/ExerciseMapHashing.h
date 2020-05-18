#pragma once
#include <vector>
#include <iostream>
#include <string>
// https://leetcode.com/problems/two-sum
class Collision
{
public:
	Collision(std::string key, int index) :_mKey(key), _mIndex(index)
	{

	}
public:
	Collision* next = nullptr;
	std::string _mKey = "";
	int _mIndex = 0;
};


class CollisionList
{
public:
	CollisionList()
	{
		_mLastCollision = nullptr;
	}
	CollisionList(const std::string& key, const int& index) : _mLastCollision(nullptr)
	{
		InsertKey(key, index);
	}
	~CollisionList()
	{
		delete _mLastCollision;
	}
	void InsertKey(const std::string& key, const int& index)
	{
		Collision* newLink = new Collision(key, index);
		newLink->next = _mLastCollision;
		_mLastCollision = newLink;
	}
	bool FindASpecificKey(const std::string& key, int& index)
	{
		if (_mLastCollision == nullptr)
		{
			return false;
		}
		Collision* current = _mLastCollision;
		Collision* prev = _mLastCollision;

		while (current->next != nullptr)
		{
			current = current->next;
			if (current->_mKey == key)
			{
				index = current->_mIndex;
				return true;
			}
		}
		if (prev->_mKey == key)
		{
			index = prev->_mIndex;
			return true;
		}
		else
		{
			index = 0;
			return false;
		}
	}

public:
	Collision* _mLastCollision;
};
class Hashing
{
public:
	Hashing(int vectorSize, int target) :_mVectorSize(vectorSize), _mMod(_mVectorSize), _mTarget(target)
	{
		_mCollisionList = new CollisionList[vectorSize];
	
	}
	std::vector<int> AddElements(const std::vector<int>& vec)
	{
		for (int i = 0; i < _mVectorSize; i++)
		{
			int index;
			int value = _mTarget - vec[i];
			if (FindAKetWithIndex(std::to_string(value),index))
			{
				if (i != index)
				{
					return {i,index};
				}
			}
			const std::string& key = std::to_string(vec[i]);
			InsertIntoTable(key, i);
		}
	}
	
	~Hashing()
	{
		delete[]_mCollisionList;
	}
	const int& CalculateHashing(const std::string& value)
	{
		return _mHashValue = stoi(value) % _mMod;
	}
	bool FindAKetWithIndex(const std::string& key, int& index)
	{
		const int& hash = CalculateHashing(key);
		if (_mCollisionList[hash].FindASpecificKey(key, index))
			return true;
		else return false;
	}
	void InsertIntoTable(const std::string& key, int index)
	{
		const int& hashValue = CalculateHashing(key);
		_mCollisionList[hashValue].InsertKey(key, index);
	}
	CollisionList* _mCollisionList;
	int _mVectorSize = 0;
	unsigned int _mMod = 0;
	unsigned int _mHashValue = 0;
	int _mTarget = 0;
};


std::vector<int> twoSum(std::vector<int>& nums, int target)
{

	Hashing hashing(nums.size(), target);

	return hashing.AddElements(nums);
}