/************************************************************
 ** Program Name: Project 4
 ** Author: Emily Addiego
 ** Date: November 24, 2019
 ** Description:  This is the header file for the Medusa
 ** class. It contains a function prototype for an
 ** overriding attack and defend function and a constructor.
 ************************************************************/
#ifndef medusa_hpp
#define medusa_hpp
#include "character.hpp"
class Medusa : public Character
{
public:
    Medusa();
    virtual ~Medusa();
    virtual int attack();
    virtual int defend();
};

#endif
