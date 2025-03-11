#include "HumanPlayer.h"

using namespace std;

Choice HumanPlayer::choose() {
    char choice;
    cout << "Enter your choice (r = Rock, p = Paper, s = Scissors): ";
    cin >> choice;

    switch (choice) {
        case 'r': return ROCK;
        case 'p': return PAPER;
        case 's': return SCISSORS;
        default:
            cout << "Invalid input! Choosing Rock by default.\n";
            return ROCK;
    }
}