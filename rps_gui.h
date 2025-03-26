#ifndef RPS_GUI_H
#define RPS_GUI_H

#include <QWidget>
#include "src/GameEngine.h"
#include <string>

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
    GameEngine* game_engine;
    int current_round_num;
    int num_of_rounds;
    void play_round(string human_choice);
    void update_stats();

private slots:
    void on_push_button_start_clicked();
    void on_push_button_rock_clicked();
    void on_push_button_paper_clicked();
    void on_push_button_scissors_clicked();
};
#endif // RPS_GUI_H
