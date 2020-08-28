/*****************************************************************
 ** Program Name: Final Project
 ** Author: Emily Addiego
 ** Date: December 10, 2019
 ** Description: This is the cpp file for the game class.
 ******************************************************************/

#include<iostream>
#include<ctime>
#include "game.hpp"

/*****************************************************************
 ** Description: This is the setUp function. It calls the makeShip
** function with the ship object, prints the game's rules, and calls
** the menu.
 ******************************************************************/
void Game::setUp()
{
//make the ship
    ghostShip.makeShip();
//print out the game rules
    std::cout << "You wake up in your berth after days of fever, to find that the ship has drifted off-course. " << std::endl;
    std::cout << "There is no one else aboard -- at least, no one human! " << std::endl;
    std::cout << "To win the game, you must make it to the ship's bridge to set a course for home. " << std::endl;
    std::cout << "Along the way, you will have the chance to gather items and battle monsters. " << std::endl;
    std::cout << "But be careful! If your strength reaches 0 before you can accomplish your goal, you will die!" << std::endl;
//call the menu    
    menu();
}

/*****************************************************************
 ** Description: This is the menu function. It offers the player
** the choice to play or quit. If the choice is 1, it calls gamePlay
** the play the game, then resets all variables and calls itselt again.
** If the choice is 2, it prints a goodbye message and deletes the
** dynamically allocated memory.
 ******************************************************************/
void Game::menu()
{
    std::cout << "1. Play the game" << std::endl;
    std::cout << "2. Quit" << std::endl;
    int choice = ghostShip.inputV(0, 3);
    if (choice != 2)
    {
//play game until end is reached
        gamePlay();
//reset variables for another round
        ghostShip.reset();
//call menu again
        menu();
    }
//free all memory and print goodbye
    else
    {
        ghostShip.deleteShip();
        std::cout << "Goodbye." << std::endl;
    }
}


/*****************************************************************
 ** Description: This is the gamePlay function. It loops the room,
** getItem, and movePlayer functions, checking if the player has won,
** lost, or died. If the game has ended, it checks the gamestate and
** prints a message.
 ******************************************************************/
void Game::gamePlay()
{
//seed rand for fighting tasks
    std::srand(time(0));
//loop until end of game
    while (ghostShip.gameState() == 1)
    {
        ghostShip.room();
//check if player is dead after the task, if not, get the item and move
        if (ghostShip.gameState() == 1)
        {
        ghostShip.getItem();
        ghostShip.movePlayer();
        }
//check for win/loss and print message if player has won or lost
        if (ghostShip.gameState() != 1)
        {
            if (ghostShip.gameState() == 2)
            {
                std::cout << '\n';
                std::cout << "___________________________________________________________" << std::endl;
                std::cout << "CONGRATULATIONS! You survived the perils of the ghost ship!" << std::endl;
                std::cout << "YOU WIN!" << std::endl;
                std::cout << '\n';
                std::cout << "Would you like to play again?" << std::endl;
            }
            else
            {
                std::cout << '\n';
                std::cout << "__________________________________________________________" << std::endl;
                std::cout << "NOOOOO! You have met your doom upon the ghost ship!" << std::endl;
                std::cout << "Your soul is doomed to wander its rooms for eternity." << std::endl;
                std::cout << '\n';
                std::cout << "Would you like to try again?" << std::endl;
            }
        }
    }
}

