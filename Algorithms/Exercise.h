#pragma once
#include <string>



class DoubleLink
{
public:
	DoubleLink(std::string Name, int Id);
	~DoubleLink();
	inline std::string Print() const  { return "Name : " + _mName + " with ID-> " + std::to_string(_mId); }
public:
	std::string _mName;
	int _mId;
	DoubleLink* next;
	DoubleLink* previous;
};

class DoubleLinkList
{
public:
	DoubleLinkList();
	~DoubleLinkList();
	void Insert(DoubleLink* newLink);
	void Insert(const std::string& newName,const int& newId);
	void Remove(DoubleLink* removeThisLink);
	void Remove(int removeById);
	void Remove(std::string removeByName);
	DoubleLink* Find(int findById);
	DoubleLink* Find(std::string findByName);
	void PrintList();
public:
	DoubleLink* _mLastItem;
	DoubleLink* _mFirstItem;
};

 struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	//https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/
	ListNode* removeNthFromEnd(ListNode* head, int n);
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

};

