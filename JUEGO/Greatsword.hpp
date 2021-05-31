#ifndef Greatsword_H
#define Greatsword_H

// Taher class included
#include "Weapon.hpp"

class Greatsword : public Weapon
{
    protected:
    public:
        Greatsword();    // Constructor
        ~Greatsword();   // Destructor

        void virtual attack( Character * );
        
};

#endif