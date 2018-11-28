#ifndef ARRAYMINHEAP_H
#define ARRAYMINHEAP_H

#include <iostream>
#include <fstream>
#include <cmath>
#include "Creature.h"
using namespace std;

string to_lower(string str) {   // return string converted to lower case
	for (char& c : str)
		c = std::tolower(c);
	return str;
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
		void minHeapify(int i = 0);

		void insert(Creature);
		bool remove();
		void resizeArray();

		void saveToFile();
		void display();

		Creature peek();
		bool isEmpty();
		bool getNumberOfNodes();
		size_t getHeight();


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

inline bool ArrayMinHeap::remove() {
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

inline Creature ArrayMinHeap::peek() {
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

inline void ArrayMinHeap::insert(Creature creature){
	if(this->heap_size >= this->capacity){
		this->resizeArray();
	}
	this->heapArray[this->heap_size++] = creature;
}

inline void ArrayMinHeap::minHeapify(int i) {
	int l = this->left(i);
	int r = 2 * i + 2;
	int smallest = i;
	if(l < heap_size && to_lower(this->heapArray[l].getName()) < to_lower(this->heapArray[i].getName()))
		smallest = l;
	
	if(r < heap_size && to_lower(this->heapArray[l].getName()) > to_lower(this->heapArray[i].getName()))
		smallest = r;
	
	if(smallest != i) {
		swap(&heapArray[i], &heapArray[smallest]);
		minHeapify(smallest);
	}
}

#endif
