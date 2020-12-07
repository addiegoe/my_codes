/************************************************************
 ** Program Name: Project 4
 ** Author: Emily Addiego
 ** Date: November 24, 2019
 ** Description: This is the header file for the Barbarian
 ** class. It contains a constructor and destructor.
 ************************************************************/
#include "barbarian.hpp"
#include<iostream>
#include<cmath>

/************************************************************
 ** Description: This is the constructor for the Barbarian
 ** objects. It sets the armor, strength, and type.
 ***********************************************************/
Barbarian::Barbarian()
{
    armor = 0;
    strength = 12;
    maxStrength = 12;
    type = "Barbarian";
}


/************************************************************
 ** Description: This is the constructor for the Barbarian
 ** objects.
 *******************************************************/
Barbarian::~Barbarian()
{
    
}
