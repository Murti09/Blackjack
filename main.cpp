#include "card.h"
#include "deck.h"
#include "player.h"
#include "dealer.h"

int main()
{
    Dealer dealer;
    Player player("Murti");

    for (int i = 0; i < 2; i++)
    {
        dealer.dealCard(player);
        dealer.takeCard();
    }

    player.showHand();
    std::cout << player.getHandValue() << std::endl;;
    dealer.showHand();
    std::cout << dealer.getHandValue() << std::endl;
}