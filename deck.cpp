#include "deck.h"

Deck::Deck()
{
    std::vector<std::string> suits = {"Herz", "Karo", "Pik", "Kreuz"};
    std::vector<int> ranks = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

    for (const auto &s : suits)
    {
        for (const int &r : ranks)
        {
            m_cards.push_back(Card(s, r));
            // std::cout << m_cards.back() << std::endl;
        }
    }
}

void Deck::shuffle()
{
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(m_cards.begin(), m_cards.end(), g);
}

void Deck::printCards()
{
    int anzKarten = 0;
    for (Card c : m_cards)
    {
        std::cout << c << std::endl;
        anzKarten++;
    }
    std::cout << "Kartenanzahl: " << anzKarten << std::endl;
}

Card Deck::drawCard()
{
    Card karte = m_cards.back();
    m_cards.pop_back();
    return karte;
}