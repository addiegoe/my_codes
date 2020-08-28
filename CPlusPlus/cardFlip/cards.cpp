/*****************************************************
 ** Author: Emily Addiego
 ** Date: August 2019
 ** Description: This game displays a series of cards
 ** (represented by 1 for face-up and 0 for face-down)
 ** The user can only remove a face-up card. When
 ** removed, the cards on either side will flip. If all
 ** cards are removed, the user wins. If cards can't be
 ** removed, the user loses.
 *****************************************************/

#include "cards.hpp"
#include<iostream>
#include<algorithm>
#include<vector>
#include<random>

/**************************************************
 ** Description: The flipCard changes the number
 ** at the location of the vector to 1 or 0
 **************************************************/
void Cards::flipCard(std::vector<int> &vec, int b)
{
    if (vec.at(b) == 1)
    {
        vec.at(b) = 0;
    }
    else
    {
        vec.at(b) = 1;
    }
}


/**************************************************
 ** Description: The removeCard function sees if
 ** the move is legal, deletes the card, then
 ** flips the cards on either side.
 **************************************************/
void Cards::removeCard(std::vector<int> &vec, int a)
{
//see if move is legal and flip cards
    if ((vec.at(a) == 1) && (a < (vec.size() - 1)) && (a > 0))
    {
        flipCard(vec, (a + 1));
        flipCard(vec, (a - 1));
        vec.erase(vec.begin() + a);
    }
    else if ((vec.at(a) == 1) && (a == 0) && (a != (vec.size() - 1)))
    {
        flipCard(vec, (a + 1));
        vec.erase(vec.begin() + a);
    }
    else if ((vec.at(a) == 1) && (a == (vec.size() - 1)) && (a != 0))
    {
        flipCard(vec, (a - 1));
        vec.erase(vec.begin() + a);
    }
    else if ((vec.at(a) == 1) && (a == 0) && (a == (vec.size() - 1)))
    {
        vec.clear();
    }
    else
    {
        std::cout << "Move is not possible." << std::endl;
    }
//check for win or loss
    int x = 1;
    if (vec.empty())
    {
        thisGame = WIN;
        std::cout << "You win!" << std::endl;
    }
//if no 1's are left, the player loses
    else if (std::find(vec.begin(), vec.end(), x) == vec.end())
    {
        thisGame = LOSE;
        std::cout << "No moves left. You lose." << std::endl;
    }
    else
    {
        thisGame = UNFINISHED;
        std::cout << "Keep playing." << std::endl;
    }
}

/**************************************************
 ** Description: The playGame function shuffles the
 ** vector and runs game play.
 **************************************************/
void Cards::playGame()
{
//shuffle cards randomly each time game is played
//source: https://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    std::shuffle(cards.begin(), cards.end(), e);
//show cards
    for (auto i : cards)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
//loop for game play, while game is unfinished
    do
    {
        std::cout << "Choose a card to remove." << std::endl;
        std::cin >> playCard;
        removeCard(cards, playCard);
        std::cout << "\n";
        for (auto i: cards)
        {
            std::cout << i << ' ';
        }
        std::cout << "\n";
    }
    while (thisGame == UNFINISHED);
//offer the user a choice to play again
    std::cout << "Would you like to play again? Enter 1 to play again or 2 to quit." << std::endl;
    int choice;
    std::cin >> choice;
//if chocie is yes, call playGame again
    if (choice == 1)
    {
        playGame();
    }
    else{
        std::cout << "Goodbye." <<std::endl;
    }
}
