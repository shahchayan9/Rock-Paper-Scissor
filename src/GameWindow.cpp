#include "GameWindow.h"

GameWindow::GameWindow(GameController *ctrl, QWidget *parent) : QWidget(parent) {
    controller = ctrl;

    rockBtn = new QPushButton("Rock");
    paperBtn = new QPushButton("Paper");
    scissorsBtn = new QPushButton("Scissors");
    resultLabel = new QLabel("Choose an option!");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(rockBtn);
    layout->addWidget(paperBtn);
    layout->addWidget(scissorsBtn);
    layout->addWidget(resultLabel);
    setLayout(layout);

    connect(rockBtn, SIGNAL(clicked()), this, SLOT(onRockClicked()));
    connect(paperBtn, SIGNAL(clicked()), this, SLOT(onPaperClicked()));
    connect(scissorsBtn, SIGNAL(clicked()), this, SLOT(onScissorsClicked()));
}

void GameWindow::onRockClicked() { controller->playRound(ROCK); }
void GameWindow::onPaperClicked() { controller->playRound(PAPER); }
void GameWindow::onScissorsClicked() { controller->playRound(SCISSORS); }