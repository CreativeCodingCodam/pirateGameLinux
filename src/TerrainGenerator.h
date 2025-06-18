#ifndef TERRAINGENERATOR_H
#define TERRAINGENERATOR_H

#include "PerlinNoise.h"
#include "ColourGenerator.h"
#include <vector>
#include "Terrain.h"

class TerrainGenerator
{
public:
    TerrainGenerator(PerlinNoise perlinNoise, ColourGenerator colourGen);
    ~TerrainGenerator();
    Terrain generateTerrain(int gridSize);
    virtual Terrain createTerrain(std::vector<std::vector<float>> heigths, std::vector<std::vector<Colour>> colours) = 0;
    std::vector<std::vector<float>> generateHeights(int gridSize, PerlinNoise perlinNoise);
    void cleanUp();
private:
    PerlinNoise perlinNoise;
    ColourGenerator colourGen;
};

#endif // !TERRAINGENERATOR_H
