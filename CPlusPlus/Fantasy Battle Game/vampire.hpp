/***********************************************************
 ** Program Name: Project 4
 ** Author: Emily Addiego
 ** Date: November 24, 2019
 ** Description: This is the header file for the Vampire
 ** class. It contains virtual function prototypes to
 ** override attack, defend, and calcDamage.
 ************************************************************/

#ifndef vampire_hpp
#define vampire_hpp
#include "character.hpp"

class Vampire : public Character
{
public:
    Vampire();
    virtual ~Vampire();
    virtual int attack();
    virtual int defend();
    virtual void calcDamage(int attack, int defend, string n);
};

#endif
