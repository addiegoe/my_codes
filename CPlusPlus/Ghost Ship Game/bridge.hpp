/*****************************************************************
 ** Program Name: Final Project
 ** Author: Emily Addiego
 ** Date: December 10, 2019
 ** Description: This is the header file for the bridge class.
 ******************************************************************/

#ifndef bridge_hpp
#define bridge_hpp
#include "space.hpp"

class Bridge: public Space
{
public:
    Bridge();
    virtual void task(int t);
    ~Bridge();
};

#endif /* bridge_hpp */

