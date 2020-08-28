/********************************************************************
 ** Program Name: Lab 4
 ** Author: Emily Addiego
 ** Date: October 27, 2019
 ** Description: This is the cpp file for the University class. It contains a
 ** constuctor and member functions.
 ********************************************************************/
#include <iostream>
#include <vector>
#include <sstream>
#include <memory>
#include <fstream>
#include "university.hpp"
using std::string;
using std::vector;

/********************************************************************
 ** Description: This is the constructor for University. It sets the
 ** name to Oregon State University.
 ********************************************************************/
University::University()
{
    name = "Oregon State University";
}

/********************************************************************
 ** Description: This the getName function. It returns the name of
 ** the university.
 ********************************************************************/
string University::getName()
{
    return name;
}

/********************************************************************
 ** Description: This is the printBuildings function. It prints out
 ** the information of all the buildings in the vector.
 ********************************************************************/
void University::printBuildings()
{
    for (int i = 0; i < buildings.size(); i++)
    {
        std::cout << "Name: " << buildings[i].getName() << std::endl;
        std::cout << "Size: " << buildings[i].getSize() << " square feet" << std::endl;
        std::cout << "Address: " << buildings[i].getAddress() << std::endl;
    }
}

/********************************************************************
 ** Description: This is the printPeople function. It prints out
 ** the information of all the people in the vector. It uses shared
 ** pointers to override the base class functions when to get rating
 ** or GPA. Source: texbook p. 960
 ********************************************************************/

void University::printPeople()
{
    for (int i = 0; i < people.size(); i++)
    {
        std::cout << "Name: " << people[i]->getName() << std::endl;
        std::cout << "Age : " << people[i]->getAge() << std::endl;
//print 'rating' or 'GPA' depending on type of person
        if (people[i]->getType() == "Instructor")
        {
            std::cout << "Rating: ";
        }
        else if (people[i]->getType() == "Student")
        {
            std::cout << "GPA: ";
        }
        std::cout << people[i]->getNumber() << std::endl;
    }
}

/********************************************************************
 ** Description: This is the getBuildings function (extra credit). It
 ** asks the user to input information about buildings on campus, then
 ** creates new objects in the vector.
 ********************************************************************/
void University::getBuildings()
{
    std::cout << "How many buildings would you like to enter? (Please only enter 10 or fewer buildings at a time)." << std::endl;
    int b = inputV(0, 11);
    for (int i = 0; i < b; i++)
    {
        string n;
        string a;
//get and check user input
        std::cout << "Enter the building's name." << std::endl;
        std::getline(std::cin, n);
        std::cout << "Enter the building's size." << std::endl;
        int s = inputV(0, 1000000);
        std::cout << "Enter the building's address." << std::endl;
        std::getline(std::cin, a);
//resize vector by creating and initalizing a new building object
        buildings.push_back(Building(n, s, a));
    }
}
/********************************************************************
 ** Description: This is the getPeople function (extra credit). It
 ** asks the user to input information about people on campus, then
 ** creates new objects in the vector. It camn create either an
 ** instructor object or a student object based on user input.
 ** Sources: textbook pp. 958-959;
 https://stackoverflow.com/questions/15731670/stdvector-of-objects-pointers-smart-pointers-to-pass-objects-buss-error
 https://stackoverflow.com/questions/15802006/how-can-i-create-objects-while-adding-them-into-a-vector
 ********************************************************************/
void University::getPeople()
{
    std::cout << "How may people would you like to enter? (Please only enter 10 or fewer people at a time)." << std::endl;
    int p = inputV(0, 11);
    for (int i = 0; i < p; i++)
    {
        std::cout << "Is the person an instructor or a student? Enter 1 to enter and instructor or 2 to enter a student." << std::endl;
        int personType = inputV(0, 3);
        if (personType == 1)
//ask for different input based on type of person
        {
            string n;
//get and check user input
            std::cout << "Enter the instructor's name." << std::endl;
            std::getline(std::cin, n);
            std::cout << "Enter the instructor's age." << std::endl;
            int a = inputV(24, 111);
            std::cout << "Enter the instructor's rating." << std::endl;
            double r = doubleInputV(0.0, 5.0);
//resize vector by creating a new instructor object
            people.push_back(std::make_shared<Instructor>(n, a, r, "Instructor"));
        }
        else if (personType == 2)
        {
            string n;
//get and check user input for name, age, and GPA
            std::cout << "Enter the student's name." << std::endl;
            std::getline(std::cin, n);
            std::cout << "Enter the student's age." << std::endl;
            int a = inputV(17, 111);
            std::cout << "Enter the student's GPA." << std::endl;
            double g = doubleInputV(0.0, 4.0);
//resize vector by creating a new student object
            people.push_back(std::make_shared<Student>(n, a, g, "Student"));
        }
    }
}
/*********************************************************************
 ** Description: This is the inputV function. It takes two
 ** parameters, a max size and a min size for input. It validates
 ** whether the input is an integer within the range of min and max.
 ** If the input is not valid, it loops continuously until a correct
 ** form of input is entered. This function is reused from Project 1
 ** and is based on Cuddlebuddie928's function from the following
 ** thread:
 ** http://www.cplusplus.com/forum/beginner/58833/
 ********************************************************************/
int University::inputV(int min, int max)
{
    int n;
    string s;
    
    while(true) {
//use getline to get entire line
        getline(std::cin, s);
//convert string to stream
        std::stringstream convert(s);
//check if stream is an integer and if it is within the minmum and maximum range
        if((convert >> n) && (!(convert >> s)) && (n > min) && (n < max))
        {
            return n;
        }
        else
        {
            std::cin.clear();
            std::cout << "Incorrect input. Try again." << std::endl;
        }
    }
}
/********************************************************************
 ** Description: This is the doubleInputV funciton, which is a
 ** modified version of InputV made to take and return doubles.
 ********************************************************************/
double University::doubleInputV(double min, double max)
{
        double n;
        string s;
        
        while(true) {
//use getline to get entire line
            getline(std::cin, s);
//convert string to stream
            std::stringstream convert(s);
//check if stream is a double and if it is within the minmum and maximum range
            if((convert >> n) && (!(convert >> s)) && (n >= min) && (n <= max))
            {
                return n;
            }
            else
            {
                std::cin.clear();
                std::cout << "Incorrect input. Try again." << std::endl;
            }
        }
}

/********************************************************************
 ** Description: This is the peopleWork function. It prints a list of
 ** people in the university and lets the user choose a person
 ** to do work, then it calls the do_work function.
 ********************************************************************/
void University::peopleWork()
{
    std::cout << "Please select a person from the list below." << std::endl;
//print out list of names
    for (int i = 0; i < people.size(); i++)
    {
        std::cout << (i + 1) << "." << people[i]->getName() << std::endl;
    }
//choose a person to do work
    int choice = inputV(0, (people.size() + 1));
    people[(choice - 1)]->do_work();
}

/********************************************************************
 ** Description: This is writeFile function for extra credit. It
 ** writes the list of buildings and people to a file and saves the
 ** file.
 ** Source:
 https://www.dreamincode.net/forums/topic/145699-eof-and-reading-text-files-c/
 ********************************************************************/
void University::writeFile()
{
//does not write first element to file, as it is already initalized in vector
    if (buildings.size() == 1)
    {
        std::cout << "Can't write to file. Please add more buildings to the list." << std::endl;
    }
    else if (buildings.size() == 2)
    {
//only write new elements to file
        std::ofstream output1;
        output1.open("buildingList.txt", std::ios::out);
            output1 << buildings[1].getName() << std::endl;
            output1 << buildings[1].getSize() << std::endl;
            output1 << buildings[1].getAddress();
        output1.close();
        std::cout << "Buildings written to 'buildingList.txt.'" << std::endl;
    }
    else if (buildings.size() > 2)
    {
    std::ofstream output1;
    output1.open("buildingList.txt", std::ios::out);
        int m = buildings.size();
    for (int i = 1; i < (m - 1); i++)
    {
        output1 << buildings[i].getName() << std::endl;
        output1 << buildings[i].getSize() << std::endl;
        output1 << buildings[i].getAddress() << std::endl;
    }
        output1 << buildings[m - 1].getName() << std::endl;
        output1 << buildings[m - 1].getSize() << std::endl;
        output1 << buildings[m - 1].getAddress();
    output1.close();
    std::cout << "Buildings written to 'buildingList.txt.'" << std::endl;
    }
    
//does not write first element to file, as it is already initalized in vector
    if (people.size() == 2)
    {
        std::cout << "Can't write to file. Please add more people to the list." << std::endl;
    }
    else if (people.size() == 3)
    {
//only write new elements to file
    std::ofstream output2;
    output2.open("peopleList.txt", std::ios::out);
        output2 << people[2]->getName() << std::endl;
        output2 << people[2]->getAge() << std::endl;
        output2 << people[2]->getNumber() << std::endl;
        output2 << people[2]->getType();
    output2.close();
    std::cout << "People written to 'peopleList.txt.'" << std::endl;
    }
    else if (people.size() > 3)
    {
        std::ofstream output2;
        output2.open("peopleList.txt", std::ios::out);
        int n = people.size();
        for (int i = 2; i < (n - 1); i++)
        {
            output2 << people[i]->getName() << std::endl;
            output2 << people[i]->getAge() << std::endl;
            output2 << people[i]->getNumber() << std::endl;
            output2 << people[i]->getType() << std::endl;
        }
        output2 << people[n - 1]->getName() << std::endl;
        output2 << people[n - 1]->getAge() << std::endl;
        output2 << people[n - 1]->getNumber() << std::endl;
        output2 << people[n - 1]->getType();
        output2.close();
        std::cout << "People written to 'peopleList.txt.'" << std::endl;
    }
    
}

/********************************************************************
 ** Description: This is the readFile function for extra credit.
 ** It reads new objects from the files created in writeFile into
 ** the person and building vectors.
 ********************************************************************/
void University::readFile()
{
//read from buildings
    std::ifstream fileB;
    fileB.open("buildingList.txt");
    if (!fileB)
    {
        std::cout << "File does not exist. Please save to file before attempting to access it." << std::endl;
    }
    else
    {
    string a;
    string n;
    int s;
    while (fileB.good())
    {
    getline(fileB, n);
    fileB >> s;
    fileB.ignore();
    getline(fileB, a);
    Building newB(n, s, a);
    buildings.push_back(newB);
    }
//close file and print message
    fileB.close();
    std::cout << "'buildings.txt' has been stored in the building list." << std::endl;
    }
//write people to vector
    std::ifstream fileP;
    fileP.open("peopleList.txt");
    if (!fileP)
    {
        std::cout << "File does not exist. Please save to file before attempting to access it." << std::endl;
    }
    else
    {
    string name;
    string t;
    int age;
    double num;
    while (fileP.good())
    {
        getline(fileP, name);
        fileP >> age;
        fileP.ignore();
        fileP >> num;
        fileP.ignore();
        getline(fileP, t);
//create different objects based on type of person
        if (t == "Instructor")
        {
            people.push_back(std::make_shared<Instructor>(name, age, num, t));
        }
        else if (t == "Student")
        {
            people.push_back(std::make_shared<Student>(name, age, num, t));
        }
    }
//close file and print a message
    fileP.close();
    std::cout << "'people.txt' has been stored in the people list." << std::endl;
    }
}



