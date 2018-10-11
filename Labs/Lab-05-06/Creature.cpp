/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	Title:	CSC1310 - Lab 05/06 - Creature Class
 *	Authors:	Rus Hoffman and Braedin Jared
 *	Date:	October 3, 2018
 *	Purpose:	Practice making classes
 *
 * * * * * * * * * * * * * * * * * * * * * * * */

#include "creature.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

Creature::Creature () {
	creature_Name = "ERROR: NOT SET";
	creature_Description = "ERROR: NOT SET";
	creature_Upkeep = -1;
	creature_IsDangerous = false;
}
Creature::Creature (string pathToFileAndName) {
	string errorString = "error in loading a creature from file.\n the fourth line should only be Yes, yes, No, no, True, true, False, or false";
	string inputBuffer;
	int boolBuffer;
	ifstream theStream;
	theStream.open(pathToFileAndName.c_str());
	getline(theStream, creature_Name);
	getline(theStream, creature_Description);
	creature_Upkeep = -1;
	cin >> creature_Upkeep;
	cin >> boolBuffer;
	cin.ignore();
	creature_IsDangerous = boolBuffer == 1 ? true : false;
	theStream.close();
}

Creature::Creature (string inputName, string inputDescription, double inputUpkeepCost, bool inputIsDangerous) {
	creature_Name = inputName;
	creature_Description = inputDescription;
	creature_Upkeep = inputUpkeepCost;
	creature_IsDangerous = inputIsDangerous;
}
Creature::Creature (string inputName, string inputDescription, float inputUpkeepCost, bool inputIsDangerous) {
	creature_Name = inputName;
	creature_Description = inputDescription;
	creature_Upkeep = static_cast<double>(inputUpkeepCost);
	creature_IsDangerous = inputIsDangerous;
}
Creature::Creature (char* inputName, char* inputDescription, double inputUpkeepCost, bool inputIsDangerous) {
	creature_Name = inputName;
	creature_Description = inputDescription;
	creature_Upkeep = inputUpkeepCost;
	creature_IsDangerous = inputIsDangerous;
}
Creature::Creature (char* inputName, char* inputDescription, float inputUpkeepCost, bool inputIsDangerous) {
	creature_Name = inputName;
	creature_Description = inputDescription;
	creature_Upkeep = static_cast<double>(inputUpkeepCost);
	creature_IsDangerous = inputIsDangerous;
}

Creature::~Creature () {

}

string Creature::getName () {
	return creature_Name;
}

string Creature::getDescription () {
	return creature_Name;
}

bool Creature::getDangerous () {
	return creature_IsDangerous;
}

double Creature::getCost () {
	return creature_Upkeep;
}

void Creature::setName (string inputName) {
	creature_Name = inputName;
}

void Creature::setDescription (string inputdescription) {
	creature_Description = inputdescription;
}

void Creature::setCost (double inputCost) {
	creature_Upkeep = inputCost;
}

void Creature::setDangerous (bool inputDangerous) {
	creature_IsDangerous = inputDangerous;
}

void Creature::printCreature () {
	cout << setw(0) << setfill(' ');
	cout << "Name: " << creature_Name << "\n";
	cout << "Description: " << creature_Description << "\n";
	cout << "Monthly upkeep costs: " << creature_Upkeep << "\n";
	cout << "Is dangerous? " << (creature_IsDangerous ? ("Yes") : ("No")) << "\n";
	cout << flush;
}

void Creature::printCreatureToFile (string fileName) {
	ofstream theStream;
	theStream.open(fileName.c_str(), ofstream::app | ofstream::ate);
	theStream << creature_Name << "\n";
	theStream << creature_Description << "\n";
	theStream << creature_Upkeep << "\n";
	theStream << (creature_IsDangerous ? ("1") : ("0")) << "\n" << flush;
	theStream.close();
}
void Creature::printCreatureToFile (ofstream& theStream) {
	theStream << setw(0) << setfill(' ');
	theStream << creature_Name << "\n";
	theStream << creature_Description << "\n";
	theStream << creature_Upkeep << "\n";
	theStream << (creature_IsDangerous ? ("1") : ("0")) << "\n";
	theStream << flush;
}
