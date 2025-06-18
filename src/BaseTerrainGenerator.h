#ifndef BASETERRAINGENERATOR_H
#define  BASETERRAINGENERATOR_H

#include "ColourGenerator.h"
#include "PerlinNoise.h"
#include "TerrainGenerator.h"
#include "TerrainRenderer.h"
#include "ofMesh.h"
#include <filesystem>
#include <vector>
class BaseTerrainGenerator : public TerrainGenerator
{
public:
    BaseTerrainGenerator(PerlinNoise perlinNoise, ColourGenerator colourGen);
    ~BaseTerrainGenerator();
protected:
    Terrain createTerrain(std::vector<std::vector<float>> heights, std::vector<std::vector<Colour>> colours) override;
private:
    int calculateVertexCount(int vertexLength);
    ofMesh createMeshData(std::vector<std::vector<float>> heights, std::vector<std::vector<Colour>> colours, int vertexCount);
    std::filesystem::path vertexShader = "terrainVertex.glsl";
    std::filesystem::path fragmentShader = "terrainFragment.glsl";
    TerrainRenderer renderer;
    int vertexSizeBytes = 12 + 4 + 4;
};

#endif // !BASETERRAINGENERATOR_H
