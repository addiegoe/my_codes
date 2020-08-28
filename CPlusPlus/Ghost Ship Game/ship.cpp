/*****************************************************************
 ** Program Name: Final Project
 ** Author: Emily Addiego
 ** Date: December 10, 2019
 ** Description: This is the cpp file for the Ship class.
 ******************************************************************/

#include<iostream>
#include "ship.hpp"
#include<vector>
#include<algorithm>
#include<sstream>

/*****************************************************************
 ** Description: This is the default constructor for the ship class.
 ******************************************************************/
Ship::Ship()
{
}


/*****************************************************************
 ** Description: This is the makeShip function. It assigns all pointers
** to new Space or derived objects and links them to create the structure
** of the ship. Then, it sets the playerAt pointer to the beginning room
** of the game.
 ******************************************************************/
void Ship::makeShip()
{
//make all the rooms
    cabin1 = new Space;
    cabin2 = new Space;
    cabin3 = new Space;
    cabin4 = new Space;
    cabin5 = new Space;
    stair1 = new Stairs;
    stair2 = new Stairs;
    bridge = new Bridge;
    dining = new DiningRoom;
    kit = new Kitchen;
    deck = new Deck;
//link rooms to each other and set member variables
    cabin1->setName("YOUR BERTH");
    cabin1->setRight(cabin2);
//second room
    cabin2->setName("BERTH 445");
    cabin2->setItem("candle");
    cabin2->setLeft(cabin1);
    cabin2->setRight(cabin3);
//third room
    cabin3->setName("BERTH 921");
    cabin3->setItem("crucifix");
    cabin3->setLeft(cabin2);
    cabin3->setTop(stair1);
//first stair
    stair1->setBottom(cabin3);
    stair1->setTop(cabin4);
//fourth room
    cabin4->setName("BERTH 85");
    cabin4->setItem("hairpin");
    cabin4->setBottom(stair1);
    cabin4->setLeft(kit);
    cabin4->setLevel(2);
//kitchen
    kit->setRight(cabin4);
    kit->setLeft(dining);
//dining room
    dining->setRight(kit);
    dining->setLeft(cabin5);
//captain's quarters
    cabin5->setName("CAPTAIN'S QUARTERS");
    cabin5->setItem("map");
    cabin5->setRight(dining);
    cabin5->setTop(stair2);
    cabin5->setLevel(2);
//stairwell
    stair2->setName("DARKENED STAIRWELL");
    stair2->setItem("rope");
    stair2->setBottom(cabin5);
    stair2->setTop(deck);
//deck
    deck->setBottom(stair2);
    deck->setRight(bridge);
//bridge
    bridge->setLeft(deck);
//place the player
    playerAt = cabin1;
}


/*****************************************************************
 ** Description: This is the deleteShip function. It deletes all
** new space and derived class objects and frees the memory.
 ******************************************************************/
void Ship::deleteShip()
{
//delete all new objects to free memory
    delete cabin1;
    cabin1 = NULL;
    delete cabin2;
    cabin2 = NULL;
    delete cabin3;
    cabin3 = NULL;
    delete cabin4;
    cabin4 = NULL;
    delete cabin5;
    cabin5 = NULL;
    delete stair1;
    stair1 = NULL;
    delete stair2;
    stair2 = NULL;
    delete bridge;
    bridge = NULL;
    delete dining;
    dining = NULL;
    delete kit;
    kit = NULL;
    delete deck;
    deck = NULL;
    playerAt = NULL;
}


/*********************************************************************
 ** Description: This is the room function. It tells the player which
** room they are in and checks for death/loss or gain of strength. It
** also calls the appropriate task by calling the space task function
** and passing the value from getTask to it.
**********************************************************************/
void Ship::room()
{
    std::cout << '\n';
    std::cout << "_____________________________________________________" << std::endl;
    std::cout << "You are in " << playerAt->getName() << std::endl;
//generate the task
    playerAt->task(getTask());
//get any damage created by task and check for player's death
    strength -= playerAt->getDamage();
    if (strength <= 0)
    { 	
    dead = true;
    }
//if player is in a room with whiskey, add to strength
    if (playerAt->getName() == "BERTH 921" || playerAt->getName() == "BERTH 85" || playerAt->getName() == "DARKENED STAIRWELL")
    {
        strength += 3;
        std::cout << "You've gained 3 points of strength." << std::endl;
    }
    
}


/*****************************************************************
 ** Description: This is the getItem function. It prints what
** the item is if the room has an item, and offers the choice to take
** the item. In special cases for some rooms, it prints a specific message.
 ******************************************************************/
void Ship::getItem()
{
//print different message depending on room or item
    if ((playerAt->getItem() == "none") && (playerAt->getName() != "BRIDGE"))
    {
        std::cout << "There are no items here." << std::endl;
    }
//special case for bridge
    else if (playerAt->getName() == "BRIDGE")
    {
        std::cout << "You tremble in fear." << std::endl;
    }
//can't get map without a way to open the desk
    else if ((playerAt->getItem() == "map") && (canOpen() == false))
    {
        std::cout << "You can't get this item without unlocking the desk." << std::endl;
    }
//default case
    else
    {
        std::cout << "There is a " << playerAt->getItem() << " in the room.";
        std::cout << " It could be useful. Would you like to take it with you?" << std::endl;
        std::cout << "1. Yes" << std::endl;
        std::cout << "2. No" << std::endl;
        int add = inputV(0, 3);
        if (add == 1)
        {
            addItem(playerAt->getItem());
        }
        
    }
}


/*****************************************************************
 ** Description: This function adds an item to the container vector
** if the olayer hasn't reached capacity of 3, or gives the choice to
** delete an item and add a new one if the player already has 3 items.
 ******************************************************************/
void Ship::addItem(std::string i)
{
//add item is there is room
    if (container.size() < 3)
    {
        container.push_back(i);
        std::cout << "You are now taking the " << i << " with you." << std::endl;
    }
    else
    {
//offer the option to leave an item behind
        std::cout << "Sorry, you don't have enough room to carry anything else." << std::endl;
        std::cout << "Would you like to leave something behind?" << std::endl;
        std::cout << "1. Yes" << std::endl;
        std::cout << "2. No" << std::endl;
        int leave = inputV(0, 3);
        if (leave == 1)
        {
            std::cout << "Choose an item to remove." << std::endl;
            for (int j = 0; j < 3; j++)
            {
                std::cout << j + 1 << "." << container.at(j) << std::endl;
            }
            int remove = inputV(-1, 4);
            container.erase(container.begin() + (remove - 1));
            container.push_back(i);
            std::cout << "You are now taking the " << i << " with you." << std::endl;
        }
    }
    
}


/*****************************************************************
 ** Description: This function returns a different int value depending
** on the room the player is in. The value is used in calling the
** specific task for each room.
 ******************************************************************/
int Ship::getTask()
{
//return a different value based on which room you are in--this determines the task
    if (playerAt->getName() == "YOUR BERTH")
    {
        return 1;
    }
    else if (playerAt->getName() == "BERTH 445")
    {
        return 2;
    }
//these two rooms have the same task
    else if (playerAt->getName() == "BERTH 921" || playerAt->getName() == "BERTH 85" )
    {
        return 3;
    }
//check if necessary items are in container, and pass a garbage value if they aren't
    else if (playerAt->getName() == "STAIRWELL")
    {
        if (haveCrucifix() == true)
        {
            return 4;
        }
        else
        {
            return 20;
        }
    }
    else if (playerAt->getName() == "KITCHEN")
    {
        return 5;
    }
  //check if necessary items are in container, and pass a garbage value if they aren't
    else if (playerAt->getName() == "CAPTAIN'S QUARTERS")
    {
        if (canOpen() == true)
        {
            return 7;
        }
        else
        {
            return 30;
        }
    }
//check if necessary items are in container, and pass a garbage value if they aren't
    else if (playerAt->getName() == "DECK")
    {
        if (haveKnife() == true)
        {
            return 8;
        }
        else
        {
            return 40;
        }
    }
    else if (playerAt->getName() == "BRIDGE")
    {
        return 9;
    }
    else if (playerAt->getName() == "DARKENED STAIRWELL")
    {
        return 10;
    }
//return 6 for dining room, which is the only other room left
    else
    {
        return 6;
    }
}


/*****************************************************************
 ** Description: this is the movePlayer function. If the player is
** alive, it offers the option to move forward or back. It moves the
** player depending on their choice. If-else statements track which
** room the player is in and control for edge cases, so the player
** can't move outside the scope of the game. After the player moves,
** it subtracts one point from the player's strength.
 ******************************************************************/
void Ship::movePlayer()
{
//check if player is dead and can't move on
    if (strength <= 1)
    {
            dead = true;
            std::cout << "Alas, your strength is gone! You have died!" << std::endl;
    }
//special case scenario for last room
    else if (playerAt->getName() == "BRIDGE")
    {
            finalBattle();
            if (dead == false)
            {
                if (haveMap() == true)
                {
                    std::cout << "Your ordeal is nearly over! The latitude and longitude of your home are on the map." << std::endl;
                    playerAt->anyKey("set your coordinates for home.");
                    win = true;
                }
                else
                {
                    std::cout << "You can't go home without a map. Go back to the captain's quarters to get it." << std::endl;
                    playerAt = playerAt->getLeft();
                }
            }
    }
//for all other rooms
    else
    {
    std::cout << "It's time to move on. What do you want to do?" << std::endl;
    std::cout << "1. Move forward" << std::endl;
    std::cout << "2. Go back" << std::endl;
    int choice = inputV(0, 3);
//leaving first room
    if ((choice == 1) && (playerAt->getName() == "YOUR BERTH"))
    {
    std::cout << "Moving forward to " << playerAt->getRight()->getName() << std::endl;
    playerAt = playerAt->getRight();
    }
    else if ((choice == 2) && (playerAt->getName() == "YOUR BERTH"))
    {
        std::cout << "You can't stay in your berth forever!" << std::endl;
        std::cout << "Moving forward to " << playerAt->getRight()->getName() << std::endl;
        playerAt = playerAt->getRight();
    }
//other movements on level 1 (left to right movements)
    else if ((playerAt->getName() != "YOUR BERTH") && (playerAt->getLevel() == 1))
    {
//middle rooms
        if ((playerAt->getLeft() != NULL) && (playerAt->getRight() != NULL))
        {
            if (choice == 1)
            {
                std::cout << "Moving on to " << playerAt->getRight()->getName() << std::endl;
                playerAt = playerAt->getRight();
            }
            else
            {
                std::cout << "Going back to the " << playerAt->getLeft()->getName() << std::endl;
                playerAt = playerAt->getLeft();
            }
        }
//edge rooms
        else
        {
            if (choice == 1)
            {
                std::cout << "Moving up to " << playerAt->getTop()->getName() << std::endl;
                playerAt = playerAt->getTop();
            }
            else
            {
                std::cout << "Going back to the " << playerAt->getLeft()->getName() << std::endl;
                playerAt = playerAt->getLeft();
            }
            
        }
    }
//movements in stairwells
    else if (playerAt->getLevel() == 0)
    {
        if (choice == 1)
        {
            std::cout << "Moving up to " << playerAt->getTop()->getName() << std::endl;
            playerAt = playerAt->getTop();
        }
        else
        {
            std::cout << "Going back down to the " << playerAt->getBottom()->getName() << std::endl;
            playerAt = playerAt->getBottom();
        }
    }
//movements for level 2 (right to left movement)
    else if (playerAt->getLevel() == 2)
    {
//middle rooms
        if ((playerAt->getLeft() != NULL) && (playerAt->getRight() != NULL))
        {
            if (choice == 1)
            {
                std::cout << "Moving on to " << playerAt->getLeft()->getName() << std::endl;
                playerAt = playerAt->getLeft();
            }
            else
            {
                std::cout << "Going back to the " << playerAt->getRight()->getName() << std::endl;
                playerAt = playerAt->getRight();
            }
        }
//edge rooms
        else if (playerAt->getName() == "BERTH 85")
        {
            if (choice == 1)
            {
                std::cout << "Moving to " << playerAt->getLeft()->getName() << std::endl;
                playerAt = playerAt->getLeft();
            }
            else
            {
                std::cout << "Going back down to the " << playerAt->getBottom()->getName() << std::endl;
                playerAt = playerAt->getBottom();
            }
            
        }
        else
        {
            if (choice == 1)
            {
                std::cout << "Moving up to " << playerAt->getTop()->getName() << std::endl;
                playerAt = playerAt->getTop();
            }
            else
            {
                std::cout << "Going back to the " << playerAt->getRight()->getName() << std::endl;
                playerAt = playerAt->getRight();
            }
        }
    }
//level 3 movements
    else if (playerAt->getLevel() == 3)
    {
//deck
        if (playerAt->getName() == "DECK")
        {
            if (choice == 1)
            {
                std::cout << "Moving on to the BRIDGE" << std::endl;
                playerAt = playerAt->getRight();
            }
            else
            {
                std::cout << "Going back down to the " << playerAt->getBottom()->getName() << std::endl;
                playerAt = playerAt->getBottom();
            }
        }
    }
//subtract from strength every time player moves
        strength -= 1;
        std::cout << "You have " << strength << " strength points left." << std::endl;
        
    }
}


/*****************************************************************
 ** Description: This function checks if the player has the fork or
** hairpin items in their container and returns true if they do, or
** false if they don't.
** Source: https://stackoverflow.com/questions/6277646/in-c-check-if-stdvectorstring-contains-a-certain-value
 ******************************************************************/
bool Ship::canOpen()
{
    if ((std::find(container.begin(), container.end(), "hairpin") != container.end()) || (std::find(container.begin(), container.end(), "fork") != container.end()))
    {
        return true;
    }
    else
    {
        return false;
    }
}


/*****************************************************************
 ** Description: This function checks if the player has the knife
** in their container vector, and returns true if yes, false if no.
 //https://stackoverflow.com/questions/6277646/in-c-check-if-stdvectorstring-contains-a-certain-value
 ******************************************************************/
bool Ship::haveKnife()
{
     if (std::find(container.begin(), container.end(), "butcher's knife") != container.end())
     {
         return true;
     }
     else
     {
         return false;
     }
    
}


/*****************************************************************
 ** Description: This function checks if the player has the crucifix
** item in their container vector and returns true if yes, false if no.
 //https://stackoverflow.com/questions/6277646/in-c-check-if-stdvectorstring-contains-a-certain-value
 ******************************************************************/
bool Ship::haveCrucifix()
{
    if (std::find(container.begin(), container.end(), "crucifix") != container.end())
    {
        return true;
    }
    else
    {
        return false;
    }
    
}


/*****************************************************************
 ** Description: This function checks if the player has the map item
** in their container vector, and returns true if yes, false if no.
 //https://stackoverflow.com/questions/6277646/in-c-check-if-stdvectorstring-contains-a-certain-value
 ******************************************************************/
bool Ship::haveMap()
{
    if (std::find(container.begin(), container.end(), "map") != container.end())
    {
        return true;
    }
    else
    {
        return false;
    }
    
}


/*****************************************************************
 ** Description: This function stages a battle between the player
** and the zombie captain of the ship. The attack/defense structure
** is based on project 3 and 4. This function is called in the last
** room of the ship.
 ******************************************************************/
void Ship::finalBattle()
{
    int captStrength = 7;
    std::cout << "The chair swivels and you see a GHOUL that was once the captain! He lunges at you, his eyes milky and possessed of a strange, fiendish light!" << std::endl;
//attack and defend until captain is dead or you are dead
    do {
    playerAt->anyKey("fight.");
//set up fight -- based on project 3
        int attack = (std::rand() % 10) + 1;
        int defend = (std::rand() % 10) + 1;
        if (attack > defend)
        {
            std::cout << "The captain tears at you with his gnarled hands!" << std::endl;
            std::cout << "You lose 1 strength point." << std::endl;
            strength -= 1;
        }
        else
        {
        std::cout << "You swing at the ghoul with a spyglass." << std::endl;
        captStrength -= 4;
        }
        if ((strength > 0) && (captStrength > 0))
        {
            std::cout << "You must defeat the captain to set a course for home! You haven't bested him yet!" << std::endl;
        }
//if player's strength <= 0, they have died
        else if ((strength <= 0) && (captStrength > 0))
        {
            std::cout << "The captain has killed you!" << std::endl;
            dead = true;
        }
//if the captain's strength is < 0, the player is the winner.
        else
        {
            std::cout << "You've defeated the monstrous captain!" << std::endl;
        }
    } while ((strength > 0) && (captStrength > 0));
    }



/*****************************************************************
 ** Description: This is the gameState function. It returns a different
** int value depending on whether the game is in progress, won, or lost.
 ******************************************************************/
int Ship::gameState()
{
    if ((win == false) && (dead == false))
    {
        return 1;
    }
    else if (win == true)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}



/*****************************************************************
 ** Description: This is the reset function. It resets all values
** and places the player back at the start of the game so they can play 
** again.
 ******************************************************************/
void Ship::reset()
{
//reset all values to the beginning of the game
    strength = 15;
    dead = false;
    win = false;
    container.clear();
    playerAt = cabin1;
}


/******************************************************************************
 ** Description: This is the inputV function. It takes two parameters an int
 ** min and an int max. It uses getline to get the entire user input, converts
 ** the input to a stream, then checks if the stream is an integer between the
 ** min and the max. If it is not, the function asks for input in a loop until
 ** correct input is entered. This function is reused from Project 1 and is
 ** based on Cuddlebuddie928's function from the following thread:
 ** http://www.cplusplus.com/forum/beginner/58833/
 ******************************************************************************/
int Ship::inputV(int min, int max)
{
    int n;
    std::string s;
    
    while(true) {
        //use getline to get entire line
        getline(std::cin, s);
        //convert string to stream
        std::stringstream convert(s);
        //check if stream is an integer and if it is within the minmum and maximum range
        if((convert >> n) && (!(convert >> s)) && (n > min) && (n < max))
        {
            return n;
        }
        else
        {
            std::cin.clear();
            std::cout << "Incorrect input. Try again." << std::endl;
        }
    }
}
