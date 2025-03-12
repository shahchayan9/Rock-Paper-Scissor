#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Player.h"

class ComputerPlayer : public Player {
public:
    virtual void save_frequencies() {}
    virtual void load_frequencies() {}
    virtual void record_move(Choice) {}
};

#endif