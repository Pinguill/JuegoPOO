#include "GameState.h"
//Init Functions
void GameState::initKeybinds(){
   std::ifstream ifs("config/gameState_keybinds.ini");

   if(!ifs){
      throw"ERROR::GAME::FAILED_TO_LOAD_GAMESTATE_KEYBINDS";
   }


   if(ifs.is_open()){
      std::string key = "";
      std::string key2 = "";
      while (ifs >> key >> key2){
         std::cout<< key<< " " << key2<< "\n";
         this->keybinds[key] = this->supportedKeys->at(key2);
      }
   }
   ifs.close();
}

void GameState::initTextures(){
   this->player->render(this->window);
   
}


GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states) 
   : State(window, supportedKeys, states)
{
   this->initKeybinds();
   std::cout << "antes de initTex\n";
   this->initTextures();
}


GameState::~GameState()
{
   delete this->player;
}

// Functions


void GameState::updateInput(const float &dt){
   //Update player input
   if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT")))){
      this->player->move(dt, -1.f, 0.f);
   }if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT")))){
      this->player->move(dt, 1.f, 0.f);
   }if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP")))){
      this->player->move(dt, 0.f, -1.f);
   }if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN")))){
      this->player->move(dt, 0.f, 1.f);
   }if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE")))){
      this->endState();
   }
}

void GameState::update(const float& dt){
   this->updateInput(dt);
   this->updateMousePositions();

   this->player->update(dt);
   
}

void GameState::render(sf::RenderTarget* target){
   if(!target){
      target = this->window;
   }
   this->player->render(target);
}