#include "Random.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;


bool binarySearch(string s, string a[]);

int main()
{
	seedRandom();

	string lotto = "";
	string guesses[5];
	for(int i = 0; i<5; i++){
		lotto += to_string(getRandomInt(0,9));
	}


	int count = 0;

	while(count < 5){

		string input;

		cout << "Gimme a list of 5 numbers of size 5" << endl;
		cin >> input;

		while(input.length() != 5){
			cout << "I said of size 5" << endl;
			cin.ignore();
			cin >> input;
		}

		guesses[count] = input;

		count++;
	}


	// if(binarySearch()){

	// }

	return 0;
}


bool binarySearch(string s, string a[]){

}