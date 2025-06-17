#ifndef TERRAIN_H
#define TERRAIN_H

#include "ofEasyCam.h"
#include "ofLight.h"
#include "ofMain.h"
#include "ofVbo.h"

class Terrain 
{
public:
    int getVertexCount();
    ofVbo getVbo();
    void render(ofEasyCam camera, ofLight light);
    void deleteVbo();
    Terrain(ofVbo vbo, int vertexCount, TerrainRenderer renderer);
private:
    ofVbo vbo;
    int vertexCount;
    TerrainRenderer renderer;
};

#endif // !TERRAIN_H
