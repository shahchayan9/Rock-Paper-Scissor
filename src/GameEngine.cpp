#include "GameEngine.h"
#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

GameEngine::GameEngine() {
    this->computer = factory.select_computer_player("RANDOM");
    human_wins = computer_wins = ties = 0;
    computer->load_frequencies();
}

Choice GameEngine::string_to_choice(string choice) {
    map<string, Choice> choiceMap = {
        {"ROCK", ROCK},
        {"PAPER", PAPER},
        {"SCISSORS", SCISSORS}
    };

    return choiceMap.at(choice);
}

string GameEngine::choice_to_string(Choice choice) {
    map<Choice, string> choiceMap = {
        {ROCK, "ROCK"},
        {PAPER, "PAPER"},
        {SCISSORS, "SCISSORS"}
    };

    return choiceMap.at(choice);
}

void GameEngine::select_computer_player(string algo_type) {
    this->computer = factory.select_computer_player(algo_type);
    computer->load_frequencies();
}

vector<string> GameEngine::play_round(string human_choice_string) {
    Choice human_choice = string_to_choice(human_choice_string);
    Choice computer_choice = computer->choose();
    Choice predicted_choice = get_prediction(computer_choice);
    string winner;

    if (human_choice == computer_choice) {
        winner = "TIE";
        ties++;
    } else if ((human_choice == ROCK && computer_choice == SCISSORS) ||
             (human_choice == PAPER && computer_choice == ROCK) ||
             (human_choice == SCISSORS && computer_choice == PAPER)) {
        winner = "HUMAN";
        human_wins++;
    } else {
        winner = "COMPUTER";
        computer_wins++;
    }

    computer->record_move(human_choice);

    vector<string> result;
    result.push_back(winner);
    result.push_back(choice_to_string(computer_choice));
    result.push_back(choice_to_string(predicted_choice));
    return result;
}

Choice GameEngine::get_prediction(Choice computer_choice) {
    if (computer_choice == ROCK)
        return SCISSORS;
    else if (computer_choice == PAPER)
        return ROCK;
    return PAPER;
}

vector<int> GameEngine::get_stats() {
    vector<int> stats;
    stats.push_back(human_wins);
    stats.push_back(computer_wins);
    stats.push_back(ties);
    return stats;
}

void GameEngine::save_frequencies() {
    computer->save_frequencies();
}
