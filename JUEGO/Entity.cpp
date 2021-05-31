#include "Entity.hpp"

// CLASE ENTITY
/*
Entity::Entity( string entName, string entDescrip, string textureDir ){
    this->entName = entName;
    this->entDescrip = entDescrip;
    this->textureDir = textureDir;
}// Constructor
*/
//Entity::~Entity(){}// Destructor

void Entity::initSprite(){
    this->entTexture.loadFromFile( this->textureDir );
    this->entSprite.setTexture( this->entTexture );
}

void Entity::centerOrigin(){
//    std::cout << "MODIFICANDO ORIGEN DE: " << this->entName << std::endl;
//    std::cout << "Previous values: " << this->entSprite.getOrigin().x << " " << this->entSprite.getOrigin().y << std::endl;
    this->entSprite.setOrigin( this->entSprite.getGlobalBounds().width / 2.f, this->entSprite.getGlobalBounds().height / 2.f );
//    std::cout << "New values: " << this->entSprite.getOrigin().x << " " << this->entSprite.getOrigin().y << std::endl;
}

string Entity::getEntityDescrip(){ // Return entity description
    return entDescrip;
}

string Entity::getEntityName(){// Return entity name
    return entName;
}

bool Entity::getCollisions(){
    return this->collisions;
}

class sf::Sprite * Entity::getSprite(){
    return &this->entSprite;
}

const float Entity::getScale(){
    return this->scale;
}

/*
const float Entity::getSideSize(){
    return this->entTexture.getSize().x;
}
*/

// CLASE GROUNDBOX

GroundBox::GroundBox(){
    this->entName = "Ground";
    this->entDescrip = "N.A.";
    this->textureDir = "./Textures/ground.png";
    this->collisions = false;
    this->initSprite();
    this->entSprite.setColor( sf::Color( 192, 181, 171 ) );
}

void GroundBox::updateSprite(){
//    cout << "WARNING: This function should not be called for class DungeonBox" << std::endl;
} // OJOOOO - En este caso, no debe llamarse

// CLASE WALLBOX

WallBox::WallBox(){
    this->entName = "Wall";
    this->entDescrip = "N.A.";
    this->textureDir = "./Textures/wall.png";
    this->collisions = true;
    this->initSprite();
    this->entSprite.setColor( sf::Color( 104, 130, 158 ) );
}

void WallBox::updateSprite(){
//    cout << "WARNING: This function should not be called for class WallBox" << std::endl;
} // OJOOOO - En este caso, no debe llamarse

// CLASE ATTACKCARD

//   DEFINIR SI SE NECESITA ALGO ACA

// CLASE BASICATTACK

void BasicAttack::updateSprite(){} // OJOOOOO - Por definir

void BasicAttack::use( class Character * target, int baseDmg ){}

// CLASE CHARACTER

//Character::Character(){}

// CLASE HERZ

Herz::Herz(){
    this->entName = "Herz";
    this->entDescrip = "Herz es el jugador principal del juego y el encargado de salvar a su pueblo.";
    this->textureDir = "./Textures/herz.png";
    this->collisions = true;
    this->animationsNumber = 5;
    this->scale = 1.3f;
    this->initSprite();
    this->baseRects = new sf::IntRect[ this->animationsNumber ];
    this->baseShiftMax = new int[ this->animationsNumber ];

    this->baseRects[ IDLE ].left = 0;
    this->baseRects[ IDLE ].top = 0;
    this->baseRects[ IDLE ].width = 48;
    this->baseRects[ IDLE ].height = 48;
    this->baseShiftMax[ IDLE ] = 5;

    this->baseRects[ LEFT ].left = 0;
    this->baseRects[ LEFT ].top = 48;
    this->baseRects[ LEFT ].width = 48;
    this->baseRects[ LEFT ].height = 48;
    this->baseShiftMax[ LEFT ] = 7;

    this->baseRects[ RIGHT ].left = 0;
    this->baseRects[ RIGHT ].top = 48;
    this->baseRects[ RIGHT ].width = 48;
    this->baseRects[ RIGHT ].height = 48;
    this->baseShiftMax[ RIGHT ] = 7;

    this->baseRects[ ATTACK ].left = 0;
    this->baseRects[ ATTACK ].top = 96;
    this->baseRects[ ATTACK ].width = 64;
    this->baseRects[ ATTACK ].height = 48;
    this->baseShiftMax[ ATTACK ] = 9;

    this->baseRects[ DEAD ].left = 0;
    this->baseRects[ DEAD ].top = 144;
    this->baseRects[ DEAD ].width = 48;
    this->baseRects[ DEAD ].height = 48;
    this->baseShiftMax[ DEAD ] = 12;

    this->previousAS = IDLE;
    this->currentAS = IDLE;
    this->entSprite.setTextureRect( this->baseRects[ IDLE ] );
    this->centerOrigin();
    this->entSprite.setScale( this->scale, this->scale );
    this->baseShift = 1;
    this->animationInterval.restart();
}

const int Herz::getXLocation(){
    return this->xLocation;
}

const int Herz::getYLocation(){
    return this->yLocation;
}

void Herz::setXLocation( const int xLocation ){
    this->xLocation = xLocation;
}

void Herz::setYLocation( const int yLocation ){
    this->yLocation = yLocation;
}

void Herz::incrementXLocation(){
    this->xLocation++;
}

void Herz::incrementYLocation(){
    this->yLocation++;
}

void Herz::decrementXLocation(){
    this->xLocation--;
}

void Herz::decrementYLocation(){
    this->yLocation--;
}

void Herz::setCasToIdle(){
    this->previousAS = this->currentAS;
    this->currentAS = IDLE;
}

void Herz::updateSprite(){
    if( this->animationInterval.getElapsedTime().asSeconds() >= 0.1f ){
        if( this->previousAS == IDLE ){
            if( this->currentAS == IDLE ){
                if( ++this->baseShift <= this->baseShiftMax[ this->currentAS ] ){
                    this->baseRects[ this->currentAS ].left += this->baseRects[ this->currentAS ].width;
                    this->entSprite.setTextureRect( this->baseRects[ this->currentAS ] );
                }
                else{
                this->baseRects[ this->currentAS ].left = 0;
                this->entSprite.setTextureRect( this->baseRects[ this->currentAS ] );
                this->baseShift = 1;
                }
            }
            this->entSprite.setScale( this->scale, this->scale );
        }
        else if( this->previousAS == LEFT ){
            if( this->currentAS == LEFT ){
                if( ++this->baseShift <= this->baseShiftMax[ this->currentAS ] ){
                    this->baseRects[ this->currentAS ].left += this->baseRects[ this->currentAS ].width;
                    this->entSprite.setTextureRect( this->baseRects[ this->currentAS ] );
                }
                else{
                this->baseRects[ this->currentAS ].left = 0;
                this->entSprite.setTextureRect( this->baseRects[ this->currentAS ] );
                this->baseShift = 1;
                }
            }
            this->entSprite.setScale( -this->scale, this->scale );
        }
        else if( this->previousAS == RIGHT ){
            if( this->currentAS == RIGHT ){
                if( ++this->baseShift <= this->baseShiftMax[ this->currentAS ] ){
                    this->baseRects[ this->currentAS ].left += this->baseRects[ this->currentAS ].width;
                    this->entSprite.setTextureRect( this->baseRects[ this->currentAS ] );
                }
                else{
                this->baseRects[ this->currentAS ].left = 0;
                this->entSprite.setTextureRect( this->baseRects[ this->currentAS ] );
                this->baseShift = 1;
                }
            }
            this->entSprite.setScale( this->scale, this->scale );
        }
        else if( this->previousAS == ATTACK ){
            if( this->currentAS == ATTACK ){
                if( ++this->baseShift <= this->baseShiftMax[ this->currentAS ] ){
                    this->baseRects[ this->currentAS ].left += this->baseRects[ this->currentAS ].width;
                    this->entSprite.setTextureRect( this->baseRects[ this->currentAS ] );
                }
                else{
                this->baseRects[ this->currentAS ].left = 0;
                this->entSprite.setTextureRect( this->baseRects[ this->currentAS ] );
                this->baseShift = 1;
                }
            }
            this->entSprite.setScale( this->scale, this->scale );
        }
        else if( this->previousAS == DEAD ){
            if( this->currentAS == DEAD ){
                if( ++this->baseShift <= this->baseShiftMax[ this->currentAS ] ){
                    this->baseRects[ this->currentAS ].left += this->baseRects[ this->currentAS ].width;
                    this->entSprite.setTextureRect( this->baseRects[ this->currentAS ] );
                }
                else{
                this->baseRects[ this->currentAS ].left = 0;
                this->entSprite.setTextureRect( this->baseRects[ this->currentAS ] );
                this->baseShift = 1;
                }
            }
            this->entSprite.setScale( this->scale, this->scale );
        }
        this->animationInterval.restart();
    }
}

void Herz::moveUp(){
    this->entSprite.move( 0.f, -( this->movingSpeed ) );
    this->previousAS = this->currentAS;
    this->currentAS = RIGHT;
}

void Herz::moveRight(){
    this->entSprite.move( this->movingSpeed, 0.f );
    this->previousAS = this->currentAS;
    this->currentAS = RIGHT;
}

void Herz::moveDown(){
    this->entSprite.move( 0.f, this->movingSpeed );
    this->previousAS = this->currentAS;
    this->currentAS = RIGHT;
}

void Herz::moveLeft(){
    this->entSprite.move( -( this->movingSpeed ), 0.f );
    this->previousAS = this->currentAS;
    this->currentAS = LEFT;
}

void Herz::moveUpRight(){
    this->entSprite.move( this->movingSpeed / 2, -( this->movingSpeed / 2 ) );
    this->previousAS = this->currentAS;
    this->currentAS = RIGHT;
}

void Herz::moveDownRight(){
    this->entSprite.move( this->movingSpeed / 2, this->movingSpeed / 2 );
    this->previousAS = this->currentAS;
    this->currentAS = RIGHT;
}

void Herz::moveDownLeft(){
    this->entSprite.move( -( this->movingSpeed / 2 ), this->movingSpeed / 2 );
    this->previousAS = this->currentAS;
    this->currentAS = LEFT;
}

void Herz::moveUpLeft(){
    this->entSprite.move( -( this->movingSpeed / 2 ), -( this->movingSpeed / 2 ) );
    this->previousAS = this->currentAS;
    this->currentAS = LEFT;
}

void Herz::attack( Character * target, class Item * weapon, class AttackCard * attackCard ){}

// CLASS SKULL

Skull::Skull(){
    this->entName = "Skull Monster";
    this->entDescrip = "Description";
    this->textureDir = "./Textures/skull.png";
    this->collisions = true;

    this->scale = 0.16f;
    this->animationsNumber = 1;
    this->initSprite();

    this->baseRects = new sf::IntRect[ this->animationsNumber ];
    this->baseShiftMax = new int[ this->animationsNumber ];

    this->baseRects[ ONE_ANIM ].left = 0;
    this->baseRects[ ONE_ANIM ].top = 0;
    this->baseRects[ ONE_ANIM ].width = 360;
    this->baseRects[ ONE_ANIM ].height = 380;
    this->baseShiftMax[ ONE_ANIM ] = 3;

    this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
    this->entSprite.setScale( this->scale, this->scale );
    this->centerOrigin();
    this->baseShift = 1;
    this->animationInterval.restart();
}

void Skull::updateSprite(){
    if( this->animationInterval.getElapsedTime().asSeconds() >= 0.1f ){
        if( ++this->baseShift <= this->baseShiftMax[ ONE_ANIM ] ){
            this->baseRects[ ONE_ANIM ].left += this->baseRects[ ONE_ANIM ].width;
            this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
        }
        else{
        this->baseRects[ ONE_ANIM ].left = 0;
        this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
        this->baseShift = 1;
        }
        this->animationInterval.restart();
    }
}

void Skull::attack( class Character * target, class Item * weapon, class AttackCard * attackCard ){}

// CLASS SWAMPWOMAN

SwampWoman::SwampWoman(){
    this->entName = "Swamp Woman";
    this->entDescrip = "Description";
    this->textureDir = "./Textures/swampWoman.png";
    this->collisions = true;

    this->scale = 0.26f;
    this->animationsNumber = 1;
    this->initSprite();

    this->baseRects = new sf::IntRect[ this->animationsNumber ];
    this->baseShiftMax = new int[ this->animationsNumber ];

    this->baseRects[ ONE_ANIM ].left = 0;
    this->baseRects[ ONE_ANIM ].top = 0;
    this->baseRects[ ONE_ANIM ].width = 240;
    this->baseRects[ ONE_ANIM ].height = 240;
    this->baseShiftMax[ ONE_ANIM ] = 4;

    this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
    this->entSprite.setScale( this->scale, this->scale );
    this->centerOrigin();
    this->baseShift = 1;
    this->animationInterval.restart();
}

void SwampWoman::updateSprite(){
    if( this->animationInterval.getElapsedTime().asSeconds() >= 0.1f ){
        if( ++this->baseShift <= this->baseShiftMax[ ONE_ANIM ] ){
            this->baseRects[ ONE_ANIM ].left += this->baseRects[ ONE_ANIM ].width;
            this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
        }
        else{
        this->baseRects[ ONE_ANIM ].left = 0;
        this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
        this->baseShift = 1;
        }
        this->animationInterval.restart();
    }
}

void SwampWoman::attack( class Character * target, class Item * weapon, class AttackCard * attackCard ){}

// CLASS MUCUS

Mucus::Mucus(){
    this->entName = "Mucus Monster";
    this->entDescrip = "Description";
    this->textureDir = "./Textures/mucus.png";
    this->collisions = true;

    this->scale = 0.32f;
    this->animationsNumber = 1;
    this->initSprite();

    this->baseRects = new sf::IntRect[ this->animationsNumber ];
    this->baseShiftMax = new int[ this->animationsNumber ];

    this->baseRects[ ONE_ANIM ].left = 0;
    this->baseRects[ ONE_ANIM ].top = 0;
    this->baseRects[ ONE_ANIM ].width = 200;
    this->baseRects[ ONE_ANIM ].height = 200;
    this->baseShiftMax[ ONE_ANIM ] = 4;

    this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
    this->entSprite.setScale( this->scale, this->scale );
    this->centerOrigin();
    this->baseShift = 1;
    this->animationInterval.restart();
}

void Mucus::updateSprite(){
    if( this->animationInterval.getElapsedTime().asSeconds() >= 0.1f ){
        if( ++this->baseShift <= this->baseShiftMax[ ONE_ANIM ] ){
            this->baseRects[ ONE_ANIM ].left += this->baseRects[ ONE_ANIM ].width;
            this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
        }
        else{
        this->baseRects[ ONE_ANIM ].left = 0;
        this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
        this->baseShift = 1;
        }
        this->animationInterval.restart();
    }
}

void Mucus::attack( class Character * target, class Item * weapon, class AttackCard * attackCard ){}

// CLASS VIRUS

Virus::Virus(){
    this->entName = "Virus monster";
    this->entDescrip = "Description";
    this->textureDir = "./Textures/virus.png";
    this->collisions = true;

    this->scale = 0.28f;
    this->animationsNumber = 1;
    this->initSprite();

    this->baseRects = new sf::IntRect[ this->animationsNumber ];
    this->baseShiftMax = new int[ this->animationsNumber ];

    this->baseRects[ ONE_ANIM ].left = 0;
    this->baseRects[ ONE_ANIM ].top = 0;
    this->baseRects[ ONE_ANIM ].width = 156;
    this->baseRects[ ONE_ANIM ].height = 222;
    this->baseShiftMax[ ONE_ANIM ] = 6;

    this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
    this->entSprite.setScale( this->scale, this->scale );
    this->centerOrigin();
    this->baseShift = 1;
    this->animationInterval.restart();
}

void Virus::updateSprite(){
    if( this->animationInterval.getElapsedTime().asSeconds() >= 0.1f ){
        if( ++this->baseShift <= this->baseShiftMax[ ONE_ANIM ] ){
            this->baseRects[ ONE_ANIM ].left += this->baseRects[ ONE_ANIM ].width;
            this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
        }
        else{
        this->baseRects[ ONE_ANIM ].left = 0;
        this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
        this->baseShift = 1;
        }
        this->animationInterval.restart();
    }
}

void Virus::attack( class Character * target, class Item * weapon, class AttackCard * attackCard ){}

// CLASS MINOTAUR

Minotaur::Minotaur(){
    this->entName = "Minotaur";
    this->entDescrip = "Description";
    this->textureDir = "./Textures/minotaur.png";
    this->collisions = true;

    this->scale = 0.26f;
    this->animationsNumber = 1;
    this->initSprite();

    this->baseRects = new sf::IntRect[ this->animationsNumber ];
    this->baseShiftMax = new int[ this->animationsNumber ];

    this->baseRects[ ONE_ANIM ].left = 0;
    this->baseRects[ ONE_ANIM ].top = 0;
    this->baseRects[ ONE_ANIM ].width = 240;
    this->baseRects[ ONE_ANIM ].height = 240;
    this->baseShiftMax[ ONE_ANIM ] = 4;

    this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
    this->entSprite.setScale( this->scale, this->scale );
    this->centerOrigin();
    this->baseShift = 1;
    this->animationInterval.restart();
}

void Minotaur::updateSprite(){
    if( this->animationInterval.getElapsedTime().asSeconds() >= 0.1f ){
        if( ++this->baseShift <= this->baseShiftMax[ ONE_ANIM ] ){
            this->baseRects[ ONE_ANIM ].left += this->baseRects[ ONE_ANIM ].width;
            this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
        }
        else{
        this->baseRects[ ONE_ANIM ].left = 0;
        this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
        this->baseShift = 1;
        }
        this->animationInterval.restart();
    }
}

void Minotaur::attack( class Character * target, class Item * weapon, class AttackCard * attackCard ){}

// CLASS DEVIL

Devil::Devil(){
    this->entName = "The Great Devil";
    this->entDescrip = "Descrition";
    this->textureDir = "./Textures/devil.png";
    this->collisions = true;

    this->scale = 0.26f;
    this->animationsNumber = 1;
    this->initSprite();

    this->baseRects = new sf::IntRect[ this->animationsNumber ];
    this->baseShiftMax = new int[ this->animationsNumber ];

    this->baseRects[ ONE_ANIM ].left = 0;
    this->baseRects[ ONE_ANIM ].top = 0;
    this->baseRects[ ONE_ANIM ].width = 250;
    this->baseRects[ ONE_ANIM ].height = 246;
    this->baseShiftMax[ ONE_ANIM ] = 6;

    this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
    this->entSprite.setScale( this->scale, this->scale );
    this->centerOrigin();
    this->baseShift = 1;
    this->animationInterval.restart();
}

void Devil::updateSprite(){
    if( this->animationInterval.getElapsedTime().asSeconds() >= 0.1f ){
        if( ++this->baseShift <= this->baseShiftMax[ ONE_ANIM ] ){
            this->baseRects[ ONE_ANIM ].left += this->baseRects[ ONE_ANIM ].width;
            this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
        }
        else{
        this->baseRects[ ONE_ANIM ].left = 0;
        this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
        this->baseShift = 1;
        }
        this->animationInterval.restart();
    }
}

void Devil::attack( class Character * target, class Item * weapon, class AttackCard * attackCard ){}

// CLASS ITEM

//Item::Item(){}
//Item::~Item(){}

// CLASS SWORD

Sword::Sword(){
    this->entName = "Sword";
    this->entDescrip = "This is a weapon you can use to attack enemies";
    this->textureDir = "./Textures/sword.png";
    this->collisions = true;
    this->initSprite();

    this->scale = 0.35f;
    this->initSprite();
    this->entSprite.setScale( this->scale, this->scale );
    this->centerOrigin();

    /*
    this->scale = 0.6f;
    this->animationsNumber = 1;
    this->initSprite();

    this->baseRects = new sf::IntRect[ this->animationsNumber ];
    this->baseShiftMax = new int[ this->animationsNumber ];

    this->baseRects[ ONE_ANIM ].left = 0;
    this->baseRects[ ONE_ANIM ].top = 0;
    this->baseRects[ ONE_ANIM ].width = 180;
    this->baseRects[ ONE_ANIM ].height = 180;
    this->baseShiftMax[ ONE_ANIM ] = 1;

    this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
    this->entSprite.setScale( this->scale, this->scale );
    this->animationInterval.restart();
    */
}

void Sword::setStrengthAndDamage( const int strength, const int dmg ){
    this->strength = strength;
    this->dmg = dmg;
}

void Sword::updateSprite(){
//    cout << "WARNING: This function should not be called for class Sword" << std::endl;
} // OJOOOO - En este caso, no debe llamarse

void Sword::use( class Character * target ){}

// CLASS MALLET

Mallet::Mallet(){
    this->entName = "Mallet";
    this->entDescrip = "This is a weapon you can use to attack enemies";
    this->textureDir = "./Textures/mallet.png";
    this->collisions = true;
    this->initSprite();

    this->scale = 0.11f;
    this->initSprite();
    this->entSprite.setScale( this->scale, this->scale );
    this->centerOrigin();

    /*
    this->animationsNumber = 1;
    this->initSprite();

    this->baseRects = new sf::IntRect[ this->animationsNumber ];
    this->baseShiftMax = new int[ this->animationsNumber ];

    this->baseRects[ ONE_ANIM ].left = 0;
    this->baseRects[ ONE_ANIM ].top = 0;
    this->baseRects[ ONE_ANIM ].width = 700;
    this->baseRects[ ONE_ANIM ].height = 580;
    this->baseShiftMax[ ONE_ANIM ] = 1;

    this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
    this->entSprite.setScale( this->scale, this->scale );
    this->animationInterval.restart();
    */
}

void Mallet::setStrengthAndDamage( const int strength, const int dmg ){
    this->strength = strength;
    this->dmg = dmg;
}

void Mallet::updateSprite(){
//    cout << "WARNING: This function should not be called for class Mallet" << std::endl;
} // OJOOOO - En este caso, no debe llamarse

void Mallet::use( class Character * target ){}

// CLASS BOW

Bow::Bow(){
    this->entName = "Bow";
    this->entDescrip = "This is a weapon you can use to attack enemies";
    this->textureDir = "./Textures/bowArrow.png";
    this->collisions = true;

    this->scale = 0.054f;
    this->initSprite();
    this->entSprite.setScale( this->scale, this->scale );
    this->centerOrigin();

    /*
    this->scale = 0.15f;
    this->animationsNumber = 1;
    this->initSprite();

    this->baseRects = new sf::IntRect[ this->animationsNumber ];
    this->baseShiftMax = new int[ this->animationsNumber ];

    this->baseRects[ ONE_ANIM ].left = 0;
    this->baseRects[ ONE_ANIM ].top = 0;
    this->baseRects[ ONE_ANIM ].width = 1184;
    this->baseRects[ ONE_ANIM ].height = 1184;
    this->baseShiftMax[ ONE_ANIM ] = 1;

    this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
    this->entSprite.setScale( this->scale, this->scale );
    this->animationInterval.restart();
    */
}

void Bow::setStrengthAndDamage( const int strength, const int dmg ){
    this->strength = strength;
    this->dmg = dmg;
}

void Bow::updateSprite(){
//    cout << "WARNING: This function should not be called for class Bow" << std::endl;
} // OJOOOO - En este caso, no debe llamarse

void Bow::use( class Character * target ){}

// CLASS ESCAPEPOTION

EscapePotion::EscapePotion(){
    this->entName = "Escape Potion";
    this->entDescrip = "You can use this potion to escape from a fight. However, it might not always work";
    this->textureDir = "./Textures/escapePotion.png";
    this->collisions = true;

    this->scale = 1.4f;
    this->animationsNumber = 1;
    this->initSprite();

    this->baseRects = new sf::IntRect[ this->animationsNumber ];
    this->baseShiftMax = new int[ this->animationsNumber ];

    this->baseRects[ ONE_ANIM ].left = 0;
    this->baseRects[ ONE_ANIM ].top = 0;
    this->baseRects[ ONE_ANIM ].width = 45;
    this->baseRects[ ONE_ANIM ].height = 50;
    this->baseShiftMax[ ONE_ANIM ] = 8;

    this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
    this->entSprite.setScale( this->scale, this->scale );
    this->centerOrigin();
    this->baseShift = 1;
    this->animationInterval.restart();
}

void EscapePotion::setEffective( const bool effective ){
    this->effective = effective;
}

void EscapePotion::updateSprite(){
    if( this->animationInterval.getElapsedTime().asSeconds() >= 0.1f ){
        if( ++this->baseShift <= this->baseShiftMax[ ONE_ANIM ] ){
            this->baseRects[ ONE_ANIM ].left += this->baseRects[ ONE_ANIM ].width;
            this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
        }
        else{
        this->baseRects[ ONE_ANIM ].left = 0;
        this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
        this->baseShift = 1;
        }
        this->animationInterval.restart();
    }
}

void EscapePotion::use( class Character * target ){}

// CLASS DAMAGEPOTION

DamagePotion::DamagePotion(){
    this->entName = "Damage Potion";
    this->entDescrip = "This potion will increse your damage points";
    this->textureDir = "./Textures/damagePotion.png";
    this->collisions = true;

    this->scale = 1.4f;
    this->animationsNumber = 1;
    this->initSprite();

    this->baseRects = new sf::IntRect[ this->animationsNumber ];
    this->baseShiftMax = new int[ this->animationsNumber ];

    this->baseRects[ ONE_ANIM ].left = 0;
    this->baseRects[ ONE_ANIM ].top = 0;
    this->baseRects[ ONE_ANIM ].width = 45;
    this->baseRects[ ONE_ANIM ].height = 50;
    this->baseShiftMax[ ONE_ANIM ] = 8;

    this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
    this->entSprite.setScale( this->scale, this->scale );
    this->centerOrigin();
    this->baseShift = 1;
    this->animationInterval.restart();
}

void DamagePotion::setDamageBonus( const int damageBonus ){
    this->damageBonus = damageBonus;
}

void DamagePotion::updateSprite(){
    if( this->animationInterval.getElapsedTime().asSeconds() >= 0.1f ){
        if( ++this->baseShift <= this->baseShiftMax[ ONE_ANIM ] ){
            this->baseRects[ ONE_ANIM ].left += this->baseRects[ ONE_ANIM ].width;
            this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
        }
        else{
        this->baseRects[ ONE_ANIM ].left = 0;
        this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
        this->baseShift = 1;
        }
        this->animationInterval.restart();
    }
}

void DamagePotion::use( class Character * target ){}

// CLASS STRENGTHPOTION

StrengthPotion::StrengthPotion(){
    this->entName = "Strength Potion";
    this->entDescrip = "This potion will increse your strength";
    this->textureDir = "./Textures/stregthPotion.png";
    this->collisions = true;

    this->scale = 1.4f;
    this->animationsNumber = 1;
    this->initSprite();

    this->baseRects = new sf::IntRect[ this->animationsNumber ];
    this->baseShiftMax = new int[ this->animationsNumber ];

    this->baseRects[ ONE_ANIM ].left = 0;
    this->baseRects[ ONE_ANIM ].top = 0;
    this->baseRects[ ONE_ANIM ].width = 45;
    this->baseRects[ ONE_ANIM ].height = 50;
    this->baseShiftMax[ ONE_ANIM ] = 8;

    this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
    this->centerOrigin();
    this->entSprite.setScale( this->scale, this->scale );
    this->baseShift = 1;
    this->animationInterval.restart();
}

void StrengthPotion::setStrengthBonus( const int strengthBonus ){
    this->strengthBonus = strengthBonus;
}

void StrengthPotion::updateSprite(){
    if( this->animationInterval.getElapsedTime().asSeconds() >= 0.1f ){
        if( ++this->baseShift <= this->baseShiftMax[ ONE_ANIM ] ){
            this->baseRects[ ONE_ANIM ].left += this->baseRects[ ONE_ANIM ].width;
            this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
        }
        else{
        this->baseRects[ ONE_ANIM ].left = 0;
        this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
        this->baseShift = 1;
        }
        this->animationInterval.restart();
    }
}

void StrengthPotion::use( class Character * target ){}

// HELTHPOTION

HealthPotion::HealthPotion(){
    this->entName = "Health Potion";
    this->entDescrip = "This potion will restore you health";
    this->textureDir = "./Textures/healthPotion.png";
    this->collisions = true;

    this->scale = 1.4f;
    this->animationsNumber = 1;
    this->initSprite();

    this->baseRects = new sf::IntRect[ this->animationsNumber ];
    this->baseShiftMax = new int[ this->animationsNumber ];

    this->baseRects[ ONE_ANIM ].left = 0;
    this->baseRects[ ONE_ANIM ].top = 0;
    this->baseRects[ ONE_ANIM ].width = 45.f;
    this->baseRects[ ONE_ANIM ].height = 50;
    this->baseShiftMax[ ONE_ANIM ] = 8;

    this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
    this->entSprite.setScale( this->scale, this->scale );
    this->centerOrigin();
    this->baseShift = 1;
    this->animationInterval.restart();

}

void HealthPotion::setHealthBonus( const int healthBonus ){
    this->healthBonus = healthBonus;
}

void HealthPotion::updateSprite(){
    if( this->animationInterval.getElapsedTime().asSeconds() >= 0.1f ){
        if( ++this->baseShift <= this->baseShiftMax[ ONE_ANIM ] ){
            this->baseRects[ ONE_ANIM ].left += this->baseRects[ ONE_ANIM ].width;
            this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
        }
        else{
        this->baseRects[ ONE_ANIM ].left = 0;
        this->entSprite.setTextureRect( this->baseRects[ ONE_ANIM ] );
        this->baseShift = 1;
        }
        this->animationInterval.restart();
    }
}

void HealthPotion::use( class Character * target ){}

