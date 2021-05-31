#include "logicController.hpp"

LogicController::Logic(){
    // Aqui debemos incializar todo aquello que deba ser incializado, como, por ejemplo,
    // la dynamic memory allocation para la matriz "dungeon".
}

void LogicController::logicRoutine(){
    // Aqui viene toda la magia. En esta funcion (logicRoutine) va a entrar toda la logica
    // pesada del programa. Cualquier funcion auxiliar necesaria, como, por ejemplo,
    // "engageInBattle" o "movePlayer" deben ser definidas antes de esta funcion. Todas las
    // funciones auxiliares seran metodos privados, pues solo seran llamados desde "logicRoutine".
    // Toda la logica del programa debe existir dentro de esta funcion, pues es aquella que
    // sera ejecutada como hilo paralelo. Todo lo que no quede dentro de esta funcion, sera inaccesible.
}

int ** LogicController::getMatrix(){
    return this->dungeon;
}

bool * LogicController::getEndGameDir(){
    return &( this->end );
}

void LogicController::launchLogic(){
    this->logicThread.launch();
}