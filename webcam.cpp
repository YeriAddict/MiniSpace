#include "webcam.h"
#include "ui_webcam.h"

Webcam::Webcam(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Webcam)
{
    ui->setupUi(this);
}

Webcam::~Webcam()
{
    delete ui;
}

