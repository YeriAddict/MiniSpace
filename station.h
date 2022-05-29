#ifndef STATION_H
#define STATION_H

#include <qopengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QImage>

#pragma once
class Station {

public:
    Station(float x, float y, float z, double radius);
    ~Station();

    void addTexture() const;
    void setMaterial(float R_ambient, float G_ambient, float B_ambient,
                     float R_diffuse, float G_diffuse, float B_diffuse,
                     float R_specular, float G_specular, float B_specular,
                     float alpha) const;
    void drawCenter() const;
    void drawAntennas(int time) const;
    void display(float time) const;

private:
    GLUquadric * quadric{nullptr};
    GLuint* textures = new GLuint[2];
    float x_;
    float y_;
    float z_;
    double radius_;
};

#endif // STATION_H
