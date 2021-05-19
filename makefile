all: compile link

compile:
	g++ -I src/include -c main.cpp Game.cpp

link:
	g++ main.o Game.o -o main -L src/lib -l sfml-graphics -l sfml-window -l sfml-system