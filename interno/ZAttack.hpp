#ifndef ZATTACK_H
#define ZATTACK_H

// Father class included
#include "AttackCard.hpp"

class ZAttack
{
    private:
    public:
        ZAttack(); // Constructor
        ~ZAttack(); // Destructor

        void virtual use( Character *, int baseDmg );
};

#endif