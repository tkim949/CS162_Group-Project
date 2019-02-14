main: main.o Game.o GBoard.o Critter.o Ant.o DoodleBug.o inputVal.o
	g++ -std=c++0x main.o Game.o GBoard.o Critter.o Ant.o DoodleBug.o inputVal.o -o main
	
main.o: main.cpp
	g++ -std=c++0x -c main.cpp
	
Game.o: Game.cpp Game.h
	g++ -std=c++0x -c Game.cpp
	
GBoard.o: GBoard.cpp GBoard.h
	g++ -std=c++0x -c GBoard.cpp
	
Critter.o: Critter.cpp Critter.h
	g++ -std=c++0x -c Critter.cpp	
	
Ant.o: Ant.cpp Ant.h
	g++ -std=c++0x -c Ant.cpp	
	
DoodleBug.o: DoodleBug.cpp DoodleBug.h
	g++ -std=c++0x -c DoodleBug.cpp	
	
inputVal.o: inputVal.cpp inputVal.h
	g++ -std=c++0x -c inputVal.cpp

.PHONY: clean

clean:
	rm *.o main
	
valgrind:
	@valgrind --leak-check=full --track-origins=yes ./main