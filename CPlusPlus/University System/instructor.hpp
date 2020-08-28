/********************************************************************
 ** Program Name: Lab 4
 ** Author: Emily Addiego
 ** Date: October 27, 2019
 ** Description: This is the header file for the Instructor class. It
 ** contains a member variable for rating.
 ********************************************************************/
#include "person.hpp"
#ifndef instructor_hpp
#define instructor_hpp
class Instructor: public Person
{
private:
    double rating;
public:
    Instructor(string n, int a, double r, string t);
    virtual void do_work();
    virtual double getNumber();
    
    
};

#endif
