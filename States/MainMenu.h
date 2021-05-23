#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "GameState.h"
#include "../ResourceFiles/Button.h"

class MainMenu : public State
{
private:
   //Variables
   sf::Texture backgroundTexture;
   sf::RectangleShape backgrounnd;
   sf::Font font;

   std::map<std::string, Button*> buttons;
   //Functions
   void initVariables();
   void initBackGround();
   void initFonts();
   void initBottons();

   
public:
   MainMenu(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
   virtual ~MainMenu();

   //Functions
   void endState();

   void updateInput(const float &dt);
   void updateButtons();
   void update(const float& dt);
   void renderButtons(sf::RenderTarget* target = NULL);
   void render(sf::RenderTarget* target = NULL);
};


#endif