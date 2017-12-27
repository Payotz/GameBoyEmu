all: gameboy.o utilities.o main.o
	g++  -o gameboy gameboy.o utilities.o main.o -lSDL2 -lSDL2_mixer

gameboy.o:
	g++ -c -std=c++17 src/gameboy.cpp

utilities.o:
	g++ -c -std=c++17 src/utilities.cpp

main.o:
	g++ -c -std=c++17 src/main.cpp

clean:
	rm *.o