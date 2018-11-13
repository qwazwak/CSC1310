CXXFLAGS += -I ./ -std=c++11


#Builds to pick from:
all		:	release

#C++ Compiler Flags
release	: CXXFLAGS += -O3
#C Compiler Flags
release : CCFLAGS  += -O3
release	: executable

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
		del Lab10.exe


#Movies.exe : executable
executable	:	Driver.o
			$(CXX) $(CXXFLAGS) -o Lab10.exe Driver.o

#File dependencies and how they are created
#if any of the files listed has been altered since the last compile, generate a new .o file
Driver.o	:	Driver.cpp
				$(CXX) $(CXXFLAGS) -c Driver.cpp