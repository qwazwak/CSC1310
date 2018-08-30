/* * * * * * * * * * * * * * * * * * * * * * * *
*
*	Title:      CSC1310 - LAB 01
*	Author(s):  Rus Hoffman, Braedin Jared, and Justice Maravilla
*	Date:       August 8, 2018
*	Purpose:    Practice structures and functions
*
* * * * * * * * * * * * * * * * * * * * * * * */

#if !defined(TEXT_H)
	#define TEXT_H

	struct Text {
		const char * textArray;
			//A character string holding my “String”
		int size;
			//The size of my string
	};
/*
Parameters: Send a pointer to a constant characterarray or a string literal to this function
Returns: A pointer to a new Text variable, which contains the c-string & the length of the string
Purpose: To create a new Text variable
*/
	Text * createText(const char* text);


/*
Parameters: Send a pointer to a Text variable, which contains a c-string & length of the string
Returns: nothing (void)
Purpose: release dynamically allocated memory that the pointer is pointing to
*/
	void destroyText(Text* myText);


/*
Parameters: Send a pointer to a Text variable, which contains a c-string & length of the string
Returns: nothing (void)
Purpose: prints out the string (character array)
*/
	void displayText(Text* myText);


/*
Parameters: Send a pointer to a Text variable, which contains a c-string & length of the string
Returns: pointer to a constant character array
*/
	const char* getText(Text* myText);


/*
Parameters: Send a pointer to a Text variable, which contains a c-string & length of the string
Returns: the lendth of the string (int)
*/
	int getLength(Text* myText);


#endif /* TEXT_H */
