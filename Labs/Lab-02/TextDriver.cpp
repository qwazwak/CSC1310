/*
 TextDriver.cpp
 Driver to test the Text Class
 April Crockett
 Last Updated: 8/8/2018
 */
#include <iostream>
#include "Text.h"

using namespace std;

int main () {
	Text *myString1;
	Text *myString2;
	char tvshow[1000];
	char movie[1000];

	cout << "\n\nWhat is the most recent TV show you watched?\n";
	cin.getline(tvshow, 1000);
	myString1 = new Text(tvshow);

	cout << "\nWhat is the most recent Movie you watched?\n";
	cin.getline(movie, 1000);
	myString2 = new Text(movie);

	cout << "\n\nTV SHOW:\t";
	myString1->displayText();
	cout << "\t# CHARACTERS:\t" << myString1->getLength() << endl;

	cout << "\nMOVIE:\t\t";
	myString2->displayText();
	cout << "\t# CHARACTERS:\t" << myString2->getLength() << endl;

	delete myString1;
	delete myString2;

	return 0;
}
