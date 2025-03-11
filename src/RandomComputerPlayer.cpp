#include "RandomComputerPlayer.h"

using namespace std;

RandomComputerPlayer::RandomComputerPlayer() {
    srand(time(0));
}

Choice RandomComputerPlayer::choose() {
    return static_cast<Choice>(rand() % 3);
}