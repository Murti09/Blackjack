#pragma once
#include "player.h"
#include "dealer.h"

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
};