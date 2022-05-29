#include "starship.h"

Starship::Starship(float x, float y, float z, float theta, float phi){
    quadric = gluNewQuadric();
    x_ = x;
    y_ = y;
    z_ = z;
    theta_ = theta;
    phi_ = phi;
}

Starship::~Starship(){
    if(quadric)
        gluDeleteQuadric(quadric);
}

void Starship::setMaterial(float R_ambient, float G_ambient, float B_ambient,
                           float R_diffuse, float G_diffuse, float B_diffuse,
                           float R_specular, float G_specular, float B_specular,
                           float alpha) const{
    GLfloat ambient_tab[] = { R_ambient/(1.f*255), G_ambient/(1.f*255), B_ambient/(1.f*255), alpha};
    GLfloat diffuse_tab[] = { R_diffuse/(1.f*255), G_diffuse/(1.f*255), B_diffuse/(1.f*255), alpha};
    GLfloat specular_tab[] = { R_specular/(1.f*255), G_specular/(1.f*255), B_specular/(1.f*255), alpha};

    glMaterialfv(GL_FRONT,GL_AMBIENT,ambient_tab);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,diffuse_tab);
    glMaterialfv(GL_FRONT,GL_SPECULAR,specular_tab);
    glMaterialf(GL_FRONT,GL_SHININESS,20);
}

void Starship::drawBody() const{
    setMaterial(0,5,110,0,5,110,255,255,255,50);
    gluQuadricDrawStyle(quadric, GLU_FILL);
    glPushMatrix();
    gluCylinder(quadric,2.,2.,14.,20,20);
    glPopMatrix();
}

void Starship::drawDisks() const{
    setMaterial(0,5,110,0,5,110,255,255,255,50);
    gluQuadricDrawStyle(quadric, GLU_FILL);

    glPushMatrix();
    // Top Disk
    glTranslatef(0.0f, 0.0f, 14.0f);
    gluDisk(quadric, 0.0, 2.0, 30, 2);

    // Bottom Disk
    glTranslatef(0.0f, 0.0f, -14.0f);
    gluDisk(quadric, 1.5, 2.0, 30, 2);

    // Reactor
    setMaterial(255,189,46,255,189,46,255,255,255,50);
    gluDisk(quadric, 0.0, 1.5, 30, 1);
    glPopMatrix();
}

void Starship::drawSides() const{
    setMaterial(230,0,31,230,0,31,255,255,255,50);
    glBegin(GL_TRIANGLES);

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

void Starship::drawHead() const{
    setMaterial(230,0,31,230,0,31,255,255,255,50);
    gluQuadricDrawStyle(quadric, GLU_FILL);

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 14.0f);
    gluCylinder(quadric,2.,0.,8.,20,20);
    glPopMatrix();
}

void Starship::display() const{
    glTranslatef(x_,y_,z_);
    glRotated(phi_,0,1,0);
    glRotated(theta_,1,0,0);
    glRotated(180,1.,0.,0.);
    drawBody();
    drawDisks();
    drawSides();
    drawHead();
}
