#ifndef Bow_H
#define Bow_H

// Taher class included
#include "Weapon.hpp"

class Bow : public Weapon
{
    protected:
    public:
        Bow();    // Constructor
        ~Bow();   // Destructor

        void virtual attack( Character * );
        
};

#endif