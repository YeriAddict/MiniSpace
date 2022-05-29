#include "result.h"
#include "ui_result.h"

Result::Result(QString result, QString time, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Result)
{
    ui->setupUi(this);
    ui->resultLabel->setText(result);
    ui->timeLabel->setText(time);
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(quit()));
    connect(ui->restartButton, SIGNAL(clicked()), this, SLOT(restart()));
}

Result::~Result() {
    delete ui;
}

void Result::restart(){
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

void Result::quit(){
    qApp->quit();
}
