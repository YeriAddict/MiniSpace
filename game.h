#ifndef GAME_H
#define GAME_H

#include "spacewidget.h"
#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QElapsedTimer>

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
    QTimer* timer;
    QElapsedTimer startTime;

private slots:
    void updateChronometer();
};
#endif // GAME_H
