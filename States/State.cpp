#include "State.h"

State::State(sf::RenderWindow* window, std::stack<State*>* states  ){
   this->window = window;
   this->states = states;
   this->quit = false;
}

State::~State(){

}

const bool& State::getQuit() const{
   return this->quit;
}

void State::checkForQuit(){
   if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
      this->quit = true;
   }
}