#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "HumanPlayer.h"
#include "ComputerPlayer.h"
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
    ComputerPlayer *computer;
    string choice_to_string(Choice choice);
    
public:
    GameEngine(HumanPlayer *human, ComputerPlayer *computer);
    void play_round();
    void display_results();
    ~GameEngine();
};

#endif