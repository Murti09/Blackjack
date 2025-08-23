#include "deck.h"

class Player
{
private:
    std::string m_name;
    std::vector<Card> m_hand;

public:
    Player(std::string name);
    void takeCard(Card karte);
    int getHandValue();
    bool isBusted();
    void showHand();
};