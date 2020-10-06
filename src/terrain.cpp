#include "terrain.h"

#include <QCoreApplication>

#include <math.h>
#include "gl/shaders/ShaderAttribLocations.h"

#include <iostream>
#include <fstream>
#include "terrains/Biome.h"
#include "terrains/Mountains.h"
#include "terrains/Plains.h"
#include "terrains/Hills.h"

Terrain::Terrain() : m_numRows(50), m_numCols(m_numRows), m_scale(20.f),
  m_rock_image(":/images/ground_image_7.jpg"),
  m_grass_image(":/images/grass_image_2.jpg"),
  m_rock_normalmap(":/images/ground_normal_map_7.jpg"),
  m_grass_normalmap(":/images/grass_normal_map_2.jpg")

{
  createBiomes(); // Initialize biomes
}


Terrain::~Terrain() {
    // Delete textures
    glDeleteTextures(1, &m_rock_textureID);
    glDeleteTextures(1, &m_grass_textureID);
    glDeleteTextures(1, &m_rock_normalmapID);
    glDeleteTextures(1, &m_grass_normalmapID);

    // Delete all Biomes
    for (unsigned long i = 0; i < m_biomeLayers.size(); i++) {
        delete m_biomeLayers[i];
    }
    m_biomeLayers.clear();

    // Delete all terrain chunks
    for (unsigned long i = 0; i < m_terrainChunks.size(); i++) {
        delete m_terrainChunks[i];
    }
    m_terrainChunks.clear();
}

/**
 * Returns a pseudo-random value between -1.0 and 1.0 for the given row and column.
 */
float Terrain::randValue(int row, int col) {
    return -1.0 + 2.0 * glm::fract(sin(row * 127.1f + col * 311.7f) * 43758.5453123f);
}

/**
 * Recreates the biomes with the new settings and clears old terrain chunks.
 *
 * @param scale the new scale of the terrain
 * @param numOctaves the new number of octaves
 */
void Terrain::updateSettings(int scale, int numOctaves) {
    m_scale = scale;
    m_numOctaves = numOctaves;
    createBiomes();

    for (unsigned long i = 0; i < m_terrainChunks.size(); i++) {
        delete m_terrainChunks[i];
    }
    m_terrainChunks.clear();
}

/**
 * Creates a list of biomes based on user selection.
 */
void Terrain::createBiomes() {

    // Clear old bioemes
    for (unsigned long i = 0; i < m_biomeLayers.size(); i++) {
        delete m_biomeLayers[i];
    }
    m_biomeLayers.clear();


    // If users chooses mountains, create a new Mountains layer
    if (settings.useMountains) {
         Mountains* mount = new Mountains(m_numRows, m_numCols, m_scale, m_numOctaves, BiomeType::MOUNTS);
         m_biomeLayers.push_back(mount);
    }

    // If users chooses hills, create a new Hills layer
    if (settings.useHills) {
        Hills* hills = new Hills(m_numRows, m_numCols, m_scale, m_numOctaves, BiomeType::HILLS);
        m_biomeLayers.push_back(hills);
    }

    // If users chooses plains, create a new Plains layer
    if (settings.usePlains) {
        Plains* plains = new Plains(m_numRows, m_numCols, m_scale, BiomeType::PLAINS);
        m_biomeLayers.push_back(plains);
    }
}


/**
 * Returns the object-space position for the terrain vertex at the given row and column.
 */
glm::vec3 Terrain::getPosition(int row, int col) {

    glm::vec3 position;

    Biome* helper = new Biome();
    // Value used to determine which biome goes where
    float biomeValue = helper->valueNoise(row, col, m_numRows / (100.0 / m_scale), 1.0);
    delete helper;

    // Conver the biomeValue to be between 0 and 1
    biomeValue = (biomeValue / 2) + 0.5;

    float y = 0.f;
    int numBiomes = m_biomeLayers.size();

    // For each type of biome
    for (int i = 0; i < numBiomes; i++) {
        // If the biomeValue lies in a specific range (determined by number if biomes)
        if (((i - 1.f) / numBiomes <= biomeValue) && (biomeValue <= (i + 1.f) / numBiomes)) {
            // Then weigh the height of the biome at that point and add it to the resulting total height
            float biomeHeight = m_biomeLayers[i]->heightAt(row, col);
            float weight = (-fabs(numBiomes * biomeValue - i) + 1);
            y += weight * biomeHeight;
        }
    }

    position.y = y;
    position.x = 10 * row/m_numRows - 5;
    position.z = 10 * col/m_numCols - 5;

    return position;
}

/**
 * Returns the normal vector for the terrain vertex at the given row and column.
 */
glm::vec3 Terrain::getNormal(int row, int col) {
    // Compute the normal at the given row and column using the positions of the
    // neighboring vertices.

    glm::vec3 vertexPos = getPosition(row, col);
    glm::vec3 n0Pos = getPosition(row, col + 1);
    glm::vec3 n1Pos = getPosition(row - 1, col + 1);
    glm::vec3 n2Pos = getPosition(row - 1, col);
    glm::vec3 n3Pos = getPosition(row - 1, col - 1);
    glm::vec3 n4Pos = getPosition(row, col - 1);
    glm::vec3 n5Pos = getPosition(row + 1, col - 1);
    glm::vec3 n6Pos = getPosition(row + 1, col);
    glm::vec3 n7Pos = getPosition(row + 1, col + 1);

    glm::vec3 pn0n1_normal = glm::normalize(glm::cross((vertexPos - n1Pos), (vertexPos - n0Pos)));
    glm::vec3 pn1n2_normal = glm::normalize(glm::cross((vertexPos - n2Pos), (vertexPos - n1Pos)));
    glm::vec3 pn2n3_normal = glm::normalize(glm::cross((vertexPos - n3Pos), (vertexPos - n2Pos)));
    glm::vec3 pn3n4_normal = glm::normalize(glm::cross((vertexPos - n4Pos), (vertexPos - n3Pos)));
    glm::vec3 pn4n5_normal = glm::normalize(glm::cross((vertexPos - n5Pos), (vertexPos - n4Pos)));
    glm::vec3 pn5n6_normal = glm::normalize(glm::cross((vertexPos - n6Pos), (vertexPos - n5Pos)));
    glm::vec3 pn6n7_normal = glm::normalize(glm::cross((vertexPos - n7Pos), (vertexPos - n6Pos)));
    glm::vec3 pn7n0_normal = glm::normalize(glm::cross((vertexPos - n0Pos), (vertexPos - n7Pos)));

    glm::vec3 normal = glm::vec3((pn0n1_normal[0] + pn1n2_normal[0] + pn2n3_normal[0] + pn3n4_normal[0] + pn4n5_normal[0] + pn5n6_normal[0] + pn6n7_normal[0] + pn7n0_normal[0]) / 8,
            (pn0n1_normal[1] + pn1n2_normal[1] + pn2n3_normal[1] + pn3n4_normal[1] + pn4n5_normal[1] + pn5n6_normal[1] + pn6n7_normal[1] + pn7n0_normal[1]) / 8,
            (pn0n1_normal[2] + pn1n2_normal[2] + pn2n3_normal[2] + pn3n4_normal[2] + pn4n5_normal[2] + pn5n6_normal[2] + pn6n7_normal[2] + pn7n0_normal[2]) / 8);

    return normal;
}

/**
 * Initializes a terrain chunk by storing positions and normals in a vertex buffer.
 */
void Terrain::init(int i, int j) {

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // Initializes a grid of vertices using triangle strips.
    int numVertices = (m_numRows - 1) * (2 * m_numCols + 2);
    std::vector<glm::vec3> data(3 * numVertices); // Multilpy by 3 because storing 3 attributes
    int index = 0;

    for (int row = 0; row < m_numRows - 1; row++) {
        for (int col = m_numCols - 1; col >= 0; col--) {
            data[index++] = getPosition(row + (m_numRows - 5)*i, col + (m_numCols - 5)*j);
            data[index++] = getNormal  (row + (m_numRows - 5)*i, col + (m_numCols - 5)*j);
            data[index++] = getUV(row, col);
            data[index++] = getPosition(row + 1 + (m_numRows - 5)*i, col + (m_numCols - 5)*j);
            data[index++] = getNormal  (row + 1 + (m_numRows - 5)*i, col + (m_numCols - 5)*j);
            data[index++] = getUV(row + 1, col);
        }
        data[index++] = getPosition(row + 1 + (m_numRows - 5)*i, (m_numCols - 5)*j);
        data[index++] = getNormal  (row + 1 + (m_numRows - 5)*i, (m_numCols - 5)*j);
        data[index++] = getUV(row + 1, 0);
        data[index++] = getPosition(row + 1 + (m_numRows - 5)*i, m_numCols - 1 + (m_numCols - 5)*j);
        data[index++] = getNormal  (row + 1 + (m_numRows - 5)*i, m_numCols - 1 + (m_numCols - 5)*j);
        data[index++] = getUV(row + 1, m_numCols - 1);

    }

    // Initialize OpenGLShape.
    OpenGLShape* shape = new OpenGLShape();
    shape->setVertexData(&data[0][0], data.size() * 3, VBO::GEOMETRY_LAYOUT::LAYOUT_TRIANGLE_STRIP, numVertices);
    shape->setAttribute(ShaderAttrib::POSITION, 3, 0, VBOAttribMarker::DATA_TYPE::FLOAT, false);
    shape->setAttribute(ShaderAttrib::NORMAL, 3, sizeof(glm::vec3), VBOAttribMarker::DATA_TYPE::FLOAT, false);
    shape->setAttribute(ShaderAttrib::TEXCOORD1, 3, 2*sizeof(glm::vec3), VBOAttribMarker::DATA_TYPE::FLOAT, false);

    // Build VAO and add shape to list of terrain chunk
    shape->buildVAO();
    shape->setExportData(data);
    m_terrainChunks.push_back(shape);

    // Add normal map and texture to the terrain segment
    addNormapMap();
    addTexture();
}


/**
 * Binds the textures and draws the terrain.
 */
void Terrain::draw()
{
    bindTextures();
    for (int i = 0; i < m_terrainChunks.size(); i++) {
        m_terrainChunks[i]->draw();
    }
}

/**
 * Gets UV coordinate of the terrain from the (row, col) input.
 */
glm::vec3 Terrain::getUV(float row, float col) {
    int num_tiles = 9;
    float u = num_tiles*(static_cast<float>(col)/m_numCols);
    float v = num_tiles*(static_cast<float>(row)/m_numRows);
    if (settings.useNormalMapping) {
        return glm::vec3(u, v, 1);
    }
    return glm::vec3(u, v, 0);
}

/**
 * Sets up all of the terrain textures.
 */
void Terrain::addTexture() {
        // rock texture:
        glGenTextures(1, &m_rock_textureID);
        glBindTexture(GL_TEXTURE_2D, m_rock_textureID);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);// repeats and mirrors the tiled texture
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_rock_image.width(), m_rock_image.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, m_rock_image.bits());

        // grass texture:
        glGenTextures(1, &m_grass_textureID);
        glBindTexture(GL_TEXTURE_2D, m_grass_textureID);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT); // repeats and mirrors the tiled texture
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_grass_image.width(), m_grass_image.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, m_grass_image.bits());
}

/**
 * Sets up the terrain normal maps
 */
void Terrain::addNormapMap() {
    // rock normal map:
    glGenTextures(1, &m_rock_normalmapID);
    glBindTexture(GL_TEXTURE_2D, m_rock_normalmapID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_rock_normalmap.width(), m_rock_normalmap.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, m_rock_normalmap.bits());
    // grass normal map:
    glGenTextures(1, &m_grass_normalmapID);
    glBindTexture(GL_TEXTURE_2D, m_grass_normalmapID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_grass_normalmap.width(), m_grass_normalmap.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, m_grass_normalmap.bits());

}


/**
 * binds the texture and the normal map to the fragment shader
 */
void Terrain::bindTextures() {
    glActiveTexture(GL_TEXTURE0 + 0); // Texture unit 0
    glBindTexture(GL_TEXTURE_2D, m_rock_textureID);

    glActiveTexture(GL_TEXTURE0 + 1); // Texture unit 1
    glBindTexture(GL_TEXTURE_2D, m_grass_textureID);

    glActiveTexture(GL_TEXTURE0 + 2); // Texture unit 2
    glBindTexture(GL_TEXTURE_2D, m_rock_normalmapID);

    glActiveTexture(GL_TEXTURE0 + 3); // Texture unit 3
    glBindTexture(GL_TEXTURE_2D, m_grass_normalmapID);

}

/**
 * Writes an .obj file representing the terrain's geometry, excluding textures and normal mapping
 */
void Terrain::toOBJ() {

    std::cout << "EXPORTING AS OBJ..." << std::endl;
    //std::ofstream file(QCoreApplication::applicationDirPath().toStdString() + "/terrain.obj");
    std::ofstream file("/Users/jennasoenksen/Desktop/cs1230/terrain_gen/terrain.obj");

    // If file has been found
    if (file.is_open()) {

        file << "g default" << "\n";

        // For each chunk of the terrain
        for (int t = 0; t < m_terrainChunks.size(); t++) {

            // Get the data for that chunk
            std::vector<glm::vec3> data = m_terrainChunks[t]->getExportData();

            // Write all of the vertex data
            for (int i = 0; i < (data.size() / 3.0); i++) {
                file << "v " << data[3*i].x << " " << data[3*i].y << " " << data[3*i].z << "\n";
            }

            // Write all of the normal data
            for (int i = 0; i < (data.size() / 3.0); i++) {
                file << "vn " << data[3*i + 1].x << " " << data[3*i + 1].y << " " << data[3*i + 1].z << "\n";
            }

            // Define each chunk as a piece of geometry
            file << "g chunk" << t << "\n";

            // Define all of the faces of the geometry
            for (int i = (data.size() / 3.0) * (t); i < (data.size() / 3.0) * (t+1) - 3; i++) {
                if (i % 2 == 0) {
                    file << "f " << (i + 1) << "//" << (i + 1) << " " << (i+ 2) << "//" << (i + 2) << " " << (i + 3) << "//" << (i + 3) << "\n";
                } else {
                    file << "f " << (i + 3) << "//" << (i + 3) << " " << (i+ 2) << "//" << (i + 2) << " " << (i + 1) << "//" << (i + 1) << "\n";
                }
            }
        }

        file << "s 1" << "\n";

        // Close
        file.close();
        std::cout << "DONE!" << std::endl;

    } else {
        std::cout << "Unable to open file" << std::endl;
    }
}
