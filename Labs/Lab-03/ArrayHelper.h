/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	Title:		CSC1310 - Program 01 - Single Movie Encapsulation class
 *	Author(s):	Rus Hoffman
 *	Date:		September 4, 2018
 *	Purpose:		Practice working with classes which include member classes
 *
 * * * * * * * * * * * * * * * * * * * * * * * */
#if !defined(ARRAYHELPER_H)
#define ARRAYHELPER_H

using namespace std;

template <class T> class ArrayHelper {
	private:
		//Variables:
		T* arrayPtr;
		long numElements;
	public:
		ArrayHelper (T* inputArray, long numElements);

		//Destructor
		~ArrayHelper () ;

		/*
		 Function name:	getMax
		 Parameters:	nothing (void)
		 Returns:		the index of the largest value in array (T)
		 */
		T getMax();

		/*
		 Function name:	getMin
		 Parameters:	nothing (void)
		 Returns:		the index of the smallest value in array (T)
		 */
		T getMin();

		/*
		 Function name:	getTotal
		 Parameters:	nothing (void)
		 Returns:		the total of all values in the array (T)
		 */
		T getTotal();

		/*
		 Function name:	getAvg
		 Parameters:	nothing (void)
		 Returns:		the average value of elements in the array (double)
		 */
		double getAvg(){
			return static_cast<double>(this->getTotal) / static_cast<double>(numElements);
		}
};

//#include "arrayHelper.cpp"

#endif
