#include "SmartComputerPlayer.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

// ----------------------------
// SmartComputerPlayer Implementation
// ----------------------------

// Constructor: Load past frequency data from file
SmartComputerPlayer::SmartComputerPlayer() {
    srand(time(0)); // Initialize random seed
    loadFrequencies();
}

// Function to record human's past moves (maintaining sequence history)
void SmartComputerPlayer::recordHumanMove(Choice humanChoice) {
    if (history.size() >= N) {
        history.pop_front(); // Remove oldest move to maintain N-length
    }
    history.push_back(humanChoice);

    // Update sequence frequency
    if (history.size() == N) {
        string sequence = historyToString();
        frequency[sequence]++;
    }
}

// Predict the next move using stored frequencies
Choice SmartComputerPlayer::predictNextMove() {
    if (history.size() < N - 1) {
        return static_cast<Choice>(rand() % 3); // Not enough history → Pick randomly
    }

    // Get current sequence without the last move
    string partialSeq = historyToString(N - 1);

    // Check which next move has the highest occurrence
    unordered_map<Choice, int> moveCount;
    for (auto& pair : frequency) {
        if (pair.first.substr(0, N - 1) == partialSeq) {
            Choice predicted = charToChoice(pair.first[N - 1]);
            moveCount[predicted] += pair.second;
        }
    }

    // Find most frequent move after this sequence
    Choice bestGuess = static_cast<Choice>(rand() % 3);
    int maxFreq = 0;

    for (auto& pair : moveCount) {
        if (pair.second > maxFreq) {
            bestGuess = pair.first;
            maxFreq = pair.second;
        }
    }

    // Choose move that beats predicted move
    return counterMove(bestGuess);
}

// Choose a move (calls prediction)
Choice SmartComputerPlayer::choose() {
    return predictNextMove();
}

// Convert move history to string
string SmartComputerPlayer::historyToString(int length) {
    stringstream ss;
    int count = 0;
    for (Choice c : history) {
        if (count++ == length) break;
        ss << choiceToChar(c);
    }
    return ss.str();
}

// Save frequency data to file
void SmartComputerPlayer::saveFrequencies() {
    ofstream file("history.txt");
    if (!file) return;

    for (auto& pair : frequency) {
        file << pair.first << " " << pair.second << "\n";
    }
}

// Load frequency data from file
void SmartComputerPlayer::loadFrequencies() {
    ifstream file("history.txt");
    if (!file) return;

    string seq;
    int freq;
    while (file >> seq >> freq) {
        frequency[seq] = freq;
    }
}

// Convert Choice to character
char SmartComputerPlayer::choiceToChar(Choice c) {
    if (c == ROCK) return 'R';
    if (c == PAPER) return 'P';
    return 'S';
}

// Convert character to Choice
Choice SmartComputerPlayer::charToChoice(char c) {
    if (c == 'R') return ROCK;
    if (c == 'P') return PAPER;
    return SCISSORS;
}

// Counter the predicted move
Choice SmartComputerPlayer::counterMove(Choice predicted) {
    if (predicted == ROCK) return PAPER;
    if (predicted == PAPER) return SCISSORS;
    return ROCK;
}