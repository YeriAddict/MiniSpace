#include "asteroid.h"

Asteroid::Asteroid(){
    quadric = gluNewQuadric();
}

Asteroid::~Asteroid(){
    if(quadric)
        gluDeleteQuadric(quadric);
}

void Asteroid::display() const{
    glPushMatrix();
    glColor3f(0.f,0.f,0.f);
    gluQuadricDrawStyle(quadric, GLU_LINE);
    gluSphere(quadric, 3.,20,20);
}
