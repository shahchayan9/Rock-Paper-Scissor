#include "GameEngine.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

int main() {
    HumanPlayer human;
    RandomComputerPlayer computer;
    GameEngine engine(&human, &computer);

    int rounds = 20; // Change this to 20 for full gameplay
    for (int i = 0; i < rounds; i++) {
        std::cout << "Round " << (i + 1) << ":\n";
        engine.playRound();
    }

    engine.displayResults();
    return 0;
}
