#include "Terrain.h"
#include "ofVbo.h"

int Terrain::getVertexCount()
{
    return (vertexCount);
}

ofVbo Terrain::getVbo()
{
    return (vbo);
}

Terrain::Terrain(ofVbo vbo, int vertexCount, TerrainRenderer *renderer)
: vbo(vbo), vertexCount(vertexCount), renderer(renderer)
{
}
