/******************************************************************************
 ** Program Name: Project 2
 ** Author: Emily Addiego
 ** Date: October 27, 2019
 ** Description: This is the header file for the Zoo class. It contains member
 ** variables for the bank, daily profit, and food cost, as well as member
 ** variables to track the size/capacity of the arrays and whether the animals
 ** can have babies. It has animal object pointers to make arrays. It also
 ** contains various member functions to help the program run. 
 ******************************************************************************/
#ifndef zoo_hpp
#define zoo_hpp

#include "animal.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"
#include "animal4.hpp"

class Zoo
{
private:
//numbers to track how many animals in zoo
    int turtNum, tigNum, penNum, animal4Num;
//numbers to track capacity of array
    int tigCapacity, turtCapacity, penCapacity, animal4Capacity;
//numbers to track money made and spent
    double bank, dailyPay, foodCharge;
//bool flags to track if animals can have babies
    bool tigerBaby, penguinBaby, turtleBaby, a4Baby;
//animal object pointers to make arrays
    Tiger *tigers;
    Penguin *penguins;
    Turtle *turtles;
//fourth animal for extra credit
    Animal4 *fourthArray;
    std::string a4Name;
    int a4Payoff;
    int a4BFC;
    int a4NumBabies;
    int a4Cost;
public:
    Zoo();
    void menu();
    int inputV(int min, int max);
    void makeArrays();
    void deleteArrays();
    void runGame();
    void feedAnimals();
    void randomEvent();
    void haveBaby();
    void sickness();
    void attendanceBoom();
    void makeNewAnimal();
    void deleteTigers(Tiger *&array);
    void addTigers(Tiger *&array);
    void deleteTurtles(Turtle *&array);
    void addTurtles(Turtle *&array);
    void deletePenguins(Penguin *&array);
    void addPenguins(Penguin *&array);
    void deleteFourth(Animal4 *&array);
    void addFourth(Animal4 *&array);
};

#endif
