all: build

build: main.o Game.o MenuState.o
	g++ main.o Game.o MenuState.o -o generic-game -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c -fpermissive main.cpp

Game.o: Game.cpp
	g++ -c Game.cpp

MenuState.o: MenuState.cpp
	g++ -c MenuState.cpp

clean:
	rm -rf *.o game 

