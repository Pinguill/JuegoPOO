#ifndef ITEM_H
#define ITEM_H
#include "Entity.hpp"
class Item: public Entity{
    protected:
        int timeToLive;

    public:
        Item();
        ~Item();
        virtual void use( class Character* ) =0;
};
#endif