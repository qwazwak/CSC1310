/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	Title:	CSC1310 - Lab 03 - ArrayHelper Container
 *	Author(s):	Rus Hoffman and Braedin Jared
 *	Date:		September 19, 2018
 *	Purpose:	provide helpful functions working with arrays
 *
 * * * * * * * * * * * * * * * * * * * * * * * */
#if !defined(ARRAYHELPER_H)
#define ARRAYHELPER_H
#include <iostream>
using namespace std;

template <class T>
class ArrayHelper {
	private:
		//Variables:
		T* arrayPtr;
		long numElements;
	public:
		ArrayHelper (T* inputArray, long newNumElements);

		//Destructor
		~ArrayHelper ();

		/*
		 Function name:	getMax
		 Parameters:	nothing (void)
		 Returns:		the index of the largest value in array (long)
		 */
		long getMax();

		/*
		 Function name:	getMin
		 Parameters:	nothing (void)
		 Returns:		the index of the smallest value in array (long)
		 */
		long getMin();

		/*
		 Function name:	getTotal
		 Parameters:	nothing (void)
		 Returns:		the total of all values in the array (T)
		 */
		T getTotal();

		/*
		 Function name:	getAvg
		 Parameters:	nothing (void)
		 Returns:		the average value of elements in the array (float)
		 */
		float getAvg();
};

#include "ArrayHelper.cpp"
#endif
