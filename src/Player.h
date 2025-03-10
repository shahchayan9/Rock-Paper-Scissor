#ifndef PLAYER_H
#define PLAYER_H

enum Choice { ROCK, PAPER, SCISSORS };

class Player {
public:
    virtual Choice choose() = 0; // Pure virtual function
    virtual ~Player() {} // Virtual destructor
};

#endif
