#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using std::endl;
using std::cout;
using std::cin;
using std::string;

const int ONE_ANIM = 0;  // Refers to objects with only one animation sequence

class Entity{
    protected: // OJOOOO cambiar a private - DEBUG
        string entName;
        string entDescrip;
        string textureDir;
        class sf::Texture entTexture;
        class sf::Sprite entSprite;
        sf::IntRect * baseRects;
        bool collisions;
        int * baseShiftMax;
        int baseShift;
        float scale;
        int animationsNumber;
        sf::Clock animationInterval;
    public:
//        Entity( string entName, string entDescrip, string textureDir );//constuctor
//        ~Entity();//destructor
        void initSprite();
        void centerOrigin();
        string getEntityName();// Get entity name
        string getEntityDescrip();// Get entity description 
        bool getCollisions();
        class sf::Sprite * getSprite();
        const float getScale();
        virtual void updateSprite() = 0;
};

class GroundBox : public Entity{
    public:
        GroundBox();
        void updateSprite();
};

class WallBox : public Entity{
    public:
        WallBox();
        void updateSprite();
};

class AttackCard : public Entity{
    private:
        int timeToLive;
    public:
        virtual void use( class Character * target, int baseDmg ) = 0;
};

class BasicAttack : AttackCard{
    private:
        const int damageBonus = 0;
    public:
        void updateSprite();
        void use( class Character * target, int baseDmg );
};

class Character : public Entity{
    protected:
        // Here goes the attack card array 
        int hp; // Health 
        int hpBonus;    // Bonus health
        int dmg;    // Damage
        int dmgBonus;   // Bonus damage
    public:
//        Character( string entName, string entDescrip, string textureDir );    // Constructor
        virtual void updateSprite() = 0;
        virtual void attack( Character * target, class Item * weapon, class AttackCard * attackCard ) = 0; 
};

class Herz : public Character{
    private:
        // Here goes Herz's inventory with space for 10 objects
        int xLocation;
        int yLocation;
        enum AS{ IDLE, LEFT, RIGHT, ATTACK, DEAD } previousAS, currentAS;  // AS = Animation State;
        const float movingSpeed = 0.3f;
    public:
        Herz(); // Constructor
        const int getXLocation();
        const int getYLocation();
        void setXLocation( const int xLocation );
        void setYLocation( const int yLocation );
        void incrementXLocation();
        void incrementYLocation();
        void decrementXLocation();
        void decrementYLocation();
        void setCasToIdle();
        void updateSprite();
        void moveUp();
        void moveRight();
        void moveDown();
        void moveLeft();
        void moveUpRight();
        void moveDownRight();
        void moveDownLeft();
        void moveUpLeft();
        void attack( Character * target, class Item * weapon, class AttackCard * attackCard ); //To attack
};

class Skull : public Character{
    public:
        Skull();
        void updateSprite();
        void attack( class Character * target, class Item * weapon, class AttackCard * attackCard );
};

class SwampWoman : public Character{
    public:
        SwampWoman();
        void updateSprite();
        void attack( class Character * target, class Item * weapon, class AttackCard * attackCard );
};

class Mucus : public Character{
    public:
        Mucus();
        void updateSprite();
        void attack( class Character * target, class Item * weapon, class AttackCard * attackCard );
};

class Virus : public Character{
    public:
        Virus();
        void updateSprite();
        void attack( class Character * target, class Item * weapon, class AttackCard * attackCard );
};

class Minotaur : public Character{
    public:
        Minotaur();
        void updateSprite();
        void attack( class Character * target, class Item * weapon, class AttackCard * attackCard );
};

class Devil : public Character{
    public:
        Devil();
        void updateSprite();
        void attack( class Character * target, class Item * weapon, class AttackCard * attackCard );
};

class Item : public Entity{
    protected:
        int timeToLive;
    protected:
//        Item();
//        ~Item();
        virtual void updateSprite() = 0;
        virtual void use( class Character * target ) = 0;
};

class Sword : public Item{
    private:
        int strength;
        int dmg;
    public:
        Sword();
        void setStrengthAndDamage( const int strength, const int dmg );
        void updateSprite();
        void use( class Character * target );
//        const int getStrength();
//        const int getDamage();
};

class Mallet : public Item{
    private:
        int strength;
        int dmg;
    public:
        Mallet();
        void setStrengthAndDamage( const int strength, const int dmg );
        void updateSprite();
        void use( class Character * target );
//        const int getStrength();
//        const int getDamage();
};

class Bow : public Item{
    private:
        int strength;
        int dmg;
    public:
        Bow();
        void setStrengthAndDamage( const int strength, const int dmg );
        void updateSprite();
        void use( class Character * target );
//        const int getStrength();
//        const int getDamage();
};

class EscapePotion : public Item{
    private:
        bool effective;
    public:
        EscapePotion();
        void setEffective( const bool effective );
        void updateSprite();
        void use( class Character * target );
//        void getEffective();
};

class DamagePotion : public Item{
    private:
        int damageBonus;
    public:
        DamagePotion();
        void setDamageBonus( const int damageBonus );
        void updateSprite();
        void use( class Character * target );
};

class StrengthPotion : public Item{
    private:
        int strengthBonus;
    public:
        StrengthPotion();
        void setStrengthBonus( const int strengthBonus );
        void updateSprite();
        void use( class Character * target );
};

class HealthPotion : public Item{
    private:
        int healthBonus;
    public:
        HealthPotion();
        void setHealthBonus( const int healthBonus );
        void updateSprite();
        void use( class Character * target );
};

#endif
