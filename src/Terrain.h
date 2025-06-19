#ifndef TERRAIN_H
#define TERRAIN_H

#include "ofCamera.h"
#include "ofLight.h"
#include "ofMain.h"
#include "ofVbo.h"

class Terrain 
{
public:
    int getVertexCount();
    ofVbo getVbo();
    Terrain();
    Terrain(ofVbo vbo, int vertexCount);
private:
    ofVbo vbo;
    int vertexCount;
};

#endif // !TERRAIN_H
