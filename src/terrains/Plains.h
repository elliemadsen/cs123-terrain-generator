#ifndef PLAINS_H
#define PLAINS_H

#include "Biome.h"

class Plains : public Biome
{
public:
    Plains(int numRows, int numCols, float scale, int type);
    ~Plains();

    float heightAt(int row, int col);


private:
    int m_numRows;
    int m_numCols;
    float m_scale;
};

#endif // PLAINS_H
