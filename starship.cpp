#include "starship.h"

Starship::Starship(){
    quadric = gluNewQuadric();
}

Starship::~Starship(){
    if(quadric)
        gluDeleteQuadric(quadric);
}

void Starship::display() const{
    // Body
    glColor3ub(0, 29, 110);
    gluQuadricDrawStyle(quadric, GLU_FILL);
//    glRotated(180, 0, 1, 0);
    gluCylinder(quadric,2.,2.,14.,10,10);

    // Triangles
    glBegin(GL_TRIANGLES);
    glColor3ub(230, 0, 31);

        // Right
    glVertex3f(2.f, 0.f, 0.f);
    glVertex3f(2.f, 0.f, 2.f);
    glVertex3f(5.f, 0.f, 0.f);

        // Left
    glVertex3f(-2.f, 0.f, 0.f);
    glVertex3f(-2.f, 0.f, 2.f);
    glVertex3f(-5.f, 0.f, 0.f);

        // Top
    glVertex3f(0.f, 2.f, 0.f);
    glVertex3f(0.f, 2.f, 2.f);
    glVertex3f(0.f, 5.f, 0.f);

        // Bottom
    glVertex3f(0.f, -2.f, 0.f);
    glVertex3f(0.f, -2.f, 2.f);
    glVertex3f(0.f, -5.f, 0.f);

    glEnd();
}
