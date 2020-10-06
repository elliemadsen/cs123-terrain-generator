
#include "sky.h"
#include "glm/glm.hpp"


sky::sky():
    m_sky_textureID(),
    m_sphere(),
    m_numTriangles(),
    m_vertices()
{

}

sky::~sky()
{
    glDeleteTextures(1, &m_sky_textureID);
}

/**
 * Initializes the sky by calculating the vertices of a sphere, making a VAO with position, normal, and uv attributes,
 * and setting the texture as the corresponding sky image. Does not draw the sphere.
 */
void sky::init() {
    calculateVertices();
    makeVAO();
    getSkyImage();
    addTexture();
}
/**
 * Binds the texture and then draws the sphere.
 */
void sky::draw() {
    glActiveTexture(GL_TEXTURE0 + 2); // Texture unit 2
    glBindTexture(GL_TEXTURE_2D, m_sky_textureID);

    m_sphere->draw();
}

/**
 * Builds the VAO, which has three attributes: the position of each vertex, the normal vector at each vertex, and
 * the corresponding uv texture coordinate.
 */
void sky::makeVAO() {
    int num_vertices = m_numTriangles * 3;
    m_sphere = std::make_unique<OpenGLShape>();
    m_sphere->setVertexData(&m_vertices[0], m_vertices.size(), VBO::GEOMETRY_LAYOUT::LAYOUT_TRIANGLES, num_vertices);
    m_sphere->setAttribute(ShaderAttrib::POSITION, 3, 0, VBOAttribMarker::DATA_TYPE::FLOAT, false);
    m_sphere->setAttribute(ShaderAttrib::NORMAL, 3, 3*sizeof(float),VBOAttribMarker::DATA_TYPE::FLOAT, true);
    m_sphere->setAttribute(ShaderAttrib::TEXCOORD0, 2, 6*sizeof(float),VBOAttribMarker::DATA_TYPE::FLOAT, false);
    m_sphere->buildVAO();
}

/**
 * loads the sky image, which depends on which setting is currently selected on the UI: day, night, or sunset.
 */
void sky::getSkyImage() {

    switch (settings.sky) {
        case SkyType::DAY :
            m_sky_image = QImage(":/images/sky_image_day.jpg");
            break;
        case SkyType::NIGHT :
            m_sky_image = QImage(":/images/sky_image_night.jpg");
            break;
        case SkyType::SUNSET :
            m_sky_image = QImage(":/images/sky_image_sunset.jpg");
            break;
    }
}

/**
 * Generates the sky texture and binds the QImage m_sky_image to the GLuint m_sky_textureID.
 */
void sky::addTexture() {
    glGenTextures(1, &m_sky_textureID);
    glBindTexture(GL_TEXTURE_2D, m_sky_textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // linearly interpolates the texture color at each coord
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT); // mirrors and repeats the texture tiles
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_sky_image.width(), m_sky_image.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, m_sky_image.bits());
}


/**
 * This function uses parametric equations to calculate the vertices of a sphere, storing them in the vector m_vertices.
 * This code is taken from the Shapes project. It uses parameters of 40 and a radius of 15. The number of triangles is
 * updated as vertices are added to the VBO.
 */
void sky::calculateVertices() {

    m_numTriangles = 0;
    m_vertices.clear();

    int p1 = 40;
    int p2 = 40;
    float phi = (2*M_PI)/static_cast<float>(p1);
    float theta = (2*M_PI)/static_cast<float>(p2);
    const float r = m_radius;

    for (int i=0; i < p1/2; i++) { // iterate radially over each 'slice' of sphere
        for (int j=0; j < p2; j++) {  // iterate over each vertical strip

            // converts each point from spherical to cartesian coordinates:
            m_vertices.insert(m_vertices.end(), {
                  r*sin(phi*i)*cos(theta*j), r*cos(phi*i), r*sin(phi*i)*sin(theta*j), // position
                  -sin(phi*i)*cos(theta*j), -cos(phi*i), -sin(phi*i)*sin(theta*j) });// normal
                 insertUV(r*sin(phi*i)*cos(theta*j), r*cos(phi*i), r*sin(phi*i)*sin(theta*j)); // texcoords

            m_vertices.insert(m_vertices.end(), {
                  r*sin(phi*i)*cos(theta*(j+1)), r*cos(phi*i), r*sin(phi*i)*sin(theta*(j+1)),
                  -sin(phi*i)*cos(theta*(j+1)), -cos(phi*i), -sin(phi*i)*sin(theta*(j+1)) });
                insertUV(r*sin(phi*i)*cos(theta*(j+1)), r*cos(phi*i), r*sin(phi*i)*sin(theta*(j+1)));

            m_vertices.insert(m_vertices.end(), {
                  r*sin(phi*(i+1))*cos(theta*(j+1)), r*cos(phi*(i+1)), r*sin(phi*(i+1))*sin(theta*(j+1)),
                  -sin(phi*(i+1))*cos(theta*(j+1)), -cos(phi*(i+1)), -sin(phi*(i+1))*sin(theta*(j+1)) });
                insertUV(r*sin(phi*(i+1))*cos(theta*(j+1)), r*cos(phi*(i+1)), r*sin(phi*(i+1))*sin(theta*(j+1)));

            m_vertices.insert(m_vertices.end(), {
                  r*sin(phi*i)*cos(theta*j), r*cos(phi*i), r*sin(phi*i)*sin(theta*j),
                  -sin(phi*i)*cos(theta*j), -cos(phi*i), -sin(phi*i)*sin(theta*j) });
                insertUV(r*sin(phi*i)*cos(theta*j), r*cos(phi*i), r*sin(phi*i)*sin(theta*j));

            m_vertices.insert(m_vertices.end(), {
                  r*sin(phi*(i+1))*cos(theta*(j+1)), r*cos(phi*(i+1)), r*sin(phi*(i+1))*sin(theta*(j+1)),
                  -sin(phi*(i+1))*cos(theta*(j+1)), -cos(phi*(i+1)), -sin(phi*(i+1))*sin(theta*(j+1)) });
                insertUV(r*sin(phi*(i+1))*cos(theta*(j+1)), r*cos(phi*(i+1)), r*sin(phi*(i+1))*sin(theta*(j+1)));

            m_vertices.insert(m_vertices.end(), {
                  r*sin(phi*(i+1))*cos(theta*(j)), r*cos(phi*(i+1)), r*sin(phi*(i+1))*sin(theta*(j)),
                  -sin(phi*(i+1))*cos(theta*(j)), -cos(phi*(i+1)), -sin(phi*(i+1))*sin(theta*(j)) });
                insertUV(r*sin(phi*(i+1))*cos(theta*(j)), r*cos(phi*(i+1)), r*sin(phi*(i+1))*sin(theta*(j)));

            m_numTriangles +=2;
        }
    }
}

/**
 * This is a helper function for adding the uv texture coordinates to the VBO. It takes in the x,y, and z
 * positions of a vertex on the sphere and calculates the corresponding uv coordinates. These equations were
 * derived in Ray. This funciton also handles tileing.
 */
void sky::insertUV( float x, float y, float z) {

    // Calculates v:
    float phi = asin(y / m_radius);
    float v = 0.5 - (phi / M_PI);

    // Calculate u based on polar coordinates:
    float u;
    float theta = atan2(z, x);

    if (theta < 0) {
        u = - (theta / (2.0*M_PI));
    } else {
        u = (theta / (2.0*M_PI));
    }

    // Handle singularity at poles
    if (fabs(v) <= 0.0001 || fabs(v - 1) <= 0.0001) {
        u = 0.5;
    }

   // repeats the texture tiles depending on which sky is selected:
   int num_tiles_v = 3;
   int num_tiles_u = 3;
   if (selected_sky == SkyType::SUNSET) {
       num_tiles_u = 1;
       num_tiles_v = 0.5; }
   else if (selected_sky == SkyType::NIGHT) {
       num_tiles_u = 1; }

   u *= num_tiles_u;
   v *= num_tiles_v;

   // inserts the uv coordinates into the VBO:
   m_vertices.insert(m_vertices.end(), u);
   m_vertices.insert(m_vertices.end(), v);
}
