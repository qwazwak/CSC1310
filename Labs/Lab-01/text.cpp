/* * * * * * * * * * * * * * * * * * * * * * * *
*
*	Title:      CSC1310 - LAB 01
*	Author(s):  Rus Hoffman, Braedin Jared, and Justice Maravilla
*	Date:       August 8, 2018
*	Purpose:    Practice structures and functions
*
* * * * * * * * * * * * * * * * * * * * * * * */

#include "Text.h"
#include <string.h>
#include <iostream>

Text * createText(const char* text){
	Text * pointerToThing = new Text;
	pointerToThing->size = strlen(text);
	pointerToThing->textArray = text;
	return pointerToThing;
}

void destroyText(Text *myText) {
	delete myText;
}

void displayText(Text * myText) {
	for (int i = 0; i < myText->size; i++) {
		std::cout << myText->textArray[i];
	}
}

const char* getText(Text* myText) {
	return myText->textArray;
}

int getLength(Text* myText) {
	return myText->size;
}
