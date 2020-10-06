#ifndef TERRAIN_H
#define TERRAIN_H

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"            // glm::vec*, mat*, and basic glm functions
#include "glm/gtx/transform.hpp"  // glm::translate, scale, rotate
#include "glm/gtc/type_ptr.hpp"   // glm::value_ptr
#include <vector>
#include "settings.h"

#include "openglshape.h"
#include "terrains/Biome.h"
#include "QImage"

enum BiomeType {
    MOUNTS,
    PLAINS,
    HILLS
};

class Terrain {
public:
    Terrain();
    ~Terrain();

    void init();
    void init(int i, int j);
    void draw();

    void updateSettings(int scale, int numOctaves);
    void toOBJ();

private:
    void createBiomes();

    float randValue(int row, int col);
    glm::vec3 getPosition(int row, int col);
    glm::vec3 getNormal(int row, int col);
    std::unique_ptr<OpenGLShape> m_shape;
    const float m_numRows, m_numCols;
    float m_scale;
    int m_numOctaves;
    std::vector<Biome*> m_biomeLayers;
    std::vector<OpenGLShape*> m_terrainChunks;


    glm::vec3 getUV(float row, float col);
    void addTexture();
    void addNormapMap();
    void bindTextures();
    QImage m_rock_image;
    QImage m_grass_image;
    GLuint m_rock_textureID;
    GLuint m_grass_textureID;

    QImage m_rock_normalmap;
    QImage m_grass_normalmap;
    GLuint m_rock_normalmapID;
    GLuint m_grass_normalmapID;


};

#endif // TERRAIN_H
