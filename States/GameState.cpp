#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states) 
   : State(window, states)
{

}


GameState::~GameState()
{
}

// Functions

void GameState::endState(){
   std::cout << "Ending game State";
}

void GameState::updateKeybinds(const float &dt){
   this->checkForQuit();

}

void GameState::update(const float& dt){
   this->updateKeybinds(dt);

   this->player.update(dt);
   
}

void GameState::render(sf::RenderTarget* target){
   if(!target){
      target = this->window;
   }
   this->player.render(target);
}