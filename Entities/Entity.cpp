#include "Entity.h"

//Init Functions
void Entity::initVariables(){
   this->movementSpeed = 100.f;
}

Entity::Entity()
{
   this->initVariables();
   this->createSprite();
}

Entity::~Entity()
{
}

//Component functions
void Entity::createSprite(){
   if(!this->texture.loadFromFile("Resource/Sprites/Player/warrior.png")){
      std::cout << "Hola\n";
   }
   this->sprite.setTexture(this->texture);
   std::cout << "after setTex\n";
   this->currentFrame = sf::IntRect(0, 0, 50, 50);
   this->sprite.setTextureRect(this->currentFrame);
}

//Functions
void Entity::setPosition(const float x, const float y){  
   this->sprite.setPosition(x, y);
}

void Entity::move(const float &dt, const float dir_x, const float dir_y){
   
   this->sprite.move(dir_x * this->movementSpeed * dt,dir_y * this->movementSpeed * dt);
}

void Entity::update(const float &dt){
   
}

void Entity::render(sf::RenderTarget * target){
   target->draw(this->sprite);
}
