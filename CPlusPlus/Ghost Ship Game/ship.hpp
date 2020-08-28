/*****************************************************************
 ** Program Name: Final Project
 ** Author: Emily Addiego
 ** Date: December 10, 2019
 ** Description: This is the header file for the Ship class. It
** contains member functions and pointers for the space objects.
 ******************************************************************/

#ifndef ship_hpp
#define ship_hpp
#include<vector>
#include<iostream>
#include "space.hpp"
#include "kitchen.hpp"
#include "stairs.hpp"
#include "deck.hpp"
#include "bridge.hpp"
#include "diningRoom.hpp"

class Ship
{
private:
    Space *playerAt;
    Space *cabin1;
    Space *cabin2;
    Space *cabin3;
    Space *cabin4;
    Space *cabin5;
    Space *kit;
    Space *stair1;
    Space *stair2;
    Space *dining;
    Space *deck;
    Space *bridge;
    std::vector<std::string> container;
    int strength = 15;
    bool win = false;
    bool dead = false;
public:
    Ship();
    void makeShip();
    void deleteShip();
    void reset();
    void room();
    void movePlayer();
    void getItem();
    int getTask();
    int inputV(int min, int max);
    bool canOpen();
    bool haveKnife();
    bool haveCrucifix();
    bool haveMap();
    void finalBattle();
    void addItem(std::string i);
    int gameState();
    
};

#endif /* ship_hpp */

