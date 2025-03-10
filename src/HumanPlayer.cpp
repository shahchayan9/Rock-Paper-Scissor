#include "HumanPlayer.h"

Choice HumanPlayer::choose() {
    char choice;
    std::cout << "Enter your choice (r = Rock, p = Paper, s = Scissors): ";
    std::cin >> choice;

    switch (choice) {
        case 'r': return ROCK;
        case 'p': return PAPER;
        case 's': return SCISSORS;
        default:
            std::cout << "Invalid input! Choosing Rock by default.\n";
            return ROCK;
    }
}
