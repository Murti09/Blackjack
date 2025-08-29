#include "card.h"
#include "deck.h"
#include "player.h"
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    Deck karten;
    karten.shuffle();
    
    Player player("Murti");
    Player dealer("dealer");

    player.takeCard(karten);
    player.takeCard(karten);

    dealer.takeCard(karten);
    dealer.takeCard(karten);

    player.showHand();
    std::cout << player.getHandValue() << std::endl;

    std::cout << std::endl;

    dealer.showHand();
    std::cout << dealer.getHandValue() << std::endl;

    std::cout << std::endl;
    karten.printCards();
}