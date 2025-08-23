#include <vector>
#include <algorithm>
#include <random>
#include "card.h"

class Deck
{
private:
    std::vector<Card> m_cards;

public:
    Deck();
    void shuffle();
    Card drawCard();
    void printCards();
};