#ifndef BOSS_H
#define BOSS_H

// Father Class included
#include "Character.hpp"

class Boss : public Character
{
    protected:

    public:
        Boss();    // Constructor
        ~Boss();    // Destructor
        void virtual attack( Character * );    // Boss attack 
};

#endif