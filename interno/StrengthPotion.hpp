#ifndef STRENGTHPOTION_H
#define STRENGTHPOTION_H

#include "Item.hpp"

class StrengthPotion : public Item
{
    protected:
        int strenghtBonus;
    public:
        StrengthPotion();
        ~StrengthPotion();
        
        void virtual use( Character * );
};

#endif