#ifndef TERRAINGENERATOR_H
#define TERRAINGENERATOR_H

#include "PerlinNoise.h"
#include "ColourGenerator.h"
#include <vector>

class TerrainGenerator
{
public:
    Terrain generateTerrain(int gridSize);
    Terrain createTerrain(std::vector<std::vector<float>> heigths, std::vector<std::vector<Colour>> colours);
    std::vector<std::vector<float>> generateHeights(int gridSizie, PerlinNoise perlinNoise);
    void cleanUp();
private:
    PerlinNoise perlinNoise;
    ColourGenerator colourGen;
};

#endif // !TERRAINGENERATOR_H
