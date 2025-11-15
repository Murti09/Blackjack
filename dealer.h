#include "player.h"

class Dealer
{
private:
    Deck m_deck;
    std::vector<Card> m_hand;

public:
    Dealer();
    void dealCard(Player& p);
    void takeCard();

    int getHandValue() const;
    void play(); // Bis 17 ziehen

    void showFirstCard() const;
    void showHand(bool revealAll) const;
};