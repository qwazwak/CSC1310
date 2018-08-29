/*
	Driver for Custom Text Structure
	LAB 1 - CSC1310
	April Crockett
	8/8/2018
*/

#include "Text.h"
#include <iostream>

using namespace std;

int main (){
	Text *myString1;
	Text *myString2;
	char tvshow[1000];
	char movie[1000];

	cout << "\n\nWhat is the most recent TV show you watched?\n";
	cin.getline(tvshow, 1000);
	myString1 = createText(tvshow);

	cout << "\nWhat is the most recent Movie you watched?\n";
	cin.getline(movie, 1000);
	myString2 = createText(movie);

	cout << "\n\nTV SHOW:\t";
	displayText(myString1);
	cout << "\t# CHARACTERS:\t" << getLength(myString1) << endl;

	cout << "\nMOVIE:\t\t";
	displayText(myString2);
	cout << "\t# CHARACTERS:\t" << getLength(myString2) << endl;

	destroyText(myString1);
	destroyText(myString2);

	return 0;
}
