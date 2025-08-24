#include "card.h"
#include "deck.h"
#include "player.h"

int main()
{
    Deck karten;
    karten.shuffle();
    karten.printCards();
    std::cout << std::endl;
}