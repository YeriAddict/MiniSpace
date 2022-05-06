#ifndef STARSHIP_H
#define STARSHIP_H

#include <qopengl.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Starship{

public:
    Starship();
    ~Starship();

    void display() const;

private:
    GLUquadric * quadric{nullptr};
};

#endif // STARSHIP_H
