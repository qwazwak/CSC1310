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
#include <cstring>
#include <algorithm>

using namespace std;

bool has_suffix (const string &str, const string &suffix) {
	return str.size() >= suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

void enterMagicalCreature (LinkedList<Creature>* listToAddTo) {
	bool shouldRepeat;
	int shouldRepeatSemiBuffer;
	string shouldRepeatBuffer;
	const int numYesSyn = 3;
	const int numNoSyn = 3;
	const string yesSyn[numYesSyn] = {"yes", "true", "y"};
	const string noSyn[numNoSyn] = {"no", "false", "n"};
	string nameBuffer;
	string descBuffer;
	double upkeepBuffer;
	string dangerBuffer;
	int isDangerSemiBuffer;
	bool isDangerConverted;
	do {
		cout << "Enter creature name: " << flush;
		getline(cin, nameBuffer);
		cout << "Enter creature description: " << flush;
		getline(cin, descBuffer);
		cout << "Enter monthly upkeep cost: " << flush;
		cin >> upkeepBuffer;
		while (cin.fail() || upkeepBuffer < 0) {
			if(cin.fail()) {
				cout << "invalid input - be sure to enter only a number" << "\n";
				cin.clear();
				cin.ignore();
			}
			else if(upkeepBuffer < 0) {
				cout << "invalid input - only enter a number greater than or equal to zero" << "\n";
			}
			cout << "Enter monthly upkeep cost: " << flush;
			cin >> upkeepBuffer;
		}

		cout << "Is the creature dangerous: " << flush;
		getline(cin, dangerBuffer);
		transform(dangerBuffer.begin(), dangerBuffer.end(), dangerBuffer.begin(), ::tolower);
		isDangerSemiBuffer = (dangerBuffer.compare(yesSyn[0]) == 0 || dangerBuffer.compare(yesSyn[1]) == 0 || dangerBuffer.compare(yesSyn[2]) == 0) ? 1 : -1;
		isDangerSemiBuffer = (dangerBuffer.compare(noSyn[0]) == 0 || dangerBuffer.compare(noSyn[1]) == 0 || dangerBuffer.compare(noSyn[2]) == 0) ? 0 : -1;
		while (isDangerSemiBuffer == -1) {
			cout << "invalid input, be sure to only enter one of the displayed options" << "\n";
			cout << "Options: ";
			for (size_t i = 0; i < numYesSyn; i++) {
				cout << noSyn[i] << ", ";
			}
			for (size_t i = 0; i < numNoSyn; i++) {
				cout << (i + 1 < numNoSyn) ? (noSyn[i] + ", ") : (noSyn[i]);
			}
			cout << "Is the creature dangerous: " << flush;
			getline(cin, dangerBuffer);
			transform(dangerBuffer.begin(), dangerBuffer.end(), dangerBuffer.begin(), ::tolower);
			isDangerSemiBuffer = (dangerBuffer.compare(yesSyn[0]) == 0 || dangerBuffer.compare(yesSyn[1]) == 0 || dangerBuffer.compare(yesSyn[2]) == 0) ? 1 : -1;
			isDangerSemiBuffer = (dangerBuffer.compare(noSyn[0]) == 0 || dangerBuffer.compare(noSyn[1]) == 0 || dangerBuffer.compare(noSyn[2]) == 0) ? 0 : -1;
		}
		isDangerConverted = isDangerSemiBuffer == 0 ? false : true;
		listToAddTo->appendNode(Creature(nameBuffer, descBuffer, upkeepBuffer, isDangerConverted));

		cout << "CREATURE ADDED:" << "\n";
		cout << "Name:" << "\n";
		cout << "\t" << "INFO" << "\n";
		cout << "Description:" << "\n";
		cout << "\t" << "INFO" << "\n";
		cout << "Monthly upkeep:" << "\n";
		cout << "\t" << "INFO" << "\n";
		cout << "Is it dangerous:" << "\n";
		cout << "\t" << (isDangerConverted ? "Yes" : "No") << "\n";
		cout << "\n" << flush;

		cout << "Do you want to enter more creatures?";
		getline(cin, shouldRepeatBuffer);
		transform(shouldRepeatBuffer.begin(), shouldRepeatBuffer.end(), shouldRepeatBuffer.begin(), ::tolower);
		shouldRepeatSemiBuffer = (shouldRepeatBuffer.compare(yesSyn[0]) == 0 || shouldRepeatBuffer.compare(yesSyn[1]) == 0 || shouldRepeatBuffer.compare(yesSyn[2]) == 0) ? 1 : -1;
		shouldRepeatSemiBuffer = (shouldRepeatBuffer.compare(noSyn[0]) == 0 || shouldRepeatBuffer.compare(noSyn[1]) == 0 || shouldRepeatBuffer.compare(noSyn[2]) == 0) ? 0 : -1;
		while (shouldRepeatSemiBuffer == -1 || cin.fail()) {
			cout << "invalid input, be sure to only enter one of the displayed options" << "\n";
			cout << "Options: ";
			for (size_t i = 0; i < numYesSyn; i++) {
				cout << noSyn[i] << ", ";
			}
			for (size_t i = 0; i < numNoSyn; i++) {
				cout << (i + 1 < numNoSyn) ? (noSyn[i] + ", ") : (noSyn[i]);
			}
			cout << "Do you want to enter more creatures?";
			getline(cin, shouldRepeatBuffer);
			transform(shouldRepeatBuffer.begin(), shouldRepeatBuffer.end(), shouldRepeatBuffer.begin(), ::tolower);
			shouldRepeatSemiBuffer = (shouldRepeatBuffer.compare(yesSyn[0]) == 0 || shouldRepeatBuffer.compare(yesSyn[1]) == 0 || shouldRepeatBuffer.compare(yesSyn[2]) == 0) ? 1 : -1;
			shouldRepeatSemiBuffer = (shouldRepeatBuffer.compare(noSyn[0]) == 0 || shouldRepeatBuffer.compare(noSyn[1]) == 0 || shouldRepeatBuffer.compare(noSyn[2]) == 0) ? 0 : -1;
		}
		shouldRepeat = shouldRepeatSemiBuffer == 0 ? false : true;

	} while (shouldRepeat == true);
}

void enterMagicalCreatureFromFile (LinkedList<Creature>* listToAddTo) {

	/*–
	 * this function should ask the user for the name of the file they want to read from.
	 * Then, if the file is able to be opened (print a message if can’t be opened)  read the creature data from the file (one at a time) with a loop and
	 * after reading in one creature, create a new creature object with this data, then append the creature to the
	 * creature linked list.
	 * After reading all the creatures from the file & adding them to the linked list
	 * print how many creatures
	 * FROM THE FILE were added to the zoo. This may or may not be the current number of creatures in the linked list!
	 * This function does not return any data.
	 */
}

/*
 deleteCreature – this function should first print a numbered list of the names of all the creatures in the linked list. Then ask
 the user which creature number they want to delete. Then the creature should be removed from the linked list. A
 confirmation should be printed out that the creature was removed. This function does not return anything.
 */
/*
 printCreatures – this function should print “THERE ARE NO CREATURES AT YOUR ZOO!” if there are no creatures in the
 linked list. If there are creatures in the linked list then it should print each creature’s detail in the list.
 This function does not return anything.
 */

/*
 * Parameters:	a pointer to a linked list of Creatures
 * Returns:	nothing (void)
 * Purpose:	export data to file
 */
void saveCreaturesToFile (LinkedList<Creature>* creatureLinkedList) {
	string filename;
	const string STANDARDFILEEXTENTION = ".txt";

	Creature* creatureBuffer;
	ofstream fileExport;

	//If there list is empty, tell the user then end function
	if(creatureLinkedList->getLength == 0) {
		cout << "THERE ARE NO CREATURES AT YOUR ZOO!" << "\n" << flush;
		return;
	}
	//get filename from user
	cout << "Enter file name: " << "\n" << flush;
	getline(cin, filename);
	//if it doesnt have a .txt extention or is too short to have one, loop until it does
	while (cin.fail() == true || has_suffix(filename, STANDARDFILEEXTENTION) == false || filename.length() == 4) {
		if(cin.fail() == true) {
			cout << "invalid input - unknown error has occurred, try again" << "\n";
		}
		else {
			if(has_suffix(filename, STANDARDFILEEXTENTION) == false) {
				cout << "invalid input - be sure the file name ends in \"" << STANDARDFILEEXTENTION << "\"" << "\n";
			}
			if(filename.length() <= 4) {
				cout << "invalid input - be sure to enter a file name" << "\n";
			}
		}
		cout << "Enter file name: " << "\n" << flush;
		getline(cin, filename);
	}

	//open a stream to the file and export the data to it
	fileExport.open(filename);
	for (size_t i = 0; i < creatureLinkedList->getLength; i++) {
		creatureBuffer = creatureLinkedList->getNodeValue(i);
		creatureBuffer->printCreatureToFile(filename);
	}
	fileExport.close();
}

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
