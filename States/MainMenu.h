#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "GameState.h"


class MainMenu : public State
{
private:
   //Variables
   sf::RectangleShape backgrounnd;


public:
   MainMenu(sf::RenderWindow* window, std::stack<State*>* states);
   virtual ~MainMenu();

   //Functions
   void endState();

   void updateKeybinds(const float &dt);
   void update(const float& dt);
   void render(sf::RenderTarget* target = NULL);
};


#endif