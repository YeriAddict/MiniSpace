#include <qopengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QImage>

class Asteroid{

public:
    Asteroid();
    ~Asteroid();

    void addTexture() const;
    void drawAsteroid() const;
    void display() const;

private:
    GLUquadric * quadric{nullptr};
    GLuint* textures = new GLuint[1];

};
