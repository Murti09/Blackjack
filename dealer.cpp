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

int Dealer::getHandValue() const
{
    return calculateHandValue(m_hand);
}

void Dealer::play()
{
    while (getHandValue() < 17)
        takeCard();
}

void Dealer::showFirstCard() const
{
    std::cout << m_hand[0] << std::endl;
}

void Dealer::showHand(bool revealAll) const
{
    if (revealAll)
    {
        printCards("Dealer", m_hand);
        std::cout << "Wert: " << getHandValue() << std::endl;
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Dealer: " << std::endl;
        std::cout << m_hand[0] << std::endl;
        std::cout << "[?]" << std::endl;
        std::cout << std::endl;
    }
}