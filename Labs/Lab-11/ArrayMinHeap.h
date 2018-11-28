#ifndef ARRAYMINHEAP_H
#define ARRAYMINHEAP_H

#include <iostream>
#include <fstream>
#include <cmath>
#include "Creature.h"
using namespace std;

string to_lower(string str ){ // return string converted to lower case
	for( char& c : str ) c = std::tolower(c) ;
		return str ;
}

class ArrayMinHeap {
	private:
		Creature* heapArray;
		size_t capacity;
		size_t heap_size;

		void swap(Creature* x, Creature* y);
		//get the parent of index i
		size_t parent(size_t i);
		//get the left child of index i
		size_t left(size_t i);
		//get the right child of index i
		size_t right(size_t i);

	public:
		ArrayMinHeap(size_t baseCapacity);
		~ArrayMinHeap();

		void minHeapify();
		void insert(Creature);
		bool remove() {
			bool isDoneDoGood = true;
			if(heap_size != 0) {
				this->heapArray[0].setName(this->heapArray[heap_size - 1].getName());
				this->heapArray[0].setDescription(this->heapArray[heap_size - 1].getDescription());
				this->heapArray[0].setDangerous(this->heapArray[heap_size - 1].getDangerous());
				this->heapArray[0].setCost(this->heapArray[heap_size - 1].getCost());
				this->heap_size = this->heap_size - 1;
			}
			else {
				isDoneDoGood = false;
			}
			return isDoneDoGood;
		}
		/*
		 minHeapify(recursive method to adjust the heap to make sure all nodes follow the min-heap rule)
		 remove(remove minimum element (or root) from min heap)
		 Note �you will need to return a Booleanfrom this function to indicate if a creature was removed (none will be removed if there are no nodes).
		 Also, you will need to return the creature removed.
		 passing the creature to be removed by reference and returning the Boolean.
		 insert(insert new creature in heap �Creature is sent to this function)
		 */

		void resizeArray();

		//saveToFile(traverses the array starting at 1stelement and calls the printCreatureToFile function sending "savedCreatures.txt"to this funct
		void saveToFile();

		//display(traverses the array starting at 1stelement and prints out the name of each creature �one per line)
		void display();

		Creature* peek();
		bool isEmpty();
		bool getNumberOfNodes();
		size_t getHeight();

		void minHeapify(int i){
			int l = 2*i + 1;
			int r = 2*i + 2; 
			int smallest = i; 
			if (l < heap_size && to_lower(this->heapArray[l].getName()) < to_lower(this->heapArray[i].getName())) 
				smallest = l; 
			if (r < heap_size && to_lower(this->heapArray[l].getName()) > to_lower(this->heapArray[i].getName()))
				smallest = r; 
			if (smallest != i){
				swap(&heapArray[i], &heapArray[smallest]); 
				minHeapify(smallest); 
			} 
		} 

};

inline void ArrayMinHeap::swap(Creature* x, Creature* y) {
	Creature* temp = x;
	x = y;
	y = temp;
}

inline size_t ArrayMinHeap::parent(size_t i) {
	return (i - 1) / 2;
}

inline size_t ArrayMinHeap::left(size_t i) {
	return (2 * i) + 1;
}

inline size_t ArrayMinHeap::right(size_t i) {
	return (2 * i) + 2;
}

inline ArrayMinHeap::ArrayMinHeap(size_t baseCapacity) {
	this->capacity = baseCapacity;
	this->heap_size = 0;
	this->heapArray = new Creature[heap_size];
}

inline ArrayMinHeap::~ArrayMinHeap() {
	this->capacity = 0;
	this->heap_size = 0;
	delete this->heapArray;
}

inline void ArrayMinHeap::resizeArray() {
	capacity = capacity * 2;
	Creature* tempArr = new Creature[capacity];
	for (size_t i = 0; i < heap_size; i++) {
		tempArr[i] = heapArray[i];
	}
	delete heapArray;
	heapArray = tempArr;
}

inline void ArrayMinHeap::saveToFile() {
	for (size_t i = 0; i < heap_size; i++) {
		heapArray[i].printCreatureToFile("savedCreatures.txt");
	}
}

inline void ArrayMinHeap::display() {
	for (size_t i = 0; i < heap_size; i++) {
		heapArray[i].printCreature();
	}
}

inline Creature* ArrayMinHeap::peek() {
	return this->heapArray[0];
}

inline bool ArrayMinHeap::isEmpty() {
	return this->heap_size == 0;
}

inline bool ArrayMinHeap::getNumberOfNodes() {
	return this->heap_size;
}

inline size_t ArrayMinHeap::getHeight() {
	return ceil(static_cast<double>(log2(this->heap_size))) + 1;
}

#endif
