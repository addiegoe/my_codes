/*****************************************************************
 ** Program Name: Final Project
 ** Author: Emily Addiego
 ** Date: December 10, 2019
 ** Description: This is the cpp file for the kitchen class.
 ******************************************************************/

#include "kitchen.hpp"
/*****************************************************************
 ** Description: This is the constructor for the kitchen object. It
** intitializes all member variables.
 ******************************************************************/
Kitchen::Kitchen()
{
    name = "KITCHEN";
    item = "butcher's knife";
    left = NULL;
    right = NULL;
    top = NULL;
    bottom = NULL;
    level = 2;
    damage = 0;
}


/*****************************************************************
 ** Description: This is the destructor for the kitchen object.
 ******************************************************************/
Kitchen::~Kitchen()
{
    
}


/*****************************************************************
 ** Description: This is the task function. It overrides the Space
** task function. It takes one parameter, an int t, and gives the
** player a task specific to the room.
 ******************************************************************/
void Kitchen::task(int t)
{
    std::cout << "There is a larder in the kitchen." << std::endl;
    anyKey("open the door.");
    std::cout << "The horror!! In the larder are piled the mutilated BODIES of the ship's kitchen crew!" << std::endl;
    std::cout << "What unnatural beast could have done such a thing?" << std::endl;
}

