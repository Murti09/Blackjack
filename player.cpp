#include "player.h"

Player::Player(std::string name)
    : m_name(name)
{
}

void Player::takeCard(Deck &deck)
{
    m_hand.push_back(deck.drawCard());
}

int Player::getHandValue()
{
    int value = 0;
    int anzAss = 0;

    for (const Card &s : m_hand)
    {
        value += s.getValue();
        if (s.getRank() == 1)
        {
            anzAss++;
        }
    }

    while (value > 21 && anzAss > 0)
    {
        value -= 10;
        anzAss--;
    }

    return value;
}

bool Player::isBusted()
{
    if (getHandValue() > 21)
        return true;

    return false;
}

void Player::showHand()
{
    std::cout << m_name << ":" << std::endl;
    for (const Card &c : m_hand)
    {
        std::cout << c << std::endl;
    }
}