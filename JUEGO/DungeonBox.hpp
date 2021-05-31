#ifndef DUNGEONBOX_H
#define DUNGEONBOX_H

#include "Entity.hpp"

class DungeonBox
{
    protected:
        class Entity * entity;
        
    public:
        DungeonBox();
        ~DungeonBox();

        void linkEntityToBox( Entity * );
        void unLinkEntityToBox();
        void getEntityOnBox();
};

#endif