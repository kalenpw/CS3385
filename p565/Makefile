all: project

project: main.o DisjointSet.o bmp.o
	g++ main.o DisjointSet.o bmp.o -o project

main.o: main.cpp DisjointSet.h bmp.h util.h Color.h
	g++ -std=c++0x -c main.cpp

bmp.o: bmp.cpp bmp.h
	g++ -std=c++0x -c bmp.cpp

DisjointSet.o: DisjointSet.cpp DisjointSet.h
	g++ -std=c++0x -c DisjointSet.cpp

clean:
	rm *.o project
