#include "Entity.hpp"
Entity::Entity(){}// Constructor
Entity::~Entity(){}// Destructor
string Entity::getEntityDescrip(){ // Return entity description
    return entDescrip;
}
string Entity::getEntityName(){// Return entity name
    return entName;
}