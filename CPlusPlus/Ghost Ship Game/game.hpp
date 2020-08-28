/*****************************************************************
 ** Program Name: Final Project
 ** Author: Emily Addiego
 ** Date: December 10, 2019
 ** Description: This is the header file for the game class.
 ******************************************************************/

#ifndef game_hpp
#define game_hpp
#include "ship.hpp"

class Game
{
private:
    Ship ghostShip;
public:
    void menu();
    void gamePlay();
    void setUp();
    
};

#endif /* game_hpp */

