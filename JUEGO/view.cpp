#include "view.hpp"

// Aqui se definiran los valores de dimension con los que se creara la ventana
View::View() : gameWindow( sf::VideoMode( 1920, 1080, 32 ), "The Devil's Dungeon" ) {
    this->gameWindow.setFramerateLimit( 60 );
}

void View::setViewMutex( sf::Mutex * mutex ){
    this->mutex = mutex;
}

void View::setLogicMutex( sf::Mutex * mutex ){
    this->logicController.setMutex( mutex );
}

void View::lockMutex(){
    this->mutex->lock();
}

void View::unlockMutex(){
    this->mutex->unlock();
}

void View::drawBackground(){
    int i, j;
    for( i = 0; i < logicController.getDungeonWidth(); i++ ){
        for( j = 0; j < logicController.getDungeonHeight(); j++ ){
            gameWindow.draw( *( logicController.getDungeonBox( i, j )->getBGSprite() ) );
        }
    }
}

void View::drawForeground(){
    int i, j;
    for( i = 0; i < logicController.getDungeonWidth(); i++ ){
        for( j = 0; j < logicController.getDungeonHeight(); j++ ){
            if( logicController.getDungeonBox( i, j )->getFGEntity() != nullptr ){
                logicController.getDungeonBox( i, j )->getFGEntity()->updateSprite();
                gameWindow.draw( *( logicController.getDungeonBox( i, j )->getFGSprite() ) );
            }
        }
    }
}

/*
void View::drawBackground(){
    const float startX = 100.0, startY = 100.0; // Esta linea es temporal, poseteriormente deben ser ajustados
    int shiftX, shiftY;                         // los inicios del tablero de juego. Probablemente en en la clase dungeon.
    const float boxSize = logicController.getBoxSize();
    class DungeonBox * dungeonBox;
    class sf::Sprite sprite;
    for( shiftX = 0; shiftX < logicController.getDungeonWidth(); shiftX++ ){
        for( shiftY = 0; shiftY < logicController.getDungeonHeight(); shiftY++ ){
            dungeonBox = logicController.getDungeonBox( shiftX, shiftY );
            sprite = dungeonBox->getBGSprite();
            sprite.setPosition( startX + shiftX * boxSize, startY + shiftY * boxSize );
            gameWindow.draw( sprite );
        }
    }
}
*/

void View::drawHerz(){
    this->logicController.getHerz()->updateSprite();
    gameWindow.draw( *( this->logicController.getHerz()->getSprite() ) );
}

void View::display(){
    while( gameWindow.isOpen() ){
//        this->lockMutex();
        while( gameWindow.pollEvent( appEvent ) ){
            if( appEvent.type == sf::Event::Closed || logicController.getEndGame() ){
                logicController.setEndGame( true );
                gameWindow.close();
            }
        }
        gameView.setCenter( ( * this->logicController.getHerz()->getSprite() ).getPosition() );
        gameWindow.clear();
        gameWindow.setView( gameView );
        drawBackground();
        drawForeground();
        drawHerz();
//        this->unlockMutex();
        gameWindow.display();
    }
}

void View::launchLogic(){
    logicController.launchLogic();
}