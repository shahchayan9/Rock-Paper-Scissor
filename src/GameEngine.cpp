#include "GameEngine.h"
#include "ComputerPlayer.h"
#include "SmartComputerPlayer.h"
#include <iostream>
#include <map>

using namespace std;

GameEngine::GameEngine(Player *humanPlayer, Player *computerPlayer) {
    human = humanPlayer;
    computer = computerPlayer;
    humanWins = computerWins = ties = 0;
}

// Function to convert Choice enum to a readable string
string choiceToString(Choice choice) {
    map<Choice, string> choiceMap = {
        {ROCK, "ROCK"},
        {PAPER, "PAPER"},
        {SCISSORS, "SCISSORS"}
    };
    return choiceMap[choice];
}

// Function to play a single round
void GameEngine::playRound() {
    Choice humanChoice = human->choose();
    Choice computerChoice = computer->choose();

    cout << "Human chose: " << choiceToString(humanChoice)
              << " | Computer chose: " << choiceToString(computerChoice) << endl;

    // Determine round winner
    if (humanChoice == computerChoice) {
        cout << "It's a tie!\n";
        ties++;
    }
    else if ((humanChoice == ROCK && computerChoice == SCISSORS) ||
             (humanChoice == PAPER && computerChoice == ROCK) ||
             (humanChoice == SCISSORS && computerChoice == PAPER)) {
        cout << "Human wins this round!\n";
        humanWins++;
    } else {
        cout << "Computer wins this round!\n";
        computerWins++;
    }

    // If the computer is using Smart Strategy, update its history
    computer -> recordHumanMove(humanChoice);
}

// Function to display final match results
void GameEngine::displayResults() {
    cout << "\n====================\n";
    cout << "     Match Stats     \n";
    cout << "====================\n";
    cout << "Human Wins   : " << humanWins << " (" << (humanWins * 100) / (humanWins + computerWins + ties) << "%)\n";
    cout << "Computer Wins: " << computerWins << " (" << (computerWins * 100) / (humanWins + computerWins + ties) << "%)\n";
    cout << "Ties         : " << ties << " (" << (ties * 100) / (humanWins + computerWins + ties) << "%)\n";
    cout << "====================\n";
}