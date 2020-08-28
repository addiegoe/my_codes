/*****************************************************************************
** Program: Project 1
** Author: Emily Addiego
** Date: October 13, 2019
** Description: This is the class file for the Menu class. It contains a
** private Ant object and member functions for the main menu, error correction,
** and making, printing, and deleting a dynamic 2D array.
******************************************************************************/
#ifndef menu_hpp
#define menu_hpp
#include "ant.hpp"
using std::string;

class Menu
{
private:
    Ant ant;
public:
    void mainMenu();
    char **makeArray(int r, int c);
    void freeArray(char **array, int r);
    int inputV(int min, int max);
    void printB(char **array, int r, int c);
    Menu();
};


#endif
