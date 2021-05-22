#ifndef STATE_H
#define STATE_H

#include "../Entities/Entity.h"


class State{
private:

protected:
   std::stack<State*>* states; 
   sf::RenderWindow* window;
   std::vector<sf::Texture> textures;
   bool quit;
public:
   State( sf::RenderWindow* window, std::stack<State*>* states) ;
   virtual ~State();

   const bool& getQuit() const;

   virtual void checkForQuit();
   virtual void endState() = 0;
   //Functions
   virtual void updateKeybinds(const float& dt) = 0;
   virtual void update(const float& dt) = 0;
   virtual void render(sf::RenderTarget* target = NULL) = 0;
};


#endif