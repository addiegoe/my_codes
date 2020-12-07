/*********************************************************
 ** Program Name: Project 4
 ** Author: Emily Addiego
 ** Date: November 24, 2019
 ** Description: This is header file for the Character
 ** class. It contains mmeber variables for character
 ** attributes and functions for gameplay.
 ********************************************************/

#include<iostream>
#ifndef character_hpp
#define character_hpp
using std::string;

class Character
{
protected:
    int armor;
    int strength;
    int maxStrength;
    string type;
    string name;
public:
    Character();
    virtual ~Character();
    int getStrength();
    int getArmor();
    string getType();
    string getName();
    void setName(string n);
    void recovery();
    virtual int attack();
    virtual int defend();
    virtual void calcDamage(int attack, int defend, string n);
    
};

#endif
