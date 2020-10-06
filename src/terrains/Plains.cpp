#include "Plains.h"
#include <iostream>

/**
 * Class that models plains on the terrain
 *
 * @param numRows the number of rows in the terrain
 * @param numCols the number of columns in the terrain
 * @param scale the scale of the terrain (from 1 to 100)
 * @param type the type of biome
 */
Plains::Plains(int numRows, int numCols, float scale, int type) : Biome()
{
    m_numRows = numRows;
    m_numCols = numCols;
    m_scale = scale;
    m_type = type;
}

Plains::~Plains(){

}

/**
 * Determines the height of the plains at the (row, col) input.
 *
 * @param row the row at which to find the height
 * @param col the column at which to find the height
 * @return the height of the plains
 */
float Plains::heightAt(int row, int col) {

    float total = 0.0;
    float cellWidth = m_scale / 10.0; //Change denominator to 5.0 if using 100 rows

    float ampDivisor = 20.f / m_scale;

    // Plains only have two levels of low amplitude, low frequency noise
    float level1 = valueNoise(row, col, cellWidth, ampDivisor);
    total = level1 * 0.05;

    float level2 = valueNoise(row, col, cellWidth / 2.f, ampDivisor * 4.f);
    total = total + level2 * 0.02;

    return total;
}
