#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "ComputerPlayerFactory.h"
#include "GameEngine.h"
#include <iostream>

using namespace std;

int main() {
    HumanPlayer human;
    ComputerPlayer* computer;

    char strategyChoice;
    cout << "Choose computer strategy: (r = Random, s = Smart): ";
    cin >> strategyChoice;

    computer = ComputerPlayerFactory::select_computer_player(strategyChoice);

    GameEngine engine(&human, computer);

    int rounds = 20;
    for (int i = 0; i < rounds; i++) {
        cout << "Round " << (i + 1) << "\n";
        engine.play_round();
    }

    engine.display_results();

    return 0;
}