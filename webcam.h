#ifndef WEBCAM_H
#define WEBCAM_H

#include "opencv2/opencv.hpp"
#include <QWidget>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Webcam; }
QT_END_NAMESPACE

struct Coordinates {
  int x;
  int y;
};

#pragma once
class Webcam : public QWidget {
    Q_OBJECT

public:
    explicit Webcam(QWidget *parent = nullptr);
    ~Webcam();

    static int webcamDetector_;

private:
    Ui::Webcam *ui;
    QTimer* webcamTimer;
    std::vector<Coordinates> palmPositions;
    std::vector<Coordinates> fistPositions;

private slots:
    int updateWebcam();
};

#endif // WEBCAM_H
