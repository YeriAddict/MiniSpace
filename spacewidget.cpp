#include "spacewidget.h"
#include <QApplication>
#include <cmath>
#include <algorithm>

// Declarations des constantes
const unsigned int WIN = 900;

SpaceWidget::SpaceWidget(QWidget* parent):QOpenGLWidget(parent)
{
    // Reglage de la taille/position
    setFixedSize(WIN, WIN);

//    // Connexion du timer
//    connect(&m_AnimationTimer,  &QTimer::timeout, [&] {
//        m_TimeElapsed += 1.0f;
//        update();
//    });

//    m_AnimationTimer.setInterval(20);
//    m_AnimationTimer.start();
}

void SpaceWidget::initializeGL(){

}

void SpaceWidget::resizeGL(int width, int heigth){

}

void SpaceWidget::paintGL(){

}
