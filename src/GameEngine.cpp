#include "GameEngine.h"
#include <iostream>
#include <map>

GameEngine::GameEngine(Player *humanPlayer, Player *computerPlayer) {
    human = humanPlayer;
    computer = computerPlayer;
    humanWins = computerWins = ties = 0;
}

std::string choiceToString(Choice choice) {
    std::map<Choice, std::string> choiceMap = {
        {ROCK, "ROCK"},
        {PAPER, "PAPER"},
        {SCISSORS, "SCISSORS"}
    };
    return choiceMap[choice];
}

void GameEngine::playRound() {
    Choice humanChoice = human->choose();
    Choice computerChoice = computer->choose();

    std::cout << "Human chose: " << choiceToString(humanChoice)
          << " | Computer chose: " << choiceToString(computerChoice) << std::endl;


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
}

void GameEngine::displayResults() {
    std::cout << "Final Score:\n";
    std::cout << "Human Wins: " << humanWins << " | Computer Wins: " << computerWins << " | Ties: " << ties << std::endl;
}
