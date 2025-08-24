#pragma once
#include "deck.h"

class Player
{
private:
    std::string m_name;
    std::vector<Card> m_hand;

public:
    Player(std::string name);
    void takeCard(Deck &deck);
    int getHandValue();
    bool isBusted();
    void showHand();
};