/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	Title:	CSC1310 - Lab 05/06 - Linked List class
 *	Authors:	Braedin Jared & Rus Hoffman
 *	Date:	October 3, 2018
 *	Purpose:	Make a templated linked list class
 *
 * * * * * * * * * * * * * * * * * * * * * * * */

#if !defined(LINKED_LIST_H)
#define LINKED_LIST_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

template<class T>
class LinkedList {
	private:
		//Variables:
		struct node {
				node *next;
				T value;
		};

		node *head;
		node *tail;
		int numNodes;

	public:
		//Default Constructor
		LinkedList () {
			head = NULL;
			tail = NULL;
			numNodes = 0;
		}

		//Destructor
		~LinkedList () {
			node *n = head;
			while (n->next) {
				node* c = n->next;
				delete n;
				n = c;
			}
			delete tail;
		}

		/*
		 * Parameters:	none (void)
		 * Returns:	the number of nodes in the linked list (int)
		 */
		int getLength () {
			return numNodes;
		}

		/*
		 * Parameters:	the node's index (int)
		 * Returns:	the data in the node (T)
		 * Purpose:	access a nodes data
		 */
		T getNodeValue (int index) {
			node *n = head;

			for (int i = 0; i <= index; i++) {
				n = n->next;
			}
			return n->value;
		}

		/*
		 * Parameters:	new data to append (T)
		 * Returns:	none (void)
		 * Purpose:	add a new node at the end of the list
		 */
		void appendNode (T value) {

			node *temp = new node;
			temp->value = value;
			temp->next = NULL;
			if(head == NULL) {
				head = temp;
				tail = temp;
				temp = NULL;
			}
			else {
				tail->next = temp;
				tail = temp;
			}
		}

		/*
		 * Parameters:	a node's index (int)
		 * Returns:	none (void)
		 * Purpose:	remove a node
		 */
		void deleteNode (int index) {
			node *current = new node;
			node *previous = new node;
			current = head;
			for (int i = 1; i < index; i++) {
				previous = current;
				current = current->next;
			}
			previous->next = current->next;
		}
};

#endif //end LINKEDLIST_H define
