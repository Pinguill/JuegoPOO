#ifndef DUNGEON
#define DUNGEON

#include <iostream>
#include "dungeonBox.hpp"

enum BACKG_TYPE{ GD, WL };   // G = Ground, W = Wall
enum FOREG_TYPE{ P, W, E, B, S, N, I };  // E = enemy, B = Boss, S = Superboss, N = Null, I = Herz init position

enum DIF_LEVEL{ EASY, NORMAL };

class HerzSurroundings{
    public:
        class DungeonBox * right;
        class DungeonBox * left;
        class DungeonBox * up;
        class DungeonBox * down;
};
/*
class ObjectsDB{
    public:
        class WallBox * wallBoxes;
        class GroundBox * groundBoxes;

        class EscapePotion * escapePotions;
        class DamagePotion * damagePotions;
        class StrengthPotion * strengthPotions;
        class HealthPotion * healthPotions;

        class Sword * swords;
        class Mallet * mallets;
        class Bow * bows;

        class BasicAttack * basicAttacks;

        class Skull * skulls;
        class SwampWoman * swampWoman;
        class Mucus * mucuses;
        class Virus * viruses;
        class Minotaur * minotaurs;
        class Devil * devils;
    public:
        void initObjectsDB( const int width, const int height );
};
*/

class Dungeon{
    private:
        enum DIF_LEVEL dificultyLevel;
        class DungeonBox ** dungeon;
//        class ObjectsDB objectsDB;
        const float startX = 20.f;
        const float startY = 20.f;
        int dungeonWidth;
        int dungeonHeight;
        class Herz herz;
        const float boxSize = 64.f;
        const float boxScale = 3.f;
    public:
        class DungeonBox * getDungeonBox( const int index, const int subindex );
//        void linkDungeonBox( class DungeonBox * dungeonBox, const int index, const int subindex );
        const float generateScaler( const float boxSize, const float entitySize );
        const int getDungeonWidth();
        const int getDungeonHeight();
        class Herz * getHerz();
        class HerzSurroundings getHerzSurroundings();
        const float getBoxSize();
        void setDungeonWidth( const int width );
        void setDungeonHeight( const int height );
        void initDungeon( const int dificultyLevel );
//        void initDungeon( const int width, const int height );
};

#endif