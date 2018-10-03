/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	Title:	CSC1310 - Lab 05/06 - Creature Class
 *	Authors:	Rus Hoffman and Braedin Jared
 *	Date:	October 3, 2018
 *	Purpose:	memebigboy
 *
 * * * * * * * * * * * * * * * * * * * * * * * */

#include "creature.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

/*
 string creatureName;
 string creatureDescription;
 double upkeepMonthlyCost;
 bool isDangerous;

 creatureName
 creatureDescription
 upkeepMonthlyCost
 isDangerous
 */
//Default Constructor
Creature::Creature (){
	 creatureName = "ERROR: NOT SET";
	 creatureDescription = "ERROR: NOT SET";
	 upkeepMonthlyCost = -1;
	 isDangerous = false;
}
Creature::Creature (string inputName, string inputDescription, double inputUpkeepCost, bool inputIsDangerous){
	 creatureName = inputName;
	 creatureDescription = inputDescription;
	 upkeepMonthlyCost = inputUpkeepCost;
	 isDangerous = inputIsDangerous;
}
Creature::Creature (string inputName, string inputDescription, float inputUpkeepCost, bool inputIsDangerous){
	 creatureName = inputName;
	 creatureDescription = inputDescription;
	 upkeepMonthlyCost = static_cast<double>(inputUpkeepCost);
	 isDangerous = inputIsDangerous;
}
Creature::Creature (char* inputName, char* inputDescription, double inputUpkeepCost, bool inputIsDangerous){
	 creatureName = inputName;
	 creatureDescription = inputDescription;
	 upkeepMonthlyCost = inputUpkeepCost;
	 isDangerous = inputIsDangerous;
}
Creature::Creature (char* inputName, char* inputDescription, float inputUpkeepCost, bool inputIsDangerous){
	 creatureName = inputName;
	 creatureDescription = inputDescription;
	 upkeepMonthlyCost = static_cast<double>(inputUpkeepCost);
	 isDangerous = inputIsDangerous;
}

//Destructor
Creature::~Creature (){
#if defined(DEBUGLOGGING)
	clog << "DEALLOCATING CREATURE" << endl;
#endif
}

/*
 Parameters:	nothing (void)
 Returns:		nothing (void)
 Purpose:		-
 */
string Creature::getName (){
	return creatureName;
}

/*
 Parameters:	nothing (void)
 Returns:		nothing (void)
 Purpose:		-
 */
string Creature::getDescription (){
	return creatureName;
}

/*
 Parameters:	nothing (void)
 Returns:		nothing (void)
 Purpose:		-
 */
bool Creature::getDangerous ();

/*
 Parameters:	nothing (void)
 Returns:		nothing (void)
 Purpose:		-
 */
double Creature::getCost ();

/*
 Parameters:	nothing (void)
 Returns:		nothing (void)
 Purpose:		-
 */
void Creature::setName ();

/*
 Parameters:	nothing (void)
 Returns:		nothing (void)
 Purpose:		-
 */
void Creature::setDescription (string);

/*
 Parameters:	nothing (void)
 Returns:		nothing (void)
 Purpose:		-
 */
void Creature::setDangerous (bool);

/*
 Parameters:	nothing (void)
 Returns:		nothing (void)
 Purpose:		-
 */
void Creature::setCost (double);

/*
 Parameters:	nothing (void)
 Returns:		nothing (void)
 Purpose:		a function to print a single creature's information to the screen in a nice, easy to read format
 */
void Creature::printCreature ();

/*
 Parameters:	nothing (void)
 Returns:		nothing (void)
 Purpose:		a function to print a single creature’s information to the file – unformatted – one piece of
 information per line. This is so the program would be able to read the creature’s information back later.
 */
void Creature::printCreatureToFile (ofstream&);
void Creature::printCreatureToFile (string);
