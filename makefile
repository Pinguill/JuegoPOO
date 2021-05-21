all: compile link

compile:
	g++ -I src/include -c main.cpp Game.cpp States/State.cpp States/GameState.cpp Entities/Entity.cpp

link:
	g++ main.o Game.o State.o GameState.o Entity.o -o main -L src/lib -l sfml-graphics -l sfml-window -l sfml-system
