#ifndef ENEMY_H
#define ENEMY_H

// Father Class included
#include "Character.hpp"

class Enemy : public Character
{
    private:

    public:
        Enemy();    // Constructor
        ~Enemy();   // Destructor
        void virtual attack( Character * ); 
};

#endif