/*********************************************************
 ** Program Name: Project 4
 ** Author: Emily Addiego
 ** Date: November 24, 2019
 ** Description: This is the main file for project 4.
 ** It calls the menu with a game object.
 ********************************************************/

#include <iostream>
#include "game.hpp"


int main() {
    Game battle;
    std::cout << "WELCOME TO THE FANTASY BATTLE TOURNAMENT" << std::endl;
    battle.menu();
    
    return 0;
}

