/********************************************************************
 ** Program Name: Lab 4
 ** Author: Emily Addiego
 ** Date: October 27, 2019
 ** Description: This is the header file for the Menu class. It
 ** contains a University object and the mainMenu function.
 ********************************************************************/
#ifndef menu_hpp
#define menu_hpp
#include "university.hpp"

class Menu
{
private:
//university object
    University university;
public:
    void mainMenu();
};

#endif
