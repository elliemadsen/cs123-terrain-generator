#ifndef SKY_H
#define SKY_H

#include "openglshape.h"
#include "gl/shaders/ShaderAttribLocations.h"
#include <math.h>
#include <iostream>
#include <memory>
#include <vector>
#include <QImage>
#include "glm/glm.hpp"
#include "settings.h"


class sky
{
public:
    sky();
    ~sky();
    void init();
    void draw();


private:
    void calculateVertices();
    void insertUV( float x, float y, float z);
    void makeVAO();
    void getSkyImage();
    void addTexture();

    const int m_radius = 15;
    int m_numTriangles;
    std::vector<float> m_vertices;
    std::unique_ptr<OpenGLShape> m_sphere;
    GLuint m_sky_textureID;
    QImage m_sky_image;
    SkyType selected_sky;



};

#endif // SKY_H
