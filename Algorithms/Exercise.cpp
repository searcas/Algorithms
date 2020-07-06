#include "Exercise.h"
#include <iostream>




DoubleLink::DoubleLink(std::string Name, int Id) : _mName(Name), _mId(Id)
{
	next = nullptr;
	previous = nullptr;
}

DoubleLink::~DoubleLink()
{
	delete next;
	delete previous;
}





DoubleLinkList::DoubleLinkList()
{
	_mLastItem = nullptr;
	_mFirstItem = nullptr;
}

DoubleLinkList::~DoubleLinkList()
{
}

void DoubleLinkList::Insert(DoubleLink* newLink)
{
	if (newLink == nullptr)
	{
		return;
	}
}
//Nenad : 32
//Sanja : 41

void DoubleLinkList::Insert(const std::string& newName, const int& newId)
{
	DoubleLink* newLink = new DoubleLink(newName, newId);

	if (_mLastItem == nullptr)
	{
		_mFirstItem = newLink;
		_mLastItem = newLink;
	}
	else
	{
		_mLastItem->next = newLink;
		_mLastItem->previous = _mLastItem;
		_mLastItem = newLink;
	}

}

void DoubleLinkList::Remove(DoubleLink* removeThisLink)
{
}

void DoubleLinkList::Remove(int removeById)
{
}

void DoubleLinkList::Remove(std::string removeByName)
{
}

DoubleLink* DoubleLinkList::Find(int findById)
{
	return nullptr;
}

DoubleLink* DoubleLinkList::Find(std::string findByName)
{
	return nullptr;
}

void DoubleLinkList::PrintList()
{
	DoubleLink* temp = _mFirstItem;

	while (temp->next != nullptr)
	{
		std::cout << temp->Print() << std::endl;
	}
}
ListNode* ListNode::removeNthFromEnd(ListNode* head, int n) {
	ListNode* cur = head;
	ListNode* prev = head;
	int ctr = 1;
	if (cur == nullptr)
		return nullptr;
	if (ctr != n)
	{
		while (cur->next != nullptr)
		{
			prev = cur;
			cur = cur->next;
			ctr++;
			if (ctr == n)
				break;
		}
	}
	else
	{
		head = head->next;
	}
	if (cur == prev)
	{
		head = head->next;
	}
	else
	{
		prev->next = cur->next;
	}

	return head;
}
ListNode* ListNode::mergeTwoLists(ListNode* l1, ListNode* l2) {
 
	ListNode* firstList = l1;
	ListNode* secondList = l2;
	ListNode* thirdList = l1;

	while (firstList->next != nullptr && secondList->next != nullptr)
	{
		if (firstList->val <= secondList->val)
		{
			thirdList->next = secondList;
			thirdList = firstList;
			firstList = firstList->next;
		}
		else
		{
			thirdList->next = secondList;
			thirdList = secondList;
			secondList = secondList->next;
		}

	}
	return thirdList;

}