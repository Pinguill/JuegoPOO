#include "Game.h"
Game::Game(){
   this->initVarible();
   this->initWindow();
   this->initEnemies();
}

Game::~Game(){
   delete this->window;
}
//Accessors
const bool Game::running() const{
   return this->window->isOpen();
}
//Functions
void Game::spawnEnemies(){
   /*
      @return void

      spwans enemies and sets their colors and positions
      -sets a random position
      -sets a random color.
      -adds enemies to the vector 
   */
   this->enemy.setPosition(
      static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)), 
      0.f);

   this->enemy.setFillColor(sf::Color::Green);

   //Spawn Enemy
   this->enemies.push_back(this->enemy);

   //removes enemies at end of sreen

}

void Game::pollEvents(){
   while (this->window->pollEvent(this->ev)){
      switch (this->ev.type){
         case sf::Event::Closed:
            this->window->close();
            break;
         case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Escape)
               this->window->close();
            break;
      }
   }
   
}

void Game::updateEnemies(){
   /*
      @return void
      Updates the enemy spawn timer and spawns enemies
      when the total amount of enemies is smaller than the maximun
      -Moves the enemies downwards
      -removes the enemies at the edge of the screen.
   */
   // Updating the timer for enemy spawning
   if (this->enemies.size() < this->maxEnemies){
      if (this->enemySpawnTimer >= this->enemySpawnTimerMax){
         //Spawn the enemy and reset the timer
         this->spawnEnemies();
         this->enemySpawnTimer = 0.f;
      }else{
         this->enemySpawnTimer += 1.f;
      }  
   }
   // Moving and updating enemies
   for (int i = 0; i < this->enemies.size(); i++){
      bool deleted = false;

      this->enemies[i].move(0.f, 1.f);
      
      // Check if clicked upon
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
         if (this->enemies[i].getGlobalBounds().contains(this->mousePosView)){
            deleted = true;
         }
      }

      //if the enemy is past the bottom of the screen
      if (this->enemies[i].getPosition().y > this->window->getSize().y){
         deleted = true;
      }

      // final delete
      if (deleted){
         this->enemies.erase(this->enemies.begin() + 1);
      }
   }

   
}

void Game::update(){
   
   this->pollEvents();

   this->updateMousePosition();

   this->updateEnemies();
}
void Game::updateMousePosition(){
   /*
      @ return void
      updates the mouse position:
         -mouse position relative to window (vector2i)
   */

  this->mousePosWindow = sf::Mouse::getPosition(*this->window);
  this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);

}

void Game::renderEnemies(){
   for (auto &e : this->enemies){
      this->window->draw(e);
   }
}

void Game::render(){
   /*
      @return void
      -clear old frame
      -render objects
      -display frame in window

      renders the game objects
   */ 
   this->window->clear();

   //Draw game objects / ALWAYS PUT YOUR OBJECTS BETWEEN THOSE TWO FUNCTIONS
   this->renderEnemies();

   this->window->display();
}


// Private functions
void Game::initVarible(){
   this->window = nullptr;

   //Game logic
   this->exp = 0;
   this->enemySpawnTimerMax = 10.f;
   this->enemySpawnTimer = this->enemySpawnTimerMax;
   this->maxEnemies = 5;
}

void Game::initWindow(){
   this->videoMode.height = 600;
   this->videoMode.width = 800;
   this->window = new sf::RenderWindow(sf::VideoMode(640, 480), "Alanna y los aguacates", sf::Style::Titlebar | sf::Style::Close);
   this->window->setFramerateLimit(60);
}

void Game::initEnemies(){
   this->enemy.setPosition(10.f,10.f);
   this->enemy.setSize(sf::Vector2f(100.f, 100.f));
   this->enemy.setScale(sf::Vector2f(0.5f,0.5f));
   this->enemy.setFillColor(sf::Color::Cyan);
   //this->enemy.setOutlineColor(sf::Color::Green);
   //this->enemy.setOutlineThickness(1.f);
}