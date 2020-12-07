/************************************************************
 ** Program Name: Project 4
 ** Author: Emily Addiego
 ** Date: November 24, 2019
 ** Description: This is the header file for the Blue Men
 ** class. It contains function prototypes for overrides for
 ** attack and defend as well as a constructor.
 ************************************************************/

#ifndef blueMan_hpp
#define blueMan_hpp
#include "character.hpp"
class BlueMen : public Character
{
public:
    BlueMen();
    virtual ~BlueMen();
    virtual int attack();
    virtual int defend();
    
};

#endif

