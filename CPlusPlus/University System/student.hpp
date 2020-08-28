/********************************************************************
 ** Program Name: Lab 4
 ** Author: Emily Addiego
 ** Date: October 27, 2019
 ** Description: This is the header file for the Student class. It
 ** contains a member variable for GPA.
 ********************************************************************/
#include "person.hpp"
#ifndef student_hpp
#define student_hpp
class Student: public Person
{
private:
    double GPA;
public:
    Student(string n, int a, double g, string t);
    virtual void do_work();
    virtual double getNumber();
    

};
#endif
