CPPFLAGS += -I ./ -std=c++98
CXXFLAGS += -I ./ -std=c++98
CCFLAGS += -I ./ -std=c98

#Builds to pick from:
all		:	release
#Movies.exe : executable
Zoo.exe	:	Zoo.o Creature.o
			$(CXX) $(CXXFLAGS) -o Zoo.exe Zoo.o Creature.o

#C++ Compiler Flags
release	: CXXFLAGS += -O3
#C Compiler Flags
release : CCFLAGS  += -O3
release	: Zoo.exe

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
		del Zoo.exe



#File dependencies and how they are created
#if any of the files listed has been altered since the last compile, generate a new .o file
Creature.o	:	Creature.cpp
				$(CXX) $(CXXFLAGS) -c Creature.cpp

Zoo.o		: Zoo.cpp
				$(CXX) $(CXXFLAGS) -c Zoo.cpp