/*
	Driver for Custom Text Structure
	LAB 1 - CSC1310
	April Crockett
	8/8/2018
*/

#include "Text.h"
#include <iostream>

using namespace std;

int main () {
	Text *myString1;
	Text *myString2;
	char tvshow[1000];
	char movie[1000];

	cout << "\n\nWhat is the most recent TV show you watched?\n";
	cin.getline(tvshow, 1000);
	myString1 = createText(tvshow);

	cout << "\nWhat is the most recent Movie you watched?\n";
	cin.getline(movie, 1000);
	myString2 = createText(movie);

	cout << "\n\nTV SHOW:\t";
	displayText(myString1);
	cout << "\t# CHARACTERS:\t" << getLength(myString1) << endl;

	cout << "\nMOVIE:\t\t";
	displayText(myString2);
	cout << "\t# CHARACTERS:\t" << getLength(myString2) << endl;

	destroyText(myString1);
	destroyText(myString2);

	return 0;
}
/*

	Created by Rus Hoffman
*/

//#include <getopt.h> //getopt.h is required for the getopt function

//#include <fstream>
//#include <cmath>
//#include <algorithm>
//#include <iterator>
//#include <random>
//#include <string> //Real strings
//#include <cstdlib>


//#include <cstdint>
//#include <quadmath.h> //required for the boost float 128
//#include <boost/multiprecision/float128.hpp>
//#include <boost/multiprecision/cpp_int.hpp>


//#include <ctime>
//#include <chrono>
//#include <quadmath.h>
//Needed for more than just float128


//#include <boost/multiprecision/cpp_int.hpp>
/*
	// Fixed precision unsigned inegers:
		boost::multiprecision::cpp_int::uint128_t
		boost::multiprecision::cpp_int::uint256_t
		boost::multiprecision::cpp_int::uint512_t
		boost::multiprecision::cpp_int::uint1024_t
	// Fixed precision signed inegers:
		boost::multiprecision::cpp_int::int128_t
		boost::multiprecision::cpp_int::int256_t
		boost::multiprecision::cpp_int::int512_t
		boost::multiprecision::cpp_int::int1024_t
*/


//#include <boost\multiprecision\float128.hpp>
/*
	boost::multiprecision::float128 variableName;
*/


//#include <vector>
/*
		Vectors:
		ONE DATA TYPE
		Varibale size

		format:
			vector <DATA TYPE HERE> VARIABLE NAME; //initial zero sized
			vector <DATA TYPE HERE> VARIABLE NAME (INITIALSIZE); //sized with INITIALSIZE size
			vector <DATA TYPE HERE> VARIABLE NAME (INITIALSIZE, OGVARIABLE); //all vals are OGVARIABLE at first
			vector <DATA TYPE HERE> VARIABLE NAME (anothervectorname); //othervectorname is copyed to the new one

		Access/assign:
			myvector[i]



		VECTORNAME.push_back(NUMBER)
			puts somthing at the end of a vector
		VECTORNAME.clear()
			clears vector
		VECTORNAME.size()
			gets size
		VECTORNAME.empty()
			If empty returns a one/true
		VECTORNAME.at(i)
			returns value of ith entry
		VECTORNAME.capacity()
			current max size
		VECTORNAME.reverse()
			reverse orders entries
		VECTORNAME.resize (i, val)
			adds I spaces to vector, and optinally initialzes to val
		VECTORNAME.swap(OTHERVECTORNAME);
			swaps two vectors contents
*/


//#include <windows.h>
/*
	LPCWSTR FOOBARDIRECTERY = L"c:\testdir";
	CreateDirectory(FOOBARDIRECTERY, NULL)
	CreateDirectory("output", NULL);
*/


//#include <ctime>
/*
	http://www.cplusplus.com/reference/ctime/

	Macro:
		CLOCKS_PER_SEC

	seconds = clock() / CLOCKS_PER_SEC

	unsigned int start = clock();
	cout << "waiting for keyhit";
	cin.ignore();
	cout << "Time taken in millisecs: " << clock()-start;
*/


//#include <random>
//All of this library is c++11 and requires compiler support
/*
	C++11
	random_device FOOBARNAMEME;
	cout << "Minumum: " << FOOBARNAMEME.min() << endl;
	cout << "Maximum: " << FOOBARNAMEME.max() << endl;
	cout << "Entropy: " << FOOBARNAMEME.entropy() << endl;
	This is real random. Only use it to seed a pseduo random generator - SEE cstdlib and rand()




		random_device rd; //call random numbers with rd()
		int seed = rd() * clock()
		mt19937_64 generator(seed);  // mt19937 is a standard mersenne_twister_engine
		srand(seed);
		Call randoms with generator() or rand()

		cout << "Seed: " << seed << endl;
		cout << "Minimum: " << rd.min() << endl;
		cout << "Maximum: " << rd.max() << endl;
		cout << "Entropy: " << rd.entropy() << endl;
		cout << "setup done" << endl;
*/


//#include <cstdint>
//All of this library is c++11 and requires compiler support
/*
	C++11
	What it adds:
		Signed maximum width integer type
			intmax_t
		Maximum width unsigned integer type
			uintmax_t

		Integer with width of exactly 8, 16, 32 and 64 bits respectively with no padding bits and using 2's complement for negative values
		(provided only if the implementation directly supports the type)
			Signed:
				int8_t
				int16_t
				int32_t
				int64_t
			Unsigned:
				uint8_t
				uint16_t
				uint32_t
				uint64_t

		Fastest integer type with width of at least 8, 16, 32 and 64 bits respectively
			Signed:
				int_fast8_t
				int_fast16_t
				int_fast32_t
				int_fast64_t
			Unsigned:
				uint_fast8_t
				uint_fast16_t
				uint_fast32_t
				uint_fast64_t

		Smallest integer type with width of at least 8, 16, 32 and 64 bits respectively
			Signed:
				int_least8_t
				int_least16_t
				int_least32_t
				int_least64_t
			Unsigned:
				uint_least8_t
				uint_least16_t
				uint_least32_t
				uint_least64_t

		Constants: (max value)
			INTMAX_MAX
			INT8_MAX
			INT16_MAX
			INT32_MAX
			INT64_MAX
			INT_FAST8_MAX
			INT_FAST16_MAX
			INT_FAST32_MAX
			INT_FAST64_MAX
			INT_LEAST8_MAX
			INT_LEAST16_MAX
			INT_LEAST32_MAX
			INT_LEAST64_MAX
*/


//#include <cstdlib>
/*
	Quicksort:
		qsort (SOURCEARRAY, NumberOfElements, SizeOfEachElementInBytes/sizeof(int), compareMyType);

		Outside main you must make a fucnction that quicksort references when checking how things are related
			prototype
				int compar (const void* p1, const void* p2);
			Actuall function:
				int compareMyType (const void * a, const void * b){
					if( *(MyType*)a <  *(MyType*)b ){
						return -1;
					}
					if( *(MyType*)a == *(MyType*)b ){
						return 0;
					}
					if( *(MyType*)a >  *(MyType*)b ){
						return 1;
					}
				}
			What returns do:
				<0	p1 goes before p2
				0	p1 is the same as p2
				>0	p1 goes after p2

		The actual call to quicksort:
			qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*));
				Parameters
					base
						Pointer to the first object of the array to be sorted, converted to a void*.
					num
						Number of elements in the array pointed to by base.
						size_t is an unsigned integral type.
					size
						Size bytes of each element in the array.
						size_t is an unsigned integral type.
					compar
						Pointer to a function that compares two elements.
						This function is called repeatedly by qsort to compare two elements. It shall follow the following prototype:


	random:
		srand(SEEDGOESHERE);
			seed sources:
				time(NULL)

				if c++ 11 is avalible use a real random generator to seed
		rand() to generate random numbers


	String to XXX Conversions:
		To use these the format is VARIABLEWITHTARGETTYPE = functionName(SOURCEVARIABLE)
			atof
				Convert string to double (function )
			atoi
				Convert string to integer (function )
			atol
				Convert string to long integer (function )
			atoll
				C++11
				Convert string to long long integer (function )
			strtod
				Convert string to double (function )
			strtof
				C++11
				Convert string to float (function )
			strtol
				Convert string to long integer (function )
			strtold
				C++11
				Convert string to long double (function )
			strtoll
				C++11
				Convert string to long long integer (function )
			strtoul
				Convert string to unsigned long integer (function )
			strtoull
				C++11
				Convert string to unsigned long long integer (function )
*/


//#include <time.h>
/*
	Has more, all I use is:
	VARIABLE = time(NULL);
*/


//#include <iostream>
/*
	system("pause")
		Enter any key to continue..
	cout << "" << endl;
		output things
	cin >> VARNAME;
		Bring in numbers
	cin.get(VARNAME);
		Single Char
	getline(cin, VARNAME);
		get a line
*/


//#include <iomanip>
/*
	Manipulates input and output
	cout << setprecision(2) << fixed << showpoint;
	cout << minumum decimal points(VARIABLE OR NUMBER) << cutoff decimal points? << show decimal point always;
*/


//#include <fstream>
/* i/ofstream info
	(i or o)fstream FILEIDENT;
	FILEIDENT.open("FILENAME.txt");
	FILEIDENT << VARIABLE << endl;
	FILEIDENT.close();

	General:
		foobar_recognizablename.open(stringVariableName.c_str());



		bar_recognizablename.open("foo/bar_Input.txt");
			Will open file for reading, file must exist to work
		foo_recognizablename.open("bar/foo_Output.txt");
			Will create file, if it already exists it will be deleted and overwritten
		if(!bar_recognizablename){HAPPENS IF ERROR}
			For input validation, you can use infile.fail()

		Closing files:
			bar_recognizablename.close();
			foo_recognizablename.close();
	Input:
		bar_recognizablename >> myVariable;
			Can be used for boolean.. [foo/bar_Input >> myVariable] returns true when it works


	Output:
		foo_recognizablename << "Thing happened" << endl;


	if(!IDENFIFIERWHATEVERYOUWANT){
		happens if it didnt open correctly
	}
*/


//#include <string>
/*
	real strings
	cstringvariable = stringVariableName.c_str();

	StringVariableFooBarWhatever = to_string(IntOrFloatOrWhateverBaZZ);



	Convert from number to string:
		ALL C++11
			to_string
				Convert numerical value to string (function )
			to_wstring
				Convert numerical value to wide string (function )
	Convert from string to number:
		ALL C++11
			stoi
				Convert string to integer (function template )
			stol
				Convert string to long int (function template )
			stoul
				Convert string to unsigned integer (function template )
			stoll
				Convert string to long long (function template )
			stoull
				Convert string to unsigned long long (function template )
			stof
				Convert string to float (function template )
			stod
				Convert string to double (function template )
			stold
				Convert string to long double (function template )
*/


//#include <cmath>
//Some parts of this library have C++11 requirments
/*
	Functions:
		Trigonometric functions:
				cos(InputFoo)
				sin(InputFoo)
				tan(InputFoo)
		ArcTrigonometric functions:
				acos(InputFoo)
				asin(InputFoo)
				atan(InputFoo)

		Hyperbolic functions:
			cosh(InputFoo)
			sinh(InputFoo)
			tanh(InputFoo)
		Area Hyperbolic functions:
			acosh(InputFoo)
				REQUIRES C++11
			asinh(InputFoo)
				REQUIRES C++11
			atanh(InputFoo)
				REQUIRES C++11

		Exponential and logarithmic functions
			log(InputFoo)
				Compute natural logarithm (function)
			log10(InputFoo)
				Compute common logarithm (function)

		Power functions
			pow(InputBase, InputPower)
				Raise to power (function)
			sqrt(InputFoo)
				Compute square root (function)
			cbrt(InputFoo)
				REQUIRES C++11
				Compute cubic root (function)
			hypot(InputA, InputB)
				REQUIRES C++11
				Compute hypotenuse (function)

		Rounding and remainder functions
			remainder(numerator, denominator);
				REQUIRES C++11
				Gives floating point remainder
			ceil(InputFoo)
				Round up value (function)
			floor(InputFoo)
				Round down value (function)
			fmod(numerator, denominator)
				Compute remainder of division (function)
			trunc(InputFoo)
				REQUIRES C++11
				Truncate value  IE rounds towards zero (function)
			round(InputFoo)
				REQUIRES C++11
				Round to nearest (function)
			lround(InputFoo)
				REQUIRES C++11
				Round to nearest and cast to long integer (function)
			llround(InputFoo)
				REQUIRES C++11
				Round to nearest and cast to long long integer (function)
			rint(InputFoo)
				REQUIRES C++11
				Round to integral value (function)
			lrint(InputFoo)
				REQUIRES C++11
				Round and cast to long integer (function)
			llrint(InputFoo)
				REQUIRES C++11
				Round and cast to long long integer (function)
			nearbyint(InputFoo)
				REQUIRES C++11
				Round to nearby integral value (function)

		Floating-point manipulation functions
			copysign(InputMagnitude, InputSign)
				REQUIRES C++11
				Copy sign (function)

		Other functions
			fabs(InputFoo)
				Compute absolute value, floating point only (function)
			abs(InputFoo)
				Compute absolute value, int or floating point (function)
*/


using namespace std;

enum bombNearbyTextures {
	none = 0,
	one,
	BOMBNEAR_TWO,
	BOMBNEAR_THREE,
	BOMBNEAR_FOUR,
	BOMBNEAR_FIVE,
	BOMBNEAR_SIX,
	BOMBNEAR_SEVEN,
	BOMBNEAR_EIGHT,
	BOMBNEAR_TOTAL
};

int main (int argc, char* argv[]){
	//Variable creation
		//very special variables
			const string programName = "Portable Number Visualizer";
			const string helpInfoText =
							"Portable Ilam Spiral Generator Help and Info:" "\n"
								"\n"
								"Main use:" "\n"
								"\t" "Just start the program," "\n"
								"\t" "arguments are optional ways of speeding up startup/setup" "\n"

								"Arguments:" "\n"
								"-c" "\n"
								"\t" "Forces console input and output" "\n"
								"-h" "\n"
								"\t" "Opens this help menu" "\n"
								"-f XXXXXXXX" "\n"
								"\t" "Specify the output file name" "\n"
								"-r XXXXXXXX" "\n"
								"\t" "Specifies minimum output resolution" "\n"
								"-m XXXXXXXX" "\n"
								"\t" "Specifies minimum maximum number to include" "\n"
								"-d" "\n"
								"\t" "Enables debug and if display" "\n";


		//bools for settings and Things

		//Output file info
			//unsigned char primeRgbColor[3];
			//unsigned char compositeRgbColor[3];
			string outputFileName = "";
		//variables created here are used all over


			uint_fast64_t edgeResolution = 128;
			uint_fast64_t numberOfNumbers = edgeResolution * edgeResolution;


		//UI Things


	#if defined(DEBUG)
		cout << "main variables created" << endl;
	#endif
	if (argc > 1) {//Argument Parsing:
		for (size_t argumentIDCycler = 0; argumentIDCycler < static_cast<size_t>(argc); argumentIDCycler++) {
			if (strcmp(argv[argumentIDCycler], "c") == 0) {
				tinyfd_forceConsole = 1;
				break;
			}
		}
		bool continueLoading = true;
		uint_fast64_t possibleEdgeResolution = 0;
		#if defined(DEBUG)
			cout << "Parsing arguments" << endl;
		#endif
		extern char *optarg;
		char argSwitcher;
		do {
			//Argument meanings:
			// c force console mode
			// h show help
			// f: output file name
			// r: resolution
			// m: minimum max number to use
			// d enable debug
			argSwitcher = getopt(argc, argv, "chf:r:m:d");
			if (argSwitcher == -1) {
				continueLoading = false;
				#if defined(DEBUG)
					cout << "Done parsing arguments" << endl;
				#endif
				break;
			}
			else {
				#if defined(DEBUG)
					cout << "Processing the '" << argSwitcher << "' argument" << endl;
				#endif
				switch (argSwitcher) {
					case 's':
						isShaded = true;
						break;
					case 'c':
						tinyfd_forceConsole = 1;
						break;
					case 'h':
						break;
					case '?':
					default:
						cout << endl << "Invalid argument: " << optarg << "Exiting Program" << endl;
						return EXIT_FAILURE;
						break;
				}
			}
		} while (continueLoading == true);
	}//End argument parsing
	const long NAMESPACEBUFFER = 3;
	char filename[255];
	//Verify Input
		if (argc != 3) {
			cout << "Ivalid argument count" << endl;
			cout << "To use this program you must specify the grades file and curve value" << endl;
			cout << "ex: " << argv[0] << " gradesFile.txt 75" << endl;
			return 0;
		}
		{
			strcpy(filename, argv[1]);
			char tempHolder;
			ifstream inputTester;
			inputTester.open(filename);
			inputTester >> tempHolder;
			while (inputTester.fail()) {
				inputTester.close();
				cout << "Error, File name is invalid" << endl;
				cout << "Enter a new file name: ";
				cin >> filename;
				while(cin.fail()){
				cin.clear();
					cin.ignore();
					cout << "Enter a new file name: ";
					cin >> filename;
				}
				inputTester.open(filename);
				inputTester >> tempHolder;
				inputTester.close();
			}
			inputTester.close();
		}
	//Input is now validated






	//Only the loader student needs manual deallocation. classDatabase has a deconstructor
	delete[] ALLOCATEDARRAY;
	return 0;
}
