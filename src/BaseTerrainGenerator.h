#ifndef BASETERRAINGENERATOR_H
#define  BASETERRAINGENERATOR_H

#include "ColourGenerator.h"
#include "PerlinNoise.h"
#include "TerrainGenerator.h"
#include "TerrainRenderer.h"
#include "fwd.hpp"
#include "ofCamera.h"
#include "ofMesh.h"
#include <filesystem>
#include <vector>

class BaseTerrainGenerator : public TerrainGenerator
{
public:
    void render(Terrain &terrain, ofCamera &cam, ofLight &light);
    BaseTerrainGenerator(PerlinNoise perlinNoise, ColourGenerator colourGen);
    BaseTerrainGenerator();
    ~BaseTerrainGenerator();
protected:
    Terrain createTerrain(std::vector<ofVec3f> vertices, std::vector<ofFloatColor> colours) override;
private:
    void setVertexData(ofVbo &vbo, std::vector<ofVec3f> vertices);
    void setColorData(ofVbo &vbo, std::vector<ofFloatColor> colors);
    void setIndexData(ofVbo &vbo, std::vector<ofFloatColor> colors);
    int calculateVertexCount(int vertexLength);
    std::filesystem::path vertexShader = "terrainVertex.glsl";
    std::filesystem::path fragmentShader = "terrainFragment.glsl";
    TerrainRenderer renderer;
};

#endif // !BASETERRAINGENERATOR_H
