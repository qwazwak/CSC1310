/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	Title:		CSC1310 - Lab 05/06 - Linked List class
 *	Author(s):	Rus Hoffman & Braedin Jared
 *	Date:		October 3, 2018
 *	Purpose:	Make a list
 *
 * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#if !defined(CLEARSCREEN_SIZE)
#define CLEARSCREEN_SIZE 100
#endif

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

template <class tVar>
struct ListNode {
	tVar data;
	ListNode* next;
};
/*
♥ A structure (struct) ADT named ListNode, which defines a node with a value & a pointer to the next ListNode.
♥  A pointer to a ListNode named head
♥  A pointer to a ListNode named tail
♥  An integer named numNodes
LinkedList class should have the following member functions:
♥  Constructor – should initialize head & tail to point to nothing and initialize numNodes to zero
♥  Destructor – like a “RemoveAll” function – should deallocate memory for all existing nodes
♥  getLength – should return the number of nodes in the list
♥  getNodeValue – this function accepts a position (integer) as a parameter and then returns the value (object) inside the
  node at that position
♥  appendNode – this function accepts a value (object) as a parameter. It creates a new node at the end of the list with the
sent object inside of it and increments the number of nodes. This function does not return anything.
♥  deleteNode – this function accepts a position (integer) as a parameter, which indicates the position of the node to be
deleted. It updates the links of the nodes on either side of this node to be deleted. Then it deletes the node. Then, it
decrements the number of nodes.


*/


template <class T>
class LinkedList {
	private:
		//Variables:
		struct node = {
			node *next;
			T value;
		};

		node *head;
		node *tail;
		int numNodes;

	public:
		//Default Constructor
		LinkedList (){
			head = NULL;
			tail = NULL;
			numNodes = 0;
		}

		//Destructor
		~LinkedList (){
			node *n = head;
			while(n->next){
				node* c = n->next;
				delete n;
				n = c;
			}
			delete tail;
		}

		//returns length of linkedlist
		int getLength(){
			return numNodes;
		}

		//get a value
		T getNodeValue(int index){
			node *n = head;

			for(int i = 0; i <= index; i++){
				n = n->next;
			}
			return n;
		}

		//add a value
		void appendNode(T value){

			node *temp=new node;
			temp->data=value;
			temp->next=NULL;
			if(head==NULL){
				head=temp;
				tail=temp;
				temp=NULL;
			}
			else{
				tail->next=temp;
				tail=temp;
			}
		}

		//remove a value
		void deleteNode(int index){
			node *current= new node;
			node *previous= new node;
			current=head;
			for(int i=1;i<index;i++){
				previous=current;
				current=current->next;
			}
			previous->next=current->next;
		}
};

#endif //end LINKEDLIST_H define
