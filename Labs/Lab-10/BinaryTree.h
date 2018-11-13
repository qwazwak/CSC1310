/*
 *	Title:		BinaryTree.h
 *	Author:		Rus Hoffman
 *	Date:		November 13, 2018
 *	Purpose:		usable implementation of a binary tree
 */
#if !defined(BINARYTREE_H)
#define BINARYTREE_H

#include <iostream>
#include <string>
#include <utility>
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

template<class tvar>
class BinaryTree {
	private:
		tvar* data;
		BinaryTree<tvar>* rightNode;
		BinaryTree<tvar>* leftNode;

	public:
		BinaryTree (tvar* inputData) {
			this->data = inputData;
			this->rightNode = nullptr;
			this->leftNode = nullptr;
		}
		BinaryTree (BinaryTree<tvar>* defaultTree)
				{
			this->data = defaultTree->getData();
			this->leftNode = defaultTree->getLeft();
			this->rightNode = defaultTree->getRight();
		}
		
		~BinaryTree ()
		{
			delete this->leftNode;
			delete this->rightNode;
			delete this->data;
			this->leftNode = nullptr;
			this->rightNode = nullptr;
			this->data = nullptr;
		}
		
		tvar* getData ();
		void setData (tvar* input);
		BinaryTree* getLeft ();
		BinaryTree* getRight ();
		void setLeft (BinaryTree* nodeToAdd);
		void setRight (BinaryTree* nodeToAdd);
		void clearLeft ();
		void clearRight ();
		void addNode (BinaryTree<tvar>* insertMe) {
			if(insertMe->getLeft() != nullptr) {
				this->addNode(insertMe->getLeft());
				insertMe->clearLeft();
			}
			if(insertMe->getRight() != nullptr) {
				this->addNode(insertMe->getRight());
				insertMe->clearRight();
			}
			if(insertMe->getData() >= this->getData()) {
				if(this->rightNode == nullptr) {
					this->rightNode = insertMe;
				}
				else {
					this->rightNode->addNode(insertMe);
				}
			}
			else {
				if(this->leftNode == nullptr) {
					this->leftNode = insertMe;
				}
				else {
					this->leftNode->addNode(insertMe);
				}
			}
		}
		void createAddNode (tvar* input)
				{
			this->addNode(new BinaryTree(input));
		}
		void streamOutInorder ();
		void streamOutPreorder ();
		void streamOutPostorder ();
		
};

template<class tvar>
inline tvar* BinaryTree<tvar>::getData ()
{
	return this->data;
}

template<class tvar>
inline void BinaryTree<tvar>::setData (tvar* input)
		{
	this->data = input;
}

template<class tvar>
inline BinaryTree<tvar>* BinaryTree<tvar>::getLeft () {
	return this->leftNode;
}

template<class tvar>
inline void BinaryTree<tvar>::clearLeft () {
	this->leftNode = nullptr;
}

template<class tvar>
inline void BinaryTree<tvar>::setLeft (BinaryTree* nodeToAdd) {
	if(this->leftNode != nullptr) {
		cerr << "OVERWRITING AND LEAKING DATA " << endl;
		delete this->leftNode;
	}
	this->leftNode = nodeToAdd;
}

template<class tvar>
inline BinaryTree<tvar>* BinaryTree<tvar>::getRight () {
	return this->rightNode;
}

template<class tvar>
inline void BinaryTree<tvar>::clearRight () {
	this->rightNode = nullptr;
}

template<class tvar>
inline void BinaryTree<tvar>::setRight (BinaryTree* nodeToAdd) {
	if(this->rightNode != nullptr) {
		cerr << "OVERWRITING AND LEAKING DATA " << endl;
		delete this->rightNode;
	}
	this->rightNode = nodeToAdd;
}

template<class tvar>
inline void BinaryTree<tvar>::streamOutInorder () {
	if(this->leftNode != nullptr) {
		this->leftNode->streamOutInorder();
	}
	cout << this->data;
	cout << "\n";
	if(this->rightNode != nullptr) {
		this->rightNode->streamOutInorder();
	}
}
template<class tvar>
inline void BinaryTree<tvar>::streamOutPreorder () {
	cout << this->data;
	cout << "\n";
	if(this->leftNode != nullptr) {
		this->leftNode->streamOutPreorder();
	}
	if(this->rightNode != nullptr) {
		this->rightNode->streamOutPreorder();
	}
}
template<class tvar>
inline void BinaryTree<tvar>::streamOutPostorder () {
	if(this->leftNode != nullptr) {
		this->leftNode->streamOutPostorder();
	}
	if(this->rightNode != nullptr) {
		this->rightNode->streamOutPostorder();
	}
	cout << this->data;
	cout << "\n";
}

#endif
