/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	Title:	CSC1310 - Lab 05/06 - Creature Class
 *	Authors:	Rus Hoffman and Braedin Jared
 *	Date:	October 4, 2018
 *	Purpose:	memebigboy
 *
 * * * * * * * * * * * * * * * * * * * * * * * */

#include "LinkedList.h"
#include "Creature.h"
#include <iostream>
#include <limits>
#include <iomanip>
#include <string>

using namespace std;

int main () {
	const string STANDARDFILEEXTENTION = ".txt";
	long menuChoice;
	const long INITMAXMOVIE = 1;
	string filename;

	do {
		cin.clear();
		cout << "\n" << "\n" << "\n";
		cout << "What would you like to do?" << "\n";
		cout << "1.  Read movies from file" << "\n";
		cout << "2.  Save movies to a file" << "\n";
		cout << "3.  Add a movie" << "\n";
		cout << "4.  Delete a movie" << "\n";
		cout << "5.  Edit a movie" << "\n";
		cout << "6.  Print all movies" << "\n";
		cout << "7.  Delete ALL movies and end the program" << "\n";

		cout << "CHOOSE 1-7:  " << flush;
		cin >> menuChoice;
		while (cin.fail() || menuChoice < 1 || menuChoice > 7) {
			if(cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "an error has occurred, try again" << "\n";
			}
			else {
				if(menuChoice < 1 || menuChoice > 7) {
					cout << "only enter a number between 1 and 7, inclusive" << "\n";
				}
			}
			cout << "CHOOSE 1-7:  " << flush;
			cin >> menuChoice;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\n";

		switch (menuChoice) {
			case 1:

				break;
			default:
				break;

		}

	} while (menuChoice != 7);
#if defined(DEBUG_LOGGING)
	cout << "\n" << "END PROGRAM" << "\n" << flush;
#endif
	return 0;
}
