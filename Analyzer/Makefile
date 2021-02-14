main: Analyzer.o main.o
	g++ -Wall -g -o main main.o Analyzer.o

main.o: main.cpp
	g++ -Wall -c main.cpp

Analyzer.o: Analyzer.cpp
	g++ -Wall -c Analyzer.cpp -lAnalyzer.hpp

clean:
	rm *.exe main *.gch *.o *.out
	
all:
	touch main.cpp Analyzer.cpp Analyzer.hpp
	main
