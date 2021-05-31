#ifndef GAME_H
#define GAME_H

#include "States/MainMenu.h"

class Game{
private:
   //Variables
   sf::RenderWindow *window;
   sf::Event ev;


   sf::Clock dtClock;
   float dt; 

   std::stack<State*> states;
   

   std::map<std::string, int> supportedKeys;

   // Init
   void initWindow();
   void initKeys();
   void initStates();
public:
   // Constructors/Destructors
   Game(/* args */);
   ~Game();

   // Functions
   void endApplication();

   void updateDt();
   void updateSFMLEvents();
   void render();
   void update();
   void run();
};



#endif