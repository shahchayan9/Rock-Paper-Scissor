#include "GameEngine.h"
#include "ComputerPlayer.h"
#include "SmartComputerPlayer.h"
#include <iostream>
#include <map>

GameEngine::GameEngine(Player *humanPlayer, Player *computerPlayer) {
    human = humanPlayer;
    computer = computerPlayer;
    humanWins = computerWins = ties = 0;
}

// Function to convert Choice enum to a readable string
std::string choiceToString(Choice choice) {
    std::map<Choice, std::string> choiceMap = {
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

    std::cout << "Human chose: " << choiceToString(humanChoice)
              << " | Computer chose: " << choiceToString(computerChoice) << std::endl;

    // Determine round winner
    if (humanChoice == computerChoice) {
        std::cout << "It's a tie!\n";
        ties++;
    }
    else if ((humanChoice == ROCK && computerChoice == SCISSORS) ||
             (humanChoice == PAPER && computerChoice == ROCK) ||
             (humanChoice == SCISSORS && computerChoice == PAPER)) {
        std::cout << "Human wins this round!\n";
        humanWins++;
    } else {
        std::cout << "Computer wins this round!\n";
        computerWins++;
    }

    // If the computer is using Smart Strategy, update its history
    SmartComputerPlayer* smartComp = dynamic_cast<SmartComputerPlayer*>(computer);
    if (smartComp) {
        smartComp->recordHumanMove(humanChoice);
    }
}

// Function to display final match results
void GameEngine::displayResults() {
    std::cout << "\n====================\n";
    std::cout << "     Match Stats     \n";
    std::cout << "====================\n";
    std::cout << "Human Wins   : " << humanWins << " (" << (humanWins * 100) / (humanWins + computerWins + ties) << "%)\n";
    std::cout << "Computer Wins: " << computerWins << " (" << (computerWins * 100) / (humanWins + computerWins + ties) << "%)\n";
    std::cout << "Ties         : " << ties << " (" << (ties * 100) / (humanWins + computerWins + ties) << "%)\n";
    std::cout << "====================\n";
}
