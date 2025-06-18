#include "TerrainGenerator.h"
#include "ColourGenerator.h"
#include "PerlinNoise.h"
#include "Terrain.h"
#include <vector>

Terrain TerrainGenerator::generateTerrain(int gridSize)
{
    std::vector<std::vector<float>> heights = generateHeights(gridSize, perlinNoise);
    std::vector<std::vector<Colour>> colours = colourGen.generateColours(heights, perlinNoise.getAmplitude());
    return (createTerrain(heights, colours));
}

std::vector<std::vector<float>> TerrainGenerator::generateHeights(int gridSize, PerlinNoise perlinNoise)
{
    std::vector<std::vector<float>> heights(gridSize + 1, std::vector<float>(gridSize + 1, 0));
    for (int z = 0; z < heights.size(); z++) {
        for (int x = 0; x < heights[z].size(); x++) {
            heights[z][x] = perlinNoise.getPerlinNoise(x, z);
        }
    }
    return (heights);
}

TerrainGenerator::TerrainGenerator(PerlinNoise perlinNoise, ColourGenerator colourGen)
: perlinNoise(perlinNoise), colourGen(colourGen)
{
}

TerrainGenerator::~TerrainGenerator()
{
}

