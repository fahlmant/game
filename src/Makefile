all: build

build: main.o bat.o ball.o
	g++ main.o bat.o ball.o -o game -lsfml-graphics -lsfml-window -lsfml-system

ball.o: ball.cpp
	g++ -c ball.cpp

bat.o: bat.cpp
	g++ -c bat.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf *.o game 

