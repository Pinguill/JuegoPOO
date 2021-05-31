#include <iostream>
#include "view.hpp"
#include "logicController.hpp"
#include "Entity.hpp"

sf::Mutex mutex;

int main(){
   View view;
   view.setViewMutex( &mutex );
   view.setLogicMutex( &mutex );
   view.launchLogic();
   sf::sleep( sf::seconds( 1.f ) );
   view.display();
   return 0;
}