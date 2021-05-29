#ifndef DAMAGEPOTION_H
#define DAMAGEPOTION_h

#include "Item.hpp"

class DamagePotion : public Item
{
    protected:
    public:
        DamagePotion(); // Constructor
        ~DamagePotion();    // Destructor

        void virtual use( Character * );
};

#endif