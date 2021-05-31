#ifndef HERZ_H
#define HERZ_H

// Father Class included
#include "Character.hpp"
#include "Weapon.hpp"

class Herz : public Character
{
    protected:
        
        class Item *inventory[10];   // Herz inventory with space for 10 objects
        int contInventory = 0;  // Useful to know how many objects are in the inventory
        
    public:
        Herz(); // Constructor
        ~Herz(); // Destructor

        void recoverStats(); // After using some potion to increase a stat, it reestablish the stats  
        void applyWeaponStats( Weapon * );  
        void unApplyWeaponStats( Weapon * );  
        void move(); // To move Herz
        void collectItem( Item * ); // To collect items
        void useItem( Item * );  // To use an item
        void virtual attack( Character * ); //To attack
};

#endif