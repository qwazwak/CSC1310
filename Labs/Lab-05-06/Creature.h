/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	Title:	CSC1310 - Lab 05/06 - Creature Class
 *	Authors:	Rus Hoffman and Braedin Jared
 *	Date:	October 3, 2018
 *	Purpose:	memebigboy
 *
 * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Creature {
	private:
		//Variables:
		string creature_Name;
		string creature_Description;
		double creature_Upkeep;
		bool creature_IsDangerous;

	public:
		//Default Constructor
		Creature ();
		Creature (string);
		Creature (string, string, float, bool);
		Creature (string, string, double, bool);
		Creature (char*, char*, float, bool);
		Creature (char*, char*, double, bool);
		//Destructor
		~Creature ();

		/*
		 Parameters:	nothing (void)
		 Returns:		nothing (void)
		 Purpose:		-
		 */
		string getName ();

		/*
		 Parameters:	nothing (void)
		 Returns:		nothing (void)
		 Purpose:		-
		 */
		string getDescription ();

		/*
		 Parameters:	nothing (void)
		 Returns:		nothing (void)
		 Purpose:		-
		 */
		bool getDangerous ();

		/*
		 Parameters:	nothing (void)
		 Returns:		nothing (void)
		 Purpose:		-
		 */
		double getCost ();

		/*
		 Parameters:	nothing (void)
		 Returns:		nothing (void)
		 Purpose:		-
		 */
		void setName (string);

		/*
		 Parameters:	nothing (void)
		 Returns:		nothing (void)
		 Purpose:		-
		 */
		void setDescription (string);

		/*
		 Parameters:	nothing (void)
		 Returns:		nothing (void)
		 Purpose:		-
		 */
		void setDangerous (bool);

		/*
		 Parameters:	nothing (void)
		 Returns:		nothing (void)
		 Purpose:		-
		 */
		void setCost (double);

		/*
		 Parameters:	nothing (void)
		 Returns:		nothing (void)
		 Purpose:		a function to print a single creature's information to the screen in a nice, easy to read format
		 */
		void printCreature ();

		/*
		 Parameters:	either a string to the filename or a stream to a file
		 Returns:		nothing (void)
		 Purpose:		export creature data one line at a time for later loading
		 */
		void printCreatureToFile (ofstream&);
		void printCreatureToFileNoFlush (ofstream&);
		void printCreatureToFile (string);
};

#endif //end CREATURE_H define
