#ifndef ESCAPEPOTION_H
#define ESCAPEPOTION_H

#include "Item.hpp"

class EscapePotion : public Item
{
    protected:
        bool efective;
    public:
        EscapePotion(); // Constructor
        ~EscapePotion();    // Destructor

        void virtual use( Character * );
};

#endif