CXXFLAGS += -I ./ -std=c++11


#Builds to pick from:
all		:	release
#Movies.exe : executable
Lab9.exe	:	Lab9.o Random.o
			$(CXX) $(CXXFLAGS) -o Lab9.exe Random.o Lab9.o

#C++ Compiler Flags
release	: CXXFLAGS += -O3
#C Compiler Flags
release : CCFLAGS  += -O3
release	: Lab9.exe

#Debug settings: unused: -fno-access-control -Q
debug : clean
#C++ Compiler Flags
debug	:	CXXFLAGS += -DDEBUG -Wchar-subscripts -pedantic -g -Wmain -Wuninitialized -Wall -Wextra -fexceptions -O
#C Compiler Flags
debug	:	CCFLAGS  += -DDEBUG -Wchar-subscripts -pedantic -g -Wmain -Wuninitialized -Wall -Wextra -fexceptions -O

debug	:	executable



#Cleanup! Deletes old exe and object files
clean	:	#clean up, nothing to build
		del *.o
		del Lab9.exe



#File dependencies and how they are created
#if any of the files listed has been altered since the last compile, generate a new .o file
Random.o	:	Random.cpp
				$(CXX) $(CXXFLAGS) -c Random.cpp

Lab9.o		: Lab9.cpp
				$(CXX) $(CXXFLAGS) -c Lab9.cpp