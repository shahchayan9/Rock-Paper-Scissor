#include "rps_gui.h"
#include "./ui_rps_gui.h"

#include "src/ComputerPlayer.h"
#include "src/RandomComputerPlayer.h"
#include "src/SmartComputerPlayer.h"
#include "src/HumanPlayer.h"
#include <vector>

rps_gui::rps_gui(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::rps_gui)
{
    ui->setupUi(this);
    ui->combo_box_algo->addItem("RANDOM");
    ui->combo_box_algo->addItem("SMART");
    game_engine = new GameEngine();
    current_round_num = 0;
    num_of_rounds = 0;

    update_stats();

    ui->push_button_rock->setEnabled(false);
    ui->push_button_paper->setEnabled(false);
    ui->push_button_scissors->setEnabled(false);
}

void rps_gui::on_push_button_start_clicked()
{
    QString algo_type = ui->combo_box_algo->currentText();
    num_of_rounds = ui->spin_box_num_of_rounds->value();
    game_engine->select_computer_player(algo_type.toStdString());
    current_round_num = 1;
    ui->label_current_round->setText("Round #" + QString::number(current_round_num) + " of " + QString::number(num_of_rounds));
    ui->combo_box_algo->setEnabled(false);
    ui->spin_box_num_of_rounds->setEnabled(false);
    ui->push_button_start->setEnabled(false);
    ui->push_button_rock->setEnabled(true);
    ui->push_button_paper->setEnabled(true);
    ui->push_button_scissors->setEnabled(true);
}

void rps_gui::on_push_button_rock_clicked()
{
    string human_choice = "ROCK";
    play_round(human_choice);
}

void rps_gui::on_push_button_paper_clicked()
{
    string human_choice = "PAPER";
    play_round(human_choice);
}

void rps_gui::on_push_button_scissors_clicked()
{
    string human_choice = "SCISSORS";
    play_round(human_choice);
}

void rps_gui::play_round(string human_choice) {
    ui->label_human_choice->setText("Human chose: " + QString::fromStdString(human_choice));
    vector<string> result = game_engine->play_round(human_choice);
    ui->label_computer_choice->setText("Computer chose: " + QString::fromStdString(result[1]));
    ui->label_winner->setText("WINNER: " + QString::fromStdString(result[0]));

    if (current_round_num < num_of_rounds) {
        current_round_num = current_round_num + 1;
        ui->label_current_round->setText("Round #" + QString::number(current_round_num) + " of " + QString::number(num_of_rounds));
    } else {
        ui->push_button_rock->setEnabled(false);
        ui->push_button_paper->setEnabled(false);
        ui->push_button_scissors->setEnabled(false);
        ui->combo_box_algo->setEnabled(true);
        ui->spin_box_num_of_rounds->setEnabled(true);
        ui->push_button_start->setEnabled(true);
        ui->label_current_round->setText("");
        game_engine->save_frequencies();
    }

    update_stats();
}

void rps_gui::update_stats() {
    vector<int> stats = game_engine->get_stats();
    ui->label_human_wins->setText("Human Wins: " + QString::number(stats[0]));
    ui->label_computer_wins->setText("Computer Wins: " + QString::number(stats[1]));
    ui->label_ties->setText("Ties: " + QString::number(stats[2]));
}

rps_gui::~rps_gui()
{
    delete ui;
}
