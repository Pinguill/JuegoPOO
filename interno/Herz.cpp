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

void Herz::applyWeaponStats()
{
};

void Herz::unApplyWeaponStats()
{
};

void Herz::move()
{
};

void Herz::collectItem( Item * item )
{
    // If the inventory is full, it cannot add the item
    if( sizeof( inventory ) == 10 )
    {
        cout << "Inventory's full!";
    }

    return;
};

void Herz::useItem( Item * item )
{
};
