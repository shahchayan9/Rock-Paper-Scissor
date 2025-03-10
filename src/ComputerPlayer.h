#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Player.h"
#include <cstdlib>
#include <ctime>

class RandomComputerPlayer : public Player {
public:
    RandomComputerPlayer();
    Choice choose() override;
};

#endif
