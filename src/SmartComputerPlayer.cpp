#include "ComputerPlayer.h"

// Constructor initializes seed for randomness
SmartComputerPlayer::SmartComputerPlayer() {
    std::srand(std::time(0));
}

// Function to record human's past moves
void SmartComputerPlayer::recordHumanMove(Choice humanChoice) {
    history.push_back(humanChoice);
}

// Function to predict the next move based on history
Choice SmartComputerPlayer::predictNextMove() {
    if (history.empty()) {
        return static_cast<Choice>(std::rand() % 3); // No history → Pick randomly
    }

    // Count occurrences of each choice
    std::unordered_map<Choice, int> count;
    for (Choice c : history) {
        count[c]++;
    }

    // Determine the most frequently played move
    Choice mostFrequentMove = ROCK; // Default
    int maxCount = 0;

    for (auto it : count) {
        if (it.second > maxCount) {
            mostFrequentMove = it.first;
            maxCount = it.second;
        }
    }

    // Choose the move that beats the most frequent human move
    if (mostFrequentMove == ROCK) return PAPER;       // Counter Rock → Paper
    if (mostFrequentMove == PAPER) return SCISSORS;   // Counter Paper → Scissors
    return ROCK;                                      // Counter Scissors → Rock
}

// Function to choose a move (calls prediction)
Choice SmartComputerPlayer::choose() {
    return predictNextMove();
}
