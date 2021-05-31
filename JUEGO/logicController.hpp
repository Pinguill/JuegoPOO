#ifndef LOGIC_CONTROLLER
#define LOGIC_CONTROLLER

#include <iostream>
#include <SFML/Graphics.hpp>
#include "dungeon.hpp"

//Definir la ubicacion del mutex: PENDIENTE

class LogicController{
   private:
      class Dungeon dungeon;
      bool endGame;
      class sf::Thread logicThread;
      sf::Mutex * mutex;
      // Se agregan cualesquiera que sean los atributos necesarios.
   private:
      void checkBoxChange();
      void detectCollisions();
      void setHerzToIdle();
      void checkInput();
   public:
      LogicController();
         // Aqui debemos incializar todo aquello que deba ser incializado, como, por ejemplo,
         // la dynamic memory allocation para la matriz "dungeon".
      void setMutex( sf::Mutex * mutex );
      void lockMutex();
      void unlockMutex();
      void initDungeon( const int dificultyLevel );
      void logicRoutine();
         // Aqui viene toda la magia. En esta funcion (logicRoutine) va a entrar toda la logica
         // pesada del programa. Cualquier funcion auxiliar necesaria, como, por ejemplo,
         // "engageInBattle" o "movePlayer" deben ser definidas antes de esta funcion. Todas las
         // funciones auxiliares seran metodos privados, pues solo seran llamados desde "logicRoutine".
         // Toda la logica del programa debe existir dentro de esta funcion, pues es aquella que
         // sera ejecutada como hilo paralelo. Todo lo que no quede dentro de esta funcion, sera inaccesible.
      class DungeonBox * getDungeonBox( const int index, const int subindex );
      bool getEndGame();
      void setEndGame( bool endGame );
      void launchLogic();
      const float getBoxSize();
      const int getDungeonWidth();
      const int getDungeonHeight();
      class Herz * getHerz();
//      const int setDungeonWidth( const int width );
//      const int setDungeonHeight( const int width );
};

#endif