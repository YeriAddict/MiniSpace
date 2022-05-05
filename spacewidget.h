#ifndef SPACEWIDGET_H
#define SPACEWIDGET_H

#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QTimer>
#include "asteroid.h"

class SpaceWidget : QOpenGLWidget
{
public:
    SpaceWidget(QWidget* parent = nullptr);

protected:

    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

private:
//    Asteroid* asteroid = nullptr;
//    float m_TimeElapsed { 0.0f };
//    QTimer m_AnimationTimer;
};

#endif // SPACEWIDGET_H
