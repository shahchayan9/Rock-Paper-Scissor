#include <iostream>
#include "ComputerPlayerFactory.h"
#include "RandomComputerPlayer.h"
#include "SmartComputerPlayer.h"

using namespace std;

ComputerPlayer* ComputerPlayerFactory::select_computer_player(string choice) {
    if (choice == "SMART") {
        return new SmartComputerPlayer();
    } else {
        return new RandomComputerPlayer();
    }
}
