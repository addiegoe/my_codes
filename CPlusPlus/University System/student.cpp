/********************************************************************
 ** Program Name: Lab 4
 ** Author: Emily Addiego
 ** Date: October 27, 2019
 ** Description: This is the cpp file for the Student class. It contains
 ** virtual functions to get the student's GPA and to do work that
 ** override the Person class functions. It also contains a constructor.
 ********************************************************************/
#include <iostream>
#include <vector>
#include<ctime>
#include<cstdlib>
#include "student.hpp"
using std::string;
using std::vector;
/********************************************************************
 ** Description: This is the constructor for Student. It takes three
 ** parameters, a string n, a int a, a double g, and a string t, and
 ** and sets them as the student's name, age, GPA, and type.
 ********************************************************************/
Student::Student(string n, int a, double g, string t)
{
    name = n;
    age = a;
    GPA = g;
    type = t;
}

/********************************************************************
 ** Description: This is the do_work function. It generates a random
 ** number between 5 and 40, then prints a that the student did that
 ** many hours of homework.
 ********************************************************************/
void Student::do_work()
{
//generate a random number
    std::srand(time(NULL));
    int X = std::rand() % (40 - 5) + 5;
//print message
    std::cout << getName() << " did " << X << " hours of homework." << std::endl;
}

/********************************************************************
 ** Description: This is the getNumber function. It returns the
 ** student's GPA.
 ********************************************************************/
double Student::getNumber()
{
    return GPA;
}

