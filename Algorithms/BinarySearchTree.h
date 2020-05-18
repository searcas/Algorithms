#pragma once
#include <string>
#include <iostream>

class Node
{
public:
	Node(int key, std::string);
	~Node();

	inline std::string toString() const
	{
		return _mName + " has a key " + std::to_string(_mKey);
	}

public:
	Node* leftChild;
	Node* rightChild;

	int _mKey;
	std::string _mName;

};




class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	void addNode(int key, std::string);
	void InOrderTraverseTree(Node* mainNode);
	void PreOrderTraverseTree(Node* mainNode);
	void PostOrderTraverseTree(Node* mainNode);
	Node* FindNode(int key);
	bool Remove(int key);
	Node* GetReplacmentNode(Node* mainNode);
	


public:
	Node* _mRoot;
};


