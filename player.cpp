#include "player.h"
#include "methods.h"

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
    calculateHandValue(m_hand);
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