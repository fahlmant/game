all: build

build: main.o
	g++ main.o -o game -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf main.o game 

