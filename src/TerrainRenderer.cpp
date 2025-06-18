#include "TerrainRenderer.h"
#include "fwd.hpp"
#include "ofConstants.h"
#include "ofVec3f.h"


TerrainRenderer::TerrainRenderer(TerrainShader shader, bool usesIndices)
: shader(shader), hasIndices(usesIndices)
{
}

void TerrainRenderer::render(Terrain terrain, ofCamera camera, ofLight light)
{
    prepare(terrain, camera, light);
    if (hasIndices)
        terrain.getVbo().drawElements(GL_TRIANGLES, terrain.getVertexCount());
    else
        terrain.getVbo().draw(GL_TRIANGLES, 0, terrain.getVertexCount());
    finish(terrain);
}

void TerrainRenderer::prepare(Terrain terrain, ofCamera camera, ofLight light)
{
    int hex = light.getDiffuseColor().getHex();
    glm::vec3 lightColour(((hex >> 16) & 0xFF), ((hex >> 8) & 0xFF), (hex & 0xFF));
    terrain.getVbo().bind();
    shader.begin();
    shader.setUniform3f("lightDirection", light.getLookAtDir());
    shader.setUniform3f("lightColour", lightColour);
    shader.setUniform2f("lightBias", glm::vec2(0.5, 0.5));
    shader.setUniformMatrix4f("projectionViewMatrix", camera.getModelViewProjectionMatrix());
}

void TerrainRenderer::finish(Terrain terrain)
{
    terrain.getVbo().unbind();
    shader.end();
}
