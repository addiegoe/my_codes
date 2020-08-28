/*****************************************************************
 ** Program Name: Final Project
 ** Author: Emily Addiego
 ** Date: December 10, 2019
 ** Description: This is the cpp file for the bridge class.
 ******************************************************************/

#include "bridge.hpp"
/*****************************************************************
 ** Description: This is the constructor for the bridge object.
** It initializes all variables.
 ******************************************************************/
Bridge::Bridge()
{
    name = "BRIDGE";
    item = "none";
    left = NULL;
    right = NULL;
    top = NULL;
    bottom = NULL;
    damage = 0;
    level = 3;
}


/*****************************************************************
 ** Description: This is the destructor for the bridge object.
 ******************************************************************/
Bridge::~Bridge()
{
    
}


/*****************************************************************
 ** Description: This is the task function for Bridge. It overrides
** the Space function.
 ******************************************************************/
void Bridge::task(int t)
{
    std::cout << "There is a shadowy figure slumped in the captain's chair." << std::endl;
}

