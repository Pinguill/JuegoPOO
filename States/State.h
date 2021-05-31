#ifndef STATE_H
#define STATE_H

#include "../Entities/Entity.h"


class State{
private:
   
protected:
   sf::RenderWindow* window;

   std::map<std::string, int>* supportedKeys;
   std::map<std::string, int> keybinds;
   std::stack<State*>* states; 
   
   sf::Texture textureSheet;
   bool quit;

   sf::Vector2i mousePosScreen;
   sf::Vector2i mousePosWindow;
   sf::Vector2f mousePosView;

   //Functions
   virtual void initKeybinds() = 0;
   
public:
   State( sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states) ;
   virtual ~State();

   const bool& getQuit() const;

   void endState();
   //Functions
   virtual void updateMousePositions();
   virtual void updateInput(const float& dt) = 0;
   virtual void update(const float& dt) = 0;
   virtual void render(sf::RenderTarget* target = NULL) = 0;
};


#endif