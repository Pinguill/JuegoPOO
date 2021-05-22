#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>
#include <string>
using std::endl;
using std::cout;
using std::cin;
using std::string;
class Entity{
    protected:
        string entName; // Entity name
        string entDescrip;// Entity description

    public:
        Entity();//constuctor
        ~Entity();//destructor
        string getEntityName();// Get entity name
        string getEntityDescrip();// Get entity description 
};
#endif
