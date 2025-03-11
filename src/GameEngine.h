#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Player.h"

class GameEngine {
private:
    int humanWins, computerWins, ties;
    Player *human;
    Player *computer;

public:
    GameEngine(Player *humanPlayer, Player *computerPlayer);
    void playRound();
    void displayResults();
};

#endif