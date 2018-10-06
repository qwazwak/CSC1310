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

void enterMagicalCreature(LinkedList* listToAddTo){
	bool shouldRepeat;

	string nameBuffer;
	string descBuffer;
	double upkeepBuffer;
	bool dangerBuffer;
	do{
		getline(cin, nameBuffer);
		getline(cin, descBuffer);
		cin >> upkeepBuffer;
		getline(cin, nameBuffer);

		listToAddTo->push(new Creature());

	}while(shouldRepeat == true);
}
this function should ask the user for the creature’s name, description, if it is dangerous, and the cost per month to care fo rhte creature.
Then it should create a new creature object with this data.
Then, it should append the creature object to the linked creature list.
Then it should print a confirmation that the creature (print creature’s name) has been added to the zoo.
The function should then ask the user if they want to add more creatures.
If they answer yes, then repeat this process. Otherwise, the function should end and it doesn’t return any data.


 enterMagicalCreatureFromFile – this function should ask the user for the name of the file they want to read from. Then, if
the file is able to be opened (print a message if can’t be opened) then read the creature data from the file (one at a time)
with a loop and after reading in one creature, create a new creature object with this data, then append the creature to the
creature linked list. After reading all the creatures from the file & adding them to the linked list, print how many creatures
FROM THE FILE were added to the zoo. This may or may not be the current number of creatures in the linked list! This
function does not return any data.
 deleteCreature – this function should first print a numbered list of the names of all the creatures in the linked list. Then ask
the user which creature number they want to delete. Then the creature should be removed from the linked list. A
confirmation should be printed out that the creature was removed. This function does not return anything.
 printCreatures – this function should print “THERE ARE NO CREATURES AT YOUR ZOO!” if there are no creatures in the
linked list. If there are creatures in the linked list then it should print each creature’s detail in the list. This function does
not return anything.
 saveCreaturesToFile – this function should either print “THERE ARE NO CREATURES AT YOUR ZOO!” if there are no
creatures in the linked list. If there are creatures in the linked list then it should ask the user for the filename that they wish
to use to save the creatures and then use a loop to get a creature from each node, and then call this creature’s
printCreatureToFile function, sending the filename to the function.


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
