#include "game.h"

Game::Game()
    : player("Player"), dealer()
{
}

void Game::playRound()
{
    bool nextRound;
    char choice;
    do
    {
        dealer.shuffleCards();

        dealer.dealCard(player);
        dealer.takeCard();
        dealer.dealCard(player);
        dealer.takeCard();

        showHands(false); // Nur die erste karte anzeigen

        if (player.getHandValue() == 21 && dealer.getHandValue() != 21)
        {
            std::cout << "Blackjack! " << player.getName() << " wins!" << std::endl;
        } // Player hat blackjack

        else if (player.getHandValue() != 21 && dealer.getHandValue() == 21)
        {
            dealer.showHand(true);
            std::cout << "Dealer has Blackjack! Dealer wins!" << std::endl;
        } // Dealer hat blackjack

        else if (player.getHandValue() == 21 && dealer.getHandValue() == 21)
        {
            dealer.showHand(true);
            std::cout << "Both have Blackjack!" << std::endl;
        } // untentschieden

        //----------------------------------Spieler Interaktionen
        else
        {
            playerTurn();
            dealerTurn();
            determineWinner();
        }
        do
        {
            std::cout << "\nNext round? (Y/N): ";
            std::cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                nextRound = true;
                system("cls");
                player.clearHand();
                dealer.clearHand();
                dealer.resetDeck();
                break;
            }
            else if (choice == 'n' || choice == 'N')
            {
                nextRound = false;
                break;
            }
            else
            {
                std::cout << "Invalid input!" << std::endl;
            }
        } while (true);
    } while (nextRound);
}

void Game::playerTurn()
{
    char choice;
    bool playerTurn = true;

    while (playerTurn)
    {
        std::cout << "\nHit or Stand? (H/S): ";
        std::cin >> choice;

        if (choice == 'h' || choice == 'H')
        {
            system("cls");
            dealer.dealCard(player);
            showHands(false);
            if (player.isBusted())
                return;
            if (player.getHandValue() == 21)
            {
                std::cout << player.getName() << " has 21!" << std::endl;
                std::cout << std::endl;
                return;
            }
        }
        else if (choice == 's' || choice == 'S')
        {
            playerTurn = false;
        }
        else
        {
            std::cout << "Invalid input!" << std::endl;
        }
    }
}

void Game::dealerTurn()
{
    if (player.isBusted())
        return;

    std::this_thread::sleep_for(1s);
    system("cls");
    showHands(true);

    while (dealer.getHandValue() < 17)
    {
        std::this_thread::sleep_for(1s);
        system("cls");
        dealer.takeCard();
        showHands(true);
    }
    system("cls");
    showHands(true);
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
        std::cout << "\n" << player.getName() << " wins!" << std::endl;
        return;
    }

    else if (playerValue > dealerValue)
    {
        std::cout << "\n" << player.getName() << " wins!" << std::endl;
        return;
    }

    else if (playerValue < dealerValue)
    {
        std::cout << "\nDealer wins!" << std::endl;
        return;
    }

    else
    {
        std::cout << "\nDraw!" << std::endl;
        return;
    }
}

void Game::showHands(bool revealAll)
{
    player.showHand();
    dealer.showHand(revealAll);
}