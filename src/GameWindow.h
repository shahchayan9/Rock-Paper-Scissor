#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "GameController.h"

class GameWindow : public QWidget {
    Q_OBJECT
    
private:
    QPushButton *rockBtn, *paperBtn, *scissorsBtn;
    QLabel *resultLabel;
    GameController *controller;
    
public:
    GameWindow(GameController *ctrl, QWidget *parent = nullptr);
    
private slots:
    void onRockClicked();
    void onPaperClicked();
    void onScissorsClicked();
};

#endif