/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	Title:	CSC1310 - Lab 03 - ArrayHelper Container
 *	Author(s):	Rus Hoffman and Braedin Jared
 *	Date:		September 19, 2018
 *	Purpose:	provide helpful functions working with arrays
 *
 * * * * * * * * * * * * * * * * * * * * * * * */

#if !defined(ARRAYHELPER_CPP)
#define ARRAYHELPER_CPP

template <typename T> ArrayHelper<T>::ArrayHelper (T* inputArray, long newNumElements){
	numElements = newNumElements;
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

template <class T> long ArrayHelper<T>::getMax(){
	long ID = 0;
	for (long i = 0; i < numElements; i++) {
		if(arrayPtr[i] > arrayPtr[ID]){
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
template <class T> long ArrayHelper<T>::getMin(){
	long ID = 0;
	for (long i = 0; i < numElements; i++) {
		if(arrayPtr[i] < arrayPtr[ID]){
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
template <class T> T ArrayHelper<T>::getTotal(){
	T net = 0;
	for (long i = 0; i < numElements; i++) {
		net = net + arrayPtr[i];
	}
	return net;
}

/*
 Function name:	getAvg
 Parameters:	nothing (void)
 Returns:		the average value of elements in the array (double)
 */
template <class T> float ArrayHelper<T>::getAvg(){
	float number = static_cast<float>(this->getTotal());
	float theReturnValue = number / static_cast<float>(numElements);
	return theReturnValue;
}


#endif
