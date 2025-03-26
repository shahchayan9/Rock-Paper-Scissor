#ifndef COMPUTERPLAYERFACTORY_H
#define COMPUTERPLAYERFACTORY_H

#include "ComputerPlayer.h"
#include <string>

using namespace std;

class ComputerPlayerFactory {
public:
    static ComputerPlayer* select_computer_player(string choice);
};

#endif
