all: compile link

compile:
	g++ -I src/include -c main.cpp Game.cpp States/State.cpp States/GameState.cpp States/MainMenu.cpp Entities/Entity.cpp ResourceFiles/Button.cpp

link:
	g++ main.o Game.o State.o GameState.o Button.o MainMenu.o Entity.o -o main -L src/lib -l sfml-graphics -l sfml-window -l sfml-system
