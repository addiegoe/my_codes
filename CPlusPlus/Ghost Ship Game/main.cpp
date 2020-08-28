/*****************************************************************
 ** Program Name: Final Project
 ** Author: Emily Addiego
 ** Date: December 10, 2019
 ** Description: This is the main file for the Final Project. It starts
** the Ghost Ship game by calling setUp with a game object.
 ******************************************************************/

#include <iostream>
#include "game.hpp"



int main() {
    Game game;
    std::cout << "______________________GHOST SHIP________________________" << std::endl;
    game.setUp();
    

    return 0;
}

