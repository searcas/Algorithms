#include "BinarySearchTree.h"



BinaryTree::BinaryTree()
{
}

BinaryTree::~BinaryTree()
{
}
void BinaryTree::addNode(int key, std::string name)
{
	Node* newNode = new Node(key, name);

	if (_mRoot == nullptr)
	{
		_mRoot = newNode;
	}
	else
	{
		Node* mainNode = _mRoot;

		Node* parent;

		while (true)
		{
			parent = mainNode;
			if (key < mainNode->_mKey)
			{
				mainNode = mainNode->leftChild; 
				if (mainNode == nullptr)
				{
					parent->leftChild = newNode;
					return;
				}
			}
			else
			{
				mainNode = mainNode->rightChild;
				if (mainNode ==nullptr)
				{
					parent->rightChild = newNode;
					return;
				}
				
			}
		}
	}
}
void BinaryTree::InOrderTraverseTree(Node* mainNode)
{
	if (mainNode != nullptr)
	{
		InOrderTraverseTree(mainNode->leftChild);
		std::cout << mainNode->toString() << std::endl;
		InOrderTraverseTree(mainNode->rightChild);
	}
}
void BinaryTree::PreOrderTraverseTree(Node* mainNode)
{
	if (mainNode != nullptr)
	{
		std::cout << mainNode->toString() << std::endl;
		PreOrderTraverseTree(mainNode->leftChild);
		PreOrderTraverseTree(mainNode->rightChild);

	}
}
void BinaryTree::PostOrderTraverseTree(Node* mainNode)
{
	if (mainNode != nullptr)
	{
		PostOrderTraverseTree(mainNode->leftChild);
		PostOrderTraverseTree(mainNode->rightChild);

		std::cout << mainNode->toString() << std::endl;
	}
}
Node* BinaryTree::FindNode(int key)
{
	Node* mainNode = _mRoot;

	while (mainNode->_mKey != key)
	{
		if (key < mainNode->_mKey)
		{
			mainNode = mainNode->leftChild;
		}
		else
		{
			mainNode = mainNode->rightChild;

		}
		if (mainNode == nullptr)
		{
			return nullptr;
		}
	}
	return mainNode;
}
bool BinaryTree::Remove(int key)
{
	Node* mainNode = _mRoot;
	Node* parent = _mRoot;

	bool isItAlfeChild = true;

	while (mainNode->_mKey != key)
	{
		parent = mainNode;
		if (key < mainNode->_mKey)
		{
			isItAlfeChild = true;
			mainNode = mainNode->leftChild;
		}
		else
		{
			isItAlfeChild = false;
			mainNode = mainNode->rightChild;
		}
		if (mainNode == nullptr)
		{
			return false;
		}
	}
	if (mainNode->leftChild == nullptr && mainNode->rightChild == nullptr)
	{
		if (mainNode == _mRoot)
		{
			_mRoot = nullptr;
		}
		else if (isItAlfeChild)
		{
			parent->leftChild == nullptr;
		}
		else
		{
			parent->rightChild = nullptr;
		}
	}
	else if (mainNode->rightChild == nullptr)
	{
		if (mainNode == _mRoot)
		{
			_mRoot = mainNode->leftChild;
		}
		else if (isItAlfeChild)
		{
			parent->leftChild = mainNode->leftChild;
		}
		else
		{
			parent->rightChild = mainNode->leftChild;
		}
	}
	else if (mainNode->leftChild == nullptr)
	{
		if (mainNode==_mRoot)
		{
			_mRoot = mainNode->rightChild;
		}
		else if(isItAlfeChild)
		{
			parent->leftChild = mainNode->rightChild;
		}
		else
		{
			parent->rightChild = mainNode->rightChild;
		}
	}
	else
	{
		Node* replacement = GetReplacmentNode(mainNode);

		if (mainNode == _mRoot)
		{
			_mRoot = replacement;
		}
		else if(isItAlfeChild)
		{
			parent->leftChild = replacement;
		}
		else
		{
			parent->rightChild = replacement;
		}
		replacement->leftChild = mainNode->leftChild;
	}
	return true;
}
Node* BinaryTree::GetReplacmentNode(Node* replaceNode)
{
	Node* replacmentParent = replaceNode;
	Node* replacment = replaceNode;

	Node* mainNode = replaceNode->rightChild;

	while (mainNode != nullptr)
	{
		replacmentParent = replacment;

		replacment = mainNode;

		mainNode = mainNode->leftChild;
	}

	if (replacment !=replaceNode->rightChild)
	{
		replacmentParent->leftChild = replacment->rightChild;
		replacment->rightChild = replaceNode->rightChild;

	}
	return replacment;

}
Node::Node(int key, std::string name) :_mKey(key), _mName(name)
{
	 
}