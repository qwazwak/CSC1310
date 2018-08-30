#ifndef TEXT_H
	#define TEXT_H

	struct Text {
		const char * textArray;
			//A character string holding my “String”
		int size;
			//The size of my string
	};

	Text * createText(const char* text);
		//Parameters: Send a pointer to a constant characterarray or a string literal to this function
		//Returns: A pointer to a new Text variable, which contains the c-string & the length of the string
		//Purpose: To create a new Text variable

	void destroyText(Text* myText);
		//Parameters: Send a pointer to a Text variable, which contains a c-string & length of the string
		//Returns: nothing (void)
		//Purpose: release dynamically allocated memory that the pointer is pointing to

	void displayText(Text* myText);
		//Parameters: Send a pointer to a Text variable, which contains a c-string & length of the string
		//Returns: nothing (void)
		//Purpose: prints out the string (character array)

	const char* getText(Text* myText);
		//Parameters: Send a pointer to a Text variable, which contains a c-string & length of the string
		//Returns: pointer to a constant character array

	int getLength(Text* myText);
		//Parameters: Send a pointer to a Text variable, which contains a c-string & length of the string
		//Returns: the lendth of the string (int)

#endif /* TEXT_H */
