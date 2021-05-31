#ifndef VIEW
#define VIEW

#include <iostream>
#include <SFML/Graphics.hpp>
#include "logicController.hpp"

class View{
   private:
      class LogicController logicController;
      class sf::View gameView;
      class sf::RenderWindow gameWindow;
      class sf::Event appEvent;
      sf::Mutex * mutex;
   public:
      View();
      void setViewMutex( sf::Mutex * mutex );
      void setLogicMutex( sf::Mutex * mutex );
      void lockMutex();
      void unlockMutex();
      void drawBackground();
      void drawForeground();
      void drawHerz();
      void display();
      void launchLogic();
};

#endif