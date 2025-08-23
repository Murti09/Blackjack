#include "card.h"
#include "deck.h"

int main()
{
    Deck karten;
    karten.shuffle();
    karten.printCards();

    std::cout << std::endl;

    Card karte1 = karten.drawCard();
    Card karte2 = karten.drawCard();
    Card karte3 = karten.drawCard();
    Card karte4 = karten.drawCard();
    Card karte5 = karten.drawCard();

    std::cout << karte1 << std::endl;    
    std::cout << karte2 << std::endl;
    std::cout << karte3 << std::endl;
    std::cout << karte4 << std::endl;
    std::cout << karte5 << std::endl;    
}