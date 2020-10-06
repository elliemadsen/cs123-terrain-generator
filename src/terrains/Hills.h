#ifndef HILLS_H
#define HILLS_H

#include "Biome.h"

class Hills : public Biome
{
public:
    Hills(int numRows, int numCols, float scale, int octaves, int type);
    ~Hills();

    float heightAt(int row, int col);

private:
    int m_numRows;
    int m_numCols;
    float m_scale;
    int m_numOctaves;
};

#endif // HILLS_H
