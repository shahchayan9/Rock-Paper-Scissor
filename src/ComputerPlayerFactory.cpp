#include "ComputerPlayerFactory.h"
#include <iostream>

using namespace std;

Player* ComputerPlayerFactory::select_computer_player(char choice) {
    if (choice == 's') {
        cout << "Smart strategy selected!\n";
        return new SmartComputerPlayer();
    } else {
        cout << "Random strategy selected!\n";
        return new RandomComputerPlayer();
    }
}