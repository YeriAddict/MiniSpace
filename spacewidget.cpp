#include "spacewidget.h"
#include <QApplication>
#include <cmath>
#include <algorithm>

const unsigned int WINDOW_SIZE = 700;

SpaceWidget::SpaceWidget(QWidget * parent) : QOpenGLWidget(parent){
    setFixedSize(WINDOW_SIZE, WINDOW_SIZE);

    connect(&m_AnimationTimer,  &QTimer::timeout, [&]{
        m_TimeElapsed += 1.0f;
        update();
    });

    m_AnimationTimer.setInterval(20);
    m_AnimationTimer.start();
}

void SpaceWidget::initializeGL(){
    glClearColor(0.8f, 0.8f, 0.8f, 0.0f);
    glEnable(GL_DEPTH_TEST);

    asteroid = new Asteroid();
    starship = new Starship();
}

void SpaceWidget::resizeGL(int width, int height){
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(width != 0)
       glFrustum(-5, 5, -5, 5, 2, 2000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void SpaceWidget::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(8.0f, 8.f, 3.f, 0.0f, 0.0f, 0.f, 0.0f, 1.0f, 0.0f);

    glEnable(GL_TEXTURE_2D);

    glPushMatrix();
    //asteroid->display();
    starship->display();
    glPopMatrix();
}
