#include "game.h"
#include "ui_game.h"

Game::Game(int asteroidNumber, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
    space = new SpaceWidget(asteroidNumber);
    ui->horizontalLayout->addWidget(space);
    space->setFocus();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateChronometer()));
    ui->timeLabel->setText(QTime(0, 0).toString());
    startTime.restart();
    timer->start(1000);
}

Game::~Game() {
    delete ui;
}

void Game::updateChronometer(){
    ui->timeLabel->setText(QTime(0, 0).addMSecs(startTime.elapsed()).toString());
}
