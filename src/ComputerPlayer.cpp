#include "ComputerPlayer.h"

using namespace std;

// ----------------------------
// RandomComputerPlayer Implementation
// ----------------------------
RandomComputerPlayer::RandomComputerPlayer() {
    srand(time(0)); // Initialize random seed
}

Choice RandomComputerPlayer::choose() {
    return static_cast<Choice>(rand() % 3); // Random number between 0 and 2
}