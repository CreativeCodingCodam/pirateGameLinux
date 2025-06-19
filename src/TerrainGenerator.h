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
    TerrainGenerator();
    ~TerrainGenerator();
    Terrain generateTerrain(int gridSize);
    virtual Terrain createTerrain(std::vector<ofVec3f> vertices, std::vector<ofFloatColor> colours) = 0;
    std::vector<ofVec3f> generateHeights(int gridSize, PerlinNoise perlinNoise);
    void cleanUp();
private:
    PerlinNoise perlinNoise;
    ColourGenerator colourGen;
};

#endif // !TERRAINGENERATOR_H
