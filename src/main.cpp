#include "GameEngine.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "SmartComputerPlayer.h"
#include <iostream>

using namespace std;

int main() {
    HumanPlayer human;
    SmartComputerPlayer* smartAI = nullptr; // Pointer for Smart AI
    Player* computer; // Pointer for computer strategy

    char strategyChoice;
    cout << "Choose computer strategy: (r = Random, s = Smart): ";
    cin >> strategyChoice;

    if (strategyChoice == 's') {
        smartAI = new SmartComputerPlayer();
        computer = smartAI; // Assign Smart AI to the Player pointer
        cout << "Smart strategy selected!\n";
    } else {
        computer = new RandomComputerPlayer();
        cout << "Random strategy selected!\n";
    }

    GameEngine engine(&human, computer);

    int rounds = 20; // Play 20 rounds
    for (int i = 0; i < rounds; i++) {
        cout << "Round " << (i + 1) << ":\n";
        engine.playRound();
    }

    engine.displayResults();

    // Save frequencies if Smart AI was used
    if (smartAI) {
        smartAI->saveFrequencies();
        cout << "Smart AI learning saved to history.txt!\n";
    }

    delete computer; // Free memory
    return 0;
}