#include "card.h"
#include "deck.h"
#include "player.h"
#include "dealer.h"

int main()
{
    system("chcp 65001 > nul");

    /* Dealer dealer;
    Player player("Murti");

    for (int i = 0; i < 2; i++)
    {
        dealer.dealCard(player);
        dealer.takeCard();
    }

    player.showHand();
    std::cout << player.getHandValue() << std::endl;;
    dealer.showHand();
    std::cout << dealer.getHandValue() << std::endl; */

    Dealer dealer;
    Player player("Murti");

    // Anfangsphase
    dealer.dealCard(player);
    dealer.takeCard();
    dealer.dealCard(player);
    dealer.takeCard();

    player.showHand();        // zeigt alles
    dealer.showHand(false);   // zeigt nur 1 Karte + [verdeckt]

    // Später, nach Spieler-Zug
    dealer.showHand(true);    // zeigt alle Karten

}