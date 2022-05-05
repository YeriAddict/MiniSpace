#include <qopengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QColor>

class Asteroid{

public:
    Asteroid();
    ~Asteroid();

    void display() const;

private:
    GLUquadric * quadric{nullptr};

};
