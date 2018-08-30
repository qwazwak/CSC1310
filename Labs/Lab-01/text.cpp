#include "Text.h"
#include <string.h>
#include <iostream>

Text * createText(const char* text){
	Text * pointerToThing = new Text;
	pointerToThing->size = strlen(text);
	pointerToThing->textArray = text;
	return pointerToThing;
}

void destroyText(Text* myText) {
	delete myText;
}

void displayText(Text* myText) {
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
