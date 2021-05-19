#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

/*
   Class that acts as the game engine
*/
class Game{
private:
   //variables
   //window
   sf::RenderWindow* window;
   sf::Event ev;
   sf::VideoMode videoMode;
   
   // Mouse position
   sf::Vector2i mousePosWindow;
   sf::Vector2f mousePosView;

   //Game Logic
   int exp;
   float enemySpawnTimer;
   float enemySpawnTimerMax;
   int maxEnemies;

   //Game objects
   std::vector<sf::RectangleShape> enemies;
   sf::RectangleShape enemy;


   //Functions
   void initVarible();
   void initWindow();
   void initEnemies();
public:
   //Constructor / Destructor
   Game();
   ~Game();
   // Accessors
   const bool running() const;
   // Functions
   void spawnEnemies();
   void update();
   void updateEnemies();
   void renderEnemies();
   void render();
   void pollEvents();
   void updateMousePosition();
};
#endif