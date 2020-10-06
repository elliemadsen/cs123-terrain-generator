#ifndef BIOME_H
#define BIOME_H

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"            // glm::vec*, mat*, and basic glm functions
#include "glm/gtx/transform.hpp"  // glm::translate, scale, rotate
#include "glm/gtc/type_ptr.hpp"   // glm::value_ptr
#include <vector>

#include "openglshape.h"

/**
 * Parent class of all specific biomes.
 */
class Biome
{
public:
    Biome();
    virtual ~Biome();

    virtual float heightAt(int row, int col);
    float randValue(int row, int col);
    float valueNoise(int row, int col, float cellWidth, float ampDivisor);

    int m_type;

};

#endif // BIOME_H
