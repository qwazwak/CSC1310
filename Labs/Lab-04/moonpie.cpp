/*	Title: CSC1310 - Lab 04
	Authors: Rus Hoffman and Braedin Jared
	Date: September 26, 2018*/
#include <iostream>
#include <vector>
void enterStolenMoonPies (std::vector<long long> &vct, long long cnt) {
	std::cout << "Enter the number stolen each day\n\n";
	for (long long i = 0; i < cnt; i++) {
		std::cout << "\nDAY " << i + 1 << ": ";
		std::cin >> vct.at(i);
		while (std::cin.fail() || vct.at(i) < 0) {
			if(std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
				std::cout << "an error has occurred, try again\n";
			}
			else if( vct.at(i) < 0)
					std::cout << "only enter a postive number or zero\n";
			std::cout << "DAY " << i + 1 << ": ";
			std::cin >> vct.at(i);
		}
	}
}
double averageMoonPies (long long mpStolenCount, long long numberOfDays) {
	return static_cast<double>(mpStolenCount) / static_cast<double>(numberOfDays);
}
long long highestMoonPies(std::vector<long long> &theVector, long long numElements){
	long long value = theVector.at(0);
	for (long long i = 0; i < numElements; i++)
		value = (value < theVector.at(i)) ? theVector.at(i) : value;
	return value;
}
long long lowestMoonPies(std::vector<long long> theVector, long long numElements){
	long long value = theVector.at(0);
	for (long long i = 0; i < numElements; i++)
		value = (value > theVector.at(i)) ? theVector.at(i) : value;
	return value;
}
int main () {
	long long dayCnt, net = 0;
	std::cout << "How many days did Jane steal moon pies?\n";
	std::cin >> dayCnt;
	while (std::cin.fail() || dayCnt < 0) {
		if(std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "an error has occurred, try again\n";
		}
		else if(dayCnt < 0) std::cout << "only enter a postive number or zero\n";
		std::cout << "How many days did Jane steal moon pies?\n";
		std::cin >> dayCnt;
	}
	std::vector<long long> theRealVector(dayCnt);
	enterStolenMoonPies(theRealVector, dayCnt);
	for (long long i = 0; i < dayCnt; i++)
		net += theRealVector[i];
	std::cout << "\n\n-------------------RESULTS-------------------\nTOTAL # MOON PIES STOLEN:  " << net << "\nAVERAGE # OF MOON PIES STOLEN PER DAY:  " << averageMoonPies(net, dayCnt) << "\nMOST # MOON PIES STOLEN IN ONE DAY: " << highestMoonPies(theRealVector, dayCnt) << "\nLEAST # OF MOON PIES STOLEN IN ONE DAY: " << lowestMoonPies(theRealVector, dayCnt) << std::endl;
	return 0;
}
