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

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat ambient_tab[] = { 1.f, 1.f, 1.f, 1.f};
    GLfloat diffuse_tab[] = { 1.f, 1.f, 1.f, 1.f};
    GLfloat specular_tab[] = { 1.f, 1.f, 1.f, 1.f};
    GLfloat light_tab[] = { 0.f, 0.f, 1.f, 0.f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_tab);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_tab);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_tab);
    glLightfv(GL_LIGHT0, GL_POSITION, light_tab);

    asteroid = new Asteroid(0,0,0, 3);
    asteroid2 = new Asteroid(10,10,10, 5);
    asteroid3 = new Asteroid(-10,-10,-10, 8);
    starship = new Starship(20,20,20);
    station = new Station(30,30,30,6);
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
    gluLookAt(eyeX,eyeY,eyeZ,centerX,centerY,centerZ,upX,upY,upZ);

    //glEnable(GL_TEXTURE_2D);

    glPushMatrix();
    asteroid->display();
    gluLookAt(eyeX,eyeY,eyeZ,centerX,centerY,centerZ,upX,upY,upZ);
    asteroid2->display();
    gluLookAt(eyeX,eyeY,eyeZ,centerX,centerY,centerZ,upX,upY,upZ);
    asteroid3->display();
    gluLookAt(eyeX,eyeY,eyeZ,centerX,centerY,centerZ,upX,upY,upZ);
    starship->display();
    gluLookAt(eyeX,eyeY,eyeZ,centerX,centerY,centerZ,upX,upY,upZ);
    station->display();
    glPopMatrix();
}

void SpaceWidget::keyPressEvent(QKeyEvent * keyEvent)
{
    if(keyEvent->key() == Qt::Key_Q)
    {
        eyeX-=0.6;
    }
    if(keyEvent->key() == Qt::Key_D)
    {
        eyeX += 0.6;
    }
    if(keyEvent->key() == Qt::Key_S)
    {
        eyeZ -= 0.6;
    }
    if(keyEvent->key() == Qt::Key_Z)
    {
        eyeZ += 0.6;
    }
}
