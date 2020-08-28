/********************************************************************
 ** Program Name: Lab 4
 ** Author: Emily Addiego
 ** Date: October 27, 2019
 ** Description: This is the cpp file for the Menu class. 
 ********************************************************************/
#include "menu.hpp"
#include <fstream>
#include <iostream>

/********************************************************************
 ** Description: This is the mainMenu function. It displays a list
 ** of options for the user, then calls different functions depending
 ** on what the user chooses. After calling a function, it offers the
 ** user the choice to choose another option or quit.
 ********************************************************************/
void Menu::mainMenu()
{
    std::cout << "Welcome to " << university.getName() << "!" << std::endl;
    std::cout << "Please select an option from the menu below:" << std::endl;
    std::cout << "Note: options 4-7 are for extra credit on the assignment." << std::endl;
    std::cout << "1. Print list of buildings." << std::endl;
    std::cout << "2. Print list of people." << std::endl;
    std::cout << "3. Select a person to do work." << std::endl;
    std::cout << "4. Add buildings to the list." << std::endl;
    std::cout << "5. Add people to the list." << std::endl;
    std::cout << "6. Save all information to a file." << std::endl;
    std::cout << "7. Read information from the file." << std::endl;
    std::cout << "8. Quit program." << std::endl;
    int choice = university.inputV(0, 9);
    if (choice !=8)
    {
//call different functions based on user's choice
        do {
            if (choice == 1)
            {
                university.printBuildings();
            }
            else if (choice == 2)
            {
                university.printPeople();
            }
            else if (choice == 3)
            {
                university.peopleWork();
            }
            else if (choice == 4)
            {
                university.getBuildings();
            }
            else if (choice == 5)
            {
                university.getPeople();
            }
            else if (choice == 6)
            {
                university.writeFile();
            
            }
            else if (choice == 7)
            {
                university.readFile();
            }
//prompt to choose again or quit
            std::cout << "Would you like to perform another action? Please select from the list again, or enter 8 to quit." << std::endl;
            choice = university.inputV(0, 9);
        } while (choice !=8);
    }
    else{
        std::cout << "Goodbye." << std::endl;
    }
    
}
