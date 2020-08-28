/******************************************************************************
 ** Program Name: Project 2
 ** Author: Emily Addiego
 ** Date: Octboer 27, 2019
 ** Description: This is the cpp file for the Animal class. It contains
 ** getter and setter functions.
 ******************************************************************************/

#include "animal.hpp"

/******************************************************************************
 ** Description: This is the getAge function. It returns the animal's age.
 ******************************************************************************/
int Animal::getAge()
{
    return age;
}

/******************************************************************************
 ** Description: This is the setAge function. It takes an int as a parameter
 ** and sets that int to be the age.
 ******************************************************************************/
void Animal::setAge(int a)
{
    age += a;
}

/******************************************************************************
 ** Description: This is the setCost function. It takes an int as a parameter
 ** and sets that int to be the cost.
 ******************************************************************************/
void Animal::setCost(int c)
{
    cost = c;
}

/******************************************************************************
 ** Description: This is the setPayoff function. It takes an int as a parameter
 ** and sets that int to be the payoff.
 ******************************************************************************/
void Animal::setPayoff(int p)
{
    payoff = p;
}

/******************************************************************************
 ** Description: This is the setFoodCost function. It takes an int as a parameter
 ** and sets that int to be the base food cost.
 ******************************************************************************/
void Animal::setFoodCost(int fC)
{
    baseFoodCost = fC;
}

/******************************************************************************
 ** Description: This is the setNumBabies function. It takes an int as a parameter
 ** and sets that int to be the number of babies.
 ******************************************************************************/
void Animal::setNumBabies(int b)
{
    numberOfBabies = b;
}


