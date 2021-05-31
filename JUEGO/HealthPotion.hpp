#ifndef HealthPotion_H
#define HealthPotion_H

#include "Item.hpp"

class HealthPotion : public Item
{
    protected:
        int strenghtBonus;
    public:
        HealthPotion();
        ~HealthPotion();
        
        void virtual use( Character * );
};

#endif