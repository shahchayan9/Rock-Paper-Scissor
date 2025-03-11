#include "SmartComputerPlayer.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

SmartComputerPlayer::SmartComputerPlayer() {
    srand(time(0));
}

Choice SmartComputerPlayer::predict_next_move() {
    if (last_n_choices.size() < N - 1) {
        cout << "    Insufficient history to predict." << endl;
        cout << "    Computer will choose randomly." << endl;
        return static_cast<Choice>(rand() % 3);
    }

    string partialSeq = history_to_string(N - 1);

    unordered_map<Choice, int> move_count;
    for (auto& pair : sequence_frequencies) {
        if (pair.first.substr(0, N - 1) == partialSeq) {
            Choice predicted = char_to_choice(pair.first[N - 1]);
            move_count[predicted] += pair.second;
        }
    }

    Choice most_likely_move = ROCK;
    int max_freq = 0;

    if (move_count.empty()) {
        most_likely_move = static_cast<Choice>(rand() % 3);
    } else {
        for (auto& pair : move_count) {
            if (pair.second > max_freq) {
                most_likely_move = pair.first;
                max_freq = pair.second;
            }
        }
    }

    return most_likely_move;
}

string SmartComputerPlayer::history_to_string(int length) {
    stringstream ss;
    int count = 0;
    for (Choice c: last_n_choices) {
        if (count++ == length) 
            break;
        ss << choice_to_char(c);
    }
    return ss.str();
}

char SmartComputerPlayer::choice_to_char(Choice c) {
    if (c == ROCK)
        return 'R';
    if (c == PAPER)
        return 'P';
    return 'S';
}

Choice SmartComputerPlayer::char_to_choice(char c) {
    if (c == 'R')
        return ROCK;
    if (c == 'P')
        return PAPER;
    return SCISSORS;
}

Choice SmartComputerPlayer::select_counter_move(Choice predicted_move) {
    if (predicted_move == ROCK)
        return PAPER;
    if (predicted_move == PAPER)
        return SCISSORS;
    return ROCK;
}

Choice SmartComputerPlayer::choose() {
    Choice predicted_move = predict_next_move();
    return select_counter_move(predicted_move);
}

void SmartComputerPlayer::load_frequencies() {
    ifstream file("user_choice_history.txt");
    if (!file)
        return;

    string seq;
    int freq;
    while (file >> seq >> freq) {
        sequence_frequencies[seq] = freq;
    }
}

void SmartComputerPlayer::save_frequencies() {
    ofstream file("user_choice_history.txt");
    if (!file)
        return;

    for (auto& pair : sequence_frequencies) {
        file << pair.first << " " << pair.second << "\n";
    }
}

void SmartComputerPlayer::record_move(Choice choice) {
    if (last_n_choices.size() >= N) {
        last_n_choices.pop_front();
    }
    last_n_choices.push_back(choice);

    if (last_n_choices.size() == N) {
        string sequence = history_to_string();
        sequence_frequencies[sequence]++;
    }
}