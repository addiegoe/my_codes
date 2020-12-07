/************************************************************
 ** Program Name: Project 4
 ** Author: Emily Addiego
 ** Date: November 24, 2019
 ** Description: This is the header file for the Medusa
 ** class. It contains a function prototype for an
 ** overriding calcDamage and a constructor and destructor.
 ************************************************************/

#ifndef harryPotter_hpp
#define harryPotter_hpp
#include "character.hpp"
class HarryPotter : public Character
{
private:
    int lives;
public:
    HarryPotter();
    virtual ~HarryPotter();
    virtual void calcDamage(int attack, int defend, string n);
};

#endif
