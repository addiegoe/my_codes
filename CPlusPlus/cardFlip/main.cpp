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

#include<iostream>
#include "cards.hpp"
//main function
int main()
{
//create a Cards object
    Cards card;
    
    std::cout << "CARD FLIP GAME\n\n";
    
    std::cout << "Instructions: choose an upward-facing card (marked 1) to remove" << std::endl;
    std::cout << "from the collection of cards. The cards on either side of the removed" << std::endl;
    std::cout << "card will flip. Your goal is to remove all cards from the board. You" << std::endl;
    std::cout << "can't remove downward-facing cards (marked 0). If all cards are removed," << std::endl;
    std::cout << "you win. If no more moves are possible, you lose.\n";
    card.playGame();
    
    return 0;
}
