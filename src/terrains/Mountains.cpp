#include "Mountains.h"
#include <iostream>

/**
 * Class that models mountains on the terrain
 *
 * @param numRows the number of rows in the terrain
 * @param numCols the number of columns in the terrain
 * @param scale the scale of the terrain (from 1 to 100)
 * @param octaves the number of octaves to include in the terrain
 * @param type the type of biome
 */
Mountains::Mountains(int numRows, int numCols, float scale, int numOctaves, int type) : Biome()
{
    m_numRows = numRows;
    m_numCols = numCols;
    m_scale = scale;
    m_numOctaves = numOctaves;
    m_type = type;
}

Mountains::~Mountains() {

}

/**
 * Determines the height of the mountains at the (row, col) input.
 *
 * @param row the row at which to find the height
 * @param col the column at which to find the height
 * @return the height of the mountains
 */
float Mountains::heightAt(int row, int col) {
    float total = 0.0;

    float cellWidth = m_scale / 10.0; //Change denominator to 5.0 if using 100 rows

    float ampDivisor = 20.f / m_scale;

    // For the number of octaves wanted
    for (int i = 0; i < m_numOctaves; i++) {

        // Create a new octave level of noise by dividing frequency and amplitude by two
        float level = valueNoise(row, col, cellWidth / (pow(2.f, i)), ampDivisor * (2*pow(2.f,i)));
        if (i == 0) {
            level = level + (1.f / ampDivisor); // Make sure mountains aren't below "sea level"
        } else {
            level = level * 0.5; // Take half of the height level
        }

        // Update the total output height
        total = total + level;
    }
    return total;
}
