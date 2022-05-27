#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include "spacewidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Menu; }
QT_END_NAMESPACE

#pragma once
class Menu : public QWidget {
    Q_OBJECT

public:
    Menu(QWidget *parent = nullptr);
    ~Menu();

private:
    Ui::Menu *ui;
    SpaceWidget* game;

private slots:
    void startGameOne();
    void startGameTwo();
    void startGameThree();
    void startGameFour();
    void startGameFive();
    void startGameSix();
    void startGameSeven();
    void startGameEight();
    void startGameNine();
    void startGameTen();
    void startGameEleven();
    void startGameTwelve();
    void startGameThirteen();
    void startGameFourteen();
    void startGameFifteen();
    void startGameSixteen();
};
#endif // MENU_H
