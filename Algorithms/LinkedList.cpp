#include "LinkedList.h"
#include <iostream>






Link::Link(int data) 
{
	this->data = data;
	next = nullptr;
}
void Link::Display()
{
	std::cout << "Current Data: ->" << data << std::endl;
}
LinkList::LinkList() : currentLink(nullptr)
{
}
bool LinkList::IsEpmty()
{
	return currentLink == nullptr;
}
void LinkList::InsertLink(int data)
{
	Link* newLink = new Link(data);
	newLink->next = currentLink;
	currentLink = newLink;
}
Link& LinkList::RemoveLink()
{
	Link* linkReference = currentLink;

	if (!IsEpmty())
		currentLink = currentLink->next;
	else 
		std::cout << "Empty Link List" << std::endl;
	return *linkReference;
}

void LinkList::DisplayData()
{
	Link* current = currentLink;

	while (current != nullptr)
	{
		current->Display();
//		std::cout << "Next link is: -> " << ((current->next == nullptr) ? 0 : current->next->data) << std::endl;
		current = current->next;
	}
	delete current;
}
Link* LinkList::FindNumber(int num)
{
	Link* temp = currentLink;

	if (!IsEpmty())
	{
			while (temp->data != num)
			{
				if (temp->next != nullptr)
				{
					temp = temp->next;
				}
				else
				{
					std::cout << "Number does not exist" << std::endl;
					return nullptr;
				}
				
			}
		return temp;
	}
	else
	{
		std::cout << "Data is empty" << std::endl;
	}
	return 0;
}
Link* LinkList::RemoveSpecificLink(int num)
{
	Link* cur = currentLink;
	Link* previous = currentLink;
	if (!IsEpmty())
	{
		while (cur->data != num)
		{ 
			if (cur->next != nullptr)
			{
				previous = cur;
				cur = cur->next;
			}
			else
			{
				std::cout << "Number does not exist" << std::endl;
				return nullptr;
			}
		}
		if (currentLink == cur)
		{
			currentLink == currentLink->next;
		}
		else
		{
			previous->next = cur->next;
		}
	}
	else
		std::cout << "List is empty" << std::endl;
	return nullptr;
}

DLink::DLink(int data): _mData(data)
{

}

void DLinkedList::InsertInFirstPosition(int storage)
{
	DLink* tempLink = new DLink(storage);

	if (IsEmpty())
	{
		lastLink = tempLink;
	}
	else
	{
		firstLink->prev = tempLink;
	}
	tempLink->next = firstLink;
	firstLink = tempLink;

}
void DLinkedList::InsertInLastPosition(int storage)
{
	DLink* tempLink = new DLink(storage);

	if (IsEmpty())
	{
		firstLink = tempLink;
	}
	else
	{
		lastLink->next = tempLink;
		tempLink->prev = lastLink;
	}

	lastLink = tempLink;
}
void DLinkedList::InsertAfterAKey(int key, int newKey)
{
	DLink* newLink = new DLink(newKey);
	DLink* currentLink = firstLink;

	while (currentLink->_mData != key)
	{
		currentLink = currentLink->next;
		if (currentLink ==nullptr)
		{
			return;
		}

	}
	if (currentLink == lastLink)
	{
		newLink->next = nullptr;
		lastLink = newLink;
	}
	else
	{
		newLink->next = currentLink->next;
		currentLink->next->prev = newLink;
	}
	newLink->prev = currentLink;
	currentLink->next = newLink;
}
void DLinkedList::InsertInOrder(int key)
{
	DLink* newLink = new DLink(key);
	DLink* previous = nullptr;
	DLink* current = firstLink;	

	while ((current != nullptr) && (current->_mData < key))
	{
		previous = current;
		current = current->next; 
	}
	if (previous == nullptr)
	{
		firstLink = newLink;
	}
	else
	{
		previous->next = newLink;

	}
	newLink->next = current;
}
bool DLinkedList::IsEmpty()
{
	
	return (firstLink == nullptr);
}
void DLinkedList::Display()
{
	DLink* current = firstLink;

	while (current != nullptr)
	{
		std::cout << "DATA : -> "<< current->_mData << std::endl;;
		//std::cout << "Next link is: -> " << ((current->next == nullptr) ? 0 : current->next->data) << std::endl;
		current = current->next;
	}
	delete current;
}

DlinkedListIterator::DlinkedListIterator(DLinkedList* theList) : doubleLinkList(theList)
{
	currentLink = theList->firstLink;
	previousLink = theList->lastLink;
}
bool DlinkedListIterator::HasNext()
{

	return (currentLink->next != nullptr) ? true : false;
}
DLink* DlinkedListIterator::Next()
{
	if (HasNext())
	{
		previousLink = currentLink;
		currentLink = currentLink->next;
		return currentLink;
	}
	return nullptr;
}
void DlinkedListIterator::Remove()
{
	if (previousLink == nullptr)
	{
		doubleLinkList->firstLink = currentLink->next;
	}
	else
	{
		previousLink->next = currentLink->next;
		if (currentLink->next == nullptr)
		{
			currentLink = doubleLinkList->firstLink;
			previousLink = nullptr;
		}
		else
		{
			currentLink = currentLink->next;
		}
	}
}
