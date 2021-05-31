#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <vector>
#include "AttackCard.hpp"

class Character
{
    protected:
        class AttackCard *attackCards[3];
        int hp; // Health 
        int hpBonus = 0;    // Bonus health
        int dmg;    // Damage
        int dmgBonus = 0;   // Bonus damage
    public:
        Character();    // Constructor
        ~Character();   // Destructor
        void virtual attack( Character * ) = 0; 
                             
};

#endif