/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	Title:	CSC1310 - Lab 10 - AT_Cast
 *	Author:	Rus Hoffman
 *	Date:	Tuesday, November 13, 2018
 *	Purpose:	Overload operators
 *
 * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef AT_CAST_H
#define AT_CAST_H

#include <iostream>
#include <string>
using namespace std;

class AT_Cast {
	private:
		//Variables:
		size_t castID;
		string name;

	public:
		AT_Cast (size_t newID, string newName);
		AT_Cast (string newName, size_t newID);

		//Destructor
		~AT_Cast ();
		void setID (size_t IDToUse);
		void setName (string nameToUse);
		size_t getID ();
		string getName ();

		bool operator== (const AT_Cast& member) {
			return this->castID == member.castID;

		}
		bool operator!= (const AT_Cast& member) {
			return ! (this->castID == member.castID);
		}
		bool operator< (const AT_Cast& member) {
			return this->castID < member.castID;
		}
		bool operator> (const AT_Cast& member) {
			return this->castID > member.castID;
		}
		bool operator<= (const AT_Cast& member) {
			return ! (this->castID > member.castID);

		}
		bool operator>= (const AT_Cast& member) {
			return ! (this->castID < member.castID);

		}
		friend ostream &operator << (ostream &stream, AT_Cast* member) {
			stream << "Cast ID Number: " << member->castID << "\tName: " << member->name;
			return stream;
		}
};

inline AT_Cast::AT_Cast (string newName, size_t newID)
		{
	this->castID = newID;
	this->name = newName;
}

inline AT_Cast::AT_Cast (size_t newID, string newName)
		{
	this->castID = newID;
	this->name = newName;
}

inline AT_Cast::~AT_Cast ()
{
	castID = 0;
	name = "";
}

inline void AT_Cast::setID (size_t IDToUse)
		{
	this->castID = IDToUse;
}

inline void AT_Cast::setName (string nameToUse)
		{
	this->name = nameToUse;
}

inline size_t AT_Cast::getID ()
{
	return this->castID;
}

inline std::__cxx11::string AT_Cast::getName ()
{
	return this->name;
}

#endif //end AT_CAST_H define
