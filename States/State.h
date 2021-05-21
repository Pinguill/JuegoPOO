#ifndef STATE_H
#define STATE_H

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


class State{
private:
   sf::RenderWindow* window;
   std::vector<sf::Texture> textures;
   bool quit;

public:
   State( sf::RenderWindow* window) ;
   virtual ~State();

   const bool& getQuit() const;

   virtual void checkForQuit();
   virtual void endState() = 0;
   //Functions
   virtual void updateKeybinds(const float& dt) = 0;
   virtual void update(const float& dt) = 0;
   virtual void render(sf::RenderTarget* target = nullptr) = 0;
};


#endif