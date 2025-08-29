#include "dealer.h"
#include "methods.h"

Dealer::Dealer()
{
    m_deck.shuffle();
}

void Dealer::dealCard(Player &p)
{
    p.takeCard(m_deck);
}

void Dealer::takeCard()
{
    m_hand.push_back(m_deck.drawCard());
}

int Dealer::getHandvalue() const
{
    calculateHandValue(m_hand);
}