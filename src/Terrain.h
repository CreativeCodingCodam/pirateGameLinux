#ifndef TERRAIN_H
#define TERRAIN_H

#include "ofCamera.h"
#include "ofLight.h"
#include "ofMain.h"
#include "ofVbo.h"

class TerrainRenderer;

class Terrain 
{
public:
    int getVertexCount();
    ofVbo getVbo();
    void render(ofCamera camera, ofLight light);
    Terrain(ofVbo vbo, int vertexCount, TerrainRenderer *renderer);
private:
    ofVbo vbo;
    int vertexCount;
    TerrainRenderer *renderer;
};

#endif // !TERRAIN_H
