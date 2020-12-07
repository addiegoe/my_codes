/*********************************************************
 ** Program Name: Project 4
 ** Author: Emily Addiego
 ** Date: November 24, 2019
 ** Description: This is the header file for the Game
 ** class. It contains member functions for game play
 ** and 3 container objects, one for each lineup and one
 ** for the losers list.
 ********************************************************/

#ifndef game_hpp
#define game_hpp
#include "container.hpp"
#include "character.hpp"
#include "barbarian.hpp"
#include "blueMan.hpp"
#include "harryPotter.hpp"
#include "medusa.hpp"
#include "vampire.hpp"

class Game
{
private:
    Container teamA;
    Container teamB;
    Container losers;
    int teamAScore;
    int teamBScore;
    int numPlayers;
public:
    Game();
    void menu();
    int inputV(int max, int min);
    void gameMenu();
    void tournament();
    void chooseLineup();
    void playRound();
    void results();
    void reset();
    Character* playerMenu();

};

#endif
