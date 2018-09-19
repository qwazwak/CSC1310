CPPFLAGS += -I ./ -std=c++98
CXXFLAGS += -I ./ -std=c++11
CCFLAGS += -I ./ -std=c11

all	:	release
Program2 : release

release : CCFLAGS  += -O3
release	: executable


executable : DogHealth.exe

DogHealth.exe	:	Driver.o DogHealth.o
					$(CXX) $(CXXFLAGS) -o DogHealth.exe Driver.o DogHealth.o

Driver.o		:	Driver.cpp
					$(CXX) $(CXXFLAGS) -I ./ -c Driver.cpp

DogHealth.o		:	DogHealth.cpp
					$(CXX) $(CXXFLAGS) -I ./ -c DogHealth.cpp

clean			:	#DogHealth.exe
					del *.o
					del DogHealth.exe
