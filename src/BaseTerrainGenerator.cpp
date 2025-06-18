#include "BaseTerrainGenerator.h"
#include "TerrainGenerator.h"
#include "TerrainRenderer.h"
#include "TerrainShader.h"
#include "ofMesh.h"
#include <vector>

Terrain BaseTerrainGenerator::createTerrain(std::vector<std::vector<float>> heights, std::vector<std::vector<Colour>> colours)
{ 
    int vertexCount = calculateVertexCount(heights.size());
    ofMesh terrainData = createMeshData(heights, colours, vertexCount);
    std::vector<int> indices = BaseIndexGenerator.generateIndexBuffer(heights.size());
}

int BaseTerrainGenerator::calculateVertexCount(int vertexLength)
{
    int bottom2Rows = 2 * vertexLength;
    int remainingRowCount = vertexLength - 2;
    int topCount = remainingRowCount * (vertexLength - 1) * 2;
    return (topCount + bottom2Rows);
}

ofMesh BaseTerrainGenerator::createMeshData(std::vector<std::vector<float>> heights, std::vector<std::vector<Colour>> colours, int vertexCount)
{
}

BaseTerrainGenerator::BaseTerrainGenerator(PerlinNoise perlinNoise, ColourGenerator colourGen)
: TerrainGenerator(perlinNoise, colourGen), renderer(TerrainShader(vertexShader, fragmentShader), true)
{
}

BaseTerrainGenerator::~BaseTerrainGenerator()
{
}
