#include "dungeon.hpp"
/*
void ObjectsDB::initObjectsDB( const int width, const int height ){
        this->wallBoxes = new class WallBox[ width * height ];
        this->groundBoxes = new class GroundBox[ width * height ];

        this->escapePotions = new class EscapePotion[ width * height ];
        this->damagePotions = new class DamagePotion[ width * height ];
        this->strengthPotions = new class StrengthPotion[ width * height ];
        this->healthPotions = new class HealthPotion[ width * height ];

        this->swords = new class Sword[ width * height ];
        this->mallets = new class Mallet[ width * height ];
        this->bows = new class Bow[ width * height ];

        this->basicAttacks = new class BasicAttack[ width * height ];

        this->skulls = new class Skull[ width * height ];
        this->swampWoman = new class SwampWoman[ width * height ];
        this->mucuses = new class Mucus[ width * height ];
        this->viruses = new class Virus[ width * height ];
        this->minotaurs = new class Minotaur[ width * height ];
        this->devils = new class Devil[ width * height ];
}
*/

const float Dungeon::generateScaler( const float boxSize, const float entitySize ){
    return ( boxSize / entitySize );
}

class DungeonBox * Dungeon::getDungeonBox( const int index, const int subindex ){
    return &( this->dungeon[ index ][ subindex ] );
}
/*
void Dungeon::linkDungeonBox( class DungeonBox * dungeonBox, const int index, const int subindex ){
    this->dungeon[ index ][ subindex ] = dungeonBox;
}
*/
const int Dungeon::getDungeonWidth(){
    return this->dungeonWidth;
}

const int Dungeon::getDungeonHeight(){
    return this->dungeonHeight;
}

class Herz * Dungeon::getHerz(){
    return &this->herz;
}

// OJOOOOOO - Aqui puede que tenga que cambiarse algo
class HerzSurroundings Dungeon::getHerzSurroundings(){
    class HerzSurroundings surroundings;
    if( this->getHerz()->getYLocation() + 1 < this->dungeonHeight ){
        surroundings.down = this->getDungeonBox( this->getHerz()->getYLocation() + 1, this->getHerz()->getXLocation() );
    }
    else{
        surroundings.down = nullptr;
    }
    if( this->getHerz()->getYLocation() - 1 >= 0 ){
        surroundings.up = this->getDungeonBox( this->getHerz()->getYLocation()  - 1, this->getHerz()->getXLocation() );
    }
    else{
        surroundings.up = nullptr;
    }
    if( this->getHerz()->getXLocation() + 1 < this->dungeonWidth ){
        surroundings.right = this->getDungeonBox( this->getHerz()->getYLocation(), this->getHerz()->getXLocation() + 1 );
    }
    else{
        surroundings.right = nullptr;
    }
    if( this->getHerz()->getXLocation() - 1 >= 0 ){
        surroundings.left = this->getDungeonBox( this->getHerz()->getYLocation(), this->getHerz()->getXLocation() - 1 );
    }
    else{
        surroundings.left = nullptr;
    }
    return surroundings;
}

const float Dungeon::getBoxSize(){
    return this->boxSize;
}

void Dungeon::setDungeonWidth( const int width ){
    this->dungeonWidth = width;
}

void Dungeon::setDungeonHeight( const int height ){
    this->dungeonHeight = height;
}

void Dungeon::initDungeon( const int dificultyLevel ){
    //Por el momento, se esta creando un objeto cualquiera (a la vez) con DMM.
    //Debe estudiarse la posiblidad de tener un array de objetos de diferentes subclases
    //de Entity, para tener todos estos objetos recogidos en una seccion de la memoria.

    int easyBGAssignment[ 12 ][ 12 ] = {{WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL},
                                        {WL, GD, WL, GD, GD, GD, GD, GD, GD, GD, GD, WL},
                                        {WL, GD, WL, GD, GD, GD, GD, GD, GD, GD, GD, WL},
                                        {WL, GD, WL, WL, WL, WL, WL, WL, WL, GD, GD, WL},
                                        {WL, GD, GD, GD, GD, GD, GD, GD, WL, GD, GD, WL},
                                        {WL, GD, GD, WL, GD, GD, GD, GD, WL, GD, GD, WL},
                                        {WL, GD, GD, WL, WL, WL, WL, WL, WL, GD, GD, WL},
                                        {WL, GD, GD, WL, GD, GD, GD, GD, GD, GD, GD, WL},
                                        {WL, GD, GD, WL, WL, WL, WL, WL, GD, GD, GD, WL},
                                        {WL, GD, GD, GD, GD, GD, GD, WL, GD, GD, GD, WL},
                                        {WL, GD, GD, GD, GD, GD, GD, GD, GD, GD, GD, WL},
                                        {WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL}};

    int easyFGAssignment[ 12 ][ 12 ] = {{N, N, N, N, N, N, N, N, N, N, N, N},
                                        {N, N, N, I, N, N, W, W, W, N, N, N},
                                        {N, S, N, N, N, N, N, N, N, N, N, N},
                                        {N, N, N, N, N, N, N, N, N, N, N, N},
                                        {N, N, N, N, N, N, N, P, N, N, N, N},
                                        {N, N, N, N, N, N, N, B, N, E, E, N},
                                        {N, N, N, N, N, N, N, N, N, N, N, N},
                                        {N, N, N, N, P, N, N, N, N, N, N, N},
                                        {N, N, N, N, N, N, N, N, N, N, N, N},
                                        {N, N, N, N, N, N, N, N, N, N, N, N},
                                        {N, N, N, N, N, N, N, N, N, N, N, N},
                                        {N, N, N, N, N, N, N, N, N, N, N, N}};

    int normalBGAssignment[ 17 ][ 17 ] = {{WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL},
                                         {WL, GD, GD, GD, GD, GD, GD, GD, GD, GD, GD, GD, GD, GD, GD, GD, WL},
                                         {WL, GD, GD, GD, GD, GD, WL, WL, WL, WL, WL, WL, GD, GD, GD, GD, WL},
                                         {WL, GD, GD, GD, GD, GD, WL, GD, GD, GD, GD, WL, GD, GD, GD, GD, WL},
                                         {WL, GD, GD, WL, WL, WL, WL, GD, GD, GD, GD, WL, GD, GD, GD, GD, WL},
                                         {WL, GD, GD, WL, GD, GD, GD, GD, GD, GD, GD, WL, GD, GD, GD, GD, WL},
                                         {WL, GD, GD, WL, GD, GD, GD, GD, GD, GD, GD, WL, GD, GD, GD, GD, WL},
                                         {WL, GD, GD, WL, WL, WL, WL, WL, WL, WL, GD, WL, WL, WL, GD, GD, WL},
                                         {WL, GD, GD, GD, GD, GD, GD, GD, WL, GD, GD, GD, GD, WL, GD, GD, WL},
                                         {WL, GD, GD, GD, GD, GD, GD, GD, WL, GD, GD, GD, GD, WL, GD, GD, WL},
                                         {WL, GD, GD, GD, GD, GD, GD, GD, WL, GD, GD, GD, GD, WL, GD, GD, WL},
                                         {WL, GD, GD, GD, GD, GD, GD, GD, WL, GD, GD, GD, GD, WL, GD, GD, WL},
                                         {WL, GD, GD, WL, WL, WL, WL, WL, WL, GD, GD, GD, GD, GD, GD, GD, WL},
                                         {WL, GD, GD, WL, GD, GD, GD, GD, GD, GD, GD, GD, GD, WL, GD, GD, WL},
                                         {WL, GD, GD, WL, GD, GD, GD, WL, GD, GD, GD, GD, GD, WL, GD, GD, WL},
                                         {WL, GD, GD, WL, GD, GD, GD, WL, GD, GD, GD, GD, GD, WL, GD, GD, WL},
                                         {WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL}};

    int normalFGAssignment[ 17 ][ 17 ] = {{N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N},
                                         {N, N, N, N, N, N, E, N, N, N, N, N, N, N, N, N, N},
                                         {N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N},
                                         {N, N, N, N, N, N, N, N, N, N, P, N, N, N, N, N, N},
                                         {N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N},
                                         {N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N},
                                         {N, N, N, N, B, N, N, N, N, N, N, N, N, N, N, N, N},
                                         {N, N, N, N, N, N, N, N, N, N, E, N, N, N, N, N, N},
                                         {N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N},
                                         {N, W, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N},
                                         {N, W, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N},
                                         {N, W, N, N, N, B, N, P, N, N, N, N, N, N, N, N, N},
                                         {N, N, N, N, N, N, N, N, N, N, N, N, N, E, N, N, N},
                                         {N, N, N, N, N, N, N, B, N, N, N, N, N, N, N, N, N},
                                         {N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N},
                                         {N, I, N, N, N, S, N, N, N, N, N, N, N, N, W, N, N},
                                         {N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N}};

    float entitiesScale;
    int shiftY, shiftX; // OJOOOO - MOVER
    class Entity * entity;

    if( dificultyLevel == EASY ){
        this->setDungeonWidth( 12 );
        this->setDungeonHeight( 12 );
        this->dificultyLevel = EASY;
    }
    else{
        this->setDungeonWidth( 17 );
        this->setDungeonHeight( 17 );
        this->dificultyLevel = NORMAL;
    }

//    this->objectsDB.initObjectsDB( this->dungeonWidth, this->dungeonHeight );

    this->dungeon = new class DungeonBox *[ this->dungeonWidth ];
    for( shiftY = 0; shiftY < this->dungeonWidth; shiftY++ ){
        this->dungeon[ shiftY ] = new class DungeonBox[ this->dungeonHeight ];
        for( shiftX = 0; shiftX < this->dungeonHeight; shiftX++ ){
            if( this->dificultyLevel == EASY ){
                if( easyBGAssignment[ shiftY ][ shiftX ] == GD ){
                    entity = new class GroundBox;
                    this->dungeon[ shiftY ][ shiftX ].linkBackground( entity );
//                    this->dungeon[ shiftY ][ shiftX ].linkBackground( &this->objectsDB.groundBoxes[ this->dungeonWidth * shiftX + shiftY ] );
                }
                else{
                    entity = new class WallBox;
                    this->dungeon[ shiftY ][ shiftX ].linkBackground( entity );
//                    this->dungeon[ shiftY ][ shiftX ].linkBackground( &this->objectsDB.wallBoxes[ this->dungeonWidth * shiftX + shiftY ] );
                }
                if( easyFGAssignment[ shiftY ][ shiftX ] == P ){
                    entity = new class HealthPotion;
                    this->dungeon[ shiftY ][ shiftX ].linkForeground( entity );
//                    this->dungeon[ shiftY ][ shiftX ].linkForeground( &this->objectsDB.healthPotions[ this->dungeonWidth * shiftX + shiftY ] );
                }
                else if( easyFGAssignment[ shiftY ][ shiftX ] == W ){
                    entity = new class Mallet;
                    this->dungeon[ shiftY ][ shiftX ].linkForeground( entity );  
//                    this->dungeon[ shiftY ][ shiftX ].linkForeground( &this->objectsDB.mallets[ this->dungeonWidth * shiftX + shiftY ] );
                }
                else if( easyFGAssignment[ shiftY ][ shiftX ] == E ){
                    entity = new class SwampWoman;
                    this->dungeon[ shiftY ][ shiftX ].linkForeground( entity );
//                    this->dungeon[ shiftY ][ shiftX ].linkForeground( &this->objectsDB.swampWoman[ this->dungeonWidth * shiftX + shiftY ] );
                }
                else if( easyFGAssignment[ shiftY ][ shiftX ] == B ){
                    entity = new class Skull;
                    this->dungeon[ shiftY ][ shiftX ].linkForeground( entity );
//                    this->dungeon[ shiftY ][ shiftX ].linkForeground( &this->objectsDB.mucuses[ this->dungeonWidth * shiftX + shiftY ] );
                }
                else if( easyFGAssignment[ shiftY ][ shiftX ] == S ){
                    entity = new class Devil;
                    this->dungeon[ shiftY ][ shiftX ].linkForeground( entity );
//                    this->dungeon[ shiftY ][ shiftX ].linkForeground( &this->objectsDB.devils[ this->dungeonWidth * shiftX + shiftY ] );
                }
                else if( easyFGAssignment[ shiftY ][ shiftX ] == N ){
                    this->dungeon[ shiftY ][ shiftX ].linkForeground( nullptr );
//                    this->dungeon[ shiftY ][ shiftX ].linkForeground( nullptr );
                }
                else if( easyFGAssignment[ shiftY ][ shiftX ] == I ){
                    this->dungeon[ shiftY ][ shiftX ].getBGSprite()->setScale( this->boxScale, this->boxScale );
                    this->dungeon[ shiftY ][ shiftX ].getBGSprite()->setPosition( this->startY + ( this->boxScale * shiftX * this->boxSize ), this->startX + ( this->boxScale * shiftY * this->boxSize ) );
//                    entitiesScale = 0.7f * this->boxScale * this->herz.getScale();
//                    this->herz.getSprite()->setScale( entitiesScale, entitiesScale );
                    this->herz.getSprite()->setPosition( this->dungeon[ shiftY ][ shiftX ].getBGSprite()->getGlobalBounds().left + this->dungeon[ shiftY ][ shiftX ].getBGSprite()->getGlobalBounds().width / 2, this->dungeon[ shiftY ][ shiftX ].getBGSprite()->getGlobalBounds().top + this->dungeon[ shiftY ][ shiftX ].getBGSprite()->getGlobalBounds().height / 2 );
                    this->herz.setXLocation( shiftX );
                    this->herz.setYLocation( shiftY );
                    continue;
                }
                else{
                    this->dungeon[ shiftY ][ shiftX ].linkForeground( nullptr );
//                    this->dungeon[ shiftY ][ shiftX ].linkForeground( nullptr );
                }
            }
            else{
                if( normalBGAssignment[ shiftY ][ shiftX ] == GD ){
                    entity = new class GroundBox;
                    this->dungeon[ shiftY ][ shiftX ].linkBackground( entity );
//                    this->dungeon[ shiftY ][ shiftX ].linkBackground( &this->objectsDB.groundBoxes[ this->dungeonWidth * shiftX + shiftY ] );
                }
                else{
                    entity = new class WallBox;
                    this->dungeon[ shiftY ][ shiftX ].linkBackground( entity );
//                    this->dungeon[ shiftY ][ shiftX ].linkBackground( &this->objectsDB.wallBoxes[ this->dungeonWidth * shiftX + shiftY ] );
                }
                if( normalFGAssignment[ shiftY ][ shiftX ] == P ){
                    entity = new class HealthPotion;
                    this->dungeon[ shiftY ][ shiftX ].linkForeground( entity );
//                    this->dungeon[ shiftY ][ shiftX ].linkForeground( &this->objectsDB.healthPotions[ this->dungeonWidth * shiftX + shiftY ] );
                }
                else if( normalFGAssignment[ shiftY ][ shiftX ] == W ){
                    entity = new class Mallet;
                    this->dungeon[ shiftY ][ shiftX ].linkForeground( entity );
//                    this->dungeon[ shiftY ][ shiftX ].linkForeground( &this->objectsDB.mallets[ this->dungeonWidth * shiftX + shiftY ] );
                }
                else if( normalFGAssignment[ shiftY ][ shiftX ] == E ){
                    entity = new class SwampWoman;
                    this->dungeon[ shiftY ][ shiftX ].linkForeground( entity );
//                    this->dungeon[ shiftY ][ shiftX ].linkForeground( &this->objectsDB.swampWoman[ this->dungeonWidth * shiftX + shiftY ] );
                }
                else if( normalFGAssignment[ shiftY ][ shiftX ] == B ){
                    entity = new class Skull;
                    this->dungeon[ shiftY ][ shiftX ].linkForeground( entity );
//                    this->dungeon[ shiftY ][ shiftX ].linkForeground( &this->objectsDB.mucuses[ this->dungeonWidth * shiftX + shiftY ] );
                }
                else if( normalFGAssignment[ shiftY ][ shiftX ] == S ){
                    entity = new class Devil;
                    this->dungeon[ shiftY ][ shiftX ].linkForeground( entity );
//                    this->dungeon[ shiftY ][ shiftX ].linkForeground( &this->objectsDB.devils[ this->dungeonWidth * shiftX + shiftY ] );
                }
                else if( normalFGAssignment[ shiftY ][ shiftX ] == N ){
                    this->dungeon[ shiftY ][ shiftX ].linkForeground( nullptr );
//                    this->dungeon[ shiftY ][ shiftX ].linkForeground( nullptr );
                }
                else if( normalFGAssignment[ shiftY ][ shiftX ] == I ){
                    this->dungeon[ shiftY ][ shiftX ].getBGSprite()->setScale( this->boxScale, this->boxScale );
                    this->dungeon[ shiftY ][ shiftX ].getBGSprite()->setPosition( this->startX + ( this->boxScale * shiftX * this->boxSize ), this->startY + ( this->boxScale * shiftY * this->boxSize ) );
//                    entitiesScale = 0.7f * this->boxScale * this->herz.getScale();
//                    this->herz.getSprite()->setScale( entitiesScale, entitiesScale );
                    this->herz.getSprite()->setPosition( this->dungeon[ shiftY ][ shiftX ].getBGSprite()->getGlobalBounds().left + this->dungeon[ shiftY ][ shiftX ].getBGSprite()->getGlobalBounds().width / 2, this->dungeon[ shiftY ][ shiftX ].getBGSprite()->getGlobalBounds().top + this->dungeon[ shiftY ][ shiftX ].getBGSprite()->getGlobalBounds().height / 2 );
                    this->herz.setXLocation( shiftX );
                    this->herz.setYLocation( shiftY );
                    std::cout << "HERZ FUE ENCONTRADO: " << this->herz.getXLocation() << " " << this->herz.getYLocation();
                    continue;
                }
                else{
                    this->dungeon[ shiftY ][ shiftX ].linkForeground( nullptr );
//                    this->dungeon[ shiftY ][ shiftX ].linkForeground( nullptr );
                }
            }
            this->dungeon[ shiftY ][ shiftX ].getBGSprite()->setScale( this->boxScale, this->boxScale );
            this->dungeon[ shiftY ][ shiftX ].getBGSprite()->setPosition( this->startY + ( this->boxScale * shiftX * this->boxSize ), this->startX + ( this->boxScale * shiftY * this->boxSize ) );
            if( this->dungeon[ shiftY ][ shiftX ].getFGEntity() != nullptr ){
                entitiesScale = 0.7f * this->boxScale * this->dungeon[ shiftY ][ shiftX ].getFGEntity()->getScale();
                this->dungeon[ shiftY ][ shiftX ].getFGSprite()->setScale( entitiesScale, entitiesScale );
                this->dungeon[ shiftY ][ shiftX ].getFGSprite()->setPosition( this->dungeon[ shiftY ][ shiftX ].getBGSprite()->getGlobalBounds().left + this->dungeon[ shiftY ][ shiftX ].getBGSprite()->getGlobalBounds().width / 2, this->dungeon[ shiftY ][ shiftX ].getBGSprite()->getGlobalBounds().top + this->dungeon[ shiftY ][ shiftX ].getBGSprite()->getGlobalBounds().height / 2 );
            }
            // REVISAR LOGICA
        }
    }
    /*
    entity = new class WallBox;   // ESTO TIENE QUE CAMBIARSE - PRUEBAS NADA MAS
    entity->getSprite()->setScale( this->boxScale, this->boxScale );
    entity->getSprite()->setPosition( this->startX + ( this->boxScale * 1 * this->boxSize ), this->startY + ( this->boxScale * 1 * this->boxSize ) );
    this->dungeon[ 1 ][ 1 ].linkBackground( entity );
    
    this->herz.getSprite()->setPosition( this->dungeon[ HERZ_INIT_POS ][ HERZ_INIT_POS ].getBGSprite()->getGlobalBounds().left + this->dungeon[ HERZ_INIT_POS ][ HERZ_INIT_POS ].getBGSprite()->getGlobalBounds().width / 2, this->dungeon[ HERZ_INIT_POS ][ HERZ_INIT_POS ].getBGSprite()->getGlobalBounds().top + this->dungeon[ HERZ_INIT_POS ][ HERZ_INIT_POS ].getBGSprite()->getGlobalBounds().height / 2 );
    */
}
/*
void Dungeon::initDungeon( const int width, const int height ){
    //Por el momento, se esta creando un objeto cualquiera (a la vez) con DMM.
    //Debe estudiarse la posiblidad de tener un array de objetos de diferentes subclases
    //de Entity, para tener todos estos objetos recogidos en una seccion de la memoria.
    int shiftY, shiftX;
    class sf::Sprite * sprite;
    class Entity * entity;  //Esto es temporal, debe cambiarse
    this->dungeon = new class DungeonBox *[ width ];
    for( shiftY = 0; shiftY < width; shiftY++ ){
        this->dungeon[ shiftY ] = new class DungeonBox[ height ];
        for( shiftX = 0; shiftX < height; shiftX++ ){
            entity = new GroundBox;
            entity->getSprite()->setScale( this->boxScale, this->boxScale );
            entity->getSprite()->setPosition( this->startX + ( this->boxScale * shiftY * this->boxSize ), this->startY + ( this->boxScale * shiftX * this->boxSize ) );
            this->dungeon[ shiftY ][ shiftX ].linkBackground( entity );
            this->dungeon[ shiftY ][ shiftX ].linkForeground( nullptr );
        }
    }
    entity = new class WallBox;   // ESTO TIENE QUE CAMBIARSE - PRUEBAS NADA MAS
    entity->getSprite()->setScale( this->boxScale, this->boxScale );
    entity->getSprite()->setPosition( this->startX + ( this->boxScale * 1 * this->boxSize ), this->startY + ( this->boxScale * 1 * this->boxSize ) );
    this->dungeon[ 1 ][ 1 ].linkBackground( entity );
    
    this->herz.getSprite()->setPosition( this->dungeon[ HERZ_INIT_POS ][ HERZ_INIT_POS ].getBGSprite()->getGlobalBounds().left + this->dungeon[ HERZ_INIT_POS ][ HERZ_INIT_POS ].getBGSprite()->getGlobalBounds().width / 2, this->dungeon[ HERZ_INIT_POS ][ HERZ_INIT_POS ].getBGSprite()->getGlobalBounds().top + this->dungeon[ HERZ_INIT_POS ][ HERZ_INIT_POS ].getBGSprite()->getGlobalBounds().height / 2 );
    this->setDungeonWidth( width );
    this->setDungeonHeight( height );
}
*/