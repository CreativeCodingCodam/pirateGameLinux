#include "Terrain.h"
#include "ofCamera.h"
#include "ofLight.h"
#include "ofVbo.h"

int Terrain::getVertexCount()
{
    return (vertexCount);
}

ofVbo Terrain::getVbo()
{
    return (vbo);
}

Terrain::Terrain()
: vbo(ofVbo()), vertexCount(0)
{
}

Terrain::Terrain(ofVbo vbo, int vertexCount)
: vbo(vbo), vertexCount(vertexCount)
{
}
