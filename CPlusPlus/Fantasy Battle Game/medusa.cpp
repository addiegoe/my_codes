/***********************************************************
 ** Program Name: Project 4
 ** Author: Emily Addiego
 ** Date: November 24, 2019
 ** Description: This is the cpp file for the Medusa
 ** class. It contains a virtual function to
 ** override attack and defend and a constructor.
 ************************************************************/
#include "medusa.hpp"

/************************************************************
 ** Description: This is the constructor for the Medusa
 ** objects. It sets the armor, strength, and type.
 ***********************************************************/
Medusa::Medusa()
{
    armor = 3;
    strength = 8;
    maxStrength = 8;
    type = "Medusa";
}

/************************************************************
 ** Description: This is the destructor for the Medusa
 ** objects.
 ***********************************************************/
Medusa::~Medusa()
{
    
}

/************************************************************
 ** Description: This is the attack function. It overrides
 ** the base class attack function. If Medusa rolls a 12, it
 ** returns the "garbage" value of 100.
 ** Otherwise, it returns a random "roll" between 1
 ** and 11. Idea from:
 //https://piazza.com/class/k0rofchnorj31s?cid=413
 ************************************************************/
int Medusa::attack()
{
    int die1 = (std::rand() % 6) + 1;
    int die2 = (std::rand() % 6) + 1;
    int total = die1 + die2;
    if (total != 12)
    {
        return total;
    }
    //return 100 to use GLARE
    else
    {
        return 100;
    }
}


/************************************************************
 ** Description: This is the defend function. It overrides
 ** the base class function. It returns a random "roll"
 ** between 1 and 6.
 ***********************************************************/
int Medusa::defend()
{
    
    int dRoll = (std::rand() % 6) + 1;
    return dRoll;
}

