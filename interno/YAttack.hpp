#ifndef YATTACK_H
#define YATTACK_h

// Father class included
#include "AttackCard.hpp"

class YAttack
{
    private:
    public:
        YAttack();  // Constructor
        ~YAttack(); // Destructor
        
        void virtual use( Character *, int baseDmg );
};

#endif