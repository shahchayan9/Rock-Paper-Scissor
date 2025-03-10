#include "GameEngine.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include <iostream>

int main() {
    HumanPlayer human;
    Player* computer; // Pointer to use either strategy

    char strategyChoice;
    std::cout << "Choose computer strategy: (r = Random, s = Smart): ";
    std::cin >> strategyChoice;

    if (strategyChoice == 's') {
        computer = new SmartComputerPlayer();
        std::cout << "Smart strategy selected!\n";
    } else {
        computer = new RandomComputerPlayer();
        std::cout << "Random strategy selected!\n";
    }

    GameEngine engine(&human, computer);

    int rounds = 20; // Play 20 rounds
    for (int i = 0; i < rounds; i++) {
        std::cout << "Round " << (i + 1) << ":\n";
        engine.playRound();
    }

    engine.displayResults();
    delete computer; // Free memory
    return 0;
}
