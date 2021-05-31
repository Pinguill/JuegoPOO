#ifndef SUPERBOSS_H
#define SUPERBOSS_H

// Father Class included
#include "Character.hpp"

class SuperBoss : public Character
{
    protected:
        // Here goes the drop
    public: 
        SuperBoss();    // Constructor
        ~SuperBoss();   // Destructor
        void virtual attack ( Character * );  // Superboss attack
};

#endif