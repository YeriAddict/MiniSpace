#include "asteroid.h"

Asteroid::Asteroid(){
    QImage asteroidTexture = QImage(":/asteroid_texture.jpg");
    QImage textAsteroidTexture = asteroidTexture.convertToFormat(QImage::Format_RGBA8888);
    glGenTextures(1, textures);
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glTexImage2D(GL_TEXTURE_2D,0,4,textAsteroidTexture.width(),textAsteroidTexture.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,textAsteroidTexture.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
    quadric = gluNewQuadric();
}

Asteroid::~Asteroid(){
    if(quadric)
        gluDeleteQuadric(quadric);
}

void Asteroid::display() const{
    glEnable(GL_TEXTURE_2D);

    glColor3f(0.f,0.f,0.f);
    gluQuadricDrawStyle(quadric, GLU_LINE);
    glBindTexture(GL_TEXTURE_2D,textures[0]);
    gluQuadricTexture(quadric, GLU_TRUE);
    gluQuadricNormals(quadric, GLU_SMOOTH);
    gluSphere(quadric, 3.,20,20);

    glDisable(GL_TEXTURE_2D);
}
