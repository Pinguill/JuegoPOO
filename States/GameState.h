#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "State.h"

class GameState: public State{
private:
   Entity player;
public:
   GameState(sf::RenderWindow* window);
   virtual ~GameState();

   //Functions
   void endState();

   void updateKeybinds(const float &dt);
   void update(const float& dt);
   void render(sf::RenderTarget* target = NULL);
};


#endif