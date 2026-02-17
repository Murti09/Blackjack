#include "game.h"

Game::Game()
    : player("Player"), dealer()
{
}

void Game::playRound()
{
    dealer.shuffleCards();

    dealer.dealCard(player);
    dealer.takeCard();
    dealer.dealCard(player);
    dealer.takeCard();

    player.showHand();
    dealer.showHand(false); // Nur die erste karte anzeigen

    if (player.getHandValue() == 21 && dealer.getHandValue() != 21)
    {
        std::cout << "Blackjack! " << player.getName() << " wins!" << std::endl;
        return;
    } // Player hat blackjack

    if (player.getHandValue() != 21 && dealer.getHandValue() == 21)
    {
        dealer.showHand(true);
        std::cout << "Dealer has Blackjack! Dealer wins!" << std::endl;
        return;
    } // Dealer hat blackjack

    if (player.getHandValue() == 21 && dealer.getHandValue() == 21)
    {
        dealer.showHand(true);
        std::cout << "Both have Blackjack!" << std::endl;
        return;
    } // untentschieden

    //----------------------------------Spieler Interaktionen

    playerTurn();
    dealerTurn();

    determineWinner();
}

void Game::playerTurn()
{
    char choice;
    bool playerTurn = true;

    while (playerTurn)
    {
        std::cout << "Hit or Stand? (H/S): ";
        std::cin >> choice;
        std::cout << std::endl;

        if (choice == 'h' || choice == 'H')
        {
            system("cls");
            dealer.dealCard(player);
            player.showHand();
            if (player.isBusted())
                return;
            if (player.getHandValue() == 21)
            {
                std::cout << player.getName() << " has 21!" << std::endl;
                return;
            }
        }
        else if (choice == 's' || choice == 'S')
        {
            playerTurn = false;
        }
        else
        {
            std::cout << "Invalid input. Try again (H/S)" << std::endl;
        }
    }
}

void Game::dealerTurn()
{
    if (player.isBusted())
        return;

    dealer.showHand(true);

    dealer.play();

    dealer.showHand(true);
}

void Game::determineWinner()
{
    int playerValue = player.getHandValue();
    int dealerValue = dealer.getHandValue();

    if (player.isBusted())
    {
        std::cout << "Dealer wins!" << std::endl;
        return;
    }

    else if (dealerValue > 21)
    {
        std::cout << player.getName() << " wins!" << std::endl;
        return;
    }

    else if (playerValue > dealerValue)
    {
        std::cout << player.getName() << " wins!" << std::endl;
        return;
    }

    else if (playerValue < dealerValue)
    {
        std::cout << "Dealer wins!" << std::endl;
        return;
    }

    else
    {
        std::cout << "draw!" << std::endl;
        return;
    }
}