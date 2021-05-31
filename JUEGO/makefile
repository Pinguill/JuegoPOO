all: Programm

# Agregar View AQUIIIIIII
Programm: Entity DungeonBox Dungeon Logic View Main
	g++ -o game main.o view.o logicController.o dungeon.o dungeonBox.o Entity.o -DSFML_STATIC -I C:\SFML-2.5.1-sources\SFML\include -L C:\SFML-2.5.1-sources\SFML\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype

Main: main.cpp view.hpp logicController.hpp Entity.hpp
	g++ -c main.cpp -DSFML_STATIC -I C:\SFML-2.5.1-sources\SFML\include -L C:\SFML-2.5.1-sources\SFML\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype

View: view.cpp view.hpp logicController.hpp Entity.hpp
	g++ -c view.cpp -DSFML_STATIC -I C:\SFML-2.5.1-sources\SFML\include -L C:\SFML-2.5.1-sources\SFML\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype

Logic: logicController.cpp logicController.hpp Entity.hpp
	g++ -c logicController.cpp -DSFML_STATIC -I C:\SFML-2.5.1-sources\SFML\include -L C:\SFML-2.5.1-sources\SFML\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype

Dungeon: dungeon.cpp dungeon.hpp dungeonBox.hpp
	g++ -c dungeon.cpp -DSFML_STATIC -I C:\SFML-2.5.1-sources\SFML\include -L C:\SFML-2.5.1-sources\SFML\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype

DungeonBox: dungeonBox.cpp dungeonBox.hpp Entity.hpp
	g++ -c dungeonBox.cpp -DSFML_STATIC -I C:\SFML-2.5.1-sources\SFML\include -L C:\SFML-2.5.1-sources\SFML\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype

Entity: Entity.cpp Entity.hpp
	g++ -c Entity.cpp -DSFML_STATIC -I C:\SFML-2.5.1-sources\SFML\include -L C:\SFML-2.5.1-sources\SFML\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype