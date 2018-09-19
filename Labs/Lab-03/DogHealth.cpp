#include "DogHealth.h"




DogHealth::DogHealth()
{
	cout << "\n\nWhat is the dog\'s name?  ";
	getline(cin, name);
	cout << "\nWhat is the dog\'s age?  ";
	cin >> age;

	cout << "\n\nPlease enter in the dog\'s weight (LBS) & resting heart rate (BPM) \nfor each month in 2017.\n";
	for(int x=0; x<MONTHS; x++)
	{
		cout << "\nMONTH " << (x+1) << " WEIGHT:  ";
		cin >> weight[x];
		cout << "MONTH " << (x+1) << " RESTING HEART RATE:  ";
		cin >> heartRate[x];
	}

	cout << "\n\nThank you!  " << name << "\'s data has been saved!\n";
}

void DogHealth::printDogHealth()
{
	cout << left << setprecision(1) << fixed;
	cout << "\n\n\t" << setw(23) << "NAME NAME:" << setw(50) << name;
	cout << "\n\t" << setw(23) << "AGE:" << setw(50) << age;
	cout << "\n\t" << setw(23) << "WEIGHT PER MONTH:\n";
	for(int x=0; x<MONTHS; x++)
	{
		cout << "\n" << left << setw(28) << " " << "MONTH " << (x+1) << ":  " << right << weight[x];
	}
	cout << left << "\n\t" << setw(23) << "HEART RATE PER MONTH:\n";
	for(int x=0; x<MONTHS; x++)
	{
		cout << "\n" << left << setw(28) << " " << "MONTH " << (x+1) << ":  " << right << heartRate[x];
	}
}

void DogHealth::printWeightStatistics()
{
	//WRITE THIS FUNCTION!!!!
}

void DogHealth::printHeartRateStatistics()
{
	string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	//	string name;
	//	int age;
	//	float weight[MONTHS];
	//	int heartRate[MONTHS];
	cout << "Heart rate"
	for (char i = 0; i < 12; i++) {
		cout << months[i] << ": " << heartRate[i] << "\n";
	}
	cout << flush;
}
