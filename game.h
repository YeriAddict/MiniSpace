#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include "spacewidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Game; }
QT_END_NAMESPACE

#pragma once
class Game : public QWidget {
    Q_OBJECT

public:
    Game(int asteroidNumber, QWidget *parent = nullptr);
    ~Game();

private:
    Ui::Game *ui;
    SpaceWidget* space;

};
#endif // GAME_H
