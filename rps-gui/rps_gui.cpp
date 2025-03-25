#include "rps_gui.h"
#include "./ui_rps_gui.h"
#include "ComputerPlayerFactory.h"

rps_gui::rps_gui(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::rps_gui)
{
    ui->setupUi(this);
    connect(ui->push_button_rock, &QPushButton::clicked, this, &MainWindow::onRockClicked);
    connect(ui->push_button_paper, &QPushButton::clicked, this, &MainWindow::onPaperClicked);
    connect(ui->push_button_scissors, &QPushButton::clicked, this, &MainWindow::onScissorsClicked);
    connect(ui->push_button_start, &QPushButton::clicked, this, &MainWindow::onStartGameClicked);
}

rps_gui::~rps_gui()
{
    delete ui;
}
