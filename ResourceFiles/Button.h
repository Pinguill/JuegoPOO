#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>


#include "SFML\Graphics.hpp"
#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Audio.hpp"

class Button
{
private:
   sf::RectangleShape r;
   std::string id;
public:
   Button(std::string identidad, sf::RectangleShape rect ){
      id = identidad;
      r = rect;
   }
   ~Button();
};



#endif