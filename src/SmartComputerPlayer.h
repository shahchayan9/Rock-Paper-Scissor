#ifndef SMARTCOMPUTERPLAYER_H
#define SMARTCOMPUTERPLAYER_H

#include "ComputerPlayer.h"
#include <deque>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class SmartComputerPlayer : public ComputerPlayer {
    private:
        static const int N = 5;
        deque<Choice> last_n_choices;
        unordered_map<string, int> sequence_frequencies;
        
        Choice predict_next_move();
        Choice select_counter_move(Choice predicted);
        string history_to_string(int length = N);
        char choice_to_char(Choice choice);
        Choice char_to_choice(char c);

    public:
        SmartComputerPlayer();
        Choice choose() override;
        void save_frequencies() override;
        void load_frequencies() override;
        void record_move(Choice choice) override;
};

#endif