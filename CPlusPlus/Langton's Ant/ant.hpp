/****************************************************************************
** Program: Project 1
** Author: Emily Addiego
** Date: October 13, 2019
** Description: This is the class file for the Ant class. It contains private
** data members to track the location and orientation of the ant, as well as
** the color of the square the ant is on. It has member functions to start,
** turn, move, and randomly start the ant on a dynamically-allocated board.
** It also has a default constructor to initialize Ant data members.
*****************************************************************************/
#include <iostream>
#ifndef ant_hpp
#define ant_hpp
using std::string;

class Ant
{
private:
    int antX, antY;
    char orientation;
    string color;
public:
    void startAnt(char **array, int x, int y);
    void randomStartAnt(char **array, int r, int c);
    void turnAnt(char **array);
    void moveAnt(char **array, int r, int c);
    void reset();
    Ant();
};

#endif
