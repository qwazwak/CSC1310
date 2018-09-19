ArrayHelper::ArrayHelper (T* inputArray, long numElements){
	arrayPtr = new T[numElements];
	for (long i = 0; i < numElements; i++) {
		arrayPtr[i] = inputArray[i];
	}
}

//Destructor
ArrayHelper::~ArrayHelper () {
	for (long i = 0; i < numElements; i++) {
		arrayPtr[i] = 0;
	}
	delete[] arrayPtr;
	numElements = 0;
}

/*
 Function name:	getMax
 Parameters:	nothing (void)
 Returns:		the index of the largest value in array (T)
 */
T ArrayHelper::getMax(){
	T cMax = arrayPtr[0];
	for (long i = 0; i < numElements; i++) {
		if(arrayPtr[i] > cMax)
			cMax = arrayPtr[i];
	}

}

/*
 Function name:	getMin
 Parameters:	nothing (void)
 Returns:		the index of the smallest value in array (T)
 */
T ArrayHelper::ArrayHelper::getMin(){
	T cMax = arrayPtr[0];
	for (long i = 0; i < numElements; i++) {
		if(arrayPtr[i] < cMax)
			cMax = arrayPtr[i];
	}

}

/*
 Function name:	getTotal
 Parameters:	nothing (void)
 Returns:		the total of all values in the array (T)
 */
T ArrayHelper::getTotal(){
	T net = 0;
	for (long i = 0; i < numElements; i++) {
		net += arrayPtr[i];
	}
}

/*
 Function name:	getAvg
 Parameters:	nothing (void)
 Returns:		the average value of elements in the array (double)
 */
double ArrayHelper::getAvg(){
	return static_cast<double>(this->getTotal) / static_cast<double>(numElements);
}
