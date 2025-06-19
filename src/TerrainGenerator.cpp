#include "TerrainGenerator.h"
#include "ColourGenerator.h"
#include "PerlinNoise.h"
#include "Terrain.h"
#include "ofVec3f.h"
#include <vector>

Terrain TerrainGenerator::generateTerrain(int gridSize)
{
    std::vector<ofVec3f> vertices = generateHeights(gridSize, perlinNoise);
    std::vector<ofFloatColor> colours = colourGen.generateColours(vertices, perlinNoise.getAmplitude());
    return (createTerrain(vertices, colours));
} 

float random_float(float min, float max) {

	return ((float)rand() / RAND_MAX) * (max - min) + min;
}

std::vector<ofVec3f> TerrainGenerator::generateHeights(int gridSize, PerlinNoise perlinNoise)
{
    std::vector<ofVec3f> vertices;
    for (int y = 0; y < gridSize; y++) {
        for (int x = 0; x < gridSize; x++) {
            srand(time(NULL));
            // vertices.push_back(ofVec3f(x * 20, y * 20, perlinNoise.getPerlinNoise(x, y)));
            if (x % 2)
                vertices.push_back(ofVec3f(x * 20, y * 20, 0));
            else
                vertices.push_back(ofVec3f(x * 20, y * 20, random_float(1.0f, 100.0f)));
        }
    }
    return (vertices);
}

TerrainGenerator::TerrainGenerator(PerlinNoise perlinNoise, ColourGenerator colourGen)
: perlinNoise(perlinNoise), colourGen(colourGen)
{
}

TerrainGenerator::TerrainGenerator()
: perlinNoise(), colourGen()
{
}

TerrainGenerator::~TerrainGenerator()
{
}

