#ifndef TERRAINRENDERER_H
#define TERRAINRENDERER_H

#include "ofCamera.h"
#include "ofLight.h"
#include "Terrain.h"
#include "TerrainShader.h"

class TerrainRenderer 
{
public:
    TerrainRenderer(TerrainShader shader, bool usesIndices);
    void render(Terrain terrain, ofCamera camera, ofLight light);
    void cleanUp();
    void prepare(Terrain terrain, ofCamera camera, ofLight light);
    void finish(Terrain terrain);
private:
    TerrainShader shader;
    bool hasIndices;
};

#endif // !TERRAINRENDERER_H
