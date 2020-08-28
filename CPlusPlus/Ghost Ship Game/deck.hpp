/*****************************************************************
 ** Program Name: Final Project
 ** Author: Emily Addiego
 ** Date: December 10, 2019
 ** Description: This is the header file for the deck class.
 ******************************************************************/

#ifndef deck_hpp
#define deck_hpp

#include "space.hpp"

class Deck: public Space
{
public:
    Deck();
    virtual void task(int t);
    virtual int getDamage();
    ~Deck();
};

#endif /* deck_hpp */

