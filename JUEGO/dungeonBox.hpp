#ifndef DUNGEON_BOX
#define DUNGEON_BOX

#include <iostream>
#include "Entity.hpp"

class DungeonBox{
    private: // // OJOOOO cambiar a private - DEBUG
        class Entity * backgroundEntity;
        class Entity * foregroundEntity;
    public:
        void linkBackground( class Entity * entity );
        void linkForeground( class Entity * entity );
        void unlinkBackground();
        void unlinkForeground();
        class Entity * getFGEntity();
        string getBGName();
        string getBGDescrip();
        bool getBGCollisions();
        bool getFGCollisions();
        class sf::Sprite * getBGSprite();
        class sf::Sprite * getFGSprite();
        string getFGName();
        string getFGDescrip();
};

#endif