#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Player.h"
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <ctime>

class RandomComputerPlayer : public Player {
public:
    RandomComputerPlayer();
    Choice choose() override;
};

// Smart strategy: Predicts human's next move
class SmartComputerPlayer : public Player {
private:
    std::vector<Choice> history; // Stores past human choices
    Choice predictNextMove(); // Function to predict the next move
public:
    SmartComputerPlayer();
    Choice choose() override;
    void recordHumanMove(Choice humanChoice); // Store move history
};

#endif
