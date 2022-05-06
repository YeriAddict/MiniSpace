#ifndef STARSHIP_H
#define STARSHIP_H

#include <qopengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QImage>

class Starship{

public:
    Starship();
    ~Starship();

    void display() const;
    void drawBody() const;
    void drawSides() const;
    void addTexture() const;

private:
    GLUquadric * quadric{nullptr};
    GLuint* textures = new GLuint[1];
};

#endif // STARSHIP_H
