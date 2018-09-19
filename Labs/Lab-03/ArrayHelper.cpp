#if !defined(ARRAYHELPER_CPP)
#define ARRAYHELPER_CPP

template <typename T> ArrayHelper<T>::ArrayHelper (T* inputArray, long numElements){
	arrayPtr = new T[numElements];
	for (long i = 0; i < numElements; i++) {
		arrayPtr[i] = inputArray[i];
	}
}

//Destructor
template <typename T> ArrayHelper<T>::~ArrayHelper () {
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

template <class T> T ArrayHelper<T>::getMax(){
	T cMax = arrayPtr[0];
	long ID = 0;
	for (long i = 0; i < numElements; i++) {
		if(arrayPtr[i] > cMax){
			cMax = arrayPtr[i];
			ID = i;
		}
	}
	return ID;
}

/*
 Function name:	getMin
 Parameters:	nothing (void)
 Returns:		the index of the smallest value in array (T)
 */
template <class T> long ArrayHelper::getMin(){
	T cMax = arrayPtr[0];
	long ID = 0;
	for (long i = 0; i < numElements; i++) {
		if(arrayPtr[i] < cMax){
			cMax = arrayPtr[i];
			ID = i;
		}
	}
	return ID;
}

/*
 Function name:	getTotal
 Parameters:	nothing (void)
 Returns:		the total of all values in the array (T)
 */
template <class T> long ArrayHelper::getTotal(){
	T net = 0;
	for (long i = 0; i < numElements; i++) {
		net += arrayPtr[i];
	}
	return net;
}

/*
 Function name:	getAvg
 Parameters:	nothing (void)
 Returns:		the average value of elements in the array (double)
 */
template <class T> float ArrayHelper<T>::getAvg(){
	T number = this->getTotal;
	return static_cast<float>(number) / static_cast<float>(numElements);
}

#endif
