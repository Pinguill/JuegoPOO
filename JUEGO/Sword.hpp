#ifndef SWORD_H
#define SWORD_H

// Taher class included
#include "Weapon.hpp"

class Sword : public Weapon
{
    protected:
    public:
        Sword();    // Constructor
        ~Sword();   // Destructor

        void virtual attack( Character * );
        
};

#endif