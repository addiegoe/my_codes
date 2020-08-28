/*****************************************************************
 ** Program Name: Final Project
 ** Author: Emily Addiego
 ** Date: December 10, 2019
 ** Description: This is the header file for the stairs class.
 ******************************************************************/

#ifndef stairs_hpp
#define stairs_hpp
#include "space.hpp"

class Stairs: public Space
{
public:
    Stairs();
    virtual void task(int t);
    virtual int getDamage();
    ~Stairs();
};

#endif /* stairs_hpp */

