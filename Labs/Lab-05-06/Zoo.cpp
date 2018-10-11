/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	Title:	CSC1310 - Lab 05/06 - Creature Class
 *	Authors:	Rus Hoffman and Braedin Jared
 *	Date:	October 4, 2018
 *	Purpose:	Practice linked lists
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
#include <cstdlib>

using namespace std;

/*
 * Parameters:	some text (string) and a suffix to check for (string)
 * Returns:	nothing (void)
 * Purpose:	allow user to enter the details for creatures and adds them to the linked list
 */
bool has_suffix (const string &str, const string &suffix) {
	return (str.size() >= suffix.size()) && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

/*
 * Parameters:	a pointer to a linked list of Creatures
 * Returns:	nothing (void)
 * Purpose:	allow user to enter the details for creatures and adds them to the linked list
 */
void enterMagicalCreature (LinkedList<Creature>* listToAddTo) {
	//Menu variables
	string shouldRepeatBuffer;
	int shouldRepeatSemiBuffer;
	bool shouldRepeat;

	//creature input variables
	string nameBuffer;
	string descBuffer;
	double upkeepBuffer;
	string dangerBuffer;
	bool isDangerConverted;

	//Loop while the user wants more creatures
	do {
		cout << "Enter creature name: " << flush;
		getline(cin, nameBuffer);
		cout << "Enter creature description: " << flush;
		getline(cin, descBuffer);

		cout << "Is the creature dangerous: " << flush;
		getline(cin, dangerBuffer);
		//Convert to lowercase
		//convert from text to int, 1 for true, 0 for false, -1 for unknown
		while (dangerBuffer.length() != 1 || ((dangerBuffer.at(0) == 'y') ? false : (dangerBuffer.at(0) == 'n') ? false : true)) {
			cout << "invalid input, be sure to only enter either 'y' for yes or 'n' for no" << "\n";
			cout << "Is the creature dangerous: " << flush;
			getline(cin, dangerBuffer);
			transform(dangerBuffer.begin(), dangerBuffer.end(), dangerBuffer.begin(), ::tolower);
		}
		//actually convert from int to bool and add to the list
		isDangerConverted = dangerBuffer.at(0) == 'y' ? true : false;


		cout << "Enter monthly upkeep cost: " << flush;
		cin >> upkeepBuffer;
		while (cin.fail() || upkeepBuffer < 0) {
			if(cin.fail()) {
				cout << "invalid input - be sure to enter only a number" << "\n";
				cin.clear();
				cin.ignore();
			}
			else
				if(upkeepBuffer < 0) {
					cout << "invalid input - only enter a number greater than or equal to zero" << "\n";
				}
			cout << "Enter monthly upkeep cost: " << flush;
			cin >> upkeepBuffer;
		}
		cin.ignore();


		listToAddTo->appendNode(Creature(nameBuffer, descBuffer, upkeepBuffer, isDangerConverted));

		//Output some confirmation for the user
		cout << "CREATURE ADDED:" << "\n";
		cout << "Name:" << "\n";
		cout << "\t" << nameBuffer << "\n";
		cout << "Description:" << "\n";
		cout << "\t" << descBuffer << "\n";
		cout << "Is it dangerous:" << "\n";
		cout << "\t" << (isDangerConverted ? "Yes" : "No") << "\n";
		cout << "Monthly upkeep:" << "\n";
		cout << "\t" << upkeepBuffer << "\n";
		cout << "\n" << flush;

		//See if the user wants to enter more user, then do standard data validation
		cout << "Do you want to enter more creatures? : ";
		getline(cin, shouldRepeatBuffer);
		while (shouldRepeatBuffer.length() != 1 || ((dangerBuffer.at(0) == 'y') ? false : (dangerBuffer.at(0) == 'n') ? false : true)) {
			cout << "invalid input, be sure to only enter either 'y' for yes or 'n' for no" << "\n";
			cout << "Do you want to enter more creatures? : " << flush;
			getline(cin, shouldRepeatBuffer);
			transform(shouldRepeatBuffer.begin(), shouldRepeatBuffer.end(), shouldRepeatBuffer.begin(), ::tolower);
		}
		shouldRepeat = shouldRepeatBuffer.compare("y") ? true : false;

	} while (shouldRepeat == true);
}

/*
 * Parameters:	a pointer to a linked list of Creatures
 * Returns:	nothing (void)
 * Purpose:	allow user to enter file name and import creates from the file
 */
void enterMagicalCreatureFromFile (LinkedList<Creature>* listToAddTo) {
	string filename;
	ifstream importFileStream;
	bool shouldContinueLooping = true;

	const int numYesSyn = 3;
	const int numNoSyn = 3;
	const string yesSyn[numYesSyn] = {"yes", "true", "y"};
	const string noSyn[numNoSyn] = {"no", "false", "n"};

	string importNameBuffer;
	string importDescriptionBuffer;
	string importUpkeepBuffer;
	float importUpkeepConverted;
	int importDangerousBuffer;
	string dangerousErrorBackup;
	bool importDangerousConverted;
	long importedCreatureCount = 0;

	//get filename from user
	cout << "Enter file name to load creatures from: " << flush;
	getline(cin, filename);
	importFileStream.open(filename.c_str());
	//if it fails to open, ask the user for a new filename and try again
	while (importFileStream.is_open() != true) {
		cout << "invalid input" << "\n";
		cout << "Enter file name to load creatures from: " << flush;
		getline(cin, filename);
		importFileStream.open(filename.c_str());
	}

	//br�ther may i have some l��ps
	while (shouldContinueLooping) {
		getline(importFileStream, importNameBuffer);
		getline(importFileStream, importDescriptionBuffer);
		importFileStream >> importDangerousBuffer;
		importFileStream.ignore();
		getline(importFileStream, importUpkeepBuffer);
		importUpkeepConverted = atof(importUpkeepBuffer.c_str());
		importDangerousConverted = importDangerousBuffer == 1 ? true : false;
		listToAddTo->appendNode(Creature(importNameBuffer, importDescriptionBuffer, importUpkeepConverted, importDangerousConverted));
					importedCreatureCount++;
		if(importFileStream.eof()) {
			shouldContinueLooping = false;
		}
		if(shouldContinueLooping == true) {


		}
	}
	importFileStream.close();
	cout << "\n" << "\n";
	cout << "Finished loading " << listToAddTo->getLength() << ( (importedCreatureCount > 1) ? " creatures" : " creature") << "\n" << flush;
}

/*
 * Parameters:	a pointer to a linked list of Creatures
 * Returns:	nothing (void)
 * Purpose:	remove a creature from the linked list
 */
void deleteCreature (LinkedList<Creature>* creatureLinkedList) {
	Creature creatureBuffer;
	long numberPicked;
	//If there list is empty, tell the user then end function
	if(creatureLinkedList->getLength() == 0) {
		cout << "THERE ARE NO CREATURES AT YOUR ZOO!" << "\n" << flush;
		return;
	}
	//open a stream to the file and export the data to it
	cout << setfill(' ');
	for (size_t i = 0; i < creatureLinkedList->getLength(); i++) {
		creatureBuffer = creatureLinkedList->getNodeValue(i);
		cout << "----           " << setw(4) << left << i + 1 << setw(0) << right << "           ----" << "\n";
		creatureBuffer.printCreature();
		cout << "----           " << setw(4) << left << i + 1 << setw(0) << right << "           ----" << "\n";
		cout << "\n" << "\n";
	}
	cout << flush;

	cout << "Enter the number of the creature to remove: ";
	cin >> numberPicked;
	while (numberPicked < 1 || numberPicked > creatureLinkedList->getLength() || cin.fail()) {
		if(cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "INVALID INPUT - only enter a number" << "\n";
		}
		if(numberPicked < 1 || numberPicked > creatureLinkedList->getLength()) {
			cout << "INVALID INPUT -  only enter a number between 1  and " << creatureLinkedList->getLength() << ", inclusive" << "\n";
		}
		cout << "Enter the number of the creature to remove: ";
		cin >> numberPicked;
	}
	cout << "Successfuly removed creature #" << numberPicked << ", \"" << creatureLinkedList->getNodeValue(numberPicked - 1).getName() << "\"" << "\n";
	creatureLinkedList->deleteNode(numberPicked - 1);
	cout << flush;
}

/*
 * Parameters:	a pointer to a linked list of Creatures
 * Returns:	nothing (void)
 * Purpose:	print out creature data to the cout buffer
 */
void printCreatures (LinkedList<Creature>* creatureLinkedList) {
	Creature creatureBuffer;
	//If there list is empty, tell the user then end function
	if(creatureLinkedList->getLength() == 0) {
		cout << "THERE ARE NO CREATURES AT YOUR ZOO!" << "\n" << flush;
		return;
	}
	//open a stream to the file and export the data to it
	for (size_t i = 0; i < creatureLinkedList->getLength(); i++) {
		creatureBuffer = creatureLinkedList->getNodeValue(i);
		creatureBuffer.printCreature();
	}
}

/*
 * Parameters:	a pointer to a linked list of Creatures
 * Returns:	nothing (void)
 * Purpose:	export data to file
 */
void saveCreaturesToFile (LinkedList<Creature>* creatureLinkedList) {
	string filename;
	const string STANDARDFILEEXTENTION = ".txt";

	Creature creatureBuffer;
	ofstream fileExport;

	//If there list is empty, tell the user then end function
	if(creatureLinkedList->getLength() == 0) {
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
	fileExport.open(filename.c_str());
	for (size_t i = 0; i < creatureLinkedList->getLength(); i++) {
		creatureBuffer = creatureLinkedList->getNodeValue(i);
		creatureBuffer.printCreatureToFile(filename);
	}
	fileExport.close();
}

int main () {

	int menuChoice;

	LinkedList<Creature> *creatureList;

	creatureList = new LinkedList<Creature>;

	do {
		cin.clear();
		cout << "\n" << "\n" << "\n";
		cout << "What would you like to do?" << "\n";
		cout << "1.  Add creature" << "\n";
		cout << "2.  Delete creature" << "\n";
		cout << "3.  Print Creatures" << "\n";
		cout << "4.  Exit" << "\n";

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
				int menuChoice2;

				do {
					cin.clear();
					cout << "\n" << "\n" << "\n";
					cout << "What would you like to do?" << "\n";
					cout << "1.  Enter Manually" << "\n";
					cout << "2.  Enter from file" << "\n";
					cout << "3.  Exit" << "\n";

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
							enterMagicalCreature(creatureList);
							break;
						case 2:
							enterMagicalCreatureFromFile(creatureList);
							break;
						case 3:
							continue;
							break;
						default:
							continue;
							break;
					}
				} while (menuChoice != 3);

				break;
			case 2:
				deleteCreature(creatureList);
				break;
			case 3:
				printCreatures(creatureList);
				break;
			case 4:
				continue;
				break;
			default:
				continue;
				break;
		}
	} while (menuChoice != 4);

	return 0;
}
