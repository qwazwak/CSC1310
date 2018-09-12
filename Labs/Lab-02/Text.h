/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	Title:      CSC1310 - Program 01 - Bootleg String Class
 *	Author(s):  Rus Hoffman and Tyler Showman
 *	Date:       September 4, 2018
 *	Purpose:
 *
 * * * * * * * * * * * * * * * * * * * * * * * */

#if !defined(TEXT_H)
#define TEXT_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;

class Text {
	private:
		//Variables:
		const char* textArray;
		int textLength;

	public:
		//default Constructor
		Text ();

		//Overloading Constructor for quicker setup
		Text (const char*);
		Text (string);

		//Destructor
		~Text ();

		/*
		 Function Name:  displayText()
		 Parameters:  nothing (void)
		 Returns:  nothing (void)
		 Purpose:  prints out the string (character array) with no formatting or new lines
		 */
		void displayText ();

		/*
		 Function Name:  getText()
		 Parameters:  none
		 Returns:  pointer to a constant character array
		 */
		const char* getText ();

		/*
		 Function Name:  getLength()
		 Parameters:  nothing (void)
		 Returns:  the length of the string
		 */
		int getLength ();

		/*
		 Function Name:  editText()
		 Parameters:  Send a pointer to a c-string
		 Returns:  nothing (void)
		 */
		void editText (const char*);
		void editText (string newText);

};

#endif
