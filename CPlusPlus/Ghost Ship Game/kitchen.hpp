/*****************************************************************
 ** Program Name: Final Project
 ** Author: Emily Addiego
 ** Date: December 10, 2019
 ** Description: This is the header file for the kitchen class.
 ******************************************************************/

#ifndef kitchen_hpp
#define kitchen_hpp
#include "space.hpp"

class Kitchen: public Space
{
public:
    Kitchen();
    virtual void task(int t);
    ~Kitchen();
};

#endif /* kitchen_hpp */
