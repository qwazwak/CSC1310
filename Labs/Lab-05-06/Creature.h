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

		//Constructor from filename
		Creature (string);

		//Auto creation constructors
		Creature (string, string, float, bool);
		Creature (string, string, double, bool);
		Creature (char*, char*, float, bool);
		Creature (char*, char*, double, bool);
		//Destructor
		~Creature ();

		/*
		 Parameters:	nothing (void)
		 Returns:		string
		 Purpose:		Returns the creatures name
		 */
		string getName ();

		/*
		 Parameters:	nothing (void)
		 Returns:		string
		 Purpose:		Returns the creatures description
		 */
		string getDescription ();

		/*
		 Parameters:	nothing (void)
		 Returns:		bool
		 Purpose:		Returns if the creature is dangerous
		 */
		bool getDangerous ();

		/*
		 Parameters:	nothing (void)
		 Returns:		double
		 Purpose:		Returns the monthly cost of upkeep for the creature
		 */
		double getCost ();

		/*
		 Parameters:	string
		 Returns:		nothing (void)
		 Purpose:		Set creature name
		 */
		void setName (string);

		/*
		 Parameters:	string
		 Returns:		nothing (void)
		 Purpose:		Set creature description
		 */
		void setDescription (string);

		/*
		 Parameters:	bool
		 Returns:		nothing (void)
		 Purpose:		Sets if the creature is dangerous or not
		 */
		void setDangerous (bool);

		/*
		 Parameters:	double
		 Returns:		nothing (void)
		 Purpose:		Sets the monthly cost of upkeep for the creature
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
