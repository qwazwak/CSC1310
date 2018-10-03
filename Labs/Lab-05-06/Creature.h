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
		string creatureName;
		string creatureDescription;
		double upkeepMonthlyCost;
		bool isDangerous;

	public:
		//Default Constructor
		Creature ();
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
		void setName ();

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
		 Parameters:	nothing (void)
		 Returns:		nothing (void)
		 Purpose:		a function to print a single creature’s information to the file – unformatted – one piece of
		 information per line. This is so the program would be able to read the creature’s information back later.
		 */
		void printCreatureToFile (ofstream&);
		void printCreatureToFile (string);
};

#endif //end CREATURE_H define
