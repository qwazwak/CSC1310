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
	cout << "\n";
	string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	int* stupidPointer = new int[MONTHS];
	for (int i = 0; i < MONTHS; i++){
		stupidPointer[i] = weight[i];
	}
	ArrayHelper<int> arrayMeme(stupidPointer, MONTHS);
	cout << "Weight: ";
	cout << "\n" << "\t" << "Maximum: " << stupidPointer[arrayMeme.getMax()] << " in " << months[arrayMeme.getMax()];
	cout << "\n" << "\t" << "Minimum: " << stupidPointer[arrayMeme.getMin()] << " in " << months[arrayMeme.getMin()];
	cout << "\n" << "\t" << "Average: " << static_cast<float>(arrayMeme.getAvg()) << "\n" << flush;
	delete[] stupidPointer;
}

void DogHealth::printHeartRateStatistics()
{
	cout << "\n";
	string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	int* stupidPointer = new int[MONTHS];
	for (int i = 0; i < MONTHS; i++){
		stupidPointer[i] = heartRate[i];
	}
	ArrayHelper<int> arrayMeme(stupidPointer, MONTHS);
	cout << "Heartrate: ";
	cout << "\n" << "\t" << "Maximum: " << stupidPointer[arrayMeme.getMax()] << " in " << months[arrayMeme.getMax()];
	cout << "\n" << "\t" << "Minimum: " << stupidPointer[arrayMeme.getMin()] << " in " << months[arrayMeme.getMin()];
	cout << "\n" << "\t" << "Average: " << static_cast<float>(arrayMeme.getAvg()) << "\n" << flush;
	delete[] stupidPointer;
}
