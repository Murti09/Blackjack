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
    return calculateHandValue(m_hand);
}

bool Player::isBusted()
{
    if (getHandValue() > 21)
        return true;

    return false;
}

void Player::showHand()
{
    printCards(m_name, m_hand);
    std::cout << "Wert: " << getHandValue() << std::endl;
    std::cout << std::endl;
}