#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

enum Choice { ROCK, PAPER, SCISSORS };

class ComputerPlayer {
public:
    virtual Choice choose() {}
    virtual void save_frequencies() {}
    virtual void load_frequencies() {}
    virtual void record_move(Choice) {}
};

#endif
