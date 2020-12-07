/*********************************************************
 ** Program Name: Project 4
 ** Author: Emily Addiego
 ** Date: November 24, 2019
 ** Description: This is the cpp file for the Game class.
 ** It contains a constructor and member functions.
 ********************************************************/

#include <iostream>
#include "game.hpp"
#include<sstream>
#include<chrono>
#include<thread>

/******************************************************
 ** Description: This is the constructor for the Game
 ** class. It sets the score and number of players to 0
 ******************************************************/
Game::Game()
{
    teamAScore = 0;
    teamBScore = 0;
    numPlayers = 0;
}

/************************************************************
 ** Description: This is the menu function. It asks
 ** the user to play or quit, then calls member functions to
 ** get the lineups and play the game. At the end of the
 ** game, it calls itself again.
 ***********************************************************/
void Game::menu()
{
    std::cout << "Please choose 1 to play or 2 to quit." << std::endl;
    int choice = inputV(0, 3);
    if (choice != 2)
    {
//get number of players
            std::cout << "Please enter the number of players on each team." << std::endl;
            std::cout << "(Enter a number between 3 and 10)." << std::endl;
            int pNum = inputV(2, 11);
            numPlayers = pNum;
//call function to fill lineups
            chooseLineup();
//print lineups
            std::cout << "____YOU HAVE CHOSEN WISELY!____" << std::endl;
            std::cout << "_________TEAM A_________" << std::endl;
            teamA.printList();
            std::cout << "VERSUS..." << std::endl;
            std::cout << "_________TEAM B_________" << std::endl;
            teamB.printList();

            std::cout << '\n';
//start tournament
            std::cout << "___LET THE BATTLE BEGIN!___" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            int battle = 1;
            do
            {
                std::cout << "______BATTLE " << battle << "______" <<std::endl;
                std::cout << teamA.getTop()->getName() << " V " << teamB.getTop()->getName() << std::endl;
                tournament();
                battle++;
            } while ((teamA.isEmpty() == false) && (teamB.isEmpty() == false));
//show final results
            results();
//reset everything and ask user to play again or quit
            reset();
            std::cout << "Would you like to play again? ";
//call menu again for user to make a choice
            menu();

    }
    else if (choice == 2)
    {
        std::cout << "Thanks for playing! Goodbye!" << std::endl;
    }
}


/******************************************************************************
 ** Description: This is the inputV function. It takes two parameters an int
 ** min and an int max. It uses getline to get the entire user input, converts
 ** the input to a stream, then checks if the stream is an integer between the
 ** min and the max. If it is not, the function asks for input in a loop until
 ** correct input is entered. This function is reused from Project 1 and is
 ** based on Cuddlebuddie928's function from the following thread:
 ** http://www.cplusplus.com/forum/beginner/58833/
 ******************************************************************************/
int Game::inputV(int min, int max)
{
    int n;
    string s;
    
    while(true) {
//use getline to get entire line
        getline(std::cin, s);
//convert string to stream
        std::stringstream convert(s);
//check if stream is an integer and if it is within the minmum and maximum range
        if((convert >> n) && (!(convert >> s)) && (n > min) && (n < max))
        {
            return n;
        }
        else
        {
            std::cin.clear();
            std::cout << "Incorrect input. Try again." << std::endl;
        }
    }
}


/**************************************************************
 ** Description: This is the chooseLineup function. It calls
 ** the player1 and plauer2 menus in a loop so that the user can
 ** choose players for each team. It adds the players to the
 ** bottom of the list in the order they were chosen.
 **************************************************************/
void Game::chooseLineup()
{
    std::cout << "_____SELECT PLAYERS FOR TEAM A_____" << std::endl;
    for (int i = 0; i < numPlayers; i++)
    {
        std::cout << "Player " << i + 1 << ":" << std::endl;
        teamA.addBottom(playerMenu());
        
    }
    std::cout << '\n';
    std::cout << "_____SELECT PLAYERS FOR TEAM B_____" << std::endl;
    for (int i = 0; i < numPlayers; i++)
    {
        std::cout << "Player " << i + 1 << ":" << std::endl;
        teamB.addBottom(playerMenu());
    }
}


/************************************************************
 ** Description: This is the p1Menu function. It prompts the
 ** user to choose one of the characters to play as, then
 ** returns a pointer to a new derived class object. Source:
 ** https://stackoverflow.com/questions/4937180/a-base-class-pointer-can-point-to-a-derived-class-object-why-is-the-vice-versa
 https://stackoverflow.com/questions/773599/return-class-pointer-from-a-function
 ***********************************************************/
Character* Game::playerMenu()
{
    std::cout << "1. Vampire" << std::endl;
    std::cout << "2. Barbarian" << std::endl;
    std::cout << "3. Blue Men" << std::endl;
    std::cout << "4. Medusa" << std::endl;
    std::cout << "5. Harry Potter" << std::endl;
    int p1Choice = inputV(0, 6);
//create a new derived object from the Character pointers, depending on
//user input
    Character *player;
    if (p1Choice == 1)
    {
        player = new Vampire();
    }
    else if (p1Choice == 2)
    {
        player = new Barbarian();
    }
    else if (p1Choice == 3)
    {
        player = new BlueMen();
    }
    else if (p1Choice == 4)
    {
        player = new Medusa();
    }
    else
    {
        player = new HarryPotter();
    }
//allow the user to name the character
    std::cout << "Enter a name for your character." << std::endl;
    std::string name;
    std::getline(std::cin, name);
    player->setName(name);
//return the character
    return player;
}


/*************************************************************
 ** Description: This is the tournament function. It calls
 ** playRound() until one team's lineup is empty. At the
 ** end of each round, it deletes the losing player from
 ** its team and moves it to the losers list. It offers the
 ** user the option to print the losers list before moving
 ** on to the next round.
 *************************************************************/
void Game::tournament()
{
//bool flag to track winner of round
    bool teamAWin = false;
//seed rand() to randomize attack and defend functions
    std::srand(time(0));
    int round = 1;
//play the game until one player's strength points <= 0
    do
    {
        std::cout << "_______ROUND " << round << "_______" << std::endl;
//play a round
        playRound();
        std::cout << '\n';
//exit and print a message if player1 has died
        if (teamA.getTop()->getStrength() <= 0)
        {
            std::cout << "Game over! " << teamA.getTop()->getName();
            std::cout << " has died!" << std::endl;
            teamAWin = false;
        }
//exit and print a message if player2 has died
        if (teamB.getTop()->getStrength() <= 0)
        {
            std::cout << "Fight over! " << teamB.getTop()->getName();
            std::cout << " has died!" << std::endl;
            teamAWin = true;
        }
//increment round
        round++;
//use chrono to display gameplay in stages
        std::this_thread::sleep_for(std::chrono::seconds(1));
    } while ((teamA.getTop()->getStrength() > 0) && (teamB.getTop()->getStrength() > 0));
    std::cout << "________END OF BATTLE________" << std::endl;
    std::cout << '\n';
//print who won
    if (teamAWin == false)
    {
        std::cout << "Team A loses this battle!" << std::endl;
//add player to losers list
        losers.addTop(teamA.getTop());
        std::cout << teamA.getTop()->getType() << " ";
        std::cout << teamA.getTop()->getName();
        std::cout << " added to losers list and removed from Team A." << std::endl;
//delete player from team
        teamA.deleteTop();
//recover player 2 and move to end of list
        teamB.getTop()->recovery();
        teamB.movePlayer();
        teamBScore += 1;
    }
    if (teamAWin == true)
    {
        std::cout << "Team B loses this battle!" << std::endl;
//add player to losers list
        losers.addTop(teamB.getTop());
        std::cout << teamB.getTop()->getType() << " ";
        std::cout << teamB.getTop()->getName();
        std::cout << " added to losers list and removed from Team B." << std::endl;
//delete player from team
        teamB.deleteTop();
//recover player 2 and move to end of list
        teamA.getTop()->recovery();
        teamA.movePlayer();
        teamAScore += 1;
    }
    std::cout << "Would you like to print the losers list?" << std::endl;
    std::cout << "Enter 1 for yes, or 2 for no." << std::endl;
    int lose = inputV(0, 3);
    if (lose == 1)
    {
    std::cout << "LOSERS BOARD:" << std::endl;
    losers.printList();
    std::cout << '\n';
//use chrono to delay start of next round
    std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    else
    {
//use chrono to delay start of next round
    std::this_thread::sleep_for(std::chrono::seconds(2));
    }

}

/**************************************************************
 ** Description: This is the playRound function. It is based on
 ** the same function from Project 3 and pits the players against
 ** each other in two fights, then prints the results of each
 ** attack.
 **************************************************************/
void Game::playRound()
{
//make sure both players still have strength points
    if ((teamA.getTop()->getStrength() > 0) && (teamB.getTop()->getStrength() > 0))
    {
        std::cout << "First Attack:" << std::endl;
//get numbers for attack and defense
        int a = teamA.getTop()->attack();
        int d = teamB.getTop()->defend();
//print both players' names
        std::cout << "Attacking player: " << teamA.getTop()->getType() << ": ";
        std::cout << teamA.getTop()->getName() << std::endl;
        std::cout << "Defending player: " << teamB.getTop()->getType() << ": ";
        std::cout << teamB.getTop()->getName() << std::endl;
//print player 2's stats
        std::cout << teamB.getTop()->getName() << "'s stats:" << std::endl;
        std::cout << "Armor: " << teamB.getTop()->getArmor() << " | Strength: ";
        std::cout << teamB.getTop()->getStrength() << std::endl;
//pass attack and defense to player 2's calcDamage function
        teamB.getTop()->calcDamage(a, d, teamA.getTop()->getName());
//print remaining strength points
        std::cout << teamB.getTop()->getName() << " now has " << teamB.getTop()->getStrength();
        std::cout << " strength points remaining." << std::endl;
        std::cout << '\n';
    }
//make sure both players still have strength points
    if ((teamA.getTop()->getStrength() > 0) && (teamB.getTop()->getStrength() > 0))
    {
        std::cout << "Second Attack:" << std::endl;
//get numbers for attack and defense
        int a = teamB.getTop()->attack();
        int d = teamA.getTop()->defend();
//print both players' names
        std::cout << "Attacking player: " << teamB.getTop()->getType() << ": ";
        std::cout << teamB.getTop()->getName() << std::endl;
        std::cout << "Defending player: " << teamA.getTop()->getType() << ": ";
        std::cout << teamA.getTop()->getName() << std::endl;
//print player 1's stats
        std::cout << teamA.getTop()->getName() << "'s stats:" << std::endl;
        std::cout << "Armor: " << teamA.getTop()->getArmor() << " | Strength: ";
        std::cout << teamA.getTop()->getStrength() << std::endl;
        //pass attack and defense to player 2's calcDamage function
        teamA.getTop()->calcDamage(a, d, teamB.getTop()->getName());
//print remaining strength points
        std::cout << teamA.getTop()->getName() << " now has " << teamA.getTop()->getStrength();
        std::cout << " strength points remaining." << std::endl;
    }
    }


/**************************************************************
 ** Description: This is the results function. It calculates the
 ** winner based on the amount of points and displays the final
 ** results of the game.
 **************************************************************/
void Game::results()
{
//print final score
    std::cout << "_______GAME OVER!_______" << std::endl;
    std::cout << "_______FINAL RESULTS:_______" << std::endl;
    std::cout << "Team A: " << teamAScore << " points." << std::endl;
    std::cout << "Team B: " << teamBScore << " points." << std::endl;
//see which score is higher or if it is a tie
    if (teamAScore == teamBScore)
    {
        std::cout << "IT'S A TIE!" << std::endl;
    }
    else if (teamAScore > teamBScore)
    {
        std::cout << "TEAM A WINS!" << std::endl;
    }
    else if (teamBScore > teamAScore)
    {
        std::cout << "TEAM B WINS!" << std::endl;
    }
    
}

/***************************************************************
** Description: This is the reset function. It deletes the
** contents of the containers and resets the scores to 0.
***************************************************************/
void Game::reset()
{
    teamAScore = 0;
    teamBScore = 0;
    if (losers.isEmpty() == false)
    {
    losers.clearList();
    }
    if (teamA.isEmpty() == false)
    {
    teamA.clearList();
    }
    if (teamB.isEmpty() == false)
    {
    teamB.clearList();
    }      
}
