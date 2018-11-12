/* Title:  Lab 09
 * Author:  Rus Hoffman and Braedin Jared
 * Date:  November 11th, 2018
 */
#include "Random.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

void sortArray(size_t* arr, size_t arraySize) {

	int i, j;
	for (i = 0; i < arraySize - 1; i++){

		// Last i elements are already in place
		for (j = 0; j < arraySize - i - 1; j++){
			if (arr[j] > arr[j + 1]){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

bool binarySearchArray(size_t* arr, size_t key, size_t first, size_t last) {

	if(first > last) {   //value was not found
		return false;
	}

	size_t middle = (first + last) / 2;

	if(arr[middle] == key) {
		return true;
	}

	if(arr[middle] < key) {
		//value not found yet and it is to the right of the middle
		return binarySearchArray(arr, key, middle + 1, last);
	}
	else {
		//value not found yet and it is to the left of the middle
		return binarySearchArray(arr, key, first, middle - 1);
	}
}

bool isInArray(size_t* arr, size_t size, size_t key) {
	sortArray(arr, size);
	return binarySearchArray(arr, key, 0, size - 1);
}

int main() {
	srand(time(NULL));
	string userInput[5];
	size_t usersNumbers[5];
	int winningNumber;
	winningNumber = 0;
	winningNumber += (rand() % 10);
	winningNumber += 10 * (rand() % 10);
	winningNumber += 100 * (rand() % 10);
	winningNumber += 1000 * (rand() % 10);
	winningNumber += 10000 * (rand() % 10);

	cout << "Mrs. Crockett, enter in your lucky numbers!" << "\n" << endl;
	for (size_t i = 0; i < 5; i++) {
		cout << i + 1 << ".  ";
		getline(cin, userInput[i]);
		while (cin.fail() || userInput[i].length() != 5 || !isdigit(userInput[i].at(0)) || !isdigit(userInput[i].at(1)) || !isdigit(userInput[i].at(2)) || !isdigit(userInput[i].at(3)) || !isdigit(userInput[i].at(4))) {
			if(cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "Error, try again" << endl;
			}
			else {
				cout << "Be sure to enter a 5 digit (including zeros) number" << endl;
			}
			cout << i + 1 << ".  ";
			getline(cin, userInput[i]);
		}
	}
	for (size_t i = 0; i < 5; i++) {
		usersNumbers[i] = stoi(userInput[i]);
	}
	if(isInArray(usersNumbers, 5, winningNumber)) {
		string winnerString =   " ____                      _       _                                " "\n"
								"(  _ \\  _                 ( )  __ ( ) _                             " "\n"
								"| (_) )(_)  ____          | | (  ) | |(_) _____  _____   ____  ____ " "\n"
								"|  _ < | | / _  \\         | | |  | | || |/  _  \\/  _  \\ / __ \\(  __)" "\n"
								"| (_) )| |( (_) |         | (_/  \\_) || || ( ) || ( ) |(  ___/| |   " "\n"
								"(____/ (_) \\__  |          \\__|/\\___/ (_)(_) (_)(_) (_) \\____)(_)    " "\n"
								"          ( )_) |                                                   " "\n"
								"            \\___/                                                   " "\n";
		
		
		cout << winnerString << endl;
	}
	else {
		cout << "you lost" << endl;
	}
	return 0;
}
