/*********************************************************************************
 *     Title:   BinaryTree.h                                                     *
 *     Author:  Rus Hoffman                                                      *
 *     Date:    March 29, 2018                                                   *
 *     Purpose: This is the specification file for the BinaryTree class, which   *
 *              is an implementation of a Binary Search Tree.  Each Tree Node    *
 *              stores a customer name (string) and the number of Krabby Patties *
 *              the customer ate.                                                *
 *********************************************************************************/
#if !defined(BINARYTREE_H)
#define BINARYTREE_H

#include <iostream>
#include <string>
#include <string.h>
#include <utility>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//Left is <
//right is >=
template<class tvar>
class BTNode {
	private:
		tvar* data;
		BTNode* leftNode;
		BTNode* rightNode;

		/*		void updateHash() {
		 std::hash<string> hash_fn;
		 string tempString(ID);
		 this->hash = hash_fn(name + tempString);
		 }
		 */
	public:

		BTNode () {
			this->data = nullptr;
			this->leftNode = nullptr;
			this->rightNode = nullptr;
			//			this->hash = NULL;
		}
		BTNode (tvar member) {
			this->data = member;
//			updateHash();
			this->leftNode = NULL;
			this->rightNode = NULL;
		}
		~BTNode () {
			delete this->leftNode;
			delete this->rightNode;
			delete this->data;
			this->data = nullptr;
			this->data = leftNode;
			this->data = rightNode;
		}
		tvar* getVal () {
			return this->data;
		}
		bool hasChild () {
			return !this->empty();
		}
		bool hasChildLeft () {
			return this->leftNode != nullptr;
		}
		bool hasChildRight () {
			return this->rightNode != nullptr;
		}
		bool empty () {
			return this->isEmpty();
		}
		bool isEmpty () {
			return this->leftNode == nullptr && this->leftNode == nullptr;
		}
		BTNode* getSmallSide () {
			return this->leftNode;
		}
		BTNode* getLargeSide () {
			return this->rightNode;
		}
		//Left is <
		//right is >=
		void smartInsert (BTNode* insertMe) {
			if(insertMe->getVal() >= this->data) {
				if(this->rightNode == nullptr) {
					rightNode = insertMe;
				}
				else {
					this->rightNode->smartInsert(insertMe);
				}
			}
			else {
				if(this->leftNode == nullptr) {
					leftNode = insertMe;
				}
				else {
					this->leftNode->smartInsert(insertMe);
				}
			}
		}
		size_t getNumberNodes () {
			return 1 + this->getNodesBelow();
		}

		size_t getNodesBelow () {
			return (leftNode == nullptr ? 0 : this->leftNode->getNumberNodes()) + (rightNode == nullptr ? 0 : this->rightNode->getNumberNodes());
		}
};

template<class tvar>
class BinaryTree {
	private:
		BTNode<tvar>* rootNode;
		//		size_t treeSize;

		void addNodeSingle (BTNode<tvar>* insertMe) {
			this->rootNode->smartInsert(insertMe);
//			this->treeSize++;
		}
	public:
		BinaryTree () {
			this->rootNode = new BTNode<tvar>;
//			this->treeSize = 1;
		}
		BinaryTree (BTNode<tvar>* defaultTree) {
			this->rootNode = defaultTree;
//			this->treeSize = defaultTree->getNumberNodes();
		}

		void addNode (BTNode<tvar>* insertMe) {

			if(insertMe->hasChildRight()) {
				this->addNode(insertMe->getLargeSide());
			}
			if(insertMe->hasChildLeft()) {
				this->addNode(insertMe->getSmallSide());
			}
		}

		void removeNode () {

//			this->treeSize++;
		}

};

#endif
