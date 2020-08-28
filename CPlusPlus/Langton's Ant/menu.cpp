/******************************************************************************
** Program: Project 1
** Author: Emily Addiego
** Date: October 13, 2019
** Description: This file contains the member functions for the menu class.
*******************************************************************************/
#include <iostream>
#include<sstream>
#include<iomanip>
using std::cin;
using std::cout;
using std::string;
#include "menu.hpp"

/*****************************************************************************
** Description: This is the default constructor fo the menu class.
*****************************************************************************/

Menu::Menu()
{
}

/*****************************************************************************
** Description: This is the mainMenu function. It takes no parameters. It asks
** the user to start/end the simulation and asks for the size of the board
** (rows and columns), the starting point of the ant or to randomly start the
** ant, and the number of times to run the simulation. It calls on other menu
** member functions to check for correct input, make the board, print the
** board, and delete the array.
*****************************************************************************/
void Menu::mainMenu()
{
    cout << "Welcome to Langton's Ant Simulator." << std::endl;
    cout << "Please enter 1 to start the game or 2 to quit." << std::endl;
//control for correct input
    int choice = inputV(0, 3);
    if (choice == 1)
    {
//begin simulation loop
    do {
//get row and column size while controlling for input
        cout << "Please enter a number of rows for the board. Choose a size between 1 and 80." << std::endl;
        int rSize = inputV(0, 81);
        cout << "Please enter a number of columns for the board. Choose a size between 1 and 80." << std::endl;
        int cSize = inputV(0, 81);
//dynamically allocate array using row and column size from user
        char** board = makeArray(rSize, cSize);
//Place the ant on the board and control for incorrect input
        cout << "Enter 1 to choose the ant's starting point on the board or 2 to randomly place the ant." << std::endl;
        int place = inputV(0, 3);
        if (place == 1)
        {
            cout << "Please enter the starting row for the ant." << std::endl;
            int startX = inputV(-1, rSize);
            cout << "Please enter the starting column for the ant." << std::endl;
            int startY = inputV(-1, cSize);
            ant.startAnt(board, startX, startY);
        }
        else if (place == 2)
        {
            ant.randomStartAnt(board, rSize, cSize);
        }
//print the board
        printB(board, rSize, cSize);
        cout << '\n';
//get the number of times to run simulation and control for bad input
        cout << "How many times would you like the simulation to run? (Choose a number between 1 and 1000000.)" << std::endl;
        int times = inputV(0, 1000000);
//loop the simulation for as many times as specified by the user
        for (int count = 0; count < times; count++)
        {
            ant.moveAnt(board, rSize, cSize);
	    ant.turnAnt(board);
            printB(board, rSize, cSize);
            cout << '\n';
        }
//reset the color and orientation
	ant.reset();
//free dynamically allocated memory
        freeArray(board, rSize);        
//prompt user to play again or quit
        cout << "Simulation over. Please enter 1 to run again or 2 to quit." << std::endl;
        choice = inputV(0, 3);
        
    } while (choice == 1);
    }
    
}


/******************************************************************************
** Description: This is the makeArray function. It takes two parameters, a
** row size int and a column size int. It dynamically allocates and returns
** a 2D array of chars using the size parameters.
*******************************************************************************/
char** Menu::makeArray(int r, int c)
{
    char **array = new char*[r];
    
    for (int i = 0; i < r; i++)
    {
        array[i] = new char[c];
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            array[i][j] = ' ';
        }
    }
    return array;
}


/******************************************************************************
** Description: This is the freeArray function. It takes two parameters, a
** pointer to a 2D char array and an int row size. It deletes the array and
** frees the memory.
*******************************************************************************/
void Menu::freeArray(char **array, int r)
{
    for(int i = 0; i < r; ++i)
    {
        delete [] array[i];
    }
    delete [] array;
}


/******************************************************************************
** Description: This is the inputV function. It takes two parameters, a
** max size and a min size for input. It validates whether the input is
** an integer within the range of min and max. If the input is not valid, it
** loops continuously until a correct form of input is entered.
*******************************************************************************/
int Menu::inputV(int min, int max)
{
    int n;
    string s;
    
    while(true) {
//use getline to get entire line
        getline(cin, s);
//convert string to stream
        std::stringstream convert(s);
//check if stream is an integer and if it is within the minmum and maximum range
        if((convert >> n) && (!(convert >> s)) && (n > min) && (n < max))
        {
            return n;
        }
        else
        {
            cin.clear();
            cout << "Incorrect input. Try again." << std::endl;
        }
    }
}


/******************************************************************************
** Description: This is the printB function. It takes three parameters,
** a pointer to a 2D char array and two ints for row and column size. It prints
** the array to the console. 
*******************************************************************************/
void Menu::printB(char **array, int r, int c)
{
    for (int i = 0; i < c; i++)
    {
        std::cout << " _ ";
    }
    std::cout << '\n';
    for (int i = 0; i < r; i++)
    {
        std::cout << "|";
        for (int j = 0; j < c; j++)
        {
            std::cout << std::setw(2) << array[i][j] << " ";
        }
        std::cout << "|";
        std::cout << '\n';
    }
    for (int i = 0; i < c; i++)
    {
        std::cout << " _ ";
    }
}




