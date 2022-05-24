#include "asteroid.h"
#include "starship.h"
#include "station.h"
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
    void keyPressEvent(QKeyEvent * keyEvent);

private:
    Asteroid* asteroid = nullptr;
    Asteroid* asteroid2 = nullptr;
    Asteroid* asteroid3 = nullptr;
    Starship* starship = nullptr;
    Station* station = nullptr;

    float m_TimeElapsed { 0.0f };
    QTimer m_AnimationTimer;

    GLdouble eyeX = 16.0;
    GLdouble eyeY = 8.0;
    GLdouble eyeZ = 3.0;
    GLdouble centerX = 0.0;
    GLdouble centerY = 0.0;
    GLdouble centerZ = 0.0;
    GLdouble upX = 0.0;
    GLdouble upY = 1.0;
    GLdouble upZ = 0.0;
};
