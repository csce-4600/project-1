all: problem4

problem4: main.o generator.o processor.o
	g++ main.o generator.o processor.o -o problem4

main.o: main.cpp
	g++ -c main.cpp

generator.o: generator.cpp
	g++ -c generator.cpp

processor.o: processor.cpp
	g++ -c processor.cpp

clean:
	rm *o problem4