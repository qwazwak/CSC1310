#ifndef DOGHEALTH_H
#define DOGHEALTH_H

#include <iostream>
#include <iomanip>
#include "ArrayHelper.h"
using namespace std;

const int MONTHS = 12;

class DogHealth
{
	private:
		string name;
		int age;
		float weight[MONTHS];
		int heartRate[MONTHS];
	
	public:
		/*
			DogHealth 	Constructor
			Purpose:  	ask the user for the name, age, and all the data for the two arrays and enter in the
						information in to the attributes.
		*/
		DogHealth();
		
		/*
			printDogHealth()
			Parameters: 	none
			Returns: 		none
			Purpose:  		prints out all the information in the attributes
		*/
		void printDogHealth();
		
		/*
			printWeightStatistics()
			Parameters: 	none
			Returns: 		none
			Purpose:  		Creates a dynamically allocated ArrayHelper object sending the weight array & 
							number of elements in the array to this object.  Should then call the getMax, getMin, 
							and getAvg functions of the ArrayHelper object in order to print:
								o	month that the dog had the highest weight and the weight amount
								o	month that the dog had the lowest weight and the weight amount
								o	the average weight of all the months
		*/
		void printWeightStatistics();
		
		/*
			printHeartRateStatistics()
			Parameters: 	none
			Returns: 		none
			Purpose:  		Creates a dynamically allocated ArrayHelper object sending the heartrate array & 
							number of elements in the array to this object.  Should then call the getMax, 
							getMin, and getAvg functions of the ArrayHelper object in order to print:
								o	month that the dog had the highest resting heart rate and the resting heart rate amount
								o	month that the dog had the lowest resting heart rate and the resting heart rate amount
								o	the average resting heart rate of all the months
		*/
		void printHeartRateStatistics();
};

#endif
