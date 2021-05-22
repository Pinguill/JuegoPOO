#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow* window, std::stack<State*>* states) 
   : State(window, states)
{
   this->backgrounnd.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
   this->backgrounnd.setFillColor(sf::Color::Magenta);
};


MainMenu::~MainMenu()
{
}

// Functions

void MainMenu::endState(){
   std::cout << "Ending game State";
}

void MainMenu::updateKeybinds(const float &dt){
   this->checkForQuit();

}

void MainMenu::update(const float& dt){
   this->updateKeybinds(dt);
   if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
      this->states->push(new GameState(this->window, this->states));
   }
   
}

void MainMenu::render(sf::RenderTarget* target){
   if(!target){
      target = this->window;
   }
   target->draw(this->backgrounnd);
}