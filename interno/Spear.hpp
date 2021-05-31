#ifndef Spear_H
#define Spear_H

// Taher class included
#include "Weapon.hpp"

class Spear : public Weapon
{
    protected:
    public:
        Spear();    // Constructor
        ~Spear();   // Destructor

        void virtual attack( Character * );
        
};

#endif