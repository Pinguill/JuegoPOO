#ifndef XATTACK_H
#define XATTACK_H

// Father class included
#include "AttackCard.hpp"

class XAttack
{
    private:
    public:
        XAttack(); // Constructor
        ~XAttack(); // Destructor

        void virtual use( Character *, int baseDmg );
};

#endif