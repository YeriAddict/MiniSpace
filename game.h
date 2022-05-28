#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QElapsedTimer>
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
    QTimer* timer;
    QTimer* webcamTimer;
    QElapsedTimer startTime;

private slots:
    void updateChronometer();
    int updateWebcam();
};
#endif // GAME_H
