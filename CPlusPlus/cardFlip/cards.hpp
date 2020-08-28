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
#include<vector>
#ifndef cards_hpp
#define cards_hpp

enum Game {WIN, LOSE, UNFINISHED};
class Cards
{
private:
    std::vector<int> cards = {1, 1, 1, 1, 0, 0, 0, 0, 0};
    int playCard = 0;
    Game thisGame;
public:
    void flipCard(std::vector<int> &vec, int b);
    void removeCard(std::vector<int> &vec, int a);
    void playGame();
    
};

#endif /* cards_hpp */
