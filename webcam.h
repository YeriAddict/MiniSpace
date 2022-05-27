#ifndef WEBCAM_H
#define WEBCAM_H

#include "opencv2/opencv.hpp"
#include <QWidget>
#include <QString>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Webcam; }
QT_END_NAMESPACE

#pragma once
class Webcam : public QWidget
{
    Q_OBJECT

public:
    explicit Webcam(QWidget *parent = nullptr);
    ~Webcam();

private:
    Ui::Webcam *ui;
    cv::VideoCapture * webCam_;

private slots:
    void updateFrame();
    void on_captureButton_clicked();
};

#endif // WEBCAM_H
