#include "GameEngine.h"
#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

GameEngine::GameEngine(Player *human, Player *computer) {
    this->human = human;
    this->computer = computer;
    humanWins = computerWins = ties = 0;
    
    SmartComputerPlayer* smartAI = dynamic_cast<SmartComputerPlayer*>(computer);
    if (smartAI) {
        smartAI->load_frequencies();
    }
}

string GameEngine::choice_to_string(Choice choice) {
    map<Choice, string> choiceMap = {
        {ROCK, "ROCK"},
        {PAPER, "PAPER"},
        {SCISSORS, "SCISSORS"}
    };

    return choiceMap.at(choice);
}

void GameEngine::play_round() {
    Choice humanChoice = human->choose();
    Choice computerChoice = computer->choose();

    cout << "  Human chose " << choice_to_string(humanChoice) << endl;
    cout << "  Computer chose " << choice_to_string(computerChoice) << endl;

    string winner;

    if (humanChoice == computerChoice) {
        winner = "TIE";
        ties++;
    } else if ((humanChoice == ROCK && computerChoice == SCISSORS) ||
             (humanChoice == PAPER && computerChoice == ROCK) ||
             (humanChoice == SCISSORS && computerChoice == PAPER)) {
        winner = "HUMAN";
        humanWins++;
    } else {
        winner = "COMPUTER";
        computerWins++;
    }

    cout << "  The winner is: " << winner << endl << endl;

    SmartComputerPlayer* smartAI = dynamic_cast<SmartComputerPlayer*>(computer);
    if (smartAI) {
        smartAI->record_move(humanChoice);
    }
}

void GameEngine::display_results() {
    int totalGames = humanWins + computerWins + ties;

    std::cout << "\nMatch stats\n";
    std::cout << "-----------\n";

    std::cout << "   Human wins: " << std::setw(4) << humanWins 
              << "   " << std::setw(3) << (humanWins * 100) / totalGames << "%\n";
    
    std::cout << "Computer wins: " << std::setw(4) << computerWins 
              << "   " << std::setw(3) << (computerWins * 100) / totalGames << "%\n";

    std::cout << "         Ties: " << std::setw(4) << ties 
              << "   " << std::setw(3) << (ties * 100) / totalGames << "%\n";
}

GameEngine::~GameEngine() {
    SmartComputerPlayer* smartAI = dynamic_cast<SmartComputerPlayer*>(computer);
    if (smartAI) {
        smartAI->save_frequencies();
    }

    delete computer;
}