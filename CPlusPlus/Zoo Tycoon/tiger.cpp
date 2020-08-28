/******************************************************************************
 ** Program Name: Project 2
 ** Author: Emily Addiego
 ** Date: October 27, 2019
 ** Description: This is the cpp file for the Tiger class. It contains a
 ** constructor to initalize variables.
 ******************************************************************************/
#include <iostream>
#include "tiger.hpp"

/******************************************************************************
** Description: This is the Tiger constructor. It initializes all member
** variables to the values set in the assignment.
*******************************************************************************/

Tiger::Tiger()
    {
        age = 0;
        cost = 10000;
        numberOfBabies = 1;
        baseFoodCost = 50;
        payoff = 2000;
    }
