#include "asteroid.h"
#include "starship.h"
#include "station.h"
#include "result.h"
#include "webcam.h"
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QTime>
#include <QApplication>
#include <QRandomGenerator>
#include <QMessageBox>
#include <cmath>
#include <algorithm>

#pragma once
class SpaceWidget : public QOpenGLWidget {

public:
    SpaceWidget(int asteroidNumber, QWidget * parent = nullptr);
    ~SpaceWidget();

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void keyPressEvent(QKeyEvent * keyEvent);
    void moveWithWebcam();
    void generateAsteroid(int asteroidNumber);
    void deleteAsteroid(int asteroidNumber);
    void collisionDetection(int asteroidNumber);

private:
    Starship* starship = nullptr;
    Station* station = nullptr;
    Asteroid* asteroidTab_[16];

    int randX[16];
    int randY[16];
    int randZ[16];
    int randRadius[16];
    int randXStation;
    int randYStation;
    int randZStation;

    int asteroidNumber_;
    bool end_= true;

    float m_TimeElapsed { 0.0f };
    QTimer m_AnimationTimer;

    Result* result;
    QTime startTime = QTime::currentTime();
};
