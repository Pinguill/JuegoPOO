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
    hpBonus++;
    hp += hpBonus;

    dmgBonus++;
    dmg += dmgBonus;

    return;
};

void Herz::unApplyWeaponStats( Weapon *)
{
    hp -= hpBonus;
    hpBonus = 0;

    dmg -= dmgBonus;
    dmgBonus;

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
