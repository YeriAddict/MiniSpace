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
}

Game::~Game() {
    delete ui;
}
