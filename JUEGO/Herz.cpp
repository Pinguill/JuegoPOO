#include "Herz.hpp"

// Constructor
Herz::Herz()
{
};

// Destructor
Herz::~Herz()
{
};

void Herz::recoverStats()
{
    
};

void Herz::applyWeaponStats( Weapon * weapon )
{
    int dmgDone = weapon->getDmg() + dmg;

    return;
};

void Herz::unApplyWeaponStats( Weapon * weapon )
{
    int dmgDone = weapon->getDmg() - dmg;

    return;
};

void Herz::move()
{
};

void Herz::collectItem( Item * item )
{

    // If the inventory is full, it cannot add the item
    if( contInventory == 10 )
    {
        std::cout << "Inventory's full!";
    }

    else
    {
        inventory[ contInventory ] = item;
        contInventory++;
    }

    return;
};

void Herz::useItem( Item * item )
{
    
};
