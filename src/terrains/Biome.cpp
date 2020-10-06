#include "Biome.h"

#include <math.h>
#include "gl/shaders/ShaderAttribLocations.h"

#include <iostream>

/**
 * Parent class of all specific biomes.
 */
Biome::Biome()
{
}

Biome::~Biome() {

}

float Biome::heightAt(int row, int col) {
}

/**
 * Produces pseudo-random value between -1 and 1 based on row, col input
 */
float Biome::randValue(int row, int col) {
    return -1.0 + 2.0 * glm::fract(sin(row * 127.1f + col * 311.7f) * 43758.5453123f);
}

/**
 * Generates a value based on value noise. Bilinearly interpolates to create smooth
 * transtions between values. Used to determine height outputs for terrain octaves.
 *
 * @param row the row at which to determine the noise value
 * @param col the column at which to determine the noise value
 * @param cellWidth the width of the cell of the grid for which the value is calculated for
 * @param ampDivisor the factor that divides the random values to shrink the range of output values
 * @return a float that represents the value of the noise function at (row, col)
 */
float Biome::valueNoise(int row, int col, float cellWidth, float ampDivisor) {
    float noiseValue = 0.f;

    int newRow = glm::floor(row/cellWidth);
    int newCol = glm::floor(col/cellWidth);

    float A = randValue(newRow, newCol) / ampDivisor;
    float B = randValue(newRow, newCol + 1) / ampDivisor;
    float C = randValue(newRow + 1, newCol) / ampDivisor;
    float D = randValue(newRow + 1, newCol + 1) / ampDivisor;

    float x1 = glm::fract(col/cellWidth);
    float x2 = glm::fract(row/cellWidth);

    // Bilinearly interpolate between A, B, C, D
    float horiz1 = glm::mix(A, B, x1*x1*(3-2*x1));
    float horiz2 = glm::mix(C, D, x1*x1*(3-2*x1));
    noiseValue = glm::mix(horiz1, horiz2, x2*x2*(3-2*x2));

    return noiseValue;
}
