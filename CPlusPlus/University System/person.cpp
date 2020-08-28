/********************************************************************
 ** Program Name: Lab 4
 ** Author: Emily Addiego
 ** Date: October 27, 2019
 ** Description: This is the cpp file for the Person class. It
 ** contains getter and setter functions as well as a virtual
 ** do_work function and getNumber function that can be overridden by
 ** derived class objects.
 ********************************************************************/
#include <iostream>
#include <vector>
#include<ctime>
#include<cstdlib>
#include <sstream>
#include "person.hpp"
using std::string;
using std::vector;

/********************************************************************
 ** Description: This is the do_work function. It is virtual and can
 ** be overridden by the derived class versions.
 ********************************************************************/
void Person::do_work()
{
    std::srand(time(NULL));
    int X = std::rand() % (40 - 5) + 5;
    std::cout << "The person worked for " << X << " hours." << std::endl;
}

/********************************************************************
 ** Description: This is the getNumber function. It is virtual and can
 ** be overridden by the derived class versions.
 ********************************************************************/
double Person::getNumber()
{
    return 1.0;
}

/********************************************************************
 ** Description: This is the getName function. It returns the name
 ** of the person.
 ********************************************************************/
string Person::getName()
{
    return name;
}

/********************************************************************
 ** Description: This is the getAge function. It returns the age
 ** of the person.
 ********************************************************************/
int Person::getAge()
{
    return age;
}

/********************************************************************
 ** Description: This is the setName function. It takes one parameter,
 ** a string n, and sets the name of the person.
 ********************************************************************/
void Person::setName(string n)
{
    name = n;
}

/********************************************************************
 ** Description: This is the setAge function. It takes one parameter,
 ** a int a, and sets the age of the person.
 ********************************************************************/
void Person::setAge(int a)
{
    age = a;
}

/********************************************************************
 ** Description: This is the getType function. It returns the person's
 ** type (student or instructor).
 ********************************************************************/
string Person::getType()
{
    return type;
}
