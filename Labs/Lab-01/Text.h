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
		//Parameters:
		//Returns:
		//Purpose:

	void displayText(Text* myText);
		//Parameters:
		//Returns:
		//Purpose:

	const char* getText(Text* myText);
		//Parameters:
		//Returns:
		//Purpose:

	int getLength(Text* myText);
		//Parameters:
		//Returns:
		//Purpose:

#endif /* TEXT_H */
