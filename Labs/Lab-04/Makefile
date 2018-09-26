all				:	Moonpie

Moonpie			:	Moonpie.o
					g++ Moonpie.o -o Moonpie.exe

#if any of the files listed has been altered since the last compile, generate a new .o file
Moonpie.o		:	moonpie.cpp
					g++ -c moonpie.cpp

clean			:	Moonpie.exe
					delete *.o
					delete Moonpie.exe
