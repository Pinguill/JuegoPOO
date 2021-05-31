#ifndef WEAPON_H
#define WEAPON_H

#include "Character.hpp"

class Weapon : public Character
{
    protected:
        int strenght;   // Number of uses of the weapon
        int dmg;    // Weapon damage
    public:
        Weapon();   // Constructor
        ~Weapon();  // Destructor

        void virtual use( Character * character );  // Use the weapon
        int getStrenght();  // To get the strenght value
};

#endif
