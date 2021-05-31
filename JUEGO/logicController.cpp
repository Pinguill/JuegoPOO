#include "logicController.hpp"

void LogicController::checkBoxChange(){
    class HerzSurroundings surroundings = this->dungeon.getHerzSurroundings();
    if( surroundings.right != nullptr ){
        if( this->dungeon.getHerz()->getSprite()->getGlobalBounds().left + this->dungeon.getHerz()->getSprite()->getGlobalBounds().width / 2 > surroundings.right->getBGSprite()->getGlobalBounds().left ){
std::cout << "ESTO 1";
            this->dungeon.getHerz()->incrementXLocation();
        }
    }
    if( surroundings.left != nullptr ){
        if( this->dungeon.getHerz()->getSprite()->getGlobalBounds().left + this->dungeon.getHerz()->getSprite()->getGlobalBounds().width / 2 < surroundings.left->getBGSprite()->getGlobalBounds().left + surroundings.left->getBGSprite()->getGlobalBounds().width ){
            std::cout << this->dungeon.getHerz()->getSprite()->getGlobalBounds().left + this->dungeon.getHerz()->getSprite()->getGlobalBounds().width / 2 << std::endl;
            std::cout << surroundings.left->getBGSprite()->getGlobalBounds().left + surroundings.left->getBGSprite()->getGlobalBounds().width << std::endl;
std::cout << "ESTO 2";
            this->dungeon.getHerz()->decrementXLocation();
        }
    }
    if( surroundings.up != nullptr ){
        if( this->dungeon.getHerz()->getSprite()->getGlobalBounds().top + this->dungeon.getHerz()->getSprite()->getGlobalBounds().height / 2 < surroundings.up->getBGSprite()->getGlobalBounds().top + surroundings.up->getBGSprite()->getGlobalBounds().height ){
std::cout << "ESTO 3";
            this->dungeon.getHerz()->decrementYLocation();
        }
    }
    if( surroundings.down != nullptr ){
        if( this->dungeon.getHerz()->getSprite()->getGlobalBounds().top + this->dungeon.getHerz()->getSprite()->getGlobalBounds().height / 2 > surroundings.down->getBGSprite()->getGlobalBounds().top ){
std::cout << "ESTO 4";
            this->dungeon.getHerz()->incrementYLocation();
        }
    }
    std::cout << "HERZ'S CURRENT BOX: " << this->dungeon.getHerz()->getXLocation() << " " << this->dungeon.getHerz()->getYLocation() << std::endl; 
}

void LogicController::detectCollisions(){
    class HerzSurroundings surroundings = this->dungeon.getHerzSurroundings();
    class Herz * herz = this->dungeon.getHerz();
    if( surroundings.right != nullptr ){
        if( surroundings.right->getBGCollisions() == false ){
            if( surroundings.right->getFGEntity() != nullptr ){
                if( herz->getSprite()->getGlobalBounds().left + herz->getSprite()->getGlobalBounds().width >= surroundings.right->getFGSprite()->getGlobalBounds().left ){
                    herz->getSprite()->setPosition( surroundings.right->getFGSprite()->getGlobalBounds().left - herz->getSprite()->getGlobalBounds().width / 2, herz->getSprite()->getGlobalBounds().top + herz->getSprite()->getGlobalBounds().height / 2 );
                }
            }
        }
        else{
            if( herz->getSprite()->getGlobalBounds().left + herz->getSprite()->getGlobalBounds().width >= surroundings.right->getBGSprite()->getGlobalBounds().left ){
                herz->getSprite()->setPosition( surroundings.right->getBGSprite()->getGlobalBounds().left - herz->getSprite()->getGlobalBounds().width / 2, herz->getSprite()->getGlobalBounds().top + herz->getSprite()->getGlobalBounds().height / 2 );
            }
        }
    }
    if( surroundings.left != nullptr ){
        if( surroundings.left->getBGCollisions() == false ){
            if( surroundings.left->getFGEntity() != nullptr ){
                if( herz->getSprite()->getGlobalBounds().left <= surroundings.left->getFGSprite()->getGlobalBounds().left + surroundings.left->getFGSprite()->getGlobalBounds().width ){
                    herz->getSprite()->setPosition( surroundings.left->getFGSprite()->getGlobalBounds().left + surroundings.left->getFGSprite()->getGlobalBounds().width + herz->getSprite()->getGlobalBounds().width / 2, herz->getSprite()->getGlobalBounds().top + herz->getSprite()->getGlobalBounds().height / 2 );
                }
            }
        }
        else{
            if( herz->getSprite()->getGlobalBounds().left <= surroundings.left->getBGSprite()->getGlobalBounds().left + surroundings.left->getBGSprite()->getGlobalBounds().width ){
std::cout << "ENTREEEE";
                herz->getSprite()->setPosition( surroundings.left->getBGSprite()->getGlobalBounds().left + surroundings.left->getBGSprite()->getGlobalBounds().width + herz->getSprite()->getGlobalBounds().width / 2, herz->getSprite()->getGlobalBounds().top + herz->getSprite()->getGlobalBounds().height / 2 );
            }
        }
    }
    if( surroundings.up != nullptr ){
        if( surroundings.up->getBGCollisions() == false ){
            if( surroundings.up->getFGEntity() != nullptr ){
                if( herz->getSprite()->getGlobalBounds().top <= surroundings.up->getFGSprite()->getGlobalBounds().top + surroundings.up->getFGSprite()->getGlobalBounds().height ){
                    herz->getSprite()->setPosition( herz->getSprite()->getGlobalBounds().left + herz->getSprite()->getGlobalBounds().width / 2, surroundings.up->getFGSprite()->getGlobalBounds().top + surroundings.up->getFGSprite()->getGlobalBounds().height + herz->getSprite()->getGlobalBounds().height / 2 );         
                }
            }
        }
        else{
            if( herz->getSprite()->getGlobalBounds().top <= surroundings.up->getBGSprite()->getGlobalBounds().top + surroundings.up->getBGSprite()->getGlobalBounds().height ){
                herz->getSprite()->setPosition( herz->getSprite()->getGlobalBounds().left + herz->getSprite()->getGlobalBounds().width / 2, surroundings.up->getBGSprite()->getGlobalBounds().top + surroundings.up->getBGSprite()->getGlobalBounds().height + herz->getSprite()->getGlobalBounds().height / 2 );
            }
        }
    }
    if( surroundings.down != nullptr ){
        if( surroundings.down->getBGCollisions() == false ){
            if( surroundings.down->getFGEntity() != nullptr ){
                if( herz->getSprite()->getGlobalBounds().top + herz->getSprite()->getGlobalBounds().height >= surroundings.down->getFGSprite()->getGlobalBounds().top ){
                    herz->getSprite()->setPosition( herz->getSprite()->getGlobalBounds().left + herz->getSprite()->getGlobalBounds().width / 2, surroundings.down->getFGSprite()->getGlobalBounds().top - herz->getSprite()->getGlobalBounds().height / 2 );
                }
            }
        }
        else{
            if( herz->getSprite()->getGlobalBounds().top + herz->getSprite()->getGlobalBounds().height >= surroundings.down->getBGSprite()->getGlobalBounds().top ){
                herz->getSprite()->setPosition( herz->getSprite()->getGlobalBounds().left + herz->getSprite()->getGlobalBounds().width / 2, surroundings.down->getBGSprite()->getGlobalBounds().top - herz->getSprite()->getGlobalBounds().height / 2 );
            }
        }
    }
}

void LogicController::setHerzToIdle(){
    this->dungeon.getHerz()->setCasToIdle();
}

void LogicController::checkInput(){
    sf::Time sleepTime = sf::seconds( 0.001f );
    while( !this->endGame ){
//        this->lockMutex();
        this->detectCollisions();
        this->checkBoxChange();
        if( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) ){
            this->endGame = true;
        }
        /* OJOOOOOO - Hay que implementar
        else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Space ) ){
            this->dungeon.getHerz()->attack();
        }
        */
        else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) && sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) ){
            this->dungeon.getHerz()->moveDownRight();
        }
        else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) && sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) ){
            this->dungeon.getHerz()->moveDownLeft();
        }
        else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) && sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) ){
            this->dungeon.getHerz()->moveUpLeft();
        }
        else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) && sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) ){
            this->dungeon.getHerz()->moveUpRight();
        }
        else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) ){
            this->dungeon.getHerz()->moveLeft();
            sf::sleep( sleepTime );
        }
        else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) ){
            this->dungeon.getHerz()->moveUp();
        }
        else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) ){
            this->dungeon.getHerz()->moveRight();
        }
        else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) ){
            this->dungeon.getHerz()->moveDown();
        }
        else{
            this->setHerzToIdle();
        }
//        this->unlockMutex();
        sf::sleep( sleepTime );
    }
}

LogicController::LogicController() : logicThread( &LogicController::logicRoutine, this ) {
    // Aqui debemos incializar todo aquello que deba ser incializado, como, por ejemplo,
    // la dynamic memory allocation para la matriz "dungeon".
    endGame = false;
}

void LogicController::setMutex( sf::Mutex * mutex ){
    this->mutex = mutex;
}

void LogicController::lockMutex(){
    this->mutex->lock();
}

void LogicController::unlockMutex(){
    this->mutex->unlock();
}

void LogicController::initDungeon( const int dificultyLevel ){
    this->lockMutex();
    this->dungeon.initDungeon( dificultyLevel );
    this->unlockMutex();
}

void LogicController::logicRoutine(){
    // Aqui viene toda la magia. En esta funcion (logicRoutine) va a entrar toda la logica
    // pesada del programa. Cualquier funcion auxiliar necesaria, como, por ejemplo,
    // "engageInBattle" o "movePlayer" deben ser definidas antes de esta funcion. Todas las
    // funciones auxiliares seran metodos privados, pues solo seran llamados desde "logicRoutine".
    // Toda la logica del programa debe existir dentro de esta funcion, pues es aquella que
    // sera ejecutada como hilo paralelo. Todo lo que no quede dentro de esta funcion, sera inaccesible.
    this->initDungeon( NORMAL );
    this->checkInput();
}

class DungeonBox * LogicController::getDungeonBox( const int index, const int subindex ){
    return this->dungeon.getDungeonBox( index, subindex );
}

bool LogicController::getEndGame(){
    return this->endGame;
}

void LogicController::setEndGame( bool endGame ){
    this->endGame = endGame;
}

void LogicController::launchLogic(){
    this->logicThread.launch();
}

const float LogicController::getBoxSize(){
    return this->dungeon.getBoxSize();
}

const int LogicController::getDungeonWidth(){
    return this->dungeon.getDungeonWidth();
}

const int LogicController::getDungeonHeight(){
    return this->dungeon.getDungeonHeight();
}
class Herz * LogicController::getHerz(){
    return this->dungeon.getHerz();
}

/*
const int LogicController::setDungeonWidth( const int width ){
    this->dungeon.setDungeonWidth( width );
}

void LogicController::setDungeonHeight( const int height ){
    this->dungeon.setDungeonHeight( height );
}
*/