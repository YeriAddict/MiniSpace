#include "starship.h"

Starship::Starship(){
    quadric = gluNewQuadric();
}

Starship::~Starship(){
    if(quadric)
        gluDeleteQuadric(quadric);
}

void Starship::addTexture() const{
    QImage asteroidTexture = QImage(":/reactor_texture.jpg");
    QImage textAsteroidTexture = asteroidTexture.convertToFormat(QImage::Format_RGBA8888);
    glGenTextures(1, textures);
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glTexImage2D(GL_TEXTURE_2D,0,4,textAsteroidTexture.width(),textAsteroidTexture.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,textAsteroidTexture.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
}

void Starship::drawBody() const{

}

void Starship::drawSides() const{

}

void Starship::display() const{
    // Body
    glColor3ub(0, 29, 110);
    gluQuadricDrawStyle(quadric, GLU_FILL);
    glPushMatrix();
    gluCylinder(quadric,2.,2.,14.,20,20);
        // Top
    glTranslatef(0.0f, 0.0f, 14.0f);
    gluDisk(quadric, 0.0, 2.0, 30, 2);
        // Bottom
    glTranslatef(0.0f, 0.0f, -14.0f);
    gluDisk(quadric, 0.0, 2.0, 30, 1);
        // Reactor
    gluDisk(quadric, 0.0, 1.5, 30, 1);

    glPopMatrix();

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
