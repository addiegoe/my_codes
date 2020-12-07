/************************************************************
 ** Program Name: Project 4
 ** Author: Emily Addiego
 ** Date: November 24, 2019
 ** Description: This is the header file for the Harry Potter
 ** class. It contains an overriding function for
 ** calcDamage and a constructor.
 ************************************************************/
#include "harryPotter.hpp"

/************************************************************
 ** Description: This is the constructor for the HarryPotter
 ** objects. It sets the armor, strength, lives, and type.
 ***********************************************************/
HarryPotter::HarryPotter()
{
    armor = 0;
    strength = 10;
    maxStrength = 10;
    lives = 2;
    type = "Harry Potter";
}

/************************************************************
 ** Description: This is the destructor for the HarryPotter
 ** objects.
 ***********************************************************/
HarryPotter::~HarryPotter()
{
    
}

/************************************************************
 ** Description: This is the calcDamage function. It overrides
 ** the base class function. It uses Hogwarts to reset
 ** the character's strength to 20 and lives to 1 if Harry's
 ** strength reaches 0 on the first life. After the second
 ** life, if Harry's strength <= 0, Harry dies. If the function
 ** receives an attack of 100, it defends against GLARE by using
 ** Hogwarts if it's on Harry's first life. Otherwise, it prints
 ** a message that Harry has died and sets his strength to 0.
 ***********************************************************/
void HarryPotter::calcDamage(int attack, int defend, string n)
{
    int total = attack - defend - armor;
    int dam;
    //if Medusa uses glare, and lives = 2, use Hogwarts and reset lives and strength
    if ((attack == 100) && (lives == 2))
    {
        std::cout << "Medusa used GLARE!" << std::endl;
        std::cout << "But Harry Potter used HOGWARTS to come back to life!" << std::endl;
        strength = 20;
        lives = 1;
        std::cout << "Harry Potter now has 1 life remaining." << std::endl;
        
    }
    //if Medusa used glare and lives < 2, Harry dies
    else if ((attack == 100) && (lives < 2))
    {
        std::cout << "Medusa used GLARE!" << std::endl;
        std::cout << "Harry Potter couldn't recover!" << std::endl;
        std::cout << "Harry Potter dies!" << std::endl;
        strength = 0;
        lives = 0;
    }
    //if damage <= 0, set damage to 0
    else if ((total <= 0) && (attack != 100))
    {
        dam = 0;
        std::cout << n << " rolled: " << attack << std::endl;
        std::cout << name << " rolled: " << defend << std::endl;
        std::cout << name << " suffers " << dam;
        std::cout << " points of damage." << std::endl;
        strength -= dam;
    }
    //calculate damage and print
    else
    {
        dam = total;
        std::cout << n << " rolled: " << attack << std::endl;
        std::cout << name << " rolled: " << defend << std::endl;
        std::cout << name << " suffers " << dam;
        std::cout << " points of damage." << std::endl;
        strength -= dam;
        //implement Hogwarts if Harry's strength gets below 0
        if ((strength <= 0) && (lives == 2))
        {
            std::cout << "Harry is a wizard! He used HOGWARTS to restore his strength!" << std:: endl;
            strength = 20;
            lives = 1;
            std::cout << "Harry Potter now has one life." << std::endl;
        }
        //if lives < 2, Harry can't use Hogwarts and dies
        else if ((strength <= 0) && (lives < 2))
        {
            std::cout << "Harry Potter has no lives remaining." << std::endl;
        }
        
    }
    
}

