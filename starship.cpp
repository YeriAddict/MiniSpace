#include "starship.h"

Starship::Starship(){
    quadric = gluNewQuadric();
}

Starship::~Starship(){
    if(quadric)
        gluDeleteQuadric(quadric);
}

void Starship::drawBody() const{
    glColor3ub(0, 29, 110);
    gluQuadricDrawStyle(quadric, GLU_FILL);
    glPushMatrix();

    gluCylinder(quadric,2.,2.,14.,20,20);

        // Top Disk
    glTranslatef(0.0f, 0.0f, 14.0f);
    gluDisk(quadric, 0.0, 2.0, 30, 2);

        // Bottom Disk
    glTranslatef(0.0f, 0.0f, -14.0f);
    gluDisk(quadric, 1.5, 2.0, 30, 2);

        // Reactor
    glColor3ub(253, 208, 23);
    gluQuadricTexture(quadric, GLU_TRUE);
    gluDisk(quadric, 0.0, 1.5, 30, 1);

    glPopMatrix();
}

void Starship::drawSides() const{
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

void Starship::display() const{
    drawBody();
    drawSides();
}
