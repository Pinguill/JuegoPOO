#include "dungeonBox.hpp"

void DungeonBox::linkBackground( class Entity * entity ){
    this->backgroundEntity = entity;
}

void DungeonBox::linkForeground( class Entity * entity ){
    this->foregroundEntity = entity;
}

void DungeonBox::unlinkBackground(){
    this->backgroundEntity = nullptr;
}

void DungeonBox::unlinkForeground(){
    this->foregroundEntity = nullptr;
}

class Entity * DungeonBox::getFGEntity(){
    return this->foregroundEntity;
}

string DungeonBox::getBGName(){
    return this->backgroundEntity->getEntityName();
}

string DungeonBox::getBGDescrip(){
    return this->backgroundEntity->getEntityDescrip();
}

bool DungeonBox::getBGCollisions(){
    return this->backgroundEntity->getCollisions();
}

bool DungeonBox::getFGCollisions(){
    return this->foregroundEntity->getCollisions();
}

class sf::Sprite * DungeonBox::getBGSprite(){
    return this->backgroundEntity->getSprite();
}

class sf::Sprite * DungeonBox::getFGSprite(){
    return this->foregroundEntity->getSprite();
}

string DungeonBox::getFGName(){
    return this->foregroundEntity->getEntityName();
}

string DungeonBox::getFGDescrip(){
    return this->foregroundEntity->getEntityDescrip();
}