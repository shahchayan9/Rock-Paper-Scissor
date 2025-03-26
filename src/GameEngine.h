#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "RandomComputerPlayer.h"
#include "SmartComputerPlayer.h"
#include "ComputerPlayerFactory.h"
#include <string>
#include <vector>

using namespace std;

class GameEngine {
private:
    ComputerPlayerFactory factory;
    int human_wins;
    int computer_wins;
    int ties;
    Player *human;
    ComputerPlayer *computer;
    Choice string_to_choice(string choice);
    string choice_to_string(Choice choice);
    
public:
    GameEngine();
    vector<string> play_round(string human_choice_string);
    void select_computer_player(string algo_type);
    vector<int> get_stats();
    void save_frequencies();
    ~GameEngine();
};

#endif
