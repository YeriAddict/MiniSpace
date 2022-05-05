#include "spacewidget.h"
#include <QApplication>
#include <cmath>
#include <algorithm>

// Declarations des constantes
const unsigned int WINDOW_SIZE = 700;

SpaceWidget::SpaceWidget(QWidget* parent):QOpenGLWidget(parent)
{
    // Reglage de la taille/position
    setFixedSize(WINDOW_SIZE, WINDOW_SIZE);

//    // Connexion du timer
//    connect(&m_AnimationTimer,  &QTimer::timeout, [&] {
//        m_TimeElapsed += 1.0f;
//        update();
//    });

//    m_AnimationTimer.setInterval(20);
//    m_AnimationTimer.start();
}

void SpaceWidget::initializeGL(){
    // Reglage de la couleur de fond
    glClearColor(0.8f, 0.8f, 0.8f, 0.0f);

    // Activation du zbuffer
    glEnable(GL_DEPTH_TEST);
}

void SpaceWidget::resizeGL(int width, int height){
    // Definition du viewport (zone d'affichage)
    glViewport(0, 0, width, height);

    // Definition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.f, 1, 0.1f, 500.f);

//    if(width != 0)
//       glFrustum(-5, 5, -5, 5, 2, 2000);

//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
}

void SpaceWidget::paintGL(){
    //Réinitialisation du zbuffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Definition de la position de la camera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0f, 0.f, 0.f, 0.0f, 0.0f, 0.f, 0.0f, 0.0f, 0.0f);
    glPushMatrix();
}
