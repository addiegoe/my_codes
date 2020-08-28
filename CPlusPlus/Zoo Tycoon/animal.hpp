/******************************************************************************
 ** Program Name: Project 2
 ** Author: Emily Addiego
 ** Date: Octboer 27, 2019
 ** Description: This is the header file for the Animal class. It contains the
 ** protected member variables age, cost, numberofBabies, baseFoodCost, and
 ** payoff.
 ******************************************************************************/
#include<iostream>
#ifndef animal_hpp
#define animal_hpp

class Animal
{
protected:
    int age;
    int cost;
    int numberOfBabies;
    int baseFoodCost;
    int payoff;
    
public:
    int getAge();
    void setAge(int a);
    void setCost(int c);
    void setPayoff(int p);
    void setFoodCost(int fC);
    void setNumBabies(int b);
    
    
};
#endif
