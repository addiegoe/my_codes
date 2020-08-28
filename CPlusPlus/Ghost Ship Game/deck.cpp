/*****************************************************************
 ** Program Name: Final Project
 ** Author: Emily Addiego
 ** Date: December 10, 2019
 ** Description: This is the cpp file for the deck class.
 ******************************************************************/

#include "deck.hpp"
/*****************************************************************
 ** Description: This is the constructor for the deck object. It
** initalizes all member variables.
 ******************************************************************/
Deck::Deck()
{
    name = "DECK";
    item = "none";
    left = NULL;
    right = NULL;
    top = NULL;
    bottom = NULL;
    damage = 0;
    level = 3;
}


/*****************************************************************
 ** Description: This is the destructor for the deck object.
 ******************************************************************/
Deck::~Deck()
{
    
}


/*****************************************************************
 ** Description: This is the task function. It takes one parameter,
** an int t. In this task, the player must fight a kraken. The player
** has more strength depending on which value of t was passed.
** This function overrides the Space task function.
 ******************************************************************/
void Deck::task(int t)
{
//set damage to default
    damage = 0;
    int knife = 0;
    std::string message1;
    std::string message2;
    std::cout << "The water next to the ship begins to churn and bubble. What eldrich horror is this?" << std::endl;
    std::cout << "A KRAKEN emerges from the ocean and heaves itself onto the deck! It reaches for you with its many tentacles!" << std::endl;
//add defense points if player has knife
    if (t == 8)
    {
        knife = 5;
    }
//attack and defend for three rounds
    for (int i = 0; i < 3; i++)
    {
        anyKey("fight.");
//print a different message for each round
        if (i == 0)
        {
            message1 = "The kraken flings you to the deck as easily as a child would fling a doll!";
            message2 = "You beat at the kraken and manage to slip from its grasp!";
        }
        else if (i == 1)
        {
            message1 = "You gasp for breath as the beast squeezes you in its grip!";
            message2 = "The kraken roars in rage as you slash at its tentacles!";
        }
        else
        {
            message1 = "The beast slides back into the sea, leaving you crumpled on the deck.";
            message2 = "Discouraged, the great monster sinks back into the sea. You are safe--for now.";
        }
//set up fight
    int attack = (std::rand() % 20) + 1;
    int defend = (std::rand() % 10) + 1;
//if the attack is more than the defense, player loses points
    if (attack > (defend + knife))
    {
        std::cout << message1 << std::endl;
        std::cout << "You lose 3 strength points." << std::endl;
        damage += 3;
    }
//if not, player is successful
    else
    {
        std::cout << message2 << std::endl;
        damage += 0;
    }
    }
}


/*****************************************************************
 ** Description: This is the getDamage function. It overrides the
** Space function. It returns the damage taken by the player during
** the task.
 ******************************************************************/
int Deck::getDamage()
{
    return damage;
}

