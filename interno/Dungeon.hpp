#ifndef DUNGEON_h
#define DUNGEON_H

#include "DungeonBox.hpp"

class Dungeon
{
    protected:
    public:
        Dungeon( int dungeonSize);
        ~Dungeon();
        
        void getDungeonBox();
        void addDungeonBox( DungeonBox *, int index, int subindex );
}; 

#endif