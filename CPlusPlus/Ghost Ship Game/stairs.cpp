/*****************************************************************
 ** Program Name: Final Project
 ** Author: Emily Addiego
 ** Date: December 10, 2019
 ** Description: This is the cpp file for the stairs class.
 ******************************************************************/

#include "stairs.hpp"
/*****************************************************************
 ** Description: This is the constructor for the stairs objects. It
** intitalizes all member variables.
 ******************************************************************/
Stairs::Stairs()
{
    name = "STAIRWELL";
    item = "none";
    left = NULL;
    right = NULL;
    top = NULL;
    bottom = NULL;
    damage = 0;
    level = 0;
}


/*****************************************************************
 ** Description: This is the destructor for the stairs objects.
 ******************************************************************/
Stairs::~Stairs()
{
    
}


/*****************************************************************
 ** Description: This is the task function. It takes one parameter,
** an int t, and gives dfferent tasks to the player depending on the
** value of t. It overrides the Space task function.
 ******************************************************************/
void Stairs::task(int t)
{
//set damage to default
    damage = 0;
    if (t !=10)
    {
       std::cout << "What ghastly apparition is this? A horrible GHOST floats down the stairs toward you!" << std::endl;
//if you have the crucifix, use it to fight ghost
       if (t == 4)
       {
           anyKey("use the crucifix.");
           std::cout << "You raise the crucifix high and the GHOST shies away, letting you slip past unharmed." << std::endl;
           damage = 0;
           }
//otherwise, lose strength points
        else
        {
            anyKey("run up the stairs.");
            std::cout << "You run as fast as you can, but the GHOST rakes you with its foul claws as you pass!" << std::endl;
            std::cout << "A chill seeps into your bones and you lose 3 strength points." << std::endl;
            damage += 3;
        }
    }
//second stairwell has no monster but has a flask of whiskey
    else
    {
        std::cout << "There is no light in the stairwell.";
        anyKey("feel your way in the dark.");
        std::cout << "You've found a flask of whiskey. Drink it to restore your strength." << std::endl;
        damage = 0;
    }
}


/*****************************************************************
 ** Description: This is the getDamage function. It returns the
** damage that the player received in this room. It overrides the Space
** function.
 ******************************************************************/
int Stairs::getDamage()
{
    return damage;
}

