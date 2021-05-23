#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <vector>

class Character
{
    protected:
        // Here goes the attack card array 
        int hp; // Health 
        int hpBonus;    // Bonus health
        int dmg;    // Damage
        int dmgBonus;   // Bonus damage
    public:
        Character();    // Constructor
        ~Character();   // Destructor
        void virtual attack( Character * ) = 0; 
                             
};

#endif