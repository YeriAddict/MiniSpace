#include "menu.h"
#include "ui_menu.h"
#include "webcam.h"
Menu::Menu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->buttonOne, SIGNAL(clicked()), this, SLOT(startGame()));
}

Menu::~Menu() {
    delete ui;
}

void Menu::startGame(){
    game = new SpaceWidget();
    game->show();
    this->close();
}
