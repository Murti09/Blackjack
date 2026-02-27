#pragma once
#include "player.h"
#include "dealer.h"
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

class Game
{
private:
    Player player;
    Dealer dealer;

public:
    Game();
    void playRound();
    void playerTurn();
    void dealerTurn();
    void determineWinner();
    void showHands(bool revealAll);
};