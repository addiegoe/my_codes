/********************************************************************
 ** Program Name: Lab 4
 ** Author: Emily Addiego
 ** Date: October 27, 2019
 ** Description: This is the heaxder file for the Building class. It
 ** contains member variables for name, size, and address.
 ********************************************************************/
#include <iostream>
#ifndef building_hpp
#define building_hpp
using std::string;

class Building
{
private:
    string name;
    int size;
    string address;
public:
    Building();
    Building(string n, int s, string a);
    string getName();
    int getSize();
    string getAddress();
    
};

#endif
