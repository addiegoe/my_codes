/************************************************************
 ** Program Name: Project 4
 ** Author: Emily Addiego
 ** Date: November 24, 2019
 ** Description: This is the cpp file for the Vampire class.
 ** It contains a constructor and an overriding attack,
 ** defend, and calcDamage function.
 ************************************************************/

#include "vampire.hpp"

/************************************************************
 ** Description: This is the constructor for the Vampire
 ** objects. It sets the armor, strength, and type.
 ***********************************************************/
Vampire::Vampire()
{
    armor = 1;
    strength = 18;
    maxStrength = 18;
    type = "Vampire";
}

/************************************************************
** Description: This is the destructor for the Vampire
** objects.
***********************************************************/
Vampire::~Vampire()
{
    
}

/************************************************************
 ** Description: This is the attack function. It overrides
 ** the base class attack function. It returns a random
 ** "roll" between 1 and 12.
 ***********************************************************/
int Vampire::attack()
{
    int die = (std::rand() % 12) + 1;
    return die;
}


/************************************************************
 ** Description: This is the defend function. It overrides
 ** the base class defend function. It generates a random
 ** number between 0 and 100. If the number is <= 50, it
 ** returns the "garbage" value 200, to create CHARM.
 ** Otherwise, it returns and random "roll" between 1
 ** and 6. Idea from:
 //https://piazza.com/class/k0rofchnorj31s?cid=413
 ************************************************************/
int Vampire::defend()
{
    //generate CHARM 50% of the time
    int charm = (std::rand() % 100) + 1;
    if (charm <= 50)
    {
        return 200;
    }
    else
    {
        int die = (std::rand() % 6) + 1;
        return die;
    }
}


/************************************************************
 ** Description: This is the calcDamage function. It
 ** takes 3 parameters, an int attack, int defend, and string
 ** name. It overrides the base class function. If CHARM is
 ** used, it blocks the attacker's attack. If CHARM is used
 ** against GLARE, charm overrides glare and no damage is
 ** done to the Vampire. If there are no special cases, it
 ** prints out the attack, defense, and damage taken.
 ***********************************************************/
void Vampire::calcDamage(int attack, int defend, string n)
{
    int total = attack - defend - armor;
    int dam;
    //if GLARE and CHARM are used, charm overrides glare
    if ((attack == 100) && (defend = 200))
    {
        std::cout << "Medusa tried to use GLARE,";
        std::cout << " but Vampire blocked it with CHARM!" << std::endl;
        std::cout << "Vampire suffers no damage!" << std::endl;
        
    }
    //if Vampire uses CHARM, override the attack, no damage taken
    else if ((attack != 100) && (defend == 200))
    {
        std::cout << "Vampire used CHARM!" << std::endl;
        std::cout << n << " has been charmed out of attacking!" <<std::endl;
        std::cout << "Vampire takes no damage!" << std::endl;
    }
    //if damage was <= 0, no damage taken
    else if ((total <= 0) && (attack != 100) && (defend != 200))
    {
        dam = 0;
        std::cout << n << " rolled: " << attack << std::endl;
        std::cout << name << " rolled: " << defend << std::endl;
        std::cout << name << " suffers " << dam;
        std::cout << " points of damage." << std::endl;
        strength -= dam;
    }
    //otherwise, calculate damage
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
