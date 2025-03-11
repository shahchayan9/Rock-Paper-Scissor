#include "ComputerPlayer.h"

// ----------------------------
// RandomComputerPlayer Implementation
// ----------------------------
RandomComputerPlayer::RandomComputerPlayer() {
    std::srand(std::time(0)); // Initialize random seed
}

Choice RandomComputerPlayer::choose() {
    return static_cast<Choice>(std::rand() % 3); // Random number between 0 and 2
}