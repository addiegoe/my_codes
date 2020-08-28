/********************************************************************
 ** Program Name: Lab 4
 ** Author: Emily Addiego
 ** Date: October 27, 2019
 ** Description: This is the cpp file for the Building class.
 ********************************************************************/
#include <iostream>
#include "building.hpp"

Building::Building()
{
    
}

/********************************************************************
 ** Description: This is the constructoor for the Building class. it
 ** takes three parameters, a string for name, an int for size, and
 ** a string for address.
 ********************************************************************/
Building::Building(string n, int s, string a)
{
    name = n;
    size = s;
    address = a;
}

/********************************************************************
 ** Description: This is the getName function. It returns the name
 ** of the building.
 ********************************************************************/
string Building::getName()
{
    return name;
}

/********************************************************************
 ** Description: This is the getSize function. It returns the size
 ** of the building.
 ********************************************************************/
int Building::getSize()
{
    return size;
}

/********************************************************************
 ** Description: This is the getAddress function. It returns the
 ** address of the building.
 ********************************************************************/
string Building::getAddress()
{
    return address;
}
