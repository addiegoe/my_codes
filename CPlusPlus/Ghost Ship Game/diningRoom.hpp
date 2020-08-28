/*****************************************************************
 ** Program Name: Final Project
 ** Author: Emily Addiego
 ** Date: December 10, 2019
 ** Description: This is the header file for the dining room class.
 ******************************************************************/

#ifndef diningRoom_hpp
#define diningRoom_hpp

#include "space.hpp"

class DiningRoom: public Space
{
private:
    int damage;
public:
    DiningRoom();
    virtual void task(int t);
    virtual int getDamage();
    ~DiningRoom();
};


#endif /* diningRoom_hpp */

