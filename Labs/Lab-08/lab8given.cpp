#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;

//function prototypes for the recursive functions
int sumOfNumbers(int);
bool isMember(int*, int, int);
void stringReverser(string&, int);
bool isPalindrome(const string&, int, int);
int multiply(int, int);

const int ARRAY_SIZE = 10;

int main() {
	int choice, num, num1, num2;
	int myArray[ARRAY_SIZE];
	srand(time(NULL));
	string userString, userStrWithoutSpaces;
	
	do {
		
		cout << "\n\nWhat do you want to do?\n";
		cout << "\t1.  Sum of Numbers\n";
		cout << "\t2.  IsMember Array Function\n";
		cout << "\t3.  String Reverser\n";
		cout << "\t4.  Palindrome Detector\n";
		cout << "\t5.  Recursive Multiplication\n";
		cout << "\t6.  End the Program\n";
		cout << "CHOOSE 1-6:  ";
		cin >> choice;
		while (choice < 1 || choice > 6) {
			cout << "\nInvalid input!  CHOOSE 1-6:  ";
			cin >> choice;
		}
		switch (choice) {
			case 1:
				cout << "\n\nSUM OF NUMBERS\n";
				cout << "Enter an integer:  ";
				cin >> num;
				//print out the result of the sumOfNumbers function here
				cout << "sum of numbers:\n\t" << sumOfNumbers(num) << "\n";
				break;
				
			case 2:
				for (int x = 0; x < ARRAY_SIZE; x++) {
					myArray[x] = (rand() % 100) + 1;
				}
				cout << "\n\nISMEMBER ARRAY FUNCTION\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << "\nHere are the array values:  ";
				for (int x = 0; x < ARRAY_SIZE; x++) {
					cout << myArray[x] << " ";
				}
				//print if the value that the user entered is in the array or not here
				cout << "\nItem was " << (isMember(myArray, ARRAY_SIZE, num) ? "found" : "not found\n");
				break;
				
			case 3:
				cout << "\n\nSTRING REVERSER\n";
				cout << "Enter a string and I will reverse it:  ";
				cin.ignore();
				getline(cin, userString);
				//call string reverser function here
				cout << "\n";
				stringReverser(userString, userString.length());
				cout << "\n";
				break;
				
			case 4:
				cout << "\n\nPALINDROME DETECTOR\n";
				cout << "Enter a string and I will tell you if it is a palindrome:  ";
				cin.ignore();
				getline(cin, userString);
				
				//change string to be all uppercase
				for (int x = 0; x < userString.length(); x++) {
					userString[x] = toupper(userString[x]);
				}
				
				//remove spaces from string
				userStrWithoutSpaces = userString;
				for (int x = 0; x < userStrWithoutSpaces.size(); x++) {
					if(userStrWithoutSpaces[x] == ' ')
						userStrWithoutSpaces.erase(x, 1);
				}
				
				//print out whether the user's string is a palindrome or not here.
				//when you print out the user's string, print out the uppercase version that doesn't have the spaces removed.
				cout << "String (" << userString << ") is " << (isPalindrome(userString, 0, userString.length() - 1) ? "a palindrome" : "not a palindrome") << "\n";
				break;
				
			case 5:
				cout << "\n\nRECURSIVE MULTIPLICATION\n";
				cout << "Enter in the first integer:  ";
				cin >> num1;
				cout << "\nEnter in the second integer:  ";
				cin >> num2;
				//print out the value returned from the multiply function here

				cout << "Multiplication of the numbers:\n\t" << multiply(num1, num2) << "\n";
				break;
				
		}
	}while (choice != 6);
	
	cout << "\n\nGOODBYE!\n\n";
	return 0;
}

//implement the five recursive functions below!!!!

int sumOfNumbers(int input) {
	return (input == 0 ? 0 : input + sumOfNumbers(input - 1));
}
bool isMember(int* arr, int size, int key) {
	return (arr[size - 1] == key ? true : (size == 0 ? false : isMember(arr, size - 1, key)));
}
void stringReverser(string &s, int n) {
	if(n >= 1) {
		cout << s.at(n - 1);
		stringReverser(s, n - 1);
	}
}
bool isPalindrome(const string &str, int start, int end) {
	return (start >= end ? true : (str.at(start) != str.at(end) ? false : isPalindrome(str, ++start, --end)));
}
int multiply(int numberAddMe, int numberCounter) {
	return (numberCounter == 0 ? 0 : multiply(numberAddMe, numberCounter - 1) + numberAddMe);
}
