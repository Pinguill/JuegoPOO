#ifndef HERZ_H
#define HERZ_H

// Father Class included
#include "Character.hpp"
#include "Item.hpp"
#include <vector>

class Herz : public Character
{
    protected:
        Item * inventory[10];   // Herz inventory with space for 10 objects

    public:
        Herz(); // Constructor
        ~Herz(); // Destructor

        void recoverStats(); // After using some potion to increase a stat, it reestablish the stats  
        void applyWeaponStats(); //In the (), goes the weapon class pointer
        void unApplyWeaponStats();  //In the (), goes the weapon class pointer
        void move(); // To move Herz
        void collectItem( Item * ); // To collect items
        void useItem( Item * );  // To use an item
        void virtual attack( Character * ); //To attack
};

#endif