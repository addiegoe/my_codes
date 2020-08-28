/*****************************************************************
 ** Program Name: Final Project
 ** Author: Emily Addiego
 ** Date: December 10, 2019
 ** Description: This is the header file for the Space class. It
** contains setter and getter functions, two virtual functions, and
** Space pointers.
 ******************************************************************/

#include<iostream>
#include<vector>
#ifndef space_hpp
#define space_hpp

class Space
{
protected:
    Space *left;
    Space *right;
    Space *top;
    Space *bottom;
    std::string name;
    std::string item;
    int level;
    int damage;
public:
    Space();
    virtual void task(int t);
    virtual int getDamage();
    void setLeft(Space *l);
    void setRight(Space *r);
    void setTop(Space *t);
    void setBottom(Space *b);
    int getLevel();
    void setLevel(int l);
    std::string getName();
    std::string getItem();
    Space* getLeft();
    Space* getRight();
    Space* getTop();
    Space* getBottom();
    void setName(std::string n);
    void setItem(std::string i);
    void anyKey(std::string action);
    ~Space();
};

#endif /* space_hpp */

