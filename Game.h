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
   

   // Init
   void initWindow();
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