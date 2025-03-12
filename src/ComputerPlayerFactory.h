#ifndef COMPUTERPLAYERFACTORY_H
#define COMPUTERPLAYERFACTORY_H

#include "RandomComputerPlayer.h"
#include "SmartComputerPlayer.h"

class ComputerPlayerFactory {
public:
    static ComputerPlayer* select_computer_player(char choice);
};

#endif