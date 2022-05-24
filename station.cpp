#include "station.h"

Station::Station(GLfloat x, GLfloat y, GLfloat z, GLdouble radius){
    quadric = gluNewQuadric();
    x_ = x;
    y_ = y;
    z_ = z;
    radius_ = radius;
}

Station::~Station(){
    if(quadric)
        gluDeleteQuadric(quadric);
}

void Station::addTexture() const{
    QImage logoTexture = QImage(":/logo_texture.jpg");
    QImage textLogoTexture = logoTexture.convertToFormat(QImage::Format_RGBA8888);
    glGenTextures(1, textures);
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glTexImage2D(GL_TEXTURE_2D,0,4,textLogoTexture.width(),textLogoTexture.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,textLogoTexture.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
}

void Station::setMaterial(float R_ambient, float G_ambient, float B_ambient,
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

void Station::drawCenter() const{
    setMaterial(255,255,255,255,255,255,255,255,255,50);
    glEnable(GL_TEXTURE_2D);
    addTexture();
    glBindTexture(GL_TEXTURE_2D,textures[0]);
    gluQuadricTexture(quadric, GLU_TRUE);
    gluSphere(quadric, radius_,20,20);
    glDisable(GL_TEXTURE_2D);
}

void Station::drawAntennas() const{
    gluQuadricDrawStyle(quadric, GLU_FILL);

    glPushMatrix();
    // Top Antenna
    setMaterial(0,5,110,0,5,110,255,255,255,50);
    glTranslatef(0.0f, 0.0f, 6.0f);
    gluCylinder(quadric,1.,1.,14.,20,20);
    glTranslatef(0.0f, 0.0f, 14.0f);
    gluDisk(quadric, 0.0, 1.0, 30, 2);

    // Bottom Antenna
    setMaterial(230,0,31,230,0,31,255,255,255,50);
    glTranslatef(0.0f, 0.0f, -40.0f);
    gluCylinder(quadric,1.,1.,14.,20,20);
    gluDisk(quadric, 0.0, 1.0, 30, 2);
    glPopMatrix();
}

void Station::display() const{
    glTranslatef(x_,y_,z_);
    drawCenter();
    drawAntennas();
}