#pragma once






class Link
{
public:
	int data;
	Link* next;
	Link(int data);
	void Display();
};

class LinkList
{
public:
	Link* currentLink;
	LinkList();
	bool IsEpmty();
	void InsertLink(int data);
	Link& RemoveLink();
	void DisplayData();
	Link* FindNumber(int num);
	Link* RemoveSpecificLink(int num);
};

class DLink
{
public:
	DLink* next = nullptr;
	DLink* prev = nullptr;
	int _mData;
	DLink(int data);
};



class DLinkedList
{
public:
	DLink* firstLink = nullptr;
	DLink* lastLink = nullptr;
public:
	void InsertInFirstPosition(int data);
	void InsertInLastPosition(int data);
	void InsertAfterAKey(int key,int newKey);
	void InsertInOrder(int key);

	bool IsEmpty();
	void Display();

};
class DlinkedListIterator
{
private:
	DLink* currentLink;
	DLink* previousLink;
	DLinkedList* doubleLinkList;
public:
	DlinkedListIterator(DLinkedList* theList);
	bool HasNext();
	DLink* Next();
	void Remove();
	
};


