/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	Title:		CSC1310 - Lab 05/06 - Linked List class
 *	Author(s):	Rus Hoffman
 *	Date:		September 4, 2018
 *	Purpose:		Practice working with classes which include member classes
 *
 * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef MOVIE_H
#define MOVIE_H

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
A structure (struct) ADT named ListNode, which defines a node with a value & a pointer to the next ListNode.
 A pointer to a ListNode named head
 A pointer to a ListNode named tail
 An integer named numNodes
LinkedList class should have the following member functions:
 Constructor – should initialize head & tail to point to nothing and initialize numNodes to zero
 Destructor – like a “RemoveAll” function – should deallocate memory for all existing nodes
 getLength – should return the number of nodes in the list
 getNodeValue – this function accepts a position (integer) as a parameter and then returns the value (object) inside the
node at that position
 appendNode – this function accepts a value (object) as a parameter. It creates a new node at the end of the list with the
sent object inside of it and increments the number of nodes. This function does not return anything.
 deleteNode – this function accepts a position (integer) as a parameter, which indicates the position of the node to be
deleted. It updates the links of the nodes on either side of this node to be deleted. Then it deletes the node. Then, it
decrements the number of nodes.


*/
class LinkedList {
	private:
		//Variables:


	public:
		//Default Constructor
		LinkedList ();

		//Destructor
		~LinkedList ();

		/*
		 Function name:	printMovieDetailsToFileNoFlushing
		 Parameters:		a file stream object (sent by reference)
		 Returns: 		nothing (void)
		 Purpose:  		This function should be called when the program needs to print ALL the movie information to a file without flushing the buffer automatically. Does not modify stream settings at all
		 */
		void printMovieDetailsToFileNoFlushing (ofstream& outFile);

};

#endif //end MOVIE_H define
