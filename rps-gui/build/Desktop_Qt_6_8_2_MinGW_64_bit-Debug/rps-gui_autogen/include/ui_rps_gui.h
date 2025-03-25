/********************************************************************************
** Form generated from reading UI file 'rps_gui.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RPS_GUI_H
#define UI_RPS_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rps_gui
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_algo;
    QComboBox *combo_box_algo;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_num_of_rounds;
    QSpinBox *spin_box_num_of_rounds;
    QPushButton *push_button_start;
    QLabel *label_current_round;
    QLabel *label_human;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_human_choose;
    QPushButton *push_button_rock;
    QPushButton *push_button_paper;
    QPushButton *push_button_scissors;
    QLabel *label_human_chooses;
    QLabel *label_computer;
    QLabel *label_pred_human_choice;
    QLabel *label_computer_choice;
    QLabel *label_winner;
    QVBoxLayout *verticalLayout;
    QLabel *label_stats;
    QLabel *label_human_wins;
    QLabel *label_computer_wins;
    QLabel *label_ties;

    void setupUi(QWidget *rps_gui)
    {
        if (rps_gui->objectName().isEmpty())
            rps_gui->setObjectName("rps_gui");
        rps_gui->resize(800, 600);
        rps_gui->setAutoFillBackground(true);
        widget = new QWidget(rps_gui);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(50, 50, 691, 501));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_algo = new QLabel(widget);
        label_algo->setObjectName("label_algo");
        label_algo->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(label_algo);

        combo_box_algo = new QComboBox(widget);
        combo_box_algo->setObjectName("combo_box_algo");

        horizontalLayout->addWidget(combo_box_algo);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_num_of_rounds = new QLabel(widget);
        label_num_of_rounds->setObjectName("label_num_of_rounds");
        label_num_of_rounds->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_2->addWidget(label_num_of_rounds);

        spin_box_num_of_rounds = new QSpinBox(widget);
        spin_box_num_of_rounds->setObjectName("spin_box_num_of_rounds");

        horizontalLayout_2->addWidget(spin_box_num_of_rounds);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        push_button_start = new QPushButton(widget);
        push_button_start->setObjectName("push_button_start");

        horizontalLayout_3->addWidget(push_button_start);


        verticalLayout_2->addLayout(horizontalLayout_3);

        label_current_round = new QLabel(widget);
        label_current_round->setObjectName("label_current_round");
        label_current_round->setTextFormat(Qt::TextFormat::MarkdownText);
        label_current_round->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label_current_round);

        label_human = new QLabel(widget);
        label_human->setObjectName("label_human");
        label_human->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label_human);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_human_choose = new QLabel(widget);
        label_human_choose->setObjectName("label_human_choose");
        label_human_choose->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_4->addWidget(label_human_choose);

        push_button_rock = new QPushButton(widget);
        push_button_rock->setObjectName("push_button_rock");

        horizontalLayout_4->addWidget(push_button_rock);

        push_button_paper = new QPushButton(widget);
        push_button_paper->setObjectName("push_button_paper");

        horizontalLayout_4->addWidget(push_button_paper);

        push_button_scissors = new QPushButton(widget);
        push_button_scissors->setObjectName("push_button_scissors");

        horizontalLayout_4->addWidget(push_button_scissors);


        verticalLayout_2->addLayout(horizontalLayout_4);

        label_human_chooses = new QLabel(widget);
        label_human_chooses->setObjectName("label_human_chooses");
        label_human_chooses->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label_human_chooses);

        label_computer = new QLabel(widget);
        label_computer->setObjectName("label_computer");
        label_computer->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label_computer);

        label_pred_human_choice = new QLabel(widget);
        label_pred_human_choice->setObjectName("label_pred_human_choice");
        label_pred_human_choice->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label_pred_human_choice);

        label_computer_choice = new QLabel(widget);
        label_computer_choice->setObjectName("label_computer_choice");
        label_computer_choice->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label_computer_choice);

        label_winner = new QLabel(widget);
        label_winner->setObjectName("label_winner");

        verticalLayout_2->addWidget(label_winner);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_stats = new QLabel(widget);
        label_stats->setObjectName("label_stats");

        verticalLayout->addWidget(label_stats);

        label_human_wins = new QLabel(widget);
        label_human_wins->setObjectName("label_human_wins");

        verticalLayout->addWidget(label_human_wins);

        label_computer_wins = new QLabel(widget);
        label_computer_wins->setObjectName("label_computer_wins");

        verticalLayout->addWidget(label_computer_wins);

        label_ties = new QLabel(widget);
        label_ties->setObjectName("label_ties");

        verticalLayout->addWidget(label_ties);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(rps_gui);

        QMetaObject::connectSlotsByName(rps_gui);
    } // setupUi

    void retranslateUi(QWidget *rps_gui)
    {
        rps_gui->setWindowTitle(QCoreApplication::translate("rps_gui", "rps_gui", nullptr));
        label_algo->setText(QCoreApplication::translate("rps_gui", "Computer Algorithm:", nullptr));
        label_num_of_rounds->setText(QCoreApplication::translate("rps_gui", "# of Rounds:", nullptr));
        push_button_start->setText(QCoreApplication::translate("rps_gui", "Start New Game", nullptr));
        label_current_round->setText(QCoreApplication::translate("rps_gui", "<html><head/><body><h3 style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:700;\">Round #0</span></h3></body></html>", nullptr));
        label_human->setText(QCoreApplication::translate("rps_gui", "<html><head/><body><h3 align=\"center\" style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:700;\">Human</span></h3></body></html>", nullptr));
        label_human_choose->setText(QCoreApplication::translate("rps_gui", "Choose:", nullptr));
        push_button_rock->setText(QCoreApplication::translate("rps_gui", "ROCK", nullptr));
        push_button_paper->setText(QCoreApplication::translate("rps_gui", "PAPER", nullptr));
        push_button_scissors->setText(QCoreApplication::translate("rps_gui", "SCISSORS", nullptr));
        label_human_chooses->setText(QCoreApplication::translate("rps_gui", "Human Chooses: ", nullptr));
        label_computer->setText(QCoreApplication::translate("rps_gui", "<html><head/><body><h3 align=\"center\" style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:700;\">Computer</span></h3></body></html>", nullptr));
        label_pred_human_choice->setText(QCoreApplication::translate("rps_gui", "Predicted Human Choice: ", nullptr));
        label_computer_choice->setText(QCoreApplication::translate("rps_gui", "Computer Choice: ", nullptr));
        label_winner->setText(QCoreApplication::translate("rps_gui", "<html><head/><body><h3 align=\"center\" style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:700;\">WINNER: </span></h3></body></html>", nullptr));
        label_stats->setText(QCoreApplication::translate("rps_gui", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Statistics</span></p></body></html>", nullptr));
        label_human_wins->setText(QCoreApplication::translate("rps_gui", "Human Wins: 0", nullptr));
        label_computer_wins->setText(QCoreApplication::translate("rps_gui", "Computer Wins: 0", nullptr));
        label_ties->setText(QCoreApplication::translate("rps_gui", "Ties: 0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rps_gui: public Ui_rps_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RPS_GUI_H
