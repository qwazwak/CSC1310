CXXFLAGS += -I ./ -std=c++98
CCFLAGS += -I ./ -std=c98

#Builds to pick from:
all		:	release
executable	:	TextDriver.o Text.o
			$(CXX) -o Lab-02.exe TextDriver.o Text.o

#C++ Compiler Flags
release	: CXXFLAGS += -03
#C Compiler Flags
release : CCFLAGS  += -O3

release	: executable

#Debug settings:

#C and C++ Preprocessor flags
#debug	:	CPPFLAGS +=
#C++ Compiler Flags
debug	:	CXXFLAGS += -DDEBUG -g -fno-access-control -pedantic -Wchar-subscripts -Wmain -Wuninitialized -Wall -Wextra -g -Q -O -fexceptions
#C Compiler Flags
debug	:	CCFLAGS  += -DDEBUG -g -fno-access-control -pedantic -Wchar-subscripts -Wmain -Wuninitialized -Wall -Wextra -g -Q -O -fexceptions

debug	:	executable



#Cleanup! Deletes old exe and object files
clean	:	Lab-02.exe
		del *.o
		del Lab-02.exe




#File dependencies and how they are created
#if any of the files listed has been altered since the last compile, generate a new .o file
TextDriver.o	:	TextDriver.cpp
				$(CXX) -c TextDriver.cpp


Text.o	:	Text.cpp
				$(CXX) -c Text.cpp
