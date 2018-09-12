/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	Title:      CSC1310 - Program 01 - Bootleg String Class
 *	Author(s):  Rus Hoffman and Tyler Showman
 *	Date:       September 4, 2018
 *	Purpose:
 *
 * * * * * * * * * * * * * * * * * * * * * * * */

#include <string>
#include "Text.h"

using namespace std;

//default Constructor
Text::Text () {
	textArray = "";
	textLength = 0;
}

//Overloading Constructor for quicker setup
Text::Text (const char* inputText) {
	textArray = inputText;
	textLength = 0;
	while (textArray[textLength] != '\0') {
		textLength = textLength + 1;
	}
}

//Overloading Constructor for quicker setup
Text::Text (string inputText) {
	textArray = inputText.c_str();
	textLength = inputText.length();
}

//Destructor
Text::~Text () {
	delete[] textArray;
}

void Text::displayText () {
	cout << textArray;
}

const char* Text::getText () {
	return textArray;
}

int Text::getLength () {
	return textLength;
}

void Text::editText (string newText) {
	editText(newText.c_str());
}

void Text::editText (const char* newCharArray) {
	delete[] textArray;

	textArray = newCharArray;
	textLength = strlen(textArray);
}
