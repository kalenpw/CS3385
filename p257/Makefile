all: project

project: main.o
	g++ main.o -o project

main.o: main.cpp util.h hash.h Person.h LinkedList.h HashTable.h
	g++ -std=c++0x -c main.cpp

clean:
	rm *.o project
