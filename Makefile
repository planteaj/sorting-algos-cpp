   all: main

main: main.o sorting.o
	g++ main.o sorting.o -o main

main.o: main.cpp
	g++ -c main.cpp

sorting.o: sorting.cpp
	g++ -c sorting.cpp

clean:
	rm main.o sorting.o main
