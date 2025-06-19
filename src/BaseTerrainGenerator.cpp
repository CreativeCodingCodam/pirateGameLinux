#include "BaseTerrainGenerator.h"
#include "TerrainGenerator.h"
#include "TerrainRenderer.h"
#include "TerrainShader.h"
#include "ofMesh.h"
#include <vector>


BaseTerrainGenerator::BaseTerrainGenerator(PerlinNoise perlinNoise, ColourGenerator colourGen)
: TerrainGenerator(perlinNoise, colourGen), renderer(TerrainShader(vertexShader, fragmentShader), true)
{
}

BaseTerrainGenerator::~BaseTerrainGenerator()
{
}
