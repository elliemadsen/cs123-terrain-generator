#ifndef MOUNTAINS_H
#define MOUNTAINS_H

#include "Biome.h"


class Mountains : public Biome
{
public:
    Mountains(int numRows, int numCols, float scale, int numOctaves, int type);
    ~Mountains();

    float heightAt(int row, int col);


private:
    int m_numRows;
    int m_numCols;
    float m_scale;
    int m_numOctaves;
};

#endif // MOUNTAINS_H
