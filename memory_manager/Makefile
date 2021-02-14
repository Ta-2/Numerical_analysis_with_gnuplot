main: MemoryManager.o main.o
	g++ -Wall -g -o main main.o MemoryManager.o

main.o: main.cpp
	g++ -Wall -c main.cpp

MemoryManager.o: MemoryManager.cpp
	g++ -Wall -c MemoryManager.cpp -lMemoryManager.hpp

clean:
	rm *.exe main *.gch *.o *.out

all:
	touch main.cpp MemoryManager.cpp MemoryManager.hpp
	main
