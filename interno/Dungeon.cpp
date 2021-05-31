#include "Dungeon.hpp"

Dungeon::Dungeon( int dungeonSize )
{
    class Entity * dungeonMatrix[ dungeonSize ][ dungeonSize ];

    int listDungeon10[ 1,0, 1,1, 1,2, 2,2, 3,2, 4,2, 5,2, 6,2, 7,2, 7,3, 7,4, 7,5, 6,5, 5,5 , 4,5, 3,5 , 3,2, 2,5,
                       2,6, 2,7, 3,7, 4,7, 5,7, 6,7, 7,7, 7,8, 7,9 ];

    int listDungeon15[ 2,14, 2,13, 2,12, 2,11, 3,11, 4,11, 5,11, 6,11, 7,11, 7,10, 7,9, 7,8, 7,7, 7,6, 6,6, 5,6, 4,6,  
                       3,6, 2,6, 2,5, 2,4, 2,3, 3,3, 4,3, 5,3, 5,2, 5,1, 6,1, 7,1, 8,1, 9,1, 10,1, 10,2, 10,3, 10,4, 
                       10,5, 10,6, 11,6, 12,6, 12,7, 12,8, 12,9, 12,10, 12,12, 12,13, 12,14 ];

    int cont = 0;
    Entity * dungeonB;
    DungeonBox dungeonB;

    if ( dungeonSize == 10 )
    {
        for( int i = 0; i < 10; i++)
        {
            for( int j = 0; j < 10; j++ )
            {
                if( i == listDungeon10[ cont ] && j == listDungeon10[ cont+1 ] )
                {
                    dungeonMatrix[ i ][ j ] = dungeonB;
                }
                cont += 2;
            }
        }
    }

    else if ( dungeonSize == 15 )
    {
        for( int i = 0; i < 15; i++)
        {
            for( int j = 0; j < 15; j++ )
            {
                if( i == listDungeon15[ cont ] && j == listDungeon15[ cont+1 ] )
                {
                    dungeonMatrix[ i ][ j ] = dungeonB;
                }
                cont += 2;
            }
        }
    }

    else
    {
        cout << "\nOpcion no disponible actualmente" << std::endl;
    }
};

Dungeon::~Dungeon()
{
};

void Dungeon::getDungeonBox()
{
};

void Dungeon::addDungeonBox( DungeonBox * dungeonBox, int index, int subindex )
{
};