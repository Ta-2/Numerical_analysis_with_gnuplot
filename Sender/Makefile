main: sender.o main.o
	g++ -Wall -o main main.o sender.o

main.o: main.cpp
	g++ -Wall -c main.cpp

sender.o: sender.cpp
	g++ -Wall -c sender.cpp

clean:
	rm *.exe main *.gch *.o
all:
	main
