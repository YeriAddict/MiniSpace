#include "asteroid.h"
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QTimer>

class SpaceWidget : public QOpenGLWidget{
public:

    // Constructeur
    SpaceWidget(QWidget * parent = nullptr);

protected:

    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

private:
    Asteroid* asteroid = nullptr;

    float m_TimeElapsed { 0.0f };
    QTimer m_AnimationTimer;
};
