 /*****************************************************************************
 ** Program Name: Project 2
 ** Author: Emily Addiego
 ** Date: October 27, 2019
 ** Description: This is the cpp file for the Animal4 class. It contains a
 ** constructor to initalize variables.
 ******************************************************************************/
#include <iostream>
#include "animal4.hpp"

/******************************************************************************
** Description: This is the Animal4 constructor. It initializes all member
** variables to 0, since they will later be set by the user.
*******************************************************************************/

Animal4::Animal4()
    {
        age = 0;
        cost = 0;
        numberOfBabies = 0;
        baseFoodCost = 0;
        payoff = 0;
    }

