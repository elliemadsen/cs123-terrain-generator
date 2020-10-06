#include "Hills.h"
#include "Biome.h"

#include <math.h>
#include "gl/shaders/ShaderAttribLocations.h"

#include <iostream>

/**
 * Class that models hills on the terrain
 *
 * @param numRows the number of rows in the terrain
 * @param numCols the number of columns in the terrain
 * @param scale the scale of the terrain (from 1 to 100)
 * @param octaves the number of octaves to include in the terrain
 * @param type the type of biome
 */
Hills::Hills(int numRows, int numCols, float scale, int octaves, int type) : Biome()
{
    m_numRows = numRows;
    m_numCols = numCols;
    m_scale = scale;
    m_type = type;
    m_numOctaves = octaves;
}

Hills::~Hills() {

}

/**
 * Determines the height of the hills at the (row, col) input.
 *
 * @param row the row at which to find the height
 * @param col the column at which to find the height
 * @return the height of the hills
 */
float Hills::heightAt(int row, int col) {
    float total = 0.0;
    // Split each terrain "chunk" into smaller rows and columns
    float cellWidth = m_scale / 10.0; // Change denominator to 5.0 if using 100 rows

    float ampDivisor = 75.f / m_scale; // Change numerator to 100.f if using 100 rows

    // For each octave
    for (int i = 0; i < m_numOctaves; i++) {

        // Use value noise to find the height at the location with a smaller amplitude and
        // frequency for each subsequent octave
        float level = valueNoise(row, col, cellWidth / (pow(2.f, i)), ampDivisor * 2.f);

        // If it's the first octave, add to make sure the hill isn't below "sea level"
        if (i == 0) {
            level = level + (1.f / ampDivisor);
        } else {
            // Otherwise take a fraction of the level height to keep hills from becoming mountains
            level = level * 0.1*(1.f / i);
        }

        // Update the total height
        total = total + level;
    }

    return total;
}
