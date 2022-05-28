#include "asteroid.h"

Asteroid::Asteroid(GLfloat x, GLfloat y, GLfloat z, GLdouble radius){
    quadric = gluNewQuadric();
    x_ = x;
    y_ = y;
    z_ = z;
    radius_ = radius;
}

Asteroid::~Asteroid(){
    if(quadric)
        gluDeleteQuadric(quadric);
    delete[] textures;
}

void Asteroid::setMaterial(float R_ambient, float G_ambient, float B_ambient,
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

void Asteroid::addTexture() const{
    QImage asteroidTexture = QImage(":/asteroid_texture.jpg");
    QImage textAsteroidTexture = asteroidTexture.convertToFormat(QImage::Format_RGBA8888);
    glGenTextures(1, textures);
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glTexImage2D(GL_TEXTURE_2D,0,4,textAsteroidTexture.width(),textAsteroidTexture.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,textAsteroidTexture.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
}

void Asteroid::drawAsteroid() const{
    glEnable(GL_TEXTURE_2D);
    addTexture();
    glBindTexture(GL_TEXTURE_2D,textures[0]);
    gluQuadricTexture(quadric, GLU_TRUE);
    setMaterial(255,255,255,255,255,255,255,255,255,50);
    gluSphere(quadric,radius_,20,20);
    glDisable(GL_TEXTURE_2D);
    glLoadIdentity();
}

void Asteroid::display() const{
    glTranslatef(x_,y_,z_);
    drawAsteroid();
    glDeleteTextures(1,textures);
}
