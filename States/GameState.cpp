#include "GameState.h"

GameState::GameState(sf::RenderWindow* window) 
   : State(window)
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
   this->player.render(this->window);
}