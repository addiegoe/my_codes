/*****************************************************************
 ** Program Name: Final Project
 ** Author: Emily Addiego
 ** Date: December 10, 2019
 ** Description: This is the cpp file for the Space class.
 ******************************************************************/
#include<iostream>
#include "space.hpp"
#include<limits>
/*****************************************************************
 ** Description: This is the constructor for the Space class. It
** initializes all member variables.
 ******************************************************************/
Space::Space()
{
    name = "ROOM";
    item = "none";
    left = NULL;
    right = NULL;
    top = NULL;
    bottom = NULL;
    level = 1;
    damage = 0;
}

/*****************************************************************
 ** Description: This is the destructor for the Space class.
 ******************************************************************/
Space::~Space()
{
    
}


/*****************************************************************
 ** Description: This is the virtual task function. It takes one parameter,
** an int t, and gives the player a different task depending on the
** value of t.
 ******************************************************************/
void Space::task(int t)
{
//generate a different task based on value passed to function
    if (t == 1)
    {
        anyKey("look out the window.");
        std::cout << "The ship is surrounded by dense fog. There is something eerie about it. As you watch, the mist twists into strange shapes—almost like the faces of souls in torment." << std::endl;
    }
//second room
    else if (t == 2)
    {
        std::cout << "You find a diary." << std::endl;
        anyKey("open it to the latest entry.");
        std::cout << "You read the unnerving text." << std::endl;
        std::cout << "'JANUARY 14th, 1918:" << std::endl;
        std::cout << "Weeks have passed and we are still adrift. Water, water, all around, and things in the water. ";
        std::cout << "Things that slither and slide and call to me to join them...'" << std::endl;
    }
//third room and fifth room
    else if (t == 3)
    {
        std::cout << "There is a bed in the room. ";
        anyKey("look under the pillow.");
        std::cout << "You find a flask of whiskey. Drink it to restore your strength." << std::endl;
    }
//captain's quarters -- if the player can unlock the desk
    else if (t == 7)
    {
        std::cout << "There is a desk in the room, but it is locked." << std::endl;
        anyKey("pick the lock.");
        std::cout << "The drawer pops open." << std::endl;
    }
//otherwise, make player return to get correct items
    else
    {
        std::cout << "There is a desk in the room, but it is locked." << std::endl;
        std::cout << "You can't get it open. You need the hairpin or the fork to pick the lock." << std::endl;
    }
}


/*****************************************************************
 ** Description: This is the virtual getDamage function. It returns 0.
 ******************************************************************/
int Space::getDamage()
{
    return 0;
}


/*****************************************************************
 ** Description: This function sets the left Space pointer.
 ******************************************************************/
void Space::setLeft(Space *l)
{
    left = l;
}

/*****************************************************************
 ** Description: This function sets the right Space pointer.
 ******************************************************************/
void Space::setRight(Space *r)
{
    right = r;
}

/*****************************************************************
 ** Description: This function sets the top Space pointer.
 ******************************************************************/
void Space::setTop(Space *t)
{
    top = t;
}

/*****************************************************************
 ** Description: This function sets the bottom Space pointer.
 ******************************************************************/
void Space::setBottom(Space *b)
{
    bottom = b;
}

/*****************************************************************
 ** Description: This function sets the name of the Space.
 ******************************************************************/
void Space::setName(std::string n)
{
    name = n;
}

/*****************************************************************
 ** Description: This function sets the item in the Space.
 ******************************************************************/
void Space::setItem(std::string i)
{
    item = i;
}

/*****************************************************************
 ** Description: This functiuon returns the left pointer.
 ******************************************************************/
Space* Space::getLeft()
{
    return left;
}

/*****************************************************************
 ** Description: This function returns the right pointer.
 ******************************************************************/
Space* Space::getRight()
{
    return right;
}

/*****************************************************************
 ** Description: This function returns the top pointer.
 ******************************************************************/
Space* Space::getTop()
{
    return top;
}


/*****************************************************************
 ** Description: This function returns the bottom pointer.
 ******************************************************************/
Space* Space::getBottom()
{
    return bottom;
}


/*****************************************************************
 ** Description: This function returns the space's name.
 ******************************************************************/
std::string Space::getName()
{
    return name;
}


/*****************************************************************
 ** Description: This function returns the space's item.
 ******************************************************************/
std::string Space::getItem()
{
    return item;
}


/*****************************************************************
 ** Description: This function sets the space's level.
 ******************************************************************/
void Space::setLevel(int l)
{
    level = l;
}


/*****************************************************************
 ** Description: This function returns the space's level.
 ******************************************************************/
int Space::getLevel()
{
    return level;
}


/*****************************************************************
 ** Description: This is the anyKey function. It takes one parameter,
** a string message, and instructs the player to press any key to
** do the action described in the message.
** Source: https://faq.cprogramming.com/cgi-bin/smartfaq.cgi?id=1043284385&answer=1042856625
 ******************************************************************/
void Space::anyKey(std::string message)
{
    std::cout<<"Press [Enter] to " << message;
    std::cin.get();
}

