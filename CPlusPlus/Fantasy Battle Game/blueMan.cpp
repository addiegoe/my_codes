/************************************************************
 ** Program Name: Project 4
 ** Author: Emily Addiego
 ** Date: November 24, 2019
 ** Description: This is the cpp file for the Blue Men class.
 ** It contains a constructor and an overriding attack and
 ** defend function.
 ************************************************************/
#include "blueMan.hpp"

/************************************************************
 ** Description: This is the constructor for the Blue Men
 ** objects. It sets the armor, strength, and type.
 ***********************************************************/
BlueMen::BlueMen()
{
    armor = 3;
    strength = 12;
    maxStrength = 12;
    type = "Blue Men";
}

/************************************************************
 ** Description: This is the destructor for the Blue Men
 ** objects.
 ***********************************************************/
BlueMen::~BlueMen()
{
    
}

/************************************************************
 ** Description: This is the attack function. It overrides
 ** the base class attack function. It returns a the sum of
 ** two random "rolls" between 1 and 10.
 ***********************************************************/
int BlueMen::attack()
{
    int die1 = (std::rand() % 10) + 1;
    int die2 = (std::rand() % 10) + 1;
    return die1 + die2;
}


/************************************************************
 ** Description: This is the defend function. It overrides
 ** the base function. It returns a random "roll" within
 ** a different range of values depending on the Blue Men's
 ** strength points.
 ***********************************************************/
int BlueMen::defend()
{
    int roll;
    int die1 = (std::rand() % 6) + 1;
    int die2 = (std::rand() % 6) + 1;
    int die3 = (std::rand() % 6) + 1;
    //control for MOB if strength gets reduced
    if (strength > 8)
    {
        roll = die1 + die2 + die3;
    }
    else if (strength > 4 && strength <= 8)
    {
        roll = die1 + die2;
    }
    else
    {
        roll = die1;
    }
    return roll;
}

