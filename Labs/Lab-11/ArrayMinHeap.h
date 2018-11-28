#ifndef ARRAYMINIHEAP_H
#define ARRAYMINIHEAP_H

#include <iostream>
#include <fstream>
#include <cmath>
#include "Creature.h"
using namespace std;

class ArrayMinHeap {
	private:
		Creature* heapArray;
		size_t capacity;
		size_t heap_size;



		void swap();
	public:
		/*
		constructor(accepts an integer capacity & creates heapArray based on this capacity)
		destructor(releases heapArray memory)
		minHeapify(recursive method to adjust the heap to make sure all nodes follow the min-heap rule)
		peek(returns root creature)
		remove(remove minimum element (or root) from min heap)
			Note –you will need to return a Booleanfrom this function to indicate if a creature was removed (none will be removed if there are no nodes).
			Also, you will need to return the creature removed.
					Isuggest passing the creature to be removed by reference and returning the Boolean.
		insert(insert new creature in heap –Creature is sent to this function)
		resizeArray(make an array 2 times as big as original)
		insert(insert new creature in heap –Creature is sent to this function)
		resizeArray(make an array 2 times as big as original)
		display(traverses the array starting at 1stelement and prints out the name of each creature –one per line)
		saveToFile(traverses the array starting at 1stelement and calls the printCreatureToFile function sending "savedCreatures.txt"to this funct
	public:
		*/
		
		bool isEmpty(){
			return heap_size == 0;
		}
		bool getNumberOfNodes(){
			return heap_size;
		}
		size_t getHeight(){
			return ceil(static_cast<double>(log2(this->heap_size))) + 1;
		}

};

#endif
