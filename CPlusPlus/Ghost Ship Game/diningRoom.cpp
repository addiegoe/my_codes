/*****************************************************************
 ** Program Name: Final Project
 ** Author: Emily Addiego
 ** Date: December 10, 2019
 ** Description: This is the cpp file for the dining room class.
 ******************************************************************/

#include "diningRoom.hpp"
/*****************************************************************
 ** Description: This is the constructor for the dining room object.
** It initializes all member variables.
 ******************************************************************/
DiningRoom::DiningRoom()
{
    name = "DINING ROOM";
    item = "fork";
    left = NULL;
    right = NULL;
    top = NULL;
    bottom = NULL;
    damage = 0;
    level = 2;
}


/*****************************************************************
 ** Description: This is the destructor for the dining room object.
 ******************************************************************/
DiningRoom::~DiningRoom()
{
    
}


/*****************************************************************
 ** Description: This is the task function. It overrides the Space
** task function. It takes one parameter, an int t, and pits the
** user in a fight against the cook. (The fight is based on Project 3).
 ******************************************************************/
void DiningRoom::task(int t)
{
//set damage to default
    damage = 0;
    std::cout << "A fearsome shape emerges from behind the bar, lurching and lumbering toward you!" << std::endl;
    std::cout << "It is a GHOUL--the ship's undead cook, his apron stained with blood!" << std::endl;
    anyKey("defend yourself.");
//set up attack and defense -- based on project 3
    int attack1 = (std::rand() % 15) + 1;
    int defend1 = (std::rand() % 10) + 1;
    if (attack1 > defend1)
    {
        std::cout << "The cook tears at you with his evil hands!" << std::endl;
        std::cout << "You've been injured! You lose 3 strength points!" << std::endl;
        damage += 3;
    }
    else
    {
        std::cout << "You manage to evade him--for now!" << std::endl;
        damage += 0;
    }
    std::cout << "He comes at you again!" << std::endl;
    anyKey("get away.");
//set up second attack
    int attack2 = (std::rand() % 10) + 1;
    int defend2 = (std::rand() % 10) + 1;
    if (attack2 > defend2)
    {
        std::cout << "The cook bites at you with his foul jaws!" << std::endl;
        std::cout << "You've been injured, but you manage to get away! You lose 3 strength points!" << std::endl;
        damage += 3;
    }
    else
    {
        std::cout << "You hit him with a serving platter and he slumps to the ground." << std::endl;
        damage += 0;
    }
}


/*****************************************************************
 ** Description: This is the getDamage function. It overrides the 
** Space function. It returns the amount of damage taken by the player
** during the fight.
 ******************************************************************/
int DiningRoom::getDamage()
{
    return damage;
}

