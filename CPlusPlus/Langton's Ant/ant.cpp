/*****************************************************************************
** Program: Project 1
** Author: Emily Addiego
** Date: October 13, 2019
** Description: This file contains all the member functions for the ant class.
*****************************************************************************/
#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#include "ant.hpp"
using std::string;


/******************************************************************************
** Description: This is the default constructor for Ant objects. It initializes
** the ant's location to (0,0), the orientation to East, and the color of the
** square to white.
******************************************************************************/
Ant::Ant()
{
    antX = 0;
    antY = 0;
    orientation = 'E';
    color = "white";
}


/******************************************************************************
** Description: This is the startAnt function. It takes three parameters,
** a pointer to a 2D array and two ints, one for row placement and one for
** column placement. It places the ant (denoted as '*') on the board at the
** coordinates passed to the function.
******************************************************************************/
void Ant::startAnt(char **array, int x, int y)
{
    antX = x;
    antY = y;
    array[antX][antY] = '*';
}

/******************************************************************************
** Description: This is the RandomStartAnt function. It takes three parameters,
** a pointer to a 2D array and two ints, one for row size and one for
** column size. It places the ant (denoted as '*') on a random square within
** the bounds of the board. 
******************************************************************************/
void Ant::randomStartAnt(char **array, int r, int c)
{
//use srand with time to make sure the same value is not generated each time
    std::srand(time(NULL));
    antX = std::rand() % r;
    antY = std::rand() % c;
    array[antX][antY]= '*';
}


/******************************************************************************
** Description: This is the turnAnt function. It takes one parameter,
** a pointer to a 2D array and two ints. If the ant is on a white square, it
** turns the ant 90 degrees to the right and changes the color to black. If
** the ant is on a black square, it turns the ant 90 degrees to the left and
** changes the color to black.
******************************************************************************/
void Ant::turnAnt(char **array)
{
    if (color == "white")
    {
        if (orientation == 'N')
        {
            orientation = 'E';
	    color = "black";
        }
        else if (orientation == 'E')
        {
            orientation = 'S';
	    color = "black";
        }
        else if (orientation == 'S')
        {
            orientation = 'W';
	    color = "black";
        }
        else if (orientation == 'W')
        {
            orientation = 'N';
	    color = "black";
        }
    }
    else if (color == "black")
    {
        if (orientation == 'N')
        {
            orientation = 'W';
	    color = "white";
        }
        else if (orientation == 'E')
        {
            orientation = 'N';
	    color = "white";
        }
        else if (orientation == 'S')
        {
            orientation = 'E';
	    color = "white";
        }
        else if (orientation == 'W')
        {
            orientation = 'S';
	    color = "white";
        }
    } 
}

/******************************************************************************
** Description: This is the moveAnt function. It takes three parameters,
** a pointer to a 2D array and two ints, one for row size and one for
** column size. It checks for impossible moves. If the ant can't move, it
** turns the ant back around to face the board. If the ant can move, it
** moves the ant, changes back the square the ant was on to its correct char,
** and stores the color of the new square that the ant is on.
******************************************************************************/ 
void Ant::moveAnt(char **array, int r, int c)
{
//control for impossible moves
    if ((orientation == 'N') && (antX > 0))
    {
//change starting square back
        if (color == "white")
        {
            array[antX][antY] = ' ';
//track color of next square
            if (array[antX - 1][antY] == '#')
            {
                color = "black";
            }
            else if (array[antX - 1][antY] == '_')
            {
                color = "white";
            }
            array[antX - 1][antY] = '*';
            antX -= 1;
        }
        else if (color == "black")
        {
            array[antX][antY] = '#';
            if (array[antX - 1][antY] == '#')
            {
                color = "black";
            }
            else if (array[antX - 1][antY] == '_')
            {
                color = "white";
            }
            array[antX - 1][antY] = '*';
            antX -= 1;
        }
    }
//turn ant around if it reaches edge of board
    else if ((orientation == 'N') && (antX == 0))
    {
            if (color == "white")
            {
            orientation = 'E';
            }
            else if (color == "black")
            {
                orientation = 'W';
            }
    }
//control for impossible moves
    else if ((orientation == 'S') && (antX < (r - 1)))
    {
        if (color == "white")
        {
            array[antX][antY] = ' ';
            if (array[antX + 1][antY] == '#')
            {
                color = "black";
            }
            else if (array[antX + 1][antY] == '_')
            {
                color = "white";
            }
            array[antX + 1][antY] = '*';
            antX += 1;
        }
        else if (color == "black")
        {
            array[antX][antY] = '#';
            if (array[antX + 1][antY] == '#')
            {
                color = "black";
            }
            else if (array[antX + 1][antY] == '_')
            {
                color = "white";
            }
            array[antX + 1][antY] = '*';
           antX += 1;
        }
    }
//turn ant around if it reaches edge of board
    else if ((orientation == 'S') && (antX == (r - 1)))
    {
        if (color == "white")
        {
            orientation = 'W';
        }
        else if (color == "black")
        {
            orientation = 'E';
        }
    }
//control for impossible moves
    else if ((orientation == 'E') && (antY < (c - 1)))
    {
        if (color == "white")
        {
            array[antX][antY] = ' ';
            if (array[antX][antY + 1] == '#')
            {
                color = "black";
            }
            else if (array[antX][antY + 1] == '_')
            {
                color = "white";
            }
            array[antX][antY + 1] = '*';
            antY += 1;
        }
        else if (color == "black")
        {
            array[antX][antY]= '#';
            if (array[antX][antY + 1] == '#')
            {
                color = "black";
            }
            else if (array[antX][antY + 1] == '_')
            {
                color = "white";
            }
            array[antX][antY + 1] ='*';
            antY += 1;
        }
    }
//turn ant around if it reaches edge of board
    else if ((orientation == 'E') && (antY == (c - 1)))
    {
        if (color == "white")
        {
            orientation = 'S';
        }
        else if (color == "black")
        {
            orientation = 'N';
        }
    }
    
//control for impossible moves
    else if ((orientation == 'W') && (antY > 0))
    {
        if (color == "white")
        {
            array[antX][antY] = ' ';
            if (array[antX][(antY - 1)] == '#')
            {
                color = "black";
            }
            else if (array[antX][(antY - 1)] == '_')
            {
                color = "white";
            }
            array[antX][(antY - 1)] = '*';
            antY -= 1;
        }
        else if (color == "black")
        {
            array[antX][antY] = '#';
            if (array[antX][(antY - 1)] == '#')
            {
                color = "black";
            }
            else if (array[antX][(antY - 1)] == '_')
            {
                color = "white";
            }
            array[antX][(antY - 1)] ='*';
            antY -= 1;
        }
    }
//turn ant around if it reaches edge of board
    else if ((orientation == 'W') && (antY == 0))
    {
        if (color == "white")
        {
            orientation = 'N';
        }
        else if (color == "black")
        {
            orientation = 'S';
        }
    }
        
}

/*************************************************************************************************
** Description: This is the reset function for the ant class. It sets the orientation and color of
** the board back to their defaults.
*************************************************************************************************/

void Ant::reset()
{
	color = "white";
	orientation = 'E';
}
