#include "BaseTerrainGenerator.h"
#include "TerrainGenerator.h"
#include "TerrainRenderer.h"
#include "TerrainShader.h"
#include "ofConstants.h"
#include "ofMesh.h"
#include <vector>

void BaseTerrainGenerator::render(Terrain &terrain, ofCamera &cam, ofLight &light)
{
    renderer.render(terrain, cam, light);
}

Terrain BaseTerrainGenerator::createTerrain(std::vector<ofVec3f> vertices, std::vector<ofFloatColor> colours)
{ 
    ofVbo vbo;
    int vertexCount = calculateVertexCount(vertices.size());
    //createindex
    // std::vector<ofIndexType> indices = createIndexBuffer(vertices.size());
    //setIndexData
    vbo.setVertexData(vertices.data(), vertices.size(), GL_DYNAMIC_DRAW);
    vbo.setColorData(colours.data(), colours.size(), GL_DYNAMIC_DRAW);
    return (Terrain(vbo, vertexCount));
}

int BaseTerrainGenerator::calculateVertexCount(int vertexLength)
{
    int bottom2Rows = 2 * vertexLength;
    int remainingRowCount = vertexLength - 2;
    int topCount = remainingRowCount * (vertexLength - 1) * 2;
    return (topCount + bottom2Rows);
}

BaseTerrainGenerator::BaseTerrainGenerator(PerlinNoise perlinNoise, ColourGenerator colourGen)
: TerrainGenerator(perlinNoise, colourGen), renderer(TerrainShader(vertexShader, fragmentShader), true)
{
}

BaseTerrainGenerator::BaseTerrainGenerator()
: TerrainGenerator(), renderer(TerrainShader(vertexShader, fragmentShader), true)
{
}

BaseTerrainGenerator::~BaseTerrainGenerator()
{
}
