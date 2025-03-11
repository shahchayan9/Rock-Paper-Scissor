#ifndef RANDOMCOMPUTERPLAYER_H
#define RANDOMCOMPUTERPLAYER_H

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

#endif