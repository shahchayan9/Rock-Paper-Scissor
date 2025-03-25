#ifndef RPS_GUI_H
#define RPS_GUI_H

#include <QWidget>
#include "GameEngine.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class rps_gui;
}
QT_END_NAMESPACE

class rps_gui : public QWidget
{
    Q_OBJECT

public:
    rps_gui(QWidget *parent = nullptr);
    ~rps_gui();

private:
    Ui::rps_gui *ui;
    GameEngine* gameEngine;

private slots:
    void onRockClicked();
    void onPaperClicked();
    void onScissorsClicked();
    void onStartGameClicked();
};
#endif // RPS_GUI_H
