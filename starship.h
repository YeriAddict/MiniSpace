#ifndef STARSHIP_H
#define STARSHIP_H

#include <qopengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QImage>

#pragma once
class Starship {

public:
    Starship(float x, float y, float z);
    ~Starship();

    float getX();
    float getY();
    float getZ();
    void setX(float x);
    void setY(float y);
    void setZ(float z);
    void setMaterial(float R_ambient, float G_ambient, float B_ambient,
                     float R_diffuse, float G_diffuse, float B_diffuse,
                     float R_specular, float G_specular, float B_specular,
                     float alpha) const;
    void drawBody() const;
    void drawDisks() const;
    void drawSides() const;
    void drawHead() const;
    void display() const;

private:
    GLUquadric * quadric{nullptr};
    GLuint* textures = new GLuint[1];
    float x_;
    float y_;
    float z_;
};

#endif // STARSHIP_H
