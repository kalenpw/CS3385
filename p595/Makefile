all: project

project: main.o bacon.o
	g++ main.o bacon.o -o project

main.o: main.cpp bacon.h Graph.h util.h
	g++ -std=c++0x -c main.cpp

bacon.o: bacon.cpp bacon.h Graph.h util.h
	g++ -std=c++0x -c bacon.cpp

clean:
	rm *.o project
