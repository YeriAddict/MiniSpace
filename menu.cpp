#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->buttonOne, SIGNAL(clicked()), this, SLOT(startGameOne()));
    connect(ui->buttonTwo, SIGNAL(clicked()), this, SLOT(startGameTwo()));
    connect(ui->buttonThree, SIGNAL(clicked()), this, SLOT(startGameThree()));
    connect(ui->buttonFour, SIGNAL(clicked()), this, SLOT(startGameFour()));
    connect(ui->buttonFive, SIGNAL(clicked()), this, SLOT(startGameFive()));
    connect(ui->buttonSix, SIGNAL(clicked()), this, SLOT(startGameSix()));
    connect(ui->buttonSeven, SIGNAL(clicked()), this, SLOT(startGameSeven()));
    connect(ui->buttonEight, SIGNAL(clicked()), this, SLOT(startGameEight()));
    connect(ui->buttonNine, SIGNAL(clicked()), this, SLOT(startGameNine()));
    connect(ui->buttonTen, SIGNAL(clicked()), this, SLOT(startGameTen()));
    connect(ui->buttonEleven, SIGNAL(clicked()), this, SLOT(startGameEleven()));
    connect(ui->buttonTwelve, SIGNAL(clicked()), this, SLOT(startGameTwelve()));
    connect(ui->buttonThirteen, SIGNAL(clicked()), this, SLOT(startGameThirteen()));
    connect(ui->buttonFourteen, SIGNAL(clicked()), this, SLOT(startGameFourteen()));
    connect(ui->buttonFifteen, SIGNAL(clicked()), this, SLOT(startGameFifteen()));
    connect(ui->buttonSixteen, SIGNAL(clicked()), this, SLOT(startGameSixteen()));
}

Menu::~Menu() {
    delete ui;
}

void Menu::startGameOne(){
    game = new SpaceWidget(1);
    game->show();
    this->close();
}

void Menu::startGameTwo(){
    game = new SpaceWidget(2);
    game->show();
    this->close();
}

void Menu::startGameThree(){
    game = new SpaceWidget(3);
    game->show();
    this->close();
}

void Menu::startGameFour(){
    game = new SpaceWidget(4);
    game->show();
    this->close();
}

void Menu::startGameFive(){
    game = new SpaceWidget(5);
    game->show();
    this->close();
}

void Menu::startGameSix(){
    game = new SpaceWidget(6);
    game->show();
    this->close();
}

void Menu::startGameSeven(){
    game = new SpaceWidget(7);
    game->show();
    this->close();
}

void Menu::startGameEight(){
    game = new SpaceWidget(8);
    game->show();
    this->close();
}

void Menu::startGameNine(){
    game = new SpaceWidget(9);
    game->show();
    this->close();
}

void Menu::startGameTen(){
    game = new SpaceWidget(10);
    game->show();
    this->close();
}

void Menu::startGameEleven(){
    game = new SpaceWidget(11);
    game->show();
    this->close();
}

void Menu::startGameTwelve(){
    game = new SpaceWidget(12);
    game->show();
    this->close();
}

void Menu::startGameThirteen(){
    game = new SpaceWidget(13);
    game->show();
    this->close();
}

void Menu::startGameFourteen(){
    game = new SpaceWidget(14);
    game->show();
    this->close();
}

void Menu::startGameFifteen(){
    game = new SpaceWidget(15);
    game->show();
    this->close();
}

void Menu::startGameSixteen(){
    game = new SpaceWidget(16);
    game->show();
    this->close();
}
