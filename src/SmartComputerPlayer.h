#ifndef SMARTCOMPUTERPLAYER_H
#define SMARTCOMPUTERPLAYER_H

#include "Player.h"
#include <deque>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Smart strategy: Predicts human's next move using ML
class SmartComputerPlayer : public Player {
    private:
        static constexpr int N = 5; // Sequence length to track human move patterns
        deque<Choice> history; // Stores last N human choices
        unordered_map<string, int> frequency; // Stores sequence frequencies

        Choice predictNextMove(); // Predicts human's next move
        void validateHistory(); // Ensures history size stays within N
        string historyToString(int length = N); // Converts history to string
        void loadFrequencies(); // Loads move frequency data from file

        char choiceToChar(Choice c); // Convert Choice to character
        Choice charToChoice(char c); // Convert character to Choice
        Choice counterMove(Choice predicted); // Selects best move against predicted choice

    public:
        SmartComputerPlayer();
        Choice choose() override;
        void recordHumanMove(Choice humanChoice); // Store move history
        void saveFrequencies(); // Saves move frequency data to file
};

#endif