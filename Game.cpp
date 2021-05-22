#include "Game.h"

//Init
void Game::initWindow(){
   std::ifstream ifs("config/window,ini");
   
   std::string title = "None";
   sf::VideoMode window_bounds(800, 600);
   unsigned framerate_limit = 60;
   bool vertical_sync_enable  = false;
   if(ifs.is_open()){
      std::getline(ifs, title);
      ifs >> window_bounds.width >> window_bounds.height;
      ifs >> framerate_limit;
      ifs >> vertical_sync_enable;
   }

   ifs.close();
   
   this->window = new sf::RenderWindow(window_bounds, title);
   this->window->setFramerateLimit(framerate_limit);
   this->window->setVerticalSyncEnabled(vertical_sync_enable);
}

void Game::initStates(){
   this->states.push(new MainMenu(this->window, &this->states ));
}

// Constructors/Destructors
Game::Game(){
   this->initWindow();
   this->initStates();
}

Game::~Game(){
   delete this->window;
   while (this->states.empty()){
      delete this->states.top();
      this->states.pop();
   }
   
}

void Game::updateDt(){
   //Updates the dt variable with the time it takes to update and render one frame
   this->dt = this->dtClock.restart().asSeconds();
}

//Functions
void Game::endApplication(){
   std::cout << "Close application";
}

void Game::updateSFMLEvents(){
   while (this->window->pollEvent(this->ev)){
      if(this->ev.type == sf::Event::Closed){
         this->window->close();
      }
   }
   
}

void Game::update(){

   this->updateSFMLEvents();

   if(!this->states.empty()){
      this->states.top()->update(this->dt);
      if(this->states.top()->getQuit()){
         this->states.top()->endState();
         delete this->states.top();
         this->states.pop();
      }
   }else{
      this->endApplication();
      this->window->close();
   }

}

void Game::render(){

   this->window->clear();

   //Render items
   if(!this->states.empty()){
      this->states.top()->render();
   }

   this->window->display();
}

void Game::run(){
   while (this->window->isOpen()){
      this->updateDt();
      this->update();
      this->render();
   }
   
}
