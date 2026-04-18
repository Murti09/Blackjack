#include "card.h"

Card::Card(const std::string& suit, int rank)
    : m_rank(rank), m_suit(suit)
{
}

/* void Card::toString()
{
    std::string rankStr;
    switch (m_rank)
    {
    case 1: rankStr = "Ass"; break;
    case 11: rankStr = "Bube"; break;
    case 12: rankStr = "Dame"; break;
    case 13: rankStr = "Koenig"; break;
    default: rankStr = std::to_string(m_rank); break;
    }
} */

int Card::getValue() const
{
    if(m_rank > 10 && m_rank < 14)
        return 10;

    if(m_rank == 1)
        return 11;

    return m_rank;
}

int Card::getRank() const
{
    return m_rank;
}

std::ostream& operator <<(std::ostream& os, const Card& card)
{
    std::string rankStr;
    switch (card.m_rank)
    {
        case 1: rankStr = "A"; break;
        case 11: rankStr = "J"; break;
        case 12: rankStr = "Q"; break;
        case 13: rankStr = "K"; break;
        default: rankStr = std::to_string(card.m_rank); break;
    }
    os << card.m_suit << " " << rankStr;
    return os;
}