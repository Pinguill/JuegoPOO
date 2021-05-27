#ifndef ATTACKCARD_H
#define ATTACKCARD_H

#include "Character.hpp"

class AttackCard
{
    protected:

        int timeToLive; //  Numbers of times to use a determinate attack
    
    public:
        AttackCard();
        ~AttackCard();

        void virtual use( Character *, int basesDmg ) = 0;
};

#endif
