#include <qopengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QImage>

class Asteroid{

public:
    Asteroid(GLfloat x, GLfloat y, GLfloat z, GLdouble radius);
    ~Asteroid();

    void setMaterial(float R_ambient, float G_ambient, float B_ambient,
                     float R_diffuse, float G_diffuse, float B_diffuse,
                     float R_specular, float G_specular, float B_specular,
                     float alpha) const;
    void addTexture() const;
    void drawAsteroid() const;
    void display() const;

private:
    GLUquadric * quadric{nullptr};
    GLuint* textures = new GLuint[1];
    GLfloat x_;
    GLfloat y_;
    GLfloat z_;
    GLdouble radius_;
};
