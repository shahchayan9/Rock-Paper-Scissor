#ifndef RANDOMCOMPUTERPLAYER_H
#define RANDOMCOMPUTERPLAYER_H

#include "ComputerPlayer.h"
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <ctime>

class RandomComputerPlayer : public ComputerPlayer {
public:
    RandomComputerPlayer();
    Choice choose() override;
};

#endif