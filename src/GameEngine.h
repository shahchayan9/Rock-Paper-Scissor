#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Player.h"
#include "RandomComputerPlayer.h"
#include "SmartComputerPlayer.h"
#include <string>

using namespace std;

class GameEngine {
private:
    int humanWins;
    int computerWins;
    int ties;
    Player *human;
    Player *computer;
    string choice_to_string(Choice choice);
    
public:
    GameEngine(Player *human, Player *computer);
    void play_round();
    void display_results();
    ~GameEngine();
};

#endif