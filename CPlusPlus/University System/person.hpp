/********************************************************************
 ** Program Name: Lab 4
 ** Author: Emily Addiego
 ** Date: October 27, 2019
 ** Description: This is the header file for the Person class. It
 ** contains member variables for name and age.
 ********************************************************************/
#include <iostream>
#ifndef person_hpp
#define person_hpp
using std::string;

class Person
{
protected:
    string name;
    int age;
    string type;
public:
    virtual void do_work();
//virtual functions for setting/getting GPA or rating
    virtual double getNumber();
//setter and getter functions for age and name
    string getName();
    int getAge();
    void setName(string n);
    void setAge(int a);
    string getType();
  
};
#endif
