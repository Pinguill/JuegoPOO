#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>
#include <stack>
#include <vector>
#include <map>

#include "SFML\Graphics.hpp"
#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Audio.hpp"

class Entity{
private:
   void initVariables();
protected:
   sf::Texture texture;
   sf::Sprite sprite;
   sf::IntRect currentFrame;
   
   float movementSpeed;
public:
   Entity();
   ~Entity();
   //Component functions
   void createSprite();

   //Functions
   virtual void setPosition(const float x, const float y);
   virtual void move(const float &dt, const float x, const float y);
   virtual void update(const float &dt);
   virtual void render(sf::RenderTarget* target);
};


#endif