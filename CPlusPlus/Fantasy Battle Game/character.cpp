/*********************************************************
 ** Program Name: Project 4
 ** Author: Emily Addiego
 ** Date: November 24, 2019
 ** Description: This is the cpp file for the Character
 ** class. It contains all member function for the class.
 ********************************************************/

#include "character.hpp"
#include<cmath>
#include<ctime>
using std::string;

/*********************************************************
**Description: This is the constructor for the character
class.
**********************************************************/
Character::Character()
{
    
}

/***********************************************************
 **Description:
 ** This is the destructor for the character class.
 ** It can be overridden by dervied objects.
 Source:
 http://www.equestionanswers.com/cpp/virtual-destructor-inheritance.php
 ***********************************************************/
Character::~Character()
{
    
}


/************************************************************
 ** Description: This is the getStrength function. It returns
 ** the character's strength points.
 ***********************************************************/
int Character::getStrength()
{
    return strength;
}


/************************************************************
 ** Description: This is the getType function. It returns the
 ** character's type.
 ***********************************************************/
string Character::getType()
{
    return type;
}


/************************************************************
 ** Description: This is the getArmor function. It returns
 ** the character's armor.
 ***********************************************************/
int Character::getArmor()
{
    return armor;
}

/************************************************************
 ** Description: This is the setName function. It takes 1
 ** parameter, a string n, and sets it as the character's
 ** name.
 ***********************************************************/
void Character::setName(string n)
{
    name = n;
}

/************************************************************
 ** Description: This is the getName function. It returns
 ** the character's name.
 ***********************************************************/
string Character::getName()
{
    return name;
}


/************************************************************
 ** Description: This is the attack function. It overrides
 ** the base class attack function. It returns a the sum of
 ** two random "rolls" between 1 and 6.
 ***********************************************************/
int Character::attack()
{
    int die1 = (std::rand() % 6) + 1;
    int die2 = (std::rand() % 6) + 1;
    return die1 + die2;
}


/************************************************************
 ** Description: This is the defend function. It is virtual
 ** an can be overridden by derived classes. It returns
 ** the sum of two random "rolls" between 1 and 6.
 ***********************************************************/
int Character::defend()
{
    int die1 = (std::rand() % 6) + 1;
    int die2 = (std::rand() % 6) + 1;
    return die1 + die2;
}


/************************************************************
 ** Description: This is the calcDamage function. It is
 ** virtual and can be overridden by derived classes. It
 ** takes 3 parameters, an int attack, int defend, and string
 ** name. It calculates the damage to the character based on
 ** attack, defense, and character's armor. It has options
 ** to control for GLARE from a Medusa attack. It prints
 ** the attack and defense of the two players and the
 ** resulting damage.
 ***********************************************************/
void Character::calcDamage(int attack, int defend, string n)
{
    //calculate damage
    int total = attack - defend - armor;
    int dam;
    //if attack=100, Medusa has used GLARE; print message
    //and set strength to 0
    if (attack == 100)
    {
        std::cout << "Medusa used GLARE!" << std::endl;
        std::cout << name << " has been turned to stone and has no strength left!" << std::endl;
        strength = 0;
        
    }
    //if total damage is less than or equal to 0, set damage to 0
    else if ((total <= 0) && (attack != 100) && (defend != 200))
    {
        dam = 0;
        std::cout << n << " rolled: " << attack << std::endl;
        std::cout << name << " rolled: " << defend << std::endl;
        std::cout << name << " suffers " << dam;
        std::cout << " points of damage." << std::endl;
        strength -= dam;
    }
    //print out attack and defense values and damage, set strength
    else
    {
        dam = total;
        std::cout << n << " rolled: " << attack << std::endl;
        std::cout << name << " rolled: " << defend << std::endl;
        std::cout << name << " suffers " << dam;
        std::cout << " points of damage." << std::endl;
        strength -= dam;
    }
    
}


/************************************************************
 ** Description: This is the recovery function. It adds a
 ** percentage of recovery to the character's strength points
 ** based on a random number between 1 and 4.
 ***********************************************************/
void Character::recovery()
{
    int recovery;
//generate a number between 1 and 4
    int percent = (std::rand() % 4) + 1;
//recovery can equal between 25-100% of remaining strength, based on number generated
    if (percent == 1)
    {
        recovery = strength * 0.25;
    }
    else if (percent == 2)
    {
        recovery = strength * 0.5;
    }
    else if (percent == 3)
    {
        recovery = strength * 0.75;
    }
    else if (percent == 4)
    {
        recovery = strength * 1;
    }
//if remaining strength and recovery are more than max
//strength for character, restore to max
    if ((strength + recovery) >= maxStrength)
    {
        strength = maxStrength;
    }
//otherwise, set add recovery amount to strength
    else
    {
        strength += recovery;
    }
    std::cout << type << " " << name << " has recovered and now has " << strength;
    std::cout << " strength points!" << std::endl;
}

