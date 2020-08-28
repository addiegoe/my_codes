/********************************************************************
 ** Program Name: Lab 4
 ** Author: Emily Addiego
 ** Date: October 27, 2019
 ** Description: This is the cpp file for the Instructor class. It contains
 ** virtual functions to get the instructor's rating and to do work that
 ** override the Person class functions. It also contains a constructor.
 ********************************************************************/
#include <iostream>
#include <vector>
#include<ctime>
#include<cstdlib>
#include "instructor.hpp"
using std::string;
using std::vector;

/********************************************************************
 ** Description: This is the constructor for Instructor. It takes
 ** three parameters, a string n, a int a, a double r, and a string
** t, and sets them as the instructor's name, age, rating, and type.
 ********************************************************************/
Instructor::Instructor(string n, int a, double r, string t)
{
    name = n;
    age = a;
    rating = r;
    type = t;
}

/********************************************************************
 ** Description: This is the do_work function. It generates a random
 ** number between 5 and 40, then prints that the instructor graded
 ** papers for that many hours.
 ********************************************************************/
void Instructor::do_work()
{
    std::srand(time(NULL));
    int X = std::rand() % (40 - 5) + 5;
    std::cout << getName() << " graded papers for " << X << " hours." << std::endl;
}

/********************************************************************
 ** Description: This is the getNumber function. It returns the
 ** instructor's rating.
 ********************************************************************/
double Instructor::getNumber()
{
    return rating;
}



